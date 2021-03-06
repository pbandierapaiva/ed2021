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

void imprimeResposta(char *resp) {
	char *p, *q;

	p = resp;
	q=p;
	
	while( 1 ) {
		while( *q!='\n' && *q!='\0' ) q++; 
		if( *q=='\0' ) {
			break;
			}
		//  *q=='\n'
		*q = '\0';
		imprimeLinha( p );
		q++;
		p=q;
		}
}


void imprimeLinha(char *linha) {
	char cpo[MAXCPO];
	
	extrai(linha, NOME, cpo);
	printf("Nome:\t %s\n",cpo);
	extrai(linha, DESCRICAO_CARGO, cpo);
	printf("Cargo:\t %s\n",cpo);
	extrai(linha, UORG_LOTACAO, cpo);
	printf("Lotacao:\t %s\n",cpo);
	extrai(linha, ORG_LOTACAO, cpo);
	printf("Org Lot:\t %s\n",cpo);
	extrai(linha, ORGSUP_LOTACAO, cpo);
	printf("Sup Lot:\t %s\n\n",cpo);
	
	return;
	}
int encontraind( char *nomebuscado, int campo, char **pRet ) {	
	FILE *indfp, *fp;
	REGIND reg;
	char linha[MAXLIN];
	char regbusca[MAXCPO];
	int i=0;
	
	if( campo!=NOME && campo!=UORG_LOTACAO )	{
		printf("\nChamada de função encontraind ERRADA\n\n!");
		return 0;	
		}
	prepara(nomebuscado);
	
	indfp = fopen( ARQUIVOIND, "r" );
	fp = 	fopen( ARQUIVOCSV, "r" );
	
	if( !indfp || !fp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
	
	fread( &reg, sizeof(REGIND), 1, indfp );
	
	while( ! feof(indfp)) {
		if( campo==NOME )
			strcpy(regbusca, reg.nome);
		else {
			//strcpy(regbusca, reg.lotacao);
			printf("Não implementado");
			exit(1);
		 	}
		if(  strstr( regbusca, nomebuscado ) ) {
			i++;
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
	return i;
	}

int encontra( char *nome, int campo, char **pRet ) {	
	FILE *fp;
	char linha[MAXLIN];
	char nomeNaLinha[MAXCPO];
	int i=0;
	char *paux;
	int tam;
	
	if( campo!=NOME && campo!=UORG_LOTACAO )	{
		printf("\nChamada de função encontra() ERRADA\n\n!");
		return 0;	
		}
	
	prepara(nome);
	
	// abre  arquivo para leitura
	fp = fopen( ARQUIVOCSV, "r" );
		
	if( !fp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
	
	
	while( ! feof( fp ) ) {       // fp chegou ao final do arquivo
		// lê linha	
		fgets( linha, MAXLIN, fp);
		
		extrai( linha, campo, nomeNaLinha );
		if( strstr( nomeNaLinha, nome ) ) {  //  nome in temp?
			if( *pRet == NULL ) {
				*pRet = malloc(  strlen(linha) +1  );
				}
			else {
				tam = strlen(*pRet) + strlen(linha)+1;

				*pRet = realloc( *pRet, tam );

				if( *pRet==NULL ){
					printf("\nERRO-problema na alocação de memória\n"); 
					return -1;
					}				
				}
			strcat(*pRet, linha);
			i++;	
			}
		}

	fclose(fp);	
	return i;
	}	


// achanomes usa uma pilha (NO) para retornar valores
int achanomes( char *nomebuscado, int campo, NO **pRet ) {	
	FILE *indfp, *fp;
	REGIND reg;
	REGISTRO r;
	char linha[MAXLIN];
	char regbusca[MAXCPO];
	int i=0;
	
	if( campo!=NOME && campo!=UORG_LOTACAO )	{
		printf("\nChamada de função encontraind ERRADA\n\n!");
		return 0;	
		}
	prepara(nomebuscado);
	
	indfp = fopen( ARQUIVOIND, "r" );
	fp = 	fopen( ARQUIVOCSV, "r" );
	
	if( !indfp || !fp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
	
	fread( &reg, sizeof(REGIND), 1, indfp );
	
	while( ! feof(indfp)) {
		if( campo==NOME )
			strcpy(regbusca, reg.nome);
		else {
			//strcpy(regbusca, reg.lotacao);
			printf("Não implementado");
			exit(1);
		 	}
		if(  strstr( regbusca, nomebuscado ) ) {
			i++;
			fseek(fp, reg.local, 0);
			fgets(linha, MAXLIN, fp);


			extrai( linha, NOME, r.nome);
			extrai( linha, ORGSUP_LOTACAO, r.lotacao);
			extrai( linha, DESCRICAO_CARGO, r.cargo);
			extrai( linha, COD_UORG_LOTACAO, r.ulotacao);
			extrai( linha, COD_ORG_LOTACAO , r.olotacao);
			push( r, pRet);
			}
		fread( &reg, sizeof(REGIND), 1, indfp );
		}
	return i;
	}
	
	
void push( REGISTRO reg, NO **pilha ) {
	NO *novo;
	
	novo = malloc( sizeof(NO) );
	if(!novo) {
		printf("\nERRO DE ALOCAÇÃO DE MEMÓRIA\n");
		exit(-1);
		}
	novo->registro = reg;
	novo->prox = *pilha;
	*pilha = novo;
}
void imprimePilha(NO *pilha) {
	NO *paux;
	
	paux = pilha;
	while( paux ){
		printf("Nome: %s\n", paux->registro.nome);
		printf("Cargo: %s\n", paux->registro.cargo);
		printf("Lot: %s\n", paux->registro.lotacao);
		printf("Lot: %s\n", paux->registro.ulotacao);
		printf("Lot: %s\n\n", paux->registro.olotacao);	
		paux = paux->prox;
		}

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



