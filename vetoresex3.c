/*****************************************************************************
vetoresex3.c 

Dados n > 0 lançamentos de uma roleta (números entre
0 e 36), calcular a frequência de cada número.

**/

#include <stdio.h>
#include <stdlib.h>

void main() { 
	int num;
	int n;
	int contadores[37];
	int i;
	
	for(i=0;i<37;i++) contadores[i] = 0; // preenche vetor com 0s
	
	printf("Quantos lançamentos? ");
	scanf("%d", &n );
	if(  n <= 0 ) {
		printf("Somente inteiros positivos");
		return;
		}
	 
	for(i=0; i < n ;i++) {	
		num = rand();		// gera num aleatório
		num = num % 37;      	// reduz para números entre 0 e 36
		
		contadores[num]++;
		}	

	for(i=0;i<37;i++) 
		printf("%d: %d\n", i, contadores[i]);
}


