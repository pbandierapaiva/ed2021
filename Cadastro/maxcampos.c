/*
	criaind.c

	Programa criar índice de cadastro em arquivo no formato CSV, baixado do transparencia.gov.br
	na Darwin3
	/data/datasets/ed2021/cadastro2020.csv
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <time.h>

#include "cadastro.h"
#include "util.h"	
	
int main() {
	char linha[MAXLIN];
	FILE *fp;
	char temp[MAXCPO];
	int maxnome=0;
	int maxlota=0;
	
	fp = fopen( ARQUIVOCSV, "r");	
	if( !fp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
		
	fgets( linha, MAXLIN, fp);	
	
	while( !feof(fp) ) {
		
		// Montando a struct reglido com dados da linha
		extrai( linha, NOME, temp);
		if( strlen(temp) > maxnome )  maxnome = strlen(temp);
				  
		extrai( linha, UORG_LOTACAO, temp);
		if( strlen(temp) > maxlota )  maxlota = strlen(temp);
		
		fgets( linha, MAXLIN, fp);
		}
	
	
	fclose(fp);
	printf("\nMáximo \n\tNOME: %d\n\tUORG_LOTACAO: %d\n", maxnome, maxlota);
	return 0;
}



