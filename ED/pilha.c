// pilha.c
//
// Arquivo para teste de implementação de Pilha utilizando lista ligada

#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

void main() {
	int t;
	int  dado;
	
	NO *stack;
	
	stack = NULL;
	
	while(1) {
		printf("\n\n****\n1.Push\n2.Pop\n3.Peek\n4.Imprime\n0.Sai\n****\n");
		printf("Selecione: ");
		scanf("%d", &t);
		
		switch( t ){
		case 1:
			printf("\nPUSH\nEntre com número: ");
			scanf("%d", &dado);
			push(dado, &stack);
			printf("inserido\n");
			break;
		case 2:
			printf("\nPOP\n---\nValor: %d\n---\n", pop(&stack));
			break;
		case 3:
			printf("\nPEEK\n---\nValor: %d\n---\n", peek(stack));
			break;
		case 4:
			imprimeLista( stack );
			break;		
		case 0:
			printf("\n---\nFIM\n");
			exit(0);
		}
	}
}

