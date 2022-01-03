// Implementação de estruturas de dados baseadas em listas simplesmente encadeadas
//
// Pilha, Fila, Lista circular

#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

// Imprime lista
void imprimeLista( NO *pilha ) {
	NO *paux;
	
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


// Implementação de Pilha
//
// NO *pilha;
// funções push(int dado, &pilha ), pop( &pilha ), peek( pilha )
//
void push( int d, NO **pilha ) {
	NO *novo;
	
	novo = malloc( sizeof(NO) );
	if(!novo) {
		printf("\nERRO DE ALOCAÇÃO DE MEMÓRIA\n");
		exit(-1);
		}
	novo->dado = d;
	novo->prox = *pilha;
	*pilha = novo;
}

int pop( NO **pilha ) {
	NO *paux;
	int vdado;
	
	if(*pilha == NULL ) {
		printf("\nVazio!\n");
		return 0;
		}
	
	paux = *pilha;
	*pilha = paux->prox;
	vdado = paux->dado;
	free(paux);
	
	return vdado;
}

int peek( NO *pilha) {
	if( pilha==NULL ) {
		printf("\nPilha vazia!\n");
		return 0;
		}
	return pilha->dado;
}

// Implementação de Fila
//
// NO *fila;
// funções entra(int dado, &fila ), sai( &fila )
//

void entra( int pdado, NO **fila ){
	NO *paux;

	NO *novo;
	novo = malloc( sizeof(NO) );
	if(!novo) {
		printf("\nERRO DE ALOCAÇÃO DE MEMÓRIA\n");
		exit(-1);
		}
	novo->dado = pdado;
	novo->prox = NULL;	
	
	
	paux = *fila;
	if( paux==NULL ) {	// fila vazia
		*fila = novo;
		return;
		}
	while( 1 ) {
		if( paux->prox==NULL ) {
			paux->prox = novo;
			break;
			}
		else {
			paux=paux->prox;
			}
		}
}

int sai( NO **fila ) {
	return pop(fila);
}

// Implementação de Lista circular
//
// NO *lc;
// funções insere(int dado, &lc ), remove( &lc ), prox( &lc )
//
void insere(int pdado, NO **lc ) {
	NO *paux;
	
	NO *novo;
	novo = malloc( sizeof(NO) );
	if(!novo) {
		printf("\nERRO DE ALOCAÇÃO DE MEMÓRIA\n");
		exit(-1);
		}
	novo->dado = pdado;
	novo->prox = novo;	

	paux = *lc;
	if(paux==NULL) {
		*lc = novo;
		return;
		}
		
	while( paux->prox != *lc ) {
		paux = paux->prox;
		}
	paux->prox = novo;
	novo->prox = *lc;
}

int retira( NO **lc ) {
	NO *paux;
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
	free(*lc);
	*lc = paux->prox;
	return vdado;
}

int prox( NO **lc ) {
	int vdado;
	vdado = (*lc)->dado;
	*lc = (*lc)->prox;
	return vdado;
}







