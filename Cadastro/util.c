/*
	util.c

	Funções para trabalhar com cadastro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cadastro.h"
#include "util.h"


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
	
int encontraind( char *nomebuscado, char **pRet ) {	
	FILE *indfp, *fp;
	REGIND reg;
	char linha[MAXLIN];
	
	prepara(nomebuscado);
	
	indfp = fopen( ARQUIVOIND, "r" );
	fp = 	fopen( ARQUIVOCSV, "r" );
	
	if( !indfp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
	
	fread( &reg, sizeof(REGIND), 1, indfp );
	
	while( ! feof(indfp)) {
	
		if( strstr( reg.nome, nomebuscado ) ) {
			printf("\nNome: %s\nLotação: %s\nOffset: %u\n\n", 
				reg.nome, reg.lotacao, reg.local );
			fseek(fp, reg.local, 0);
			fgets(linha, MAXLIN, fp);

			if( *pRet==NULL ) {
				*pRet = malloc(strlen(linha)+1);
				strcpy( *pRet, linha);
				}
			else {
				*pRet = realloc( *pRet, strlen(*pRet)+strlen(linha)+1 );
				strcat(*pRet, linha);
				}
							
			}
		fread( &reg, sizeof(REGIND), 1, indfp );
		}
	}

int encontra( char *arquivo, char *nome, char **pRet ) {	
	FILE *fp;
	char linha[MAXLIN];
	char nomeNaLinha[MAXCPO];
	int i=0;
	char *paux;
	int tam;
	
	
	prepara(nome);
	
	// abre  arquivo para leitura
	fp = fopen( arquivo, "r" );
		
	if( !fp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
	
	
	while( ! feof( fp ) ) {       // fp chegou ao final do arquivo
		// lê linha	
		fgets( linha, MAXLIN, fp);
		
		extrai( linha, NOME, nomeNaLinha );
		if( strstr( nomeNaLinha, nome ) ) {  //  nome in temp?
			if( *pRet == NULL ) {
				*pRet = malloc(  strlen(linha) +1  );
				}
			else {
				tam = strlen(*pRet) + strlen(linha)+1;
				printf("\n Tam: %d\n",tam);

				printf("antes do malloc\n");				
				
				*pRet = realloc( *pRet, tam );
				printf("depois do malloc\n");				
				if( *pRet==NULL ){
					printf("\nERRO - problema na alocação de memória.\n"); 
					return -1;
					}				
				}
		
		
			strcat(*pRet, linha);
			strcat(*pRet, "\n");

			printf(*pRet);

			i++;	
			}
		}

	fclose(fp);	
	return i;
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



