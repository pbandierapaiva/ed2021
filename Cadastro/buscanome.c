/*
	buscanome.c

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
	NO *resposta;
	
	arvore indicebst, encontrado;
	clock_t cronometro;
	
	resposta=NULL;
	
	printf("Entre com nome a ser encontrado: ");
	fgets(texto, MAXCPO, stdin);	
	
	/*** Inicia cronometro ***/
	cronometro = clock();
	printf("\nProcurando no arquivo indexado: %s\n\n", texto);
	printf("Encontrados: %d\n", 
		achanomes( texto, NOME, &resposta));

	/*** Imprime cronometro ***/
	printf("Tempo de processamento: %u ms\n", (long)(clock()-cronometro)/1000);

	//imprimeResposta(resposta);
	
	imprimePilha(resposta);	
	
	cronometro = clock();

	printf("\nBusca BST\n\n");
	indicebst = carregaindice();
	achanomesbst( texto, indicebst, &resposta );
	
	printf("Tempo de processamento: %u ms\n", (long)(clock()-cronometro)/1000);

	imprimePilha(resposta);	


	
	return 0;
}



