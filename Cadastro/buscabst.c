// Implementação de BST para busca no Cadastro de servidores

#include "cadastro.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insere(arvore *a, REGIND valor ) {
  arvore novono;

  if( *a !=NULL ) { // árvore existe
    if( strcmp( valor.nome, (*a)->dados.nome ) < 0 )   // 0 se for igual, -1 se esq maior
      insere( &( (*a)->esq ), valor );
    else
      insere( &( (*a)->dir ), valor );

    // verifica fator de balanceamento fb
    int fb;

    fb = altura( (*a)->dir) -   altura( (*a)->esq);
    if( fb<-1 ){ //desbalanceada para a esquerda
      rotacaoDireita(a);
      }
    else if (fb>1){
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
  if( a->esq != NULL )
    travessia( a->esq );  //E
  printf(" %s %s %d\n", a->dados.nome, a->dados.local); //R
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

int main() {
  arvore raiz=NULL;
  // REGIND valor;
  FILE *fp;

  REGIND reglido;
  char linha[MAXLIN];
  long int onde;
  int regs=0;


  fp = fopen(ARQUIVOCSV,"r");
  if(fp==NULL) {
  	printf("Erro de aberturra de arquivo");
  	exit(1);
  	}

  fgets( linha, MAXLIN, fp); // cabeçalho do arquivo

  while( 1 ) {
	  if(feof(fp)) break;
    regs++;

    if(regs%1000==0) {
    	printf("\b\b\b\b\b\b\b\b%d", regs);
    	fflush(stdout);
    	}
    onde = ftell( fp );
    fgets( linha, MAXLIN, fp);

	// Montando a struct reglido com dados da linha
	extrai( linha, NOME, reglido.nome);
	reglido.local = onde;

	insere(&raiz, reglido);

	}
  fclose(fp);

  printf("Carregado");
  fgets( linha, MAXLIN, stdin);


  printf("\nTravessia da rede em ordem (ERD)\n");
  travessia(raiz);
  printf("\n\n");

}
