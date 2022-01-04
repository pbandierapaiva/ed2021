//
// Arquivo para teste de implementação de Lista DUPLAMENTE LIGADA

#include "listadl.h"

#include <stdio.h>
#include <stdlib.h>

void main() {
	int t;
	int  dado;

	NOD *dl;

	dl = NULL;

	printf("Pilha (1) / Lista circular (2) / Fila com prioridade (3)? ");
	scanf("%d", &t);

		switch(t) {
	// Pilha
		case 1:
				while(1) {
					printf("\n\n****\n1.Push\n2.Pop\n3.Peek\n4.Imprime\n0.Sai\n****\n");
					printf("Selecione: ");
					scanf("%d", &t);

					switch( t ){
					case 1:
						printf("Entre com número: ");
						scanf("%d", &dado);
						push(dado, &dl);
						printf("inserido\n");
						break;
					case 2:
						printf("\n\nValor: %d\n---\n", pop(&dl));
						break;
					case 3:
						printf("\n\nValor: %d\n---\n", peek(dl));
						break;
					case 4:
						imprimeLista( dl );
						break;
					case 0:
						printf("\n---\nFIM\n");
						exit(0);
					}
				}
			break;
	// Lista circular
	case 2:
			while(1) {
				printf("\n\n****\n1.Insere\n2.Prox\n3.Peek\n4.Imprime\n0.Sai\n****\n");
				printf("Selecione: ");
				scanf("%d", &t);

				switch( t ){
				case 1:
					printf("Entre com número: ");
					scanf("%d", &dado);
					insere(dado, &dl);
					printf("inserido\n");
					break;
				case 2:
					printf("\n\nValor: %d\n---\n", prox(&dl));
					break;
				case 3:
					printf("\n\nValor: %d\n---\n", dl->dado  );
					break;
				case 4:
					imprimeLista( dl );
					break;
				case 0:
					printf("\n---\nFIM\n");
					exit(0);
				}
			}
		break;
	case 3:
		FCP filaComPrioridade;
		filaComPrioridade.prior = NULL;
		filaComPrioridade.comum = NULL;

		while(1) {

			printf("\n\n****\n1.Insere PRIORITÁRIO\n2.Insere COMUM\n3.Retira\n4.Imprime\n0.Sai\n****\n");
			printf("Selecione: ");
			scanf("%d", &t);

			switch( t ){
					case 1:
						printf("Entre com número: ");
						scanf("%d", &dado);
						entraFCP(dado, &filaComPrioridade, 1);
						break;
					case 2:
						printf("Fila comum, entre com número: ");
						scanf("%d", &dado);
						entraFCP(dado, &filaComPrioridade, 0);
						break;
					case 3:
						printf("\n\nValor: %d\n---\n", saiFCP(&filaComPrioridade));
						break;
					case 4:
						imprimeListasPrioridade(&filaComPrioridade);
						break;
					case 0:
						printf("\n---\nFIM\n");
						exit(0);

					}
			}
		}
}
