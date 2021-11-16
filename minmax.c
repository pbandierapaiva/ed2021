/*
	minmax.c

	Programa que lê um vetor de float e encontra os valores  max e min, usando alocação dinâmica
*/
#include <stdio.h>
#include <stdlib.h>


float *leVetor(int num) {
	float *p, *vet;
	
	float valor;
	
	printf("\nAlocando %d bytes\n", num*sizeof(float));
	
	vet = malloc( num * sizeof(float) );
				
	if( ! vet )    // Não conseguiu alocar espaço, retorna ponteiro nulo 
		return 0;
		
	p = vet;
	
	while( num>0 ) {
		printf("-> ");
		scanf("%f", &valor);
		*p = valor;
		num--;
		p++; // próximo endereço de inteiro no vetor
		}
	return vet;
}


void main() { 
	float *vetor, *p;
	int n;
	float max, min;
	
	printf("Entre tamanho da série: ");
	scanf("%d",&n);
	
	vetor = leVetor( n );
	
	if( ! vetor ) {
		printf("N maior que o tamanho disponível de memória \n\n");
		return;
		}
	
	p = vetor;
	// min e o max?	
	min = *p;
	max = *p;
	while( p < vetor + n )  {
		if( *p < min ) min = *p;
		if( *p > max ) max = *p;
		p++;
	} 
		
	printf("Min: %.2f\nMax: %.2f\n\n", min, max);		
		
//	imprimeVetor( n, valores );
	free( vetor ); 	
	}






