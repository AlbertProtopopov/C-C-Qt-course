#include <stdio.h>
#include <locale.h>

int recursion(int x);

int main(){

    setlocale(LC_ALL, "Russian");
    printf("Введите день своего рождения\n");

    int  x;
    scanf("%d", &x);
        
    if (x < 32 && x > 0) {
        int y = recursion(x);
        printf("Сумма дней рождения равна = %d \n", y);
    }
    else 
    	printf("День рождения указан некорректно\n");

	return 0;
}

int recursion(int x){
	while (x > 0)
		return x + recursion(x - 1);
}