#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxDig 1000

struct factorial {
	
	char num[5];
	int count;
	char mid[5];
	}		;	

int main(){
	
	struct factorial array [MaxDig];
	
	FILE *file;
	file = fopen ("fact.txt","r");
	
	char ch;
	char ch2[1];
	char ch3[1];
	int n = 1;
	
	int xi;
	char str[4];
	char str4[4];
	
	ch = getc(file);
	
	array[0].count = 1;

	
	while(ch != EOF) {
		
		ch2[0] = ch;
		  
		for (xi = 1 ; xi <= array[0].count; xi ++){

			if(strlen(array[xi].num) < 4) {
				

				strcat(array[xi].num,ch2);
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
		
				str4[xj]=array[xi].num[xj+1];
					}
				strcpy(array[xi].num,str4);
				strcat(array[xi].num,ch2);
				if(strlen(array[xi+1].num) > 0) strcpy(ch2,array[0].mid);
		
			}
		}
		
		int i = array[0].count;
		
		if(strlen(array[i+1].num) >= 1){
			
			array[0].count++;
	
		}

			ch = getc(file);
	
	}

	fclose(file);
	
	for(xi = array[0].count;xi >= 1;xi--){
		
		printf("\n #%d = %s",xi,array[xi].num);
	}
	
	return 0;
}






