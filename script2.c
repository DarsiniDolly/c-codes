#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char filename[50];
    int filesize;
    char index1;
    char index2;
    char string1[50];
    char string2[50];
    int size1;
    int size2;
    char keyvalue1[1000];
    int signed_status1, signed_status2, signed_status3, signed_status4, signed_status5;
}metadata;

int main()
{

  metadata data;  
 

  FILE* fptr;
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
  FILE* ptr12;
  FILE* ptr13;
  

  fptr = fopen("bcombine.bin","rb");
  ptr1 = fopen("bfile1.bin","wb");
  ptr2 = fopen("bfile2.bin","wb");
  ptr3 = fopen("bfile3.bin","wb");
  ptr4 = fopen("bfile4.bin","wb");
  ptr5 = fopen("bfile5.bin","wb");
  ptr6 = fopen("script1_c.sign","rb");
  ptr7 = fopen("bfile1_bin.sign","rb");
  ptr8 = fopen("bfile2_bin.sign","rb");
  ptr9 = fopen("bfile3_bin.sign","rb");
  ptr10 = fopen("bfile4_bin.sign","rb");
  ptr11 = fopen("bfile5_bin.sign","rb");
  ptr12 = fopen("public.pem","rb");



  if (fptr == NULL) 
    {
        printf("Could not open the merged file.\n");
    
    }

    fread(&data, sizeof(metadata), 1, fptr);
    printf("filename of file1:%s\n",data.filename);
    printf("the size of the file:%d\n",data.filesize);
    printf("the value of string1 in file1:%s\n",data.string1);
    printf("the first character in string1:%c\n",data.index1);
    printf("the size of string1:%d\n",data.size1);
    printf("the value of string2 in file1:%s\n",data.string2);
    printf("the first character in string2:%c\n",data.index2);
    printf("the size of string2:%d\n",data.size2);
    printf("the public key value is:%s\n",data.keyvalue1);
    fwrite(&data, sizeof(metadata), 1, ptr1);
    fclose(ptr1);


    fread(&data, sizeof(metadata), 1, fptr);
    printf("filename of file2:%s\n",data.filename);
    printf("the size of the file:%d\n",data.filesize);
    printf("the value of string1 in file2:%s\n",data.string1);
    printf("the first character in string1:%c\n",data.index1);
    printf("the size of string1:%d\n",data.size1);
    printf("the value of string2 in file2:%s\n",data.string2);
    printf("the first character in string2:%c\n",data.index2);
    printf("the size of string2:%d\n",data.size2);
    printf("the public key value is:%s\n",data.keyvalue1);
    fwrite(&data, sizeof(metadata), 1, ptr2);
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
    printf("the public key value is:%s\n",data.keyvalue1);
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
    printf("the public key value is:%s\n",data.keyvalue1);
    fwrite(&data, sizeof(metadata), 1, ptr4);
    fclose(ptr4);

    
    fread(&data, sizeof(metadata), 1, fptr);
    printf("filename of file5:%s\n",data.filename);
    printf("the size of the file:%d\n",data.filesize);
    printf("the value of string1 in file5:%s\n",data.string1);
    printf("the first character in string1:%c\n",data.index1);
    printf("the size of string1:%d\n",data.size1);
    printf("the value of string2 in file5:%s\n",data.string2);
    printf("the first character in string2:%c\n",data.index2);
    printf("the size of string2:%d\n",data.size2);
    printf("the public key value is:%s\n",data.keyvalue1);
    fwrite(&data, sizeof(metadata), 1, ptr5);
    fclose(ptr5);

    printf("Merged file has been split into five separate files.\n");
    fclose(fptr);

    return 0;
}



