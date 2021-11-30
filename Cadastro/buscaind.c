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
	char *resposta;
	
	resposta=NULL;
	
	printf("Entre com nome a ser encontrado: ");
	fgets(texto, MAXCPO, stdin);	
	
	/*** Inicia cronometro ***/
	clock_t cronometro = clock();

	printf("\nProcurando: %s\n\n", texto);
	encontraind( texto, &resposta);
	
	printf("RESPOSTAS: \n%s",resposta);
	
	/*** Imprime cronometro ***/
	printf("Tempo de processamento: %u ms\n", (long)(clock()-cronometro)/1000);
	
	return 0;
}



