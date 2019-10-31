#include <stdio.h>

int main(){
	
	int x = 0;
	int doCount = 0;
	int whileCount = 0;
	int forCount = 0;	

	do{
		printf("do-while: %d \n", x);
		x++;
		doCount++;
		int y = 0;
		while(y < 10){
			printf("while: %d \n", y);
			y++;
			whileCount++;
			for (int z = 0; z < 10; z++){
				printf("for: %d \n", z);
				forCount++;		
			}
				
		}			
	}
	while(x < 10);
	
	printf("\ndo-while: %d \n", doCount);
	printf("while: %d \n", whileCount);
	printf("for: %d \n", forCount);

return 0;
}
