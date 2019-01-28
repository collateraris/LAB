#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int numfact;
	
	printf ("This program perfomed n!\n\n");
	
	for(;;){
		printf("\nPlease, enter number\t");
		scanf("%d",&numfact);
		if (numfact >= 0) break;
		printf("\nIncorrectly dates\n");
	}
	
	int size=0;
	

	
	for(;;){
		if(numfact/10 >=1) {
		size++;
		printf("\n Op %d \t %d",numfact/10,size);
	}
		 else break;
		 numfact = numfact/10;
	}
	
	printf("\n%d",size+1);
	
	
	return 0;
}
