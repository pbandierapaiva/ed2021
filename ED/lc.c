//
// Arquivo para teste de implementação de Lista circular usando lista ligada

#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

void main() {
	int t;
	int  dado;
	
	NO *lc;
	
	lc = NULL;
	
	while(1) {
		printf("\n\n****\n1.Ins\n2.Del\n3.Prox\n4.Imprime\n0.Sai\n****\n");
		printf("Selecione: ");
		scanf("%d", &t);
		
		switch( t ){
		case 1:
			printf("\nEntrando na LC\nEntre com número: ");
			scanf("%d", &dado);
			insere(dado, &lc);
			printf("inserido\n");
			break;
		case 2:
			printf("\nRemovendo da LC\n---\nValor: %d\n---\n", retira(&lc));
			break;
		case 3:
			printf("\nPróximo\n---\nValor: %d\n---\n", prox(&lc));
			break;
		case 4:
			imprimeLista( lc );
			break;		
		case 0:
			printf("\n---\nFIM\n");
			exit(0);
		}
	}
}

