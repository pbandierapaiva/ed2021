/*****************************************************************************
vetoresex4.c 

Dada uma sequência de n > 0 números reais, imprimi-los
eliminando as repetições.
***/

#include <stdio.h>

#define TAM_MAX 1000

void main() { 
	int n=0;
	int i=0, j=0;
	int repetido=0;
	int ind;
	
	float tmp;
	float vetor[TAM_MAX];
	
	printf("Quantos elementos? ");
	scanf("%d", &n );
	
	for(ind=0; ind<n; ind++){
		printf("> ");		
		scanf("%f", &tmp);
	
		repetido = 0;
		for(j=0;j< i; j++) {
			if( vetor[j] == tmp ) {
				repetido = 1;
				break;
				}	
			}
		if( !repetido ) {
			vetor[i]= tmp;
			i++;
			}
		}
	// imprime vetor resultante
	for(ind=0;ind<i;ind++) {
		printf("%f\n", vetor[ind]);
		}	
}
