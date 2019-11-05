//создание символьного массива и заполнение случайными знаками и символами латинского алфавита
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 1000
#define CHAR_MIN 32
#define CHAR_MAX 94

int main(){
     
    srand(time(0));

    char array[ARRAY_MAX];
    
    for (int i = 0; i < ARRAY_MAX; i++){
    
        array[i] = CHAR_MIN + rand()%CHAR_MAX;    //заполнение массива случайными символами

        printf("array[%d] = %c \n", i, array[i]); //вывод на консоль
    }

    return 0;
}
