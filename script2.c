#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/err.h>

typedef struct {
    char filename[10];
    int filesize;
    char index1;
    char index2;
    char string1[50];
    char string2[50];
    int size1;
    int size2;
    int size3;
    char keyvalue[836];
} metadata;

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

int main() {
    metadata data;
    int f1size, f2size, f3size, f4size, f5size;
    char ch;
    unsigned char sign[2000], sign1[2000], sign2[2000], sign3[2000], sign4[2000], sign5[2000];
    size_t signature_len = 0, signature_len1 = 0, signature_len2 = 0, signature_len3 = 0, signature_len4 = 0, signature_len5 = 0;

    FILE* fptr;
    FILE* fptr1;
    FILE* ptr1;
    FILE* ptr2;
    FILE* ptr3;
    FILE* ptr4;
    FILE* ptr5;
    FILE* ptr6;
    FILE* ptr7;
    FILE* ptr8;
    FILE* ptr9;
    FILE* ptr10;
    FILE* ptr11;

    // Open each file to perform operations

    fptr = fopen("bcombine.bin", "rb"); // Open the combined file in binary read mode
    ptr1 = fopen("bfile1.bin", "wb"); // Open file1 in binary write mode
    ptr2 = fopen("bfile2.bin", "wb"); // Open file2 in binary write mode
    ptr3 = fopen("bfile3.bin", "wb"); // Open file3 in binary write mode
    ptr4 = fopen("bfile4.bin", "wb"); // Open file4 in binary write mode
    ptr5 = fopen("bfile5.bin", "wb"); // Open file5 in binary write mode
    ptr11 = fopen("public.pem", "rb"); // Open the public key file in binary read mode

    fseek(ptr1, 0, SEEK_END); // Move the file pointer to the end of file1
    f1size = ftell(ptr1); // Get the current position of the file pointer (size of file1)
    fseek(ptr2, 0, SEEK_END); // Move the file pointer to the end of file2
    f2size = ftell(ptr2); // Get the current position of the file pointer (size of file2)
    fseek(ptr3, 0, SEEK_END); // Move the file pointer to the end of file3
    f3size = ftell(ptr3); // Get the current position of the file pointer (size of file3)
    fseek(ptr4, 0, SEEK_END); // Move the file pointer to the end of file4
    f4size = ftell(ptr4); // Get the current position of the file pointer (size of file4)
    fseek(ptr5, 0, SEEK_END); // Move the file pointer to the end of file5
    f5size = ftell(ptr5); // Get the current position of the file pointer (size of file5)

    // Handle the case if the combined file is not accessible
    if (fptr == NULL) {
        printf("Could not open the merged file.\n");
        return 1; // Return 1 to indicate failure
    }

    // Extract metadata from the combined file and write to separate files
    fseek(fptr, f1size, SEEK_SET); // Move the file pointer to the start of the first metadata block
    fread(&data, sizeof(metadata), 1, fptr); // Read the metadata from the combined file into 'data'
    fwrite(&data, sizeof(metadata), 1, ptr1); // Write the metadata to file1

    fclose(ptr1); // Close file1

    fseek(fptr, f2size, SEEK_CUR); // Move the file pointer to the start of the second metadata block
    fread(&data, sizeof(metadata), 1, fptr); // Read the metadata from the combined file into 'data'
    fwrite(&data, sizeof(metadata), 1, ptr2); // Write the metadata to file2

    fclose(ptr2); // Close file2

    fseek(fptr, f3size, SEEK_CUR); // Move the file pointer to the start of the third metadata block
    fread(&data, sizeof(metadata), 1, fptr); // Read the metadata from the combined file into 'data'
    fwrite(&data, sizeof(metadata), 1, ptr3); // Write the metadata to file3

    fclose(ptr3); // Close file3

    fseek(fptr, f4size, SEEK_CUR); // Move the file pointer to the start of the fourth metadata block
    fread(&data, sizeof(metadata), 1, fptr); // Read the metadata from the combined file into 'data'
    fwrite(&data, sizeof(metadata), 1, ptr4); // Write the metadata to file4

    fclose(ptr4); // Close file4

    fseek(fptr, f5size, SEEK_CUR); // Move the file pointer to the start of the fifth metadata block
    fread(&data, sizeof(metadata), 1, fptr); // Read the metadata from the combined file into 'data'
    fwrite(&data, sizeof(metadata), 1, ptr5); // Write the metadata to file5

    fclose(ptr5); // Close file5
    fclose(fptr); // Close the combined file
    printf("Merged file has been split into five separate files.\n");

    // Verify the signatures for each of the five files and the combined file.

    // For file1
    ptr6 = fopen("bfile1_bin.sign", "rb"); // Open the signature file for file1 in binary read mode
    if (ptr6 == NULL) {
        printf("Failed to open the signature file for file1.\n");
        return 1; // Return 1 to indicate failure
    }

    // Extract signature and its length from the signature file
    signature_len1 = fread(sign1, 1, sizeof(sign1), ptr6);
    fclose(ptr6); // Close the signature file for file1

    // Read the public key from the public key file
    EVP_PKEY* pubkey = PEM_read_PUBKEY(ptr11, NULL, NULL, NULL);
    if (pubkey == NULL) {
        printf("Failed to read the public key from the file.\n");
        return 1; // Return 1 to indicate failure
    }

    // Verify the signature for file1 using the public key
    int result1 = verify_signature("bfile1.bin", pubkey, sign1, signature_len1);
    EVP_PKEY_free(pubkey); // Free the public key object

    if (result1 == 0) {
        printf("Signature verification failed for file1.\n");
        return 1; // Return 1 to indicate failure
    } else {
        printf("Signature verification successful for file1.\n");
    }

    // For file2 (similar to file1, repeat the process)
    ptr7 = fopen("bfile2_bin.sign", "rb");
    if (ptr7 == NULL) {
        printf("Failed to open the signature file for file2.\n");
        return 1;
    }

    signature_len2 = fread(sign2, 1, sizeof(sign2), ptr7);
    fclose(ptr7);

    pubkey = PEM_read_PUBKEY(ptr11, NULL, NULL, NULL);
    if (pubkey == NULL) {
        printf("Failed to read the public key from the file.\n");
        return 1;
    }

    int result2 = verify_signature("bfile2.bin", pubkey, sign2, signature_len2);
    EVP_PKEY_free(pubkey);

    if (result2 == 0) {
        printf("Signature verification failed for file2.\n");
        return 1;
    } else {
        printf("Signature verification successful for file2.\n");
    }

    // For file3 (similar to file1, repeat the process)
    ptr8 = fopen("bfile3_bin.sign", "rb");
    if (ptr8 == NULL) {
        printf("Failed to open the signature file for file3.\n");
        return 1;
    }

    signature_len3 = fread(sign3, 1, sizeof(sign3), ptr8);
    fclose(ptr8);

    pubkey = PEM_read_PUBKEY(ptr11, NULL, NULL, NULL);
    if (pubkey == NULL) {
        printf("Failed to read the public key from the file.\n");
        return 1;
    }

    int result3 = verify_signature("bfile3.bin", pubkey, sign3, signature_len3);
    EVP_PKEY_free(pubkey);

    if (result3 == 0) {
        printf("Signature verification failed for file3.\n");
        return 1;
    } else {
        printf("Signature verification successful for file3.\n");
    }

    // For file4 (similar to file1, repeat the process)
    ptr9 = fopen("bfile4_bin.sign", "rb");
    if (ptr9 == NULL) {
        printf("Failed to open the signature file for file4.\n");
        return 1;
    }

    signature_len4 = fread(sign4, 1, sizeof(sign4), ptr9);
    fclose(ptr9);

    pubkey = PEM_read_PUBKEY(ptr11, NULL, NULL, NULL);
    if (pubkey == NULL) {
        printf("Failed to read the public key from the file.\n");
        return 1;
    }

    int result4 = verify_signature("bfile4.bin", pubkey, sign4, signature_len4);
    EVP_PKEY_free(pubkey);

    if (result4 == 0) {
        printf("Signature verification failed for file4.\n");
        return 1;
    } else {
        printf("Signature verification successful for file4.\n");
    }

    // For file5 (similar to file1, repeat the process)
    ptr10 = fopen("bfile5_bin.sign", "rb");
    if (ptr10 == NULL) {
        printf("Failed to open the signature file for file5.\n");
        return 1;
    }

    signature_len5 = fread(sign5, 1, sizeof(sign5), ptr10);
    fclose(ptr10);

    pubkey = PEM_read_PUBKEY(ptr11, NULL, NULL, NULL);
    if (pubkey == NULL) {
        printf("Failed to read the public key from the file.\n");
        return 1;
    }

    int result5 = verify_signature("bfile5.bin", pubkey, sign5, signature_len5);
    EVP_PKEY_free(pubkey);

    if (result5 == 0) {
        printf("Signature verification failed for file5.\n");
        return 1;
    } else {
        printf("Signature verification successful for file5.\n");
    }

    // For the combined file
    ptr6 = fopen("bcombine_bin.sign", "rb");
    if (ptr6 == NULL) {
        printf("Failed to open the signature file for the combined file.\n");
        return 1;
    }

    // Extract signature and its length from the signature file
    signature_len = fread(sign, 1, sizeof(sign), ptr6);
    fclose(ptr6);

    pubkey = PEM_read_PUBKEY(ptr11, NULL, NULL, NULL);
    if (pubkey == NULL) {
        printf("Failed to read the public key from the file.\n");
        return 1;
    }

    // Verify the signature for the combined file using the public key
    int result = verify_signature("bcombine.bin", pubkey, sign, signature_len);
    EVP_PKEY_free(pubkey);

    if (result == 0) {
        printf("Signature verification failed for the combined file.\n");
        return 1;
    } else {
        printf("Signature verification successful for the combined file.\n");
    }

    // Free allocated memory and close files

    return 0; // Return 0 to indicate successful execution
}
