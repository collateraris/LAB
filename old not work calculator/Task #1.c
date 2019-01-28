#include <stdio.h>
#include <stdlib.h>


int main (int args, char *argv[]) {
	
	
	int ch;
	int i;
	int over;
	int Mass2;
	FILE *file;
	file = fopen("fact.txt", "r");
	int osn = 1000;
	long long int *mass;
	mass = (long long int*)malloc(sizeof(long long int));
	mass[0] = 1;
	mass[1] = mass [2] = 0 ;
	
	ch = getc(file);
	while (ch!=EOF){
		
		
		
		for(i=1;i<=mass[0];i++){
			
			if( mass[i] == 0 ) { //if fisrt
			ch = (int)ch - 48;
			mass[i] = ch;
			printf("\nif first = %d ",mass[i]);
			
		
			} else 
				if ( mass [i] < 10 ) {
					if (i==1) ch = (int)ch - 48;
					mass[i] = mass[i]*10 + ch;
					printf("\nif #2 ¹%d %d ",i,mass[i]);
				//	putchar(mass[i]);
					} else      //if#2
					if(mass[i] < 100) {
					 if(i==1)	ch = (int)ch - 48;
						mass[i] = mass[i]*10 + ch; 
						printf("\nif #3 %d ",mass[i]);
						//putchar(mass[i]);
						}else     //if#3
						if (mass[i] < 1000) {
						if(i==1)	ch = (int)ch - 48;
							over= mass[i]*10 + ch;
							printf("\nif over #%d  = %d ",i, over);
							//putchar(mass[i]);
							
						/*	} else //if over
							
						 	if (over < 10000) {  */                          //if trasporate
						 		Mass2 = (over - over%osn)/1000;
						 		mass[i] = over%osn;
						 		printf("\nif transpotare mass[%d] = %d ",i,mass[i]);
						 		if (mass[i+1]==0){
								
						 		mass[i+1] = mass[i+1] + Mass2;
						 		printf("\nif transpotare mass[%d] = %d ",i+1,mass[i+1]);
						 	
						        } else ch = Mass2;
						 		
						 			 } 
			
		}
		
		
		i = mass[0];
		if (mass[i+1] > 0) {   //if increase
				mass[i+2] = 0;
				mass[0]++;
				printf("\nif increase mass[i+2] %d ",mass[i+2]);
				//putchar(mass[mass[0] + 2]);
				printf("\nif increase = % mass[0]%d ",mass[0]);
				//putchar(mass[0]);
			}
		
		
		
	//	putchar(ch);
	ch = getc(file);
		
	}
	
	
	printf("\n\nWell Done!\n\n");
	
	for (i=mass[0]; i>=0;i--){
		printf("\nmass[%d] == %d",i,mass[i]);
	}
	printf("\n\n");
	for (i=mass[0]; i>=1;i--){
		printf("%d",mass[i]);
	}
	
	fclose(file);
	
	return 0;
}
