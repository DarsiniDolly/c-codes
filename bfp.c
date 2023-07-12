// This program consist of code signing and merging the binary files


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>


typedef struct {
    int numImages;           // Number of images
    int sizeOfBFP;           // Size of the complete BFP
    int bfpSignedStatus;     // BFP signed status 
} BfpHeader;

typedef struct {
    char imageName[10];      // Image name
    int imageOffset;         // Image offset
    int certificateOffset;   // Certificate offset
    int flags;               // Flags 
    int imageSigned;         // Image signed status 
    int imageEncrypted;      // Image encrypted status 
} ImageHeader;

typedef struct {
    char filename[10];
    int filesize;
    char index1;
    char index2;
    char string1[50];
    char string2[50];
    int size1;
    int size2;
} metadata;


int main()
{
    BfpHeader bfp_h;
    ImageHeader img_h;
    metadata data;
   

    FILE * fptr;
    FILE * ptr;
    FILE * ptr1;
    FILE * ptr2;
    FILE * ptr3;
    FILE * ptr4;
    FILE * ptr5;

    fptr = fopen("bfp.bin","rb");
    ptr = fopen("public.pem","rb");
    ptr1 = fopen("header.bin","wb");
    ptr2 = fopen("image.bin","wb");
    ptr3 = fopen("bfile3.bin","wb");
    ptr4 = fopen("file4.bin","wb");
    ptr5 = fopen("file5.bin","wb");

    if(ptr== NULL)
    {
      bfp_h.bfpSignedStatus = 0;
      img_h.imageSigned = 0;
      img_h.imageEncrypted = 0;
    }
    else
    {
      bfp_h.bfpSignedStatus = 1;
      img_h.imageSigned = 1;
      img_h.imageEncrypted = 1;
    }

    if( ptr1==NULL || ptr2==NULL || ptr3==NULL || ptr4==NULL || ptr5==NULL)
    {
        printf("FILE NOT EXIST\n");
    }
    
    
    
    printf("the number of images:");
    scanf("%d",&bfp_h.numImages);
    bfp_h.sizeOfBFP = sizeof(bfp_h.numImages) + sizeof(bfp_h.bfpSignedStatus);
    printf("the size of bfp:%d\n",bfp_h.sizeOfBFP);
    printf("bfp signed status:%d\n",bfp_h.bfpSignedStatus);
    fwrite(&bfp_h, sizeof(BfpHeader), 1 , ptr1);
    fclose(ptr1);

    printf("the name of the image:");
    scanf("%s",img_h.imageName);
    img_h.imageOffset = offsetof(ImageHeader, imageOffset);
    printf("the image offset:%d\n",img_h.imageOffset);
    img_h.certificateOffset = offsetof(ImageHeader, certificateOffset);
    printf("the certificate offset:%d\n",img_h.certificateOffset);
    printf("the flags:");
    scanf("%d",&img_h.flags);
    printf("the image is signed or not:%d\n",img_h.imageSigned);
    printf("the image is encrypted or not:%d\n",img_h.imageEncrypted);
    fwrite(&img_h, sizeof( ImageHeader), 1, ptr2);
    fclose(ptr2);

    printf("the name of the file3:");
    scanf("%s", data.filename);
    printf("the string1 in file3:");
    scanf("%s",data.string1);
    data.size1= strlen(data.string1);
    printf("The size of the string1 in file3: %d\n",data.size1);
    printf("the string2 in file3:");
    scanf("%s",data.string2);
    data.size2= strlen(data.string2);
    printf("The size of the string2 in file3: %d\n",data.size2);
    data.filesize = data.size1 + data.size2;
    printf("the size of the file:%d\n",data.filesize);
    data.index1 =data.string1[0];
    data.index2 = data.string2[0];
    printf("The first character in the string1:%c\n",data.index1);
    printf("the first character in the string2:%c\n",data.index2);
    
    fwrite(&data, sizeof( metadata),1,ptr3);
    fclose(ptr3);

    printf("the name of the file4:");
    scanf("%s", data.filename);
    printf("the string1 in file4:");
    scanf("%s",data.string1);
    data.size1= strlen(data.string1);
    printf("The size of the string1 in file4: %d\n",data.size1);
    printf("the string2 in file4:");
    scanf("%s",data.string2);
    data.size2= strlen(data.string2);
    printf("The size of the string2 in file4: %d\n",data.size2);
    data.filesize = data.size1 + data.size2;
    printf("the size of the file:%d\n",data.filesize);
    data.index1 =data.string1[0];
    data.index2 = data.string2[0];
    printf("The first character in the string1:%c\n",data.index1);
    printf("the first character in the string2:%c\n",data.index2);
    
    fwrite(&data, sizeof( metadata),1,ptr4);
    fclose(ptr4);

    printf("the number of images:");
    scanf("%d",&bfp_h.numImages);
    printf("the name of the image:");
    scanf("%s",img_h.imageName);

    fwrite(&bfp_h, sizeof( BfpHeader),1,ptr5);
    fwrite(&img_h, sizeof( ImageHeader),1,ptr5);
    fclose(ptr5);

    

    // merging files

    fptr = fopen("bfp.bin","wb");
    ptr1 = fopen("header.bin","rb");
    ptr2 = fopen("image.bin","rb");
    ptr3 = fopen("bfile3.bin","rb");
    ptr4 = fopen("file4.bin","rb");
    ptr5 = fopen("file5.bin","rb");

    char m;

    if(ptr1==NULL || ptr2==NULL || ptr3==NULL || ptr4==NULL || ptr5==NULL || fptr==NULL)
    {
        printf("could not open files.");
    }

    while ((m = fgetc(ptr1)) != EOF)
    {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr2)) != EOF)
    {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr3)) != EOF)
    {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr4)) != EOF)
    {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr5)) != EOF)
    {
        fputc(m, fptr);
    }

    printf("All files have been merged.\n");
    fclose(fptr);
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
    fclose(ptr4);
    fclose(ptr5);

    return 0;


}









