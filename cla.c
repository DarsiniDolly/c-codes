#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char filename[10];
    int filesize;
    char index1;
    char index2;
    char string1[50];
    char string2[50];
    int size1;
    int size2;
    char keyvalue[1000];
    int size3;
    
} metadata;

int main(int argc, char *argv[])
{
    if (argc < 1) {
        printf("file does not exist");
        return 1;
    }
    
    int  signed_status,signed_status1,signed_status2,signed_status3,signed_status4,signed_status5;
    int f1size,f2size,f3size,f4size,f5size;
    metadata data;

    // Open the input files
    FILE* ptr1 = fopen(argv[1], "ab");
    FILE* ptr2 = fopen(argv[2], "ab");
    FILE* ptr3 = fopen(argv[3], "ab");
    FILE* ptr4 = fopen(argv[4], "ab");
    FILE* ptr5 = fopen(argv[5], "ab");
    FILE* ptr6 = fopen(argv[6], "rb");// bfile_bin.sign 6-10
    FILE* ptr7 = fopen(argv[7], "rb");
    FILE* ptr8 = fopen(argv[8], "rb");
    FILE* ptr9 = fopen(argv[9], "rb");
    FILE* ptr10 = fopen(argv[10],"rb");
    FILE* ptr11 = fopen(argv[11],"rb");// public key
    FILE* fptr = fopen(argv[12],"wb");// combined file
    FILE* fptr1 = fopen(argv[13],"rb");
    

    if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL || ptr4 == NULL || ptr5 == NULL || ptr11 == NULL) {
        printf("Error opening input files.\n");
        return 1;
    }

    
    fseek(ptr11, 0, SEEK_END);
    data.size3 = ftell(ptr11);
    rewind(ptr11);


    fread(data.keyvalue, data.size3, 1, ptr11);

    fseek(ptr1, 0, SEEK_END);
    fwrite(data.keyvalue, data.size3, 1, ptr1);

    fseek(ptr2, 0, SEEK_END);
    fwrite(data.keyvalue, data.size3, 1, ptr2);

    fseek(ptr3, 0, SEEK_END);
    fwrite(data.keyvalue, data.size3, 1, ptr3);

    fseek(ptr4, 0, SEEK_END);
    fwrite(data.keyvalue, data.size3, 1, ptr4);

    fseek(ptr5, 0, SEEK_END);
    fwrite(data.keyvalue, data.size3, 1, ptr5);

    if(fptr1 == NULL){
     signed_status = 0;
    }
    else
    {
     signed_status = 1;
    }

  
    if(ptr6 == NULL){
     signed_status1 = 0;
    }
    else
    {
     signed_status1 = 1;
    }


    if(ptr7 == NULL){
     signed_status2 = 0;
    }
    else
    {
      signed_status2 = 1;
    }


    if(ptr8 == NULL){
      signed_status3 = 0;
    }
    else
    {
      signed_status3 = 1;
    }

   if(ptr9 == NULL){
     signed_status4 = 0;
   }
   else
   {
     signed_status4 = 1;
    }

   if(ptr10 == NULL){
     signed_status5 = 0;
    }
   else
   {
     signed_status5 = 1;
    }
  
  

  
  printf("signed status of the bcombine file is: %d\n",signed_status);
  printf("signed status of the file1 is: %d\n",signed_status1);
  printf("signed status of the file2 is: %d\n",signed_status2);
  printf("signed status of the file3 is: %d\n",signed_status3);
  printf("signed status of the file4 is: %d\n",signed_status4);
  printf("signed status of the file5 is: %d\n",signed_status5);


  fclose(fptr);
  fclose(ptr1);
  fclose(ptr2);
  fclose(ptr3);
  fclose(ptr4);
  fclose(ptr5);
  fclose(fptr1);
  fclose(ptr6);
  fclose(ptr7);
  fclose(ptr8);
  fclose(ptr9);
  fclose(ptr10);
  fclose(ptr11);
 

  //merging these files
   fptr = fopen("bcombine.bin","ab");
   ptr1 = fopen("bfile1.bin", "rb");// bfile 1 -5
   ptr2 = fopen("bfile2.bin", "rb");
   ptr3 = fopen("bfile3.bin", "rb");
   ptr4 = fopen("bfile4.bin", "rb");
   ptr5 = fopen("bfile5.bin", "rb");
  

  if(ptr1 == NULL || ptr2 == NULL || ptr3 == NULL || ptr4 == NULL || ptr5 == NULL || fptr == NULL)
  {
    printf("files does not exists......");
  }
  
  char m;

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
