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
		
		// Montando a struct reglido com dados da linha
		extrai( linha, NOME, reglido.nome);  
		extrai( linha, UORG_LOTACAO, reglido.lotacao);
		reglido.local = onde;
		
		fwrite( &reglido, sizeof(REGIND), 1, indfp);
		
		onde = ftell( fp );
		fgets( linha, MAXLIN, fp);
		}
	fclose(fp);
	fclose(indfp);
	return 0;
}



