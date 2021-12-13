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
	printf("\n\nImprimindo pilha:\n-- Topo --\n");
	while( paux ) {
		printf("Val: %d\n", paux->dado );
		paux = paux->prox;
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
		printf("\nPilha vazia!\n");
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


