#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxDig 1000


	


struct factorial {
	
	char num[5];
	char mid[5];
	}	;
	

void fact(void);


int main(){
	
	
	
	fact();
	
	
	return 0;
}

void fact(void ) {
	struct factorial array[MaxDig];
	
	
	
	FILE *file;
	file = fopen ("fact.txt","r");
	
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

	fclose(file);

	
	for(xi = sum;xi >=1;xi--){
		
		printf("\n #%d = %s",xi,array[xi].num);
			
	}


}
