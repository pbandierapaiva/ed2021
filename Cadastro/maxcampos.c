/*
	maxcampos.c

	Encontra o tamanho máximo dos campos Nome e UORG_LOTACAO
	
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
	
	char *p, *q;
	int tam, tammax=0;
	int i=0;
	
	fp = fopen( ARQUIVOCSV, "r");	
	if( !fp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
		
	fgets( linha, MAXLIN, fp);	
	printf("Verificando tamanho dos campos...\n");
	
	while( !feof(fp) ) {
		i++;
		//if( ! i%1000 )  
		printf("\r%d", i);
		
		
		
		// Montando a struct reglido com dados da linha
		extrai( linha, NOME, temp);
		if( strlen(temp) > maxnome )  maxnome = strlen(temp);
				  
		extrai( linha, UORG_LOTACAO, temp);
		if( strlen(temp) > maxlota )  maxlota = strlen(temp);
		
		p= linha;
		q= linha;
		
		
		while(1) {
			
			while(*q!=';' && *q!='\0')  q++;			
			tam = q-p;
			if(tam>tammax) tammax=tam;

			if(*q=='\0') break;
						
			q++;
			p=q;
			}	
			
		fgets( linha, MAXLIN, fp);
		}
	
	
	fclose(fp);
	printf("\nMáximo \n\tNOME: %d\n\tUORG_LOTACAO: %d\n", maxnome, maxlota);
	printf("Tamanho máximo de todos os campos: %d\n\n",tammax);
	return 0;
}



