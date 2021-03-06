/*
	buscaind.c

	Programa para ler cadastro em arquivo no formato CSV, baixado do transparencia.gov.br
	na Darwin3
	/data/datasets/ed2021/cadastro2020.csv
	
	Faz uma busca usando índice e retorna as linhas encontradas.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "cadastro.h"
#include "util.h"	

	
int main() {
	char texto[MAXCPO];
	char *resposta1, *resposta2;
	clock_t cronometro;
	
	resposta1=NULL;
	resposta2=NULL;
	
	printf("Entre com nome a ser encontrado: ");
	fgets(texto, MAXCPO, stdin);	
	
	/*** Inicia cronometro ***/
	cronometro = clock();
	printf("\nProcurando no arquivo indexado: %s\n\n", texto);
	printf("Encontrados: %d\n", 
		encontraind( texto, NOME, &resposta1));
	/*** Imprime cronometro ***/
	printf("Tempo de processamento: %u ms\n", (long)(clock()-cronometro)/1000);

	cronometro = clock();
	printf("\nProcurando direto no CSV: %s\n\n", texto);
	printf("Encontrados: %d\n", 
		encontra( texto, NOME, &resposta2));
	printf("Tempo de processamento: %u ms\n", (long)(clock()-cronometro)/1000);

	if( !strcmp(resposta1,resposta2) ) 
		printf("Responderam a mesma coisa\n");
	else
		printf("\n\n%s\n\n%s", resposta1, resposta2 );
		
	
	
	return 0;
}



