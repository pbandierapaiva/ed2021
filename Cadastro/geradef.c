/*
	geradef.c

	Programa para ler cadastro em arquivo no formato CSV, baixado do transparencia.gov.br
	na Darwin3
	/data/datasets/ed2021/cadastro2020.csv
	e gerar arquivo .h com as definições dos índices dos campos (#define) 
*/

#include <stdio.h>
#include <stdlib.h>

#include "cadastro.h"


int main() {
	FILE *fp, *outfp;
	int i=0;
	char linha[MAXLIN];
	char *inicio, *final;
	
	
	// Lê cabeçalho do arquivo
	
	fp = fopen( "/data/datasets/ed2021/cadastro2020.csv", "r");
	outfp = fopen( "cadastro-auto.h","w");
		
	if( !fp || !outfp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
	
	while( ! feof( fp ) ) {       // fp chegou ao final do arquivo
		// lê linha	
		fgets( linha, MAXLIN, fp);
		break;	
		}

	
	fprintf(outfp, "// Arquivo gerado automaticamente \n");		
	inicio=linha;
	final=linha;
	
	while( *final!='\0' ) {
	
		if( *final == ';' ) {
			
			*final = '\0';
			*(final-1) = '\0';   // remove aspas no final
			inicio++;            // inicia após as aspas
			fprintf(outfp, "#define %s %d\n", inicio,i);
			i++;
			final++;
			inicio=final;
		
			}
		else {
			final++;
			}	
		}
		
	fclose(outfp);	
	fclose(fp);

	return 0;
}



