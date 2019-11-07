// Версия посимвольного чтения
#include <stdio.h>
#define MAX 100000
     
int main (){
    FILE * pfile;
    int counter = 0;
    int size_counter = 0;
    
    pfile = fopen("file.txt", "r");

    if (!pfile)
        perror("Unable to open file");
    else{
        printf("The file is opened successfully\n");

        char fchar;
        while ((fchar = fgetc(pfile) != EOF) && (counter < MAX)){
                counter++;
                size_counter += sizeof(fchar);
        }
    }
        fclose(pfile);
        printf("Number of characters: %d\n", counter);
        printf("Number of bytes: %d\n", size_counter);
        printf("The file is closed\n");
    
    return 0;
}
