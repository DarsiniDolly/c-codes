// this program split the merged files into seperate files from a code signed file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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
    FILE * ptr1;
    FILE * ptr2;
    FILE * ptr3;
    FILE * ptr4;
    FILE * ptr5;

    fptr = fopen("bfp.bin","rb");
    ptr1 = fopen("header.bin","wb");
    ptr2 = fopen("image.bin","wb");
    ptr3 = fopen("bfile3.bin","wb");
    ptr4 = fopen("file4.bin","wb");
    ptr5 = fopen("file5.bin","wb");

    if (fptr == NULL) 
    {
        printf("Could not open the merged file.\n");
    }
    
    fread(&bfp_h, sizeof(BfpHeader),1,fptr);
    printf("the number of images:%d\n",bfp_h.numImages);
    printf("the size of bfp:%d\n",bfp_h.sizeOfBFP);
    printf("bfp signed status:%d\n",bfp_h.bfpSignedStatus);
    fwrite(&bfp_h, sizeof(BfpHeader), 1 , ptr1);
    fclose(ptr1);

    fread(&img_h, sizeof(ImageHeader),1,fptr);
    printf("the name of the image:%s\n",img_h.imageName);
    printf("the image offset:%d\n",img_h.imageOffset);
    printf("the certificate offset:%d\n",img_h.certificateOffset);
    printf("the flags:%d\n",img_h.flags);
    printf("the image is signed or not:%d\n",img_h.imageSigned);
    printf("the image is encrypted or not:%d\n",img_h.imageEncrypted);
    fwrite(&img_h, sizeof( ImageHeader), 1, ptr2);
    fclose(ptr2);


    fread(&data, sizeof(metadata), 1, fptr);
    printf("filename of file3:%s\n",data.filename);
    printf("the size of the file:%d\n",data.filesize);
    printf("the value of string1 in file3:%s\n",data.string1);
    printf("the first character in string1:%c\n",data.index1);
    printf("the size of string1:%d\n",data.size1);
    printf("the value of string2 in file3:%s\n",data.string2);
    printf("the first character in string2:%c\n",data.index2);
    printf("the size of string2:%d\n",data.size2);
    fwrite(&data, sizeof(metadata), 1, ptr3);
    fclose(ptr3);

    
    fread(&data, sizeof(metadata), 1, fptr);
    printf("filename of file4:%s\n",data.filename);
    printf("the size of the file:%d\n",data.filesize);
    printf("the value of string1 in file4:%s\n",data.string1);
    printf("the first character in string1:%c\n",data.index1);
    printf("the size of string1:%d\n",data.size1);
    printf("the value of string2 in file4:%s\n",data.string2);
    printf("the first character in string2:%c\n",data.index2);
    printf("the size of string2:%d\n",data.size2);
    fwrite(&data, sizeof(metadata), 1, ptr4);
    fclose(ptr4);

    fread(&bfp_h, sizeof(BfpHeader), 1,fptr);
    fread(&img_h, sizeof(ImageHeader), 10,fptr);
    printf("the number of images:%d\n",bfp_h.numImages);
    printf("the name of the image:%s\n",img_h.imageName);
    fwrite(&bfp_h, sizeof(BfpHeader),1,ptr5);
    fwrite(&img_h, sizeof(ImageHeader),10,ptr5);
    fclose(ptr5);

    return 0;

}


