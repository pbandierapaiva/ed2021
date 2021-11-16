/*
	Exemplo de uso de struct e union
*/

#include <stdio.h>
#include <string.h>


struct cara {
	char nome[100];
	unsigned short dia;
	unsigned short mes;
	unsigned int ano;
	} ;


typedef struct  {
	char nome[100];
	unsigned short dia;
	unsigned short mes;
	unsigned int ano;
	} CARA;	
	
	
	
	
int main(){

	CARA ca;
	
	struct cara c;
	
	struct cara *ptr;
	
	strcpy( c.nome, "Paulo Bandiera-Paiva" );
	c.dia = 9;
	c.mes = 8;
	c.ano = 1966;
	
	printf("%s  Nasc: %d/%d/%d\n\n", c.nome,c.dia,c.mes,c.ano); 
	
	
	ptr = &c;
	
	printf("%s  Nasc: %d/%d/%d\n\n", ptr->nome, ptr->dia, ptr->mes, ptr->ano);
	
	}
	
	
	
	
