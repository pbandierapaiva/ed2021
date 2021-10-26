/*****************************************************************************
strings1.c - Manipula strings
*/


#include <stdio.h>
#include <string.h>

#define LIM 100

int main(){
	char nome[] = "Paulo Bandiera-Paiva";
	char outro[LIM];
	int i;

	printf("Minha string: %s \n", nome);
	printf("Tamanho: %d \n", strlen(nome) );
	
	// equivalente ao strlen()
	i=0;
	while( nome[i]!='\0' )
		i++;		
	printf("Tamanho calculado: %d\n",i);

	return 0;
}
