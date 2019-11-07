// Версия с форматированием данных
#include <stdio.h>
#include <ctype.h>
#define MAX 100000
     
int main (){
    FILE * pfile;
    int counter = 0;
    int size_counter = 0;
    int int_counter = 0;
    int float_counter = 0;
    int integers[100] = {0};
    
    pfile = fopen("file.txt", "r");

    if (!pfile)
        perror("Unable to open file");
    else{
        printf("The file is opened successfully\n");

        char fchar;
        while ((fchar = fgetc(pfile) != EOF) && (counter < MAX)){                
            counter++;
        }
        while ((fchar = fgetc(pfile) != EOF) && (counter < MAX)){                
            if (!isdigit(fchar))
            size_counter += sizeof(fchar);
        }
        int i = 0;
        while (fscanf(pfile, "%d", &(integers[i])) != EOF){
            printf("integers %d\n", integers[i]);
            i++;
        }
    }
        fclose(pfile);
        printf("Number of characters: %d\n", counter);
        printf("Number of integers:%d\n", int_counter);
        printf("The file is closed\n");
    
    return 0;
}
