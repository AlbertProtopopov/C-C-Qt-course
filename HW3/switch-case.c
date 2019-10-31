#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){

    setlocale(LC_ALL, "Russian");

    srand(time(0));

    int x = rand()%10;

    switch(x){

    case 0: printf("ноль\n");
    break;

    case 1: printf("один\n");
    break;

    case 2: printf("два\n");
    break;

    case 3: printf("три\n");
    break;

    case 4: printf("четыре\n");
    break;

    case 5: printf("пять\n");
    break;

    case 6: printf("шесть\n");
    break;

    case 7: printf("семь\n");
    break;

    case 8: printf("восемь\n");
    break;

    case 9: printf("девять\n");
    break;

    } 

return 0;
}
