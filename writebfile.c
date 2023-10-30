#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct{
    char filename[10];
    char string[500];
}filemetadata;

int main(int argc, char *argv[])
{
    filemetadata metadata;

    if (argc < 1) {
        printf("Usage: %s merged_file [ls/append/cat] inputfiles...\n", argv[0]);
        return 1;
    }

    for (int i=1;i < argc;i++)
    {
        char *inputfile = argv[i];

        FILE *input = fopen(inputfile,"wb");
        if(input == NULL){
            perror("Error opening files.......");
        }
    
        
       // printf("the name of the file:%s\n",inputfile);
        //strcpy(metadata.filename,inputfile);
        printf("the string to be written in file %s: ",argv[i]);
        fgets(metadata.string,500,stdin);
        int fsize = strlen(metadata.string);
        //printf("The size of the string: %d\n",metadata.size);
        //metadata.offset = offsetof(filemetadata, offset);
        //printf("the offset of file %s is %d\n", argv[i], metadata.offset);
        fwrite(&metadata.string, fsize, 1, input);
        
        fclose(input);
    }
    
   return 0;
}











