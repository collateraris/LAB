#include <stdio.h>
#include <stdlib.h>

int fact (int numfact){
	
	if ((numfact==0)||(numfact==1)) {
		
	  			return printf ("%d! = 1",numfact);
	  		}
	  		
		else {
		
	
	
	int xi, xk, num, num2;
	int Pow;
	const Max = 1000;
	 int *arrayA;
	arrayA = ( int*) malloc (sizeof(int));
	long long int *arrayB;
	arrayB = (long long int*) malloc (sizeof(long long int)*Max);
	long long int *arrayC;
	arrayC = (long long int*) malloc (sizeof(long long int)*Max);	
	
	for(xk=1,num = 2;num<=numfact,xk<=numfact;xk++,num++){
		
//Заполнение массива А значением факториала
	
	num2 = num;
	
	int size_A=0;

	for(;;){
		if(num2/10 >=1) {
		size_A++;
		printf("\n Op %d \t %d",num2/10,size_A);
	}
		 else break;
		 num2 = num2/10;
	}
	num2=num;	
		for (xi=size_A+1;xi>=1;xi--){
			
			Pow = pow(10,xi-1);
			arrayA[xi] = num2/Pow;
			num2 = num2 % Pow;
			printf("\narrayA[%d] = %d \t %d \t %d",xi,arrayA[xi],Pow,size_A );
			
		}
//Конец заполнения		
		
	
	
		}	
	
}
}

int main(){
	
	
	int numfact;
	
	printf ("This program perfomed n!\n\n");
	
	for(;;){
		printf("\nPlease, enter number\t");
		scanf("%d",&numfact);
		if (numfact >= 0) break;
		printf("\nIncorrectly dates\n");
	}
	
	fact(numfact);
	
	return 0;
}
