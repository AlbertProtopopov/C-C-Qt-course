#include<stdio.h>
#include<float.h>

int main (){

    double x = DBL_MAX;
	printf("%g \n", x);

	x += x;
	printf("%g \n", x);
	
	return 0;
}
