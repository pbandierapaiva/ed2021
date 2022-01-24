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
	FILE *fp, *indfp;
	REGIND reglido;
	char linha[MAXLIN];
	long int onde;
	char resposta[MAXCPO], resp2[MAXCPO];
	
	fp = fopen( ARQUIVOCSV, "r");
	indfp = fopen( ARQUIVOIND, "w");

	if( !fp || !indfp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
		
		
	fgets( linha, MAXLIN, fp); // cabeçalho do arquivo
	onde = ftell( fp );
	fgets( linha, MAXLIN, fp);
	while( !feof(fp) ) {
		
		// Extrai org_LOTACAO
		extrai( linha, COD_ORG_LOTACAO, resposta);

// Filtra apenas registros com ORG_LOTACAO da Unifesp 26262
		if( ! strcmp( resposta,"26262" ) ) {
			
			// Montando a struct reglido com dados da linha
			extrai( linha, NOME, reglido.nome);  

			reglido.local = onde;
			
			fwrite( &reglido, sizeof(REGIND), 1, indfp);
			
			}
		onde = ftell( fp );
		fgets( linha, MAXLIN, fp);
		}
	fclose(fp);
	fclose(indfp);
	return 0;
}



