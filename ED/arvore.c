// Implementação de BST

#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>

void insere(arvore *a, int valor ) {
  arvore novono;

  if( *a !=NULL ) { // árvore existe
    if( valor > (*a)->conteudo )   //Direita
      insere( &( (*a)->dir ), valor );
    else
      insere( &( (*a)->esq ), valor );
    return;
  }

  novono = malloc( sizeof(NO) );
  if( !novono ) {
    printf("Erro de alocação de memória");
    exit(1);
  }
  novono->conteudo = valor;
  novono->pai=NULL;
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

int main() {
  arvore raiz=NULL;
  int valor;

  printf("Entre com valor inteiro positivo (0 termina)\n\n");

  while(1) {
    printf("> ");
    scanf("%d", &valor);
    if( valor==0 )
      break;
    insere(&raiz, valor);
    }

  printf("\nTravessia da rede em ordem (ERD)\n");
  travessia(raiz);
  printf("\n\n")

}
