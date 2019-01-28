#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


int main (int args, char *argv[]) {

	FILE *file;
	file = fopen("fact.txt","r");
	
	int ch;
	
	char *array;
	const MaxDeg = 1000;
	array = (char*)malloc(sizeof(char)*MaxDeg);
	
	
	array[1]= '0000';
	array[2] = '0';
	
	printf("%s",array[1]);
	
	int ar_null = 1;
	int xi;
	int ar_time;
	
	ch = getc( file );
	
/*	while ( ch != EOF) {
		
		
		for ( xi = 1; xi <= ar_null; xi++){
			
			ar_time = strlen(array[xi]);
			
			if (ar_time == 0 ) {
				
				array[xi] = ch;
				printf("\nFirst if  array[%d] = %s",xi,array[xi]);
			}
			
		}
		
	} */
	
	
	









	return 0;
}

