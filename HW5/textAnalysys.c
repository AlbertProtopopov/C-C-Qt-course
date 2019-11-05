#include <stdio.h>
#define CHAR_MIN 32
#define CHAR_MAX 126
     
int main (){
    FILE * pfile;
    
    pfile = fopen("Gatsby.txt", "r");

    if (!pfile)
        perror("Unable to open file");
    else{
        printf("The file is opened successfully\n");
        printf("Frequency of character usage\n");
        
        for (char i = CHAR_MIN; i < (CHAR_MAX + 1); i++){
	    long counter = 0;                               // тип long int от -2 147 483 647 до 2 147 483 647 
            char fchar = 0;

            while ((fchar = fgetc(pfile)) != EOF){
                if (i == fchar)
                    counter++;            
            }
            printf("%c = %ld \n", i, counter);
            fseek (pfile, 0, SEEK_SET);                   // переход в начало файла
        }
        fclose(pfile);
        printf("The file is closed\n");
    } 
    return 0;
}
