// Implementação de estruturas de dados baseadas em listas duplamente encadeadas
//
// Pilha, Fila, Lista circular

#include "listadl.h"

#include <stdio.h>
#include <stdlib.h>

// Imprime lista
void imprimeLista( NOD *pilha) {
	NOD *paux;

	paux = pilha;
	printf("\n\nImprimindo lista:\n-- Topo --\n");
	while( paux ) {
		printf("Val: %d\n", paux->dado );
		paux = paux->prox;
		if( paux==pilha )
			break;
	}
	printf("-----\n\n");
}

// Imprime lista invertida
void imprimeListaInvertida( NOD *lista) {
	NOD *paux;

	paux = lista;
	printf("\n\nImprimindo lista Invertida:\n-- Base --\n");

	if( paux==NULL ) {
		printf("Lista vazia\n");
		return;
		}

	while( paux->prox )
		paux = paux->prox;

	while( paux!=NULL ) {
		printf("Val: %d\n", paux->dado );
		paux = paux->ant;
		if( paux==lista )
			break;
		}
	printf("-----\n\n");
}

// Implementação de Pilha
//
// NOD *pilha;
// funções push(int dado, &pilha ), pop( &pilha ), peek( pilha )
//
void push( int d, NOD **pilha ) {
	NOD *novo;

	novo = malloc( sizeof(NOD) );
	if(!novo) {
		printf("\nERRO DE ALOCAÇÃO DE MEMÓRIA\n");
		exit(-1);
		}
	novo->dado = d;
	novo->prox = *pilha;
	if(*pilha==NULL)
		novo->ant = NULL;
	else
		novo->ant = (*pilha)->ant;
	*pilha = novo;
}

int pop( NOD **pilha ) {
	NOD *paux;
	int vdado;

	if(*pilha == NULL ) {
		printf("\nVazio!\n");
		return 0;
		}

	paux = *pilha;
	*pilha = paux->prox;
	if(*pilha!=NULL)
	 (*pilha)->ant = NULL;
	vdado = paux->dado;
	free(paux);

	return vdado;
}

int peek( NOD *pilha) {
	if( pilha==NULL ) {
		printf("\nPilha vazia!\n");
		return 0;
		}
	return pilha->dado;
}

// Implementação de Fila
//
// NOD *fila;
// funções entra(int dado, &fila ), sai( &fila )
//

void entra( int pdado, NOD **fila ){
	NOD *paux;

	NOD *novo;
	novo = malloc( sizeof(NOD) );
	if(!novo) {
		printf("\nERRO DE ALOCAÇÃO DE MEMÓRIA\n");
		exit(-1);
		}
	novo->dado = pdado;
	novo->prox = NULL;


	paux = *fila;
	if( paux==NULL ) {	// fila vazia
		*fila = novo;
		novo->ant = NULL;
		return;
		}
	while( 1 ) {
		if( paux->prox==NULL ) {
			paux->prox = novo;
			novo->ant = paux;
			break;
			}
		else {
			paux=paux->prox;
			}
		}
}

int sai( NOD **fila ) {
	return pop(fila);
}

// Implementação de Lista circular
//
// NO *lc;
// funções insere(int dado, &lc ), remove( &lc ), prox( &lc )
//
void insere(int pdado, NOD **lc ) {
	NOD *paux;

	NOD *novo;
	novo = malloc( sizeof(NOD) );
	if(!novo) {
		printf("\nERRO DE ALOCAÇÃO DE MEMÓRIA\n");
		exit(-1);
		}
	novo->dado = pdado;
	novo->prox = novo;
	novo->ant = novo;

	paux = *lc;
	if(paux==NULL) { //lista vazia
		*lc = novo;
		return;
		}

	while( paux->prox != *lc ) {
		paux = paux->prox;
		}
	paux->prox = novo;
	novo->prox = *lc;
	novo->ant = (*lc)->ant;
	(*lc)->ant = novo;

}

int retira( NOD **lc ) {
	NOD *paux;
	int vdado;

	paux = *lc;
	if(paux==NULL) {
		printf("\nLista vazia.\n");
		return 0;
		}

	while( paux->prox != *lc )
		paux=paux->prox;
	paux->prox = (*lc)->prox;
	vdado = (*lc)->dado;
	paux->ant  = (*lc)->prox;

	free(*lc);
	*lc = paux->prox;
	return vdado;
}

int prox( NOD **lc ) {
	int vdado;
	vdado = (*lc)->dado;
	*lc = (*lc)->prox;
	return vdado;
}

// Fila com prioridade - apenas 2 categorias
//
// NOD *fcp;
// funções entraFCP(int dado, &fila, int prioridade ), saiFCP( &fila )
//
void imprimeListasPrioridade( FCP *fcp){
	printf("\nImprimindo fila com prioridade\n\nPrioritaria:");
	imprimeLista(fcp->prior);
	printf("\nComum:");
	imprimeLista(fcp->comum);
}

void entraFCP( int pdado, FCP *fcp, int prioridade ){ // 1 ou 0
 	if(prioridade)
		entra(pdado, &( fcp->prior ) );
	else
		entra(pdado, &( fcp->comum ) );
}

int saiFCP(FCP *fcp) 	 {
	if( fcp->prior != NULL )
		return sai( &( fcp->prior) );
	else
		return sai( &( fcp->comum) );
}
