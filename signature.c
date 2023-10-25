#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/err.h>

typedef struct {
    char filename[10];
    char string[1000];
    int size;
} filemetadata;

// Function for error handling
void print_openssl_error() {
    unsigned long err_code = ERR_get_error(); // Get the last occurred OpenSSL error code
    char err_msg[256];
    memset(err_msg, 0, sizeof(err_msg));
    ERR_error_string_n(err_code, err_msg, sizeof(err_msg)); // Convert the OpenSSL error code to a human-readable error message
    printf("OpenSSL Error: %s\n", err_msg);
}

// Function for decoding the base64 encoded input
int base64_decode(const unsigned char* input, size_t input_len, unsigned char* output, size_t* output_len) {
    BIO* bio, * b64;
    int decodeLen = 0;

    b64 = BIO_new(BIO_f_base64()); // Create a new BIO object for base64 decoding
    bio = BIO_new_mem_buf(input, input_len); // Create a new memory BIO with the input buffer
    bio = BIO_push(b64, bio); // Push the base64 BIO into the memory BIO

    *output_len = BIO_read(bio, output, input_len); // Perform the base64 decoding and get the output length

    BIO_free_all(bio); // Free the BIO objects
    return 1; // Return 1 on success, 0 on failure
}

// Function to verify the given signature
int verify_signature(const char* filename, EVP_PKEY* pubkey, const unsigned char* signature, size_t signature_len) {
    FILE* file = fopen(filename, "rb"); // Open the file in binary read mode
    if (!file) {
        printf("Failed to open the file to verify.\n");
        return 0; // Return 0 to indicate failure
    }

    EVP_MD_CTX* md_ctx = EVP_MD_CTX_new(); // Create a new message digest context
    if (md_ctx == NULL) {
        fclose(file);
        printf("Failed to create message digest context.\n");
        return 0; // Return 0 to indicate failure
    }

    EVP_MD_CTX_init(md_ctx); // Initialize the message digest context
    if (EVP_VerifyInit(md_ctx, EVP_sha256()) != 1) { // Initialize verification with SHA-256 hash function
        EVP_MD_CTX_free(md_ctx);
        fclose(file);
        printf("Failed to initialize verification.\n");
        return 0; // Return 0 to indicate failure
    }

    unsigned char buffer[1024];
    size_t read_len;

    while ((read_len = fread(buffer, 1, sizeof(buffer), file)) > 0) { // Read data from the file in chunks
        if (EVP_DigestUpdate(md_ctx, buffer, read_len) != 1) { // Update the verification with the read data
            EVP_MD_CTX_free(md_ctx);
            fclose(file);
            printf("Failed to update verification.\n");
            return 0; // Signature verification failed, return 0 to indicate failure
        }
    }

    fclose(file); // Close the file

    // Decoding the base64-encoded signature
    unsigned char decoded_signature[1024];
    size_t decoded_len = sizeof(decoded_signature);
    if (!base64_decode(signature, signature_len, decoded_signature, &decoded_len)) { // Decode the base64-encoded signature
        printf("Failed to decode the base64-encoded signature.\n");
        return 0; // Return 0 to indicate failure
    }

    printf("Decoded Signature: ");
    for (int i = 0; i < decoded_len; i++) {
        printf("%02x", decoded_signature[i]); // Print the decoded signature in hexadecimal format
    }
    printf("\n");

    int result = EVP_VerifyFinal(md_ctx, decoded_signature, decoded_len, pubkey); // Perform the final verification
    EVP_MD_CTX_free(md_ctx); // Free the message digest context

    if (result == 1) {
        printf("Signature verification successful.\n"); // Signature verification successful, return 1 to indicate success
    } else {
        printf("Signature verification failed.\n");
        print_openssl_error(); // Signature verification failed, print the OpenSSL error
    }

    return result == 1 ? 1 : 0; // Return 1 on success, 0 on failure
}

int main(int argc, char *argv[]) {
    filemetadata metadata;
    unsigned char sign[1026];
    size_t signature_len = 0;

    char *publickey = argv[1];
    
    
    if (argc < 3) {
        printf("Usage: %s merged_file [ls/append/cat] inputfiles...\n", argv[0]);
        return 1;
    }

    for(int i=3; i < argc; i++)
    {
       char *inputfile = argv[i-1];
       char *signfile = argv[i];
       
       FILE *sf = fopen(signfile, "rb"); // Open the signature file for file1 in binary read mode
       if (sf == NULL) {
          printf("Failed to open the signature file.\n");
          return 1; // Return 1 to indicate failure
        }

       // Extract signature and its length from the signature file
       signature_len = fread(sign, 1, sizeof(sign), sf);
       fclose(sf); // Close the signature file for file1

       // Read the public key from the public key file
       FILE *pubkey_file = fopen(publickey, "rb");
       EVP_PKEY* pubkey = PEM_read_PUBKEY(pubkey_file, NULL, NULL, NULL);
       if (pubkey == NULL) {
          printf("Failed to read the public key from the file.\n");
          return 1; // Return 1 to indicate failure
        }

        FILE *input = fopen(inputfile, "rb"); // Open the signature file for file1 in binary read mode
        if (input == NULL) {
          printf("Failed to open the signature file %s.\n",argv[i]);
          return 1; // Return 1 to indicate failure
        }

       // Verify the signature for file1 using the public key
       int result = verify_signature(inputfile, pubkey, sign, signature_len);
       EVP_PKEY_free(pubkey); // Free the public key object

       if (result == 0) {
          printf("Signature verification failed for file  %s.\n",argv[i-1]);
          return 1; // Return 1 to indicate failure
        }  else {
          printf("Signature verification successful for file %s.\n",argv[i-1]);
        }

        fclose(input);
        i++;

    }

    return 0; // Return 0 to indicate successful execution
}