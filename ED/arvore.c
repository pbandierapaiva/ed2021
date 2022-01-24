// Implementação de BST

#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>


void insere(arvore *a, int valor ) {
  arvore novono;
  int fb;

  if( *a !=NULL ) { // árvore existe
    if( valor > (*a)->conteudo )   //Direita
      insere( &( (*a)->dir ), valor );
    else
      insere( &( (*a)->esq ), valor );

    fb = altura( (*a)->dir) -   altura( (*a)->esq);
    if( fb < -1 ) { //desbalanceada para a esquerda

      if( altura( (*a)->esq->dir ) - altura( (*a)->esq->esq) > 0 )
        rotacaoEsquerda((arvore *)(*a)->esq);
      rotacaoDireita(a);
    }
    else if (fb > 1 ) {
      if(  altura( (*a)->dir->dir ) - altura( (*a)->dir->esq)    < 0 )
        rotacaoDireita((arvore *)(*a)->dir );
      rotacaoEsquerda(a);
    }
    return;
  }

  novono = malloc( sizeof(NO) );
  if( !novono ) {
    printf("Erro de alocação de memória");
    exit(1);
  }
  novono->conteudo = valor;
  novono->esq=NULL;
  novono->dir=NULL;

  (*a) = novono;
}

arvore busca(arvore a, int termo) {
  if( a==NULL)
    return NULL;
  if( termo == a->conteudo )
    return a;
  if( termo > a->conteudo )
    return busca(a->dir, termo);
  else
    return busca(a->esq, termo);
}

void travessia(arvore a){
  if( a->esq != NULL )
    travessia( a->esq );  //E
  printf(" %d ", a->conteudo); //R
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

int main() {
  arvore raiz=NULL;
  int valor;


// Entrando números sequenciais
for(valor=0; valor<10000; valor++)
  insere(&raiz, valor);

// Entrando dados através de um arquivo com 10.000 números aletaórios
  // FILE *fpd;
  // fpd = fopen("entrada.txt","r");
  //
  // while(1) {
  //   if( feof(fpd) ) break;
  //   fscanf(fpd, "%d\n", &valor);
  //   insere(&raiz, valor);
  // }

//Entrando dados usando arquivo "entrada.txt"
  // printf("Entre com valor inteiro positivo (0 termina)\n\n");
  // while(1) {
  //   printf("> ");
  //   scanf("%d", &valor);
  //   if( valor==0 )
  //     break;
  //   insere(&raiz, valor);
  //   }

  printf("Altura da árvore %d\n", altura(raiz));

  // printf("\nTravessia da rede em ordem (ERD)\n");
  // travessia(raiz);
  // printf("\n\n");


}
