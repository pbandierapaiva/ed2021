// Pilha

#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

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

void main() {
	int t;
	int  dado;
	
	NO *stack;
	NO *paux;
	
	stack = NULL;
	
	while(1) {
		printf("\n\n****\n1.Push\n2.Pop\n3.Peek\n4.Imprime\n0.Sai\n****\nSelecione: ");
		//t = fgetc(stdin);
		scanf("%d", &t);
		
		printf("Opção: %d\n",t);
		switch( t ){
		case 1:
			printf("\nEntre com número: ");
			scanf("%d", &dado);
			push(dado, &stack);
			printf("inserido\n");
			break;
		case 2:
			printf("\n\nValor: %d\n\n", pop(&stack));
			break;
		case 3:
			printf("\n\nValor: %d\n\n", peek(stack));
			break;
		case 4:
			paux = stack;
			while( paux ) {
				printf("Val: %d\n", paux->dado );
				paux = paux->prox;
			}		
			break;		
		case 0:
			exit(0);
		}
	}

		

}

