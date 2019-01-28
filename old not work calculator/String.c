#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char strleft(char *str, char *str4){
	
	int xi;
	
	for(xi=0;xi<4;xi++){
		
	str4[xi]=str[xi+1];
	}
	
	return str4;
}

int main () {
	
	char str[4];
	char str2[4];
	char str3[4];
	char str4[4];
	
	gets(str);
	gets(str2);
	
	int n = 1;
	
	strncpy(str3,str, n);
	strcat(str,str2);
	strleft(str,str4);


	
	
	
	puts(str4);
	puts(str);
	puts(str3);
	
	
	
	
	return 0;
}
