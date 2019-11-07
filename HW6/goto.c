#include <stdio.h>
#define MAX 100

int main(){

	char i = 1;
cycle:
	printf("%d\n", i);
	i++;

	if (i < MAX + 1)
		goto cycle;

    return 0;
}
