#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxDig 1000


	


struct factorial {
	
	char num[5];
	char mid[5];
	}	;
	

void fact(void);


int main(int argc, char *argv[]){
	
	
	
	fact();
	
	
	return 0;
}

void fact(void ) {
	
	struct factorial array[MaxDig];
	
	
	
	FILE *file;
	file = fopen ("numberone.txt","r");
	
	char ch;
	char chp[0];
	
	int n = 1;
	
	int xi;
	
	char strp[3];
	
	ch = getc(file);
	
	int sum = 1;

	
	while(ch != EOF) {
		
		chp[0] = ch;
		  
		for (xi = 1 ; xi <= sum; xi ++){

			if(strlen(array[xi].num) < 4) {
				

				strcat(array[xi].num,chp);
			}
			else 
			{
				if(strlen(array[xi+1].num) == 0){
				
				strncpy(array[xi+1].num,array[xi].num,n);
				}
				else
				{
				  strncpy(array[0].mid,array[xi].num,n);
				}
				
				int xj;
	
				for(xj=0;xj<4;xj++){
		
				strp[xj]=array[xi].num[xj+1];
					}
				strcpy(array[xi].num,strp);
				strcat(array[xi].num,chp);
				if(strlen(array[xi+1].num) > 0) strcpy(chp,array[0].mid);
		
			}
		}
		
		int i = sum;
		
		if(strlen(array[i+1].num) >= 1){
			
			sum++;
	
		}
			
			ch = getc(file);
	
	}

	for(;;){
		
		fclose(file);
		if(fclose(file) == 0 )break;
		printf("\n\tError");
	}
	
	if(fclose(file) != 0) {
		
		printf("Erors ");
	}

	
	for(xi = sum;xi >=1;xi--){
		
		printf("\n #%d = %s",xi,array[xi].num);
			
	}
	
	
	/////////////////////////
	struct factorial array2[MaxDig];
	
	FILE *fl;
	
	fl = fopen ("numbertwo.txt","r");
	
	char ch2;
	char chp2[0];
    
    
	
	char strp2[3];
	
	ch2 = getc(fl);
	
	int sum2 = 1;
	
	
	
	while(ch2 != EOF) {
		
		chp2[0] = ch2;
		printf("\nchp2 =");
		puts(chp2);
		  
		for (xi = 1 ; xi <= sum2; xi ++){
 			
			if(strlen(array2[xi].num) < 4) {
				printf("\nbefore cat array2 %d =",xi);
				puts(array2[xi].num);
				strcat(array2[xi].num,chp2);
				printf("\ncat array2 %d =",xi);
				puts(array2[xi].num);
			}
			else 
			{
				if(strlen(array2[xi+1].num) == 0){
				
				strncpy(array2[xi+1].num,array2[xi].num,n);
				printf("\nafter else array2 %d =",xi+1);
				puts(array2[xi+1].num);
				}
				else
				{
				  strncpy(array2[0].mid,array2[xi].num,n);
				  printf("\narray2 mid %d =",xi);
				  puts(array2[xi].num);
				}
				
				int xj;
	
				for(xj=0;xj<4;xj++){
		
				strp2[xj]=array2[xi].num[xj+1];
					}
				strcpy(array2[xi].num,strp2);
				strcat(array2[xi].num,chp2);
				printf("\n shift array2 %d =",xi);
				puts(array2[xi].num);
				if(strlen(array2[xi+1].num) > 0) strcpy(chp2,array2[0].mid);
				printf("\narray chp2 after mid   =");
				puts(chp2);
		
			}
		}
		
		int j = sum2;
		
		if(strlen(array2[j+1].num) >= 1){
			printf("\n PIZDA");
			sum2++;
	
		}
			
			ch2 = getc(fl);
	
	}

	fclose(fl);
	


	
	for(xi = sum2;xi >=1;xi--){
		
		printf("\n #%d = %s",xi,array2[xi].num);
			
	}	

	
}
