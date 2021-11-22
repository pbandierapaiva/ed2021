/*****************************************************************************
strings1.c - Exercício 1 
*/


#include <stdio.h>
#include <string.h>

#define LIM 200

int main(){
	char str[LIM];
	int i;

	printf("Entre com cadeia de caracteres: ");

	fgets( str, LIM-1, stdin);
	
	while( str[i]!='\0' ) { //enquanto str[i] não for final da str
		if(str[i]==' ') {
			printf("\n");
			while(str[i]==' ') // enquanto for espaço, incrementa i
				i++;	
			}
		else {
			printf("%c", str[i]);
			i++;
			}	
		}
	return 0;
}
