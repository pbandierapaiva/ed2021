/*****************************************************************************
strings1.c - Exercício 2 
*/


#include <stdio.h>
#include <string.h>

#define LIM 200

int main(){
	char str[LIM];
	char palavra[LIM];
	
	int i, j, contador=0;
	

	printf("Entre com cadeia de caracteres: ");

	fgets( str, LIM-1, stdin);
	
	printf("%s\n", str);
	i=0;

	
	
	while( 1 ) {
		while( str[i]==' ')
			i++;
		if( str[i]=='\0' )
			break;
		
		j=0;
		while( str[i]!=' ' && str[i]!='\0' ) {
			palavra[j] = str[i];
			i++;
			j++;
			}
		palavra[j] = '\0';
		
		// if( palavra[0]=='e' && palavra[1]=='n' && palavra[2]=='d' && palavra[3]=='\0' )
		if( ! strcmp(palavra,"end")   )  {  // em Python:   if   palavra == "end":
			contador++;
			printf("%d palavras\n", contador);
			break;
			}
		else {
			contador++;
			}
		}

	return 0;
}
