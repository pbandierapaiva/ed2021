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

int extrai( char *li, int campo, char *resp ) {
	char copiaLi[MAXLIN];
	char *inicio, *final;
	int i=0;
	
	strcpy(copiaLi, li);	

	inicio = copiaLi;
	final = copiaLi;
	
	
	while( *final!='\0' ) {
		if( *final == ';' ) {
			if( i == campo ) {
				*(final-1) = '\0';   // remove aspas no final
				inicio++;            // inicia após as aspas
				
				strcpy(resp, inicio);
				return strlen(inicio); //retorna o tamanho do string lido
				}
			i++;
			final++;
			inicio=final;
		
			}
		else {
			final++;
			}	
		}
	return 0;
	}
	
int encontra( char *arquivo, char *nome ) {	
	FILE *fp;
	char linha[MAXLIN];
	char temp[MAXCPO];
	
	// abre  arquivo para leitura
	fp = fopen( arquivo, "r" );
		
	if( !fp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
	
	while( ! feof( fp ) ) {       // fp chegou ao final do arquivo
		// lê linha	
		fgets( linha, MAXLIN, fp);
		
		extrai( linha, NOME, temp );
		if( strstr( temp, nome ) ) {  //  nome in temp?
			printf("%s\n",linha);
			}
		}

	fclose(fp);	
	
	}	
	
void prepara(char *texto) {
	char *p;
	p= texto;
	while( *p!='\0' && *p!='\n') {
		*p = toupper(*p);
		p++;
		}
	*p='\0';
	}
	
int main() {
	char texto[MAXCPO];
	char *p;
	
	printf("Entre com nome a ser encontrado: ");
	fgets(texto, MAXCPO, stdin);
	prepara(texto);	
	
	printf("\nProcurando: %s\n\n", texto);
	encontra("/data/datasets/ed2021/cadastro2020.csv",texto);
		
	return 0;
}



