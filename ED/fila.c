//
// Arquivo para teste de implementação de Fila utilizando lista ligada

#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

void main() {
	int t;
	int  dado;
	
	NO *fila;
	
	fila = NULL;
	
	while(1) {
		printf("\n\n****\n1.Entra\n2.Sai\n3.Peek\n4.Imprime\n0.Sai\n****\n");
		printf("Selecione: ");
		scanf("%d", &t);
		
		switch( t ){
		case 1:
			printf("\nEntrando na fila\nEntre com número: ");
			scanf("%d", &dado);
			entra(dado, &fila);
			printf("inserido\n");
			break;
		case 2:
			printf("\nSaindo da fila\n---\nValor: %d\n---\n", sai(&fila));
			break;
		case 3:
			printf("\nPeek\n---\nValor: %d\n---\n", peek(fila));
			break;
		case 4:
			imprimeLista( fila );
			break;		
		case 0:
			printf("\n---\nFIM\n");
			exit(0);
		}
	}
}

