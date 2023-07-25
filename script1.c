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
    char keyvalue[836];
    int size3;
    
}metadata;



int main()
{

  metadata data;
  
  int  signed_status,signed_status1,signed_status2,signed_status3,signed_status4,signed_status5;
  int f1size,f2size,f3size,f4size,f5size;
  

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
  FILE* ptr12;
  

  fptr = fopen("bcombine.bin","wb");
  fptr1 = fopen("bcombine_bin.sign","rb");
  ptr1 = fopen("bfile1.bin","ab");
  ptr2 = fopen("bfile2.bin","ab");
  ptr3 = fopen("bfile3.bin","ab");
  ptr4 = fopen("bfile4.bin","ab");
  ptr5 = fopen("bfile5.bin","ab");
  ptr6 = fopen("script1_c.sign","rb");
  ptr7 = fopen("bfile1_bin.sign","rb");
  ptr8 = fopen("bfile2_bin.sign","rb");
  ptr9 = fopen("bfile3_bin.sign","rb");
  ptr10 = fopen("bfile4_bin.sign","rb");
  ptr11 = fopen("bfile5_bin.sign","rb");
  ptr12 = fopen("public.pem","rb");

  
  fseek(ptr12, 0, SEEK_END);
  data.size3 = ftell(ptr12);
  rewind(ptr12);
  fread(data.keyvalue, data.size3, 1, ptr12);

  fwrite(data.keyvalue, data.size3, 1, ptr1);
  fwrite(data.keyvalue, data.size3, 1, ptr2);
  fwrite(data.keyvalue, data.size3, 1, ptr3);  // Append the content to ptr1,ptr2,ptr3,ptr4,ptr5
  fwrite(data.keyvalue, data.size3, 1, ptr4);
  fwrite(data.keyvalue, data.size3, 1, ptr5);

 
  data.filesize = data.size1 + data.size2 + data.size3;


  fseek(ptr1,0L,SEEK_END);
  f1size = ftell(ptr1);
  fseek(ptr2,0L,SEEK_END);
  f2size = ftell(ptr2);
  fseek(ptr3,0L,SEEK_END);
  f3size = ftell(ptr3);
  fseek(ptr4,0L,SEEK_END);
  f4size = ftell(ptr4);
  fseek(ptr5,0L,SEEK_END);
  f5size = ftell(ptr5);


  if(fptr1 == NULL){
     signed_status = 0;
  }
  else
  {
   signed_status = 1;
  }

  
  if(ptr7 == NULL){
     signed_status1 = 0;
  }
  else
  {
   signed_status1 = 1;
  }


  if(ptr8 == NULL){
    signed_status2 = 0;
  }
  else
  {
    signed_status2 = 1;
  }


  if(ptr9 == NULL){
    signed_status3 = 0;
  }
  else
  {
    signed_status3 = 1;
  }

  if(ptr10 == NULL){
    signed_status4 = 0;
  }
  else
  {
    signed_status4 = 1;
  }

  if(ptr11 == NULL){
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


  printf("Value in keyvalue1 in file1: %s\n",data.keyvalue);
  fclose(fptr);
  fclose(ptr1);
  fclose(ptr2);
  fclose(ptr3);
  fclose(ptr4);
  fclose(ptr5);
 

  //merging these files

  fptr = fopen("bcombine.bin","ab");
  ptr1 = fopen("bfile1.bin","rb");
  ptr2 = fopen("bfile2.bin","rb");
  ptr3 = fopen("bfile3.bin","rb");
  ptr4 = fopen("bfile4.bin","rb");
  ptr5 = fopen("bfile5.bin","rb");

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
    fclose(ptr6);
    fclose(ptr7);

    return 0;


  
}
