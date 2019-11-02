#include <stdio.h>
#include <stdlib.h>

int main (){

    char * str1 = ", ";
    int x;

    srand(time(0));

    FILE * fp;
    
	fp = fopen("1.txt", "w");
        if (fp){

            for (int i = 0; i < 1000; i++){
                x = rand()%1000;
                fprintf(fp, "%d", x);
                if (i != 999)
                    fputs(str1, fp);
            }	    
        }
    
        fclose(fp);

    return 0;
}
