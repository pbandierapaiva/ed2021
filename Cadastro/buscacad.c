/*
	buscacad.c

	Programa para ler cadastro em arquivo no formato CSV, baixado do transparencia.gov.br
	na Darwin3
	/data/datasets/ed2021/cadastro2020.csv
	
	Faz uma busca e retorna as linhas encontradas.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cadastro.h"
#include "util.h"	
	
int main() {
	char texto[MAXCPO];
	char *resposta;
	
	resposta=NULL;
	
	printf("Entre com nome a ser encontrado: ");
	fgets(texto, MAXCPO, stdin);	
	
	printf("\nProcurando: %s\n\n", texto);
	encontra( ARQUIVOCSV ,texto, &resposta);
	
	printf("RESPOSTAS: \n%s",resposta);
	
	return 0;
}



