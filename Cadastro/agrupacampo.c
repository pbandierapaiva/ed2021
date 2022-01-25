/*
	agrupacampo.c

	Programa para ler cadastro em arquivo no formato CSV
	Faz listas de valores únicos dos campos:

  ORGSUP_LOTACAO
	    ORG_LOTACAO
	        UORG_LOTACAO


	/data/datasets/ed2021/cadastro2020.csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "cadastro.h"
#include "util.h"

// Estrutura de lista para armazenar textos dos campos buscados
typedef struct NoCpo {
	char campo[MAXCPO];
	struct NoCpo *prox;
	struct NoCpo *filho;
} NOCPO;

void insereuorg(NOCPO **, char * );
void insereorg(NOCPO **, char *, char * );

void insereorgsup(NOCPO **lisup, char *sup, char *org, char *uorg ){
	NOCPO *ptr, *novo;

	ptr = (*lisup);
	while( ptr!=NULL ) {
		if( strcmp( ptr->campo, sup )==0 ) {
				insereorg( &(ptr->filho), org, uorg);
				return;
				}
		ptr = ptr->prox;
		}

	novo = malloc( sizeof(NOCPO) );
	strcpy(novo->campo, sup);
	novo->filho = NULL;
	novo->prox = (*lisup);
	(*lisup) = novo;
	insereorg( &(novo->filho), org, uorg);
}

void insereorg(NOCPO **liorg, char *org, char *uorg ){
	NOCPO *ptr, *novo;

	ptr = (*liorg);	ptr = (*liorg);

	while( ptr!=NULL ) {
		if( strcmp( ptr->campo, org )==0 ) {
			insereuorg( &(ptr->filho), uorg );
			return;
			}
		ptr = ptr->prox;
		}
	ptr  = (*liorg);
	novo = malloc( sizeof(NOCPO) );
	strcpy(novo->campo, org);
	novo->prox = (*liorg);
	novo->filho=NULL;
	(*liorg) = novo;
	insereuorg(	&(novo->filho), uorg);

}

void insereuorg(NOCPO **liuorg, char *uorg ){
	NOCPO *ptr, *novo;

	ptr = (*liuorg);
	while( ptr!=NULL ) {
		if( strcmp( ptr->campo, uorg )==0 ) {
			return; //já inserido
			}
		ptr = ptr->prox;
		}
	novo = malloc( sizeof(NOCPO) );
	strcpy(novo->campo, uorg);
	novo->prox = (*liuorg);
	novo->filho = NULL;
	(*liuorg) = novo;
}


int imprimeIrmaos(NOCPO *li) {
	NOCPO *ptr;
  int contador=0;

	ptr=li;
	while(ptr!=NULL) {
		printf("%d. %s\n", contador, ptr->campo);
		ptr=ptr->prox;
		contador ++;
	}
	return contador;
}

int contaIrmaos(NOCPO *li) {
	int contador=0;
	NOCPO *ptr;

	ptr = li;
	while(ptr!=NULL) {
		contador++;
		ptr = ptr->prox;
	}
	return contador;
}

int acumulafilhos(NOCPO *li) {
	int acum=0;
	NOCPO *ptr;

	ptr = li;
	while(ptr!=NULL){
		acum += contaIrmaos(ptr->filho);
	}
}

int main() {
	FILE *fp;
	char linha[MAXLIN];
	char org[MAXCPO],uorg[MAXCPO],orgsup[MAXCPO];
	NOCPO *lorgsup=NULL;
	NOCPO *ptr;
	int escolha, maxescolha;


	fp = fopen( ARQUIVOCSV, "r");
	if( !fp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
	fgets( linha, MAXLIN, fp); // cabeçalho do arquivo
	while( !feof(fp) ) {
		fgets( linha, MAXLIN, fp);
		extrai(linha, UORG_LOTACAO,uorg);
		extrai(linha, ORG_LOTACAO,org);
		extrai(linha, ORGSUP_LOTACAO,orgsup);

		insereorgsup(&lorgsup, orgsup, org, uorg);
		}

	maxescolha = imprimeIrmaos(lorgsup);
	printf("\nEscolha ORGSUP a destrinchar (0-%d): ",maxescolha);
	scanf("%d", &escolha);

	ptr = lorgsup;
	for(int i=0; i<escolha; i++) {
			ptr = ptr->prox;
			}
	maxescolha = imprimeIrmaos(ptr->filho);
	printf("\nEscolha ORG a destrinchar (0-%d): ",maxescolha);
	scanf("%d", &escolha);

	ptr = ptr->filho;
	for(int i=0; i<escolha; i++) {
			ptr = ptr->prox;
			}
	imprimeIrmaos(ptr->filho);

	printf("Número total de ORGSUP: %d",contaIrmaos(lorgsup));
	printf("Número total de ORG: %d",acumulafilhos(lorgsup));



 // scanf("%d", &escolha);
	// imprimePilha(resposta);
 // maxescolha = imprimeIrmaos(lorgsup);
 // printf("\nEscolha ORGSUP a destrinchar (0-%d): ",maxescolha);
 // scanf("%d", &escolha);
 // ptr = lorgsup;
 // for(int i=0; i<escolha; i++){
	//  ptr = ptr->prox;
 // }
 // printf("\n\n%s\n", ptr->campo);
 // maxescolha = imprimeIrmaos(ptr->filho);
 // printf("\nEscolha ORG a destrinchar (0-%d): ",maxescolha);
 // scanf("%d", &escolha);
 // ptr = ptr->filho;
 // for(int i=0; i<escolha; i++){
	//  ptr = ptr->prox;
 // }
 // maxescolha = imprimeIrmaos(ptr->filho);

 return 0;
}
