// Lidando com matrizes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct nomx {
  int valor;
  int coluna;
  struct nomx *prox;
} NOMX;

typedef NOMX* PONT;

typedef struct {
  PONT A;
  int linhas;
  int colunas;
} MATRIZ;

void initMatriz( MATRIZ *m, int lin, int col) {
  m->linhas = lin;
  m->colunas = col;
  m->A  =  (PONT *) malloc( lin * sizeof(PONT) );
  for (int i=0; i<lin; i++) m->A[i] = NULL;
}

bool seta(MATRIZ *m, int lin, int col, int valor ){
  PONT ant=NULL;
  PONT atual, novo;
  if( lin<0 || col<0 || lin>=m->linhas || col>= m->colunas) return false;
  atual = m->A[lin];

  if(atual!=NULL) {
      ant = atual;
      atual = atual->prox;

      if( atual!=NULL && col == atual->coluna ){
          if(valor==0) {
            ant = atual->prox;
            free(atual);
          }
          else {
            atual->valor = valor;
          }
      else {
          if(valor==0){
              return true;
            }
          novo = (PONT)  malloc( sizeof(NO));
          novo->valor = valor;
          novo->coluna = col;
          novo->prox=atual;
          if( ant==NULL ) m->A[lin]=novo;
          else ant->prox = novo;
        }
      return true;
      }

  }



  m.A


}


int main() {


}
