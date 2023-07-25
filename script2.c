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

}metadata;

// for error handling
void print_openssl_error() {
    unsigned long err_code = ERR_get_error();
    char err_msg[256];
    memset(err_msg, 0, sizeof(err_msg)); 
    ERR_error_string_n(err_code, err_msg, sizeof(err_msg));//printing the error message in a readable format
    printf("OpenSSL Error: %s\n", err_msg);
}

// decoding the base64 encoded input
int base64_decode(const unsigned char* input, size_t input_len, unsigned char* output, size_t* output_len) {
    BIO *bio, *b64;
    int decodeLen = 0;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new_mem_buf(input, input_len);
    bio = BIO_push(b64, bio);

    *output_len = BIO_read(bio, output, input_len);

    BIO_free_all(bio);
    return 1; // Return 1 on success, 0 on failure
}

// to verify the given signature
int verify_signature(const char* filename, EVP_PKEY* pubkey, const unsigned char* signature, size_t signature_len) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open the file to verify.\n");
        return 0;
    }

    EVP_MD_CTX* md_ctx = EVP_MD_CTX_new(); // creating a message digest context
    if (md_ctx == NULL) {
        fclose(file);
        printf("Failed to create message digest context.\n");
        return 0;
    }

    EVP_MD_CTX_init(md_ctx);
    if (EVP_VerifyInit(md_ctx, EVP_sha256()) != 1) {
        EVP_MD_CTX_free(md_ctx);
        fclose(file);
        printf("Failed to initialize verification.\n");
        return 0;
    }

    unsigned char buffer[1024];
    size_t read_len;

    while ((read_len = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (EVP_DigestUpdate(md_ctx, buffer, read_len) != 1) {
            EVP_MD_CTX_free(md_ctx);
            fclose(file);
            printf("Failed to update verification.\n");
            return 0; // Signature verification failed.
        }
    }

    fclose(file);

    // Decoding the base64-encoded signature
    unsigned char decoded_signature[1024];
    size_t decoded_len = sizeof(decoded_signature);
    if (!base64_decode(signature, signature_len, decoded_signature, &decoded_len)) {
        printf("Failed to decode the base64-encoded signature.\n");
        return 0;
    }

    printf("Decoded Signature: ");
    for (int i = 0; i < decoded_len; i++) {
        printf("%02x", decoded_signature[i]);
    }
    printf("\n");

    int result = EVP_VerifyFinal(md_ctx, decoded_signature, decoded_len, pubkey);
    EVP_MD_CTX_free(md_ctx);

    if (result == 1) {
        printf("Signature verification successful.\n");
    } else {
        printf("Signature verification failed.\n");
        print_openssl_error();
    }

  return result == 1 ? 1 : 0;
}



int main()
{

  metadata data;  
  int f1size,f2size,f3size,f4size,f5size;
  char ch;
  unsigned char sign[2000], sign1[2000], sign2[2000], sign3[2000], sign4[2000], sign5[2000] ;
  size_t signature_len = 0 , signature_len1 = 0 ,signature_len2 = 0 , signature_len3 = 0 , signature_len4 = 0 , signature_len5 = 0;
   

   FILE* fptr;
   FILE* fptr1;
   FILE* ptr1;
   FILE* ptr2;
   FILE* ptr3;
   FILE* ptr4;
   FILE* ptr5;
   FILE* ptr7;
   FILE* ptr8;
   FILE* ptr9;
   FILE* ptr10;
   FILE* ptr11;
   FILE* ptr12;

   fptr = fopen("bcombine.bin","rb");
   ptr1 = fopen("bfile1.bin","wb");
   ptr2 = fopen("bfile2.bin","wb");
   ptr3 = fopen("bfile3.bin","wb");
   ptr4 = fopen("bfile4.bin","wb");
   ptr5 = fopen("bfile5.bin","wb");
   ptr12 = fopen("public.pem","rb");
  
   fseek(ptr1,0,SEEK_END);
   f1size = ftell(ptr1);
   fseek(ptr2,0,SEEK_END);
   f2size = ftell(ptr2);
   fseek(ptr3,0,SEEK_END);
   f3size = ftell(ptr3);
   fseek(ptr4,0,SEEK_END);
   f4size = ftell(ptr4);
   fseek(ptr5,0,SEEK_END);
   f5size = ftell(ptr5);
  



   if (fptr == NULL) 
    {
        printf("Could not open the merged file.\n");
    
    }
  
   fseek(fptr, f1size, SEEK_SET);
   fread(&data,sizeof(metadata),1,fptr);
   fwrite(&data,sizeof(metadata),1,ptr1);
  
   fclose(ptr1);

   fseek(fptr, f2size, SEEK_CUR);
   fread(&data,sizeof(metadata),1,fptr);
   fwrite(&data,sizeof(metadata),1,ptr2);
  
    
   fclose(ptr2);

   fseek(fptr, f3size, SEEK_CUR);
   fread(&data,sizeof(metadata),1,fptr);
   fwrite(&data,sizeof(metadata),1,ptr3);
  
    
   fclose(ptr3);

   fseek(fptr, f4size, SEEK_CUR);
   fread(&data,sizeof(metadata),1,fptr);
   fwrite(&data,sizeof(metadata),1,ptr4);
  
   fclose(ptr4);
    
   fseek(fptr, f5size, SEEK_CUR);
   fread(&data,sizeof(metadata),1,fptr);
   fwrite(&data,sizeof(metadata),1,ptr5);
 
    
   fclose(ptr5);
   fclose(fptr);
   printf("Merged file has been split into five separate files.\n");


  // verify the signatures 
    ptr7 = fopen("bfile1_bin.sign", "rb");
    if (ptr7 == NULL) {
        printf("Failed to open signature file\n");
        return 1;
    }

    while ((ch = fgetc(ptr7)) != EOF) {
        sign[signature_len++] = ch;
    }

    fclose(ptr7);

    const char* pubkey_path = "public.pem";
    const char* file_to_verify = "bfile1.bin";

    ptr12 = fopen(pubkey_path, "rb");
    if (ptr12 == NULL) {
        printf("Failed to open public key file\n");
        return 1;
    }

    EVP_PKEY* pubkey = PEM_read_PUBKEY(ptr12, NULL, NULL, NULL);
    

    if (pubkey == NULL) {
        printf("Failed to load public key.\n");
        return 1;
    }

    int verification_result = verify_signature(file_to_verify, pubkey, sign, signature_len);
    EVP_PKEY_free(pubkey);
    fclose(ptr12);

    if (verification_result == 1) {
        printf("Signature verification for file1 is successful.\n");
    } else {
        printf("Signature verification for file1 failed.\n");
        print_openssl_error();
        return 1;
    }


    //for file2


    ptr8 = fopen("bfile2_bin.sign", "rb");
    if (ptr8 == NULL) {
        printf("Failed to open signature file\n");
        return 1;
    }

    while ((ch = fgetc(ptr8)) != EOF) {
        sign1[signature_len1++] = ch;
    }

    fclose(ptr8);

    pubkey_path = "public.pem";
    file_to_verify = "bfile2.bin";
     
    ptr12 = fopen(pubkey_path, "rb");
    if (ptr12 == NULL) {
        printf("Failed to open public key file\n");
        return 1;
    }
    
    pubkey = PEM_read_PUBKEY(ptr12, NULL, NULL, NULL);
    fclose(ptr12);

    if (pubkey == NULL) {
        printf("Failed to load public key.\n");
        return 1;
    }

    verification_result = verify_signature(file_to_verify, pubkey, sign1, signature_len1);
    EVP_PKEY_free(pubkey);

    if (verification_result == 1) {
        printf("Signature verification for file2 is successful.\n");
    } else {
        printf("Signature verification for file2 failed.\n");
        print_openssl_error();
        return 1;
    }


    //for file3

    ptr9 = fopen("bfile3_bin.sign", "rb");
    if (ptr9 == NULL) {
        printf("Failed to open signature file\n");
        return 1;
    }

    while ((ch = fgetc(ptr9)) != EOF) {
        sign2[signature_len2++] = ch;
    }

    fclose(ptr9);
   
    pubkey_path = "public.pem";
    file_to_verify = "bfile3.bin";
    
    ptr12 = fopen(pubkey_path, "rb");
    if (ptr12 == NULL) {
        printf("Failed to open public key file\n");
        return 1;
    }
    
    pubkey = PEM_read_PUBKEY(ptr12, NULL, NULL, NULL);
    fclose(ptr12);

    if (pubkey == NULL) {
        printf("Failed to load public key.\n");
        return 1;
    }

    verification_result = verify_signature(file_to_verify, pubkey, sign2, signature_len2);
    EVP_PKEY_free(pubkey);

    if (verification_result == 1) {
        printf("Signature verification for file3 is successful.\n");
    } else {
        printf("Signature verification for file3 failed.\n");
        print_openssl_error();
        return 1;
    }


    //for file4


    ptr10 = fopen("bfile4_bin.sign", "rb");
    if (ptr10 == NULL) {
        printf("Failed to open signature file\n");
        return 1;
    }

    while ((ch = fgetc(ptr10)) != EOF) {
        sign3[signature_len3++] = ch;
    }

    fclose(ptr10);

    pubkey_path = "public.pem";
    file_to_verify = "bfile4.bin";
    
    ptr12 = fopen(pubkey_path, "rb");
    if (ptr12 == NULL) {
        printf("Failed to open public key file\n");
        return 1;
    }

    pubkey = PEM_read_PUBKEY(ptr12, NULL, NULL, NULL);
    fclose(ptr12);

    if (pubkey == NULL) {
        printf("Failed to load public key.\n");
        return 1;
    }

    verification_result = verify_signature(file_to_verify, pubkey, sign3, signature_len3);
    EVP_PKEY_free(pubkey);

    if (verification_result == 1) {
        printf("Signature verification for file4 is successful.\n");
    } else {
        printf("Signature verification for file4 failed.\n");
        print_openssl_error();
        return 1;
    }



   //for file5

    ptr11 = fopen("bfile5_bin.sign", "rb");
    if (ptr11 == NULL) {
        printf("Failed to open signature file\n");
        return 1;
    }

    while ((ch = fgetc(ptr11)) != EOF) {
        sign4[signature_len4++] = ch;
    }

    fclose(ptr11);

    pubkey_path = "public.pem";
    file_to_verify = "bfile5.bin";
    

    ptr12 = fopen(pubkey_path, "rb");
    if (ptr12 == NULL) {
        printf("Failed to open public key file\n");
        return 1;
    }
    pubkey = PEM_read_PUBKEY(ptr12, NULL, NULL, NULL);
    fclose(ptr12);

    if (pubkey == NULL) {
        printf("Failed to load public key.\n");
        return 1;
    }

    verification_result = verify_signature(file_to_verify, pubkey, sign4, signature_len4);
    EVP_PKEY_free(pubkey);

    if (verification_result == 1) {
        printf("Signature verification for file5 is successful.\n");
    } else {
        printf("Signature verification for file5 failed.\n");
        print_openssl_error();
        return 1;
    }


    // for combined file

    fptr = fopen("bcombine_bin.sign", "rb");
    if (fptr == NULL) {
        printf("Failed to open signature file\n");
        return 1;
    }

    while ((ch = fgetc(fptr)) != EOF) {
        sign5[signature_len5++] = ch;
    }

    fclose(fptr);

    pubkey_path = "public.pem";
    file_to_verify = "bcombine.bin";

    ptr12 = fopen(pubkey_path, "rb");
    if (ptr12 == NULL) {
        printf("Failed to open public key file\n");
        return 1;
    }

    pubkey = PEM_read_PUBKEY(ptr12, NULL, NULL, NULL);
    fclose(ptr12);

    if (pubkey == NULL) {
        printf("Failed to load public key.\n");
        return 1;
    }

    verification_result = verify_signature(file_to_verify, pubkey, sign5, signature_len5);
    EVP_PKEY_free(pubkey);

    if (verification_result == 1) {
        printf("Signature verification for  combined file is successful.\n");
    } else {
        printf("Signature verification for combined file is failed.\n");
        print_openssl_error();
        return 1;
    }


 
  return 0;
}
