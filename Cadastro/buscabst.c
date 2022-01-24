// Implementação de BST para busca no Cadastro de servidores

#include "cadastro.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void insere(arvore *a, REGIND valor ) {
  arvore novono;
	int fb;

  if( *a !=NULL ) { // árvore existe
    if( strcmp( valor.nome, (*a)->dados.nome ) < 0 )   // 0 se for igual, -1 se esq maior
      insere( &( (*a)->esq ), valor );
    else
      insere( &( (*a)->dir ), valor );

    // verifica fator de balanceamento fb
    fb = altura( (*a)->dir) -   altura( (*a)->esq);
    if( fb<-1 ){ //desbalanceada para a esquerda
			if( altura( (*a)->esq->dir ) - altura( (*a)->esq->esq) > 0 )
				rotacaoEsquerda((arvore *)(*a)->esq);
      rotacaoDireita(a);
      }
    else if (fb>1){
			if(  altura( (*a)->dir->dir ) - altura( (*a)->dir->esq)    < 0 )
				rotacaoDireita((arvore *)(*a)->dir );
      rotacaoEsquerda(a);
      }

    return;
  }

  novono = malloc( sizeof(NOBST) );

  if( !novono ) {
    printf("Erro de alocação de memória");
    exit(1);
  }

  //strcpy(novono->dados.nome, valor.nome);
  //strcpy(novono->dados.localizacao,	valor.localizacao);
  //novono->dados.local	 = valor.local;
  //
  memcpy(&(novono->dados), &valor, sizeof(REGIND));
  novono->esq=NULL;
  novono->dir=NULL;

  (*a) = novono;

}

arvore rotacaoDireita(arvore *p){
  arvore paux;
  paux = (*p)->esq;
  (*p)->esq = paux->dir;
  paux->dir = (*p);
  (*p) = paux;
}
arvore rotacaoEsquerda(arvore *p){
  arvore paux;
  paux = (*p)->dir;
  (*p)->dir = paux->esq;
  paux->esq = (*p);
  (*p) = paux;
}

arvore busca(arvore a, char *pnome) {
  if( a==NULL)
    return NULL;
  if( strcmp(pnome, a->dados.nome)==0 )   // LE e LD são iguais
    return a;
  if( strcmp(pnome, a->dados.nome)>0 )
    return busca(a->dir, pnome);
  else
    return busca(a->esq, pnome);
}

void travessia(arvore a){
	if( a==NULL) return;
  if( a->esq != NULL )
    travessia( a->esq );  //E
  printf(" %s %d\n", a->dados.nome, a->dados.local); //R
  if( a->dir != NULL )
    travessia( a->dir ) ;//D
}

int altura(arvore a) {
  int he, hd;
  if( a==NULL )
    return 0;
  he = altura(a->esq);
  hd = altura(a->dir);
  if(he>hd)
    return he+1;
  return hd+1;
}

arvore carregaindice() {
  arvore raiz=NULL;
  // REGIND valor;
  FILE *fp, *indfp;

  REGIND regind;
  char linha[MAXLIN];
  long int onde;
  int regs=0;


  fp = fopen(ARQUIVOCSV,"r");
	indfp = fopen( ARQUIVOIND, "r");

	if( !fp || !indfp ) {
		printf("Erro de aberturra de arquivo");
  	exit(1);
  	}
	

  while( ! feof(indfp) ) {
		  fread( &regind, sizeof(regind), 1, indfp);
			insere(&raiz, regind);
	}
  fclose(indfp);

  printf("Índice carregado");

  // printf("\nTravessia da rede em ordem (ERD)\n");
  // travessia(raiz);
	printf("\nAltura da árvore: %d", altura(raiz));
  printf("\n\n");
	
	return raiz;

}

void achanomesbst(char *texto, arvore raiz, NO **resposta) {
	arvore encontrado;	
	FILE *fp;
	char linha[MAXLIN];
	REGISTRO r;
	
	encontrado = busca( raiz, texto );

	if(encontrado){
		fp = 	fopen( ARQUIVOCSV, "r" );
		if(!fp){
				printf("Erro de abertura de arquivo.\n");
				exit(-1);
			}
		fseek( fp, encontrado->dados.local,0);
		fgets(linha, MAXLIN, fp);

		extrai( linha, NOME, r.nome);
		extrai( linha, ORGSUP_LOTACAO, r.lotacao);
		extrai( linha, DESCRICAO_CARGO, r.cargo);
		extrai( linha, COD_UORG_LOTACAO, r.ulotacao);
		extrai( linha, COD_ORG_LOTACAO , r.olotacao);
		push( r, resposta );
	}
}
	
	
	
	
	
	
	
	
	
	
	
	

