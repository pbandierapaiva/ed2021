
#include <stdio.h>


#define TAM_MAX 1000

void leVetor(int num, int *vet) {
	int val;	
	while( num>0 ) {
		scanf("%d", &val);
		*vet = val;
		num--;
		vet++; // próximo endereço de inteiro no vetor
		}
}

void leVetorPorIndice(int num, int *vet) {
	int val;	
	int i=0;
	
	while( i<num) {
		scanf("%d", &val);
		vet[i] = val;
		i++;
		}
}

void imprimeVetor(int num, int *vet) {
	while( num>0 ) {
		printf("%d\n", *vet);
		vet++;
		num--;
		}
}

void main() { 
	int valores[TAM_MAX];
	int n;
	
	printf("Entre tamanho da série: ");
	scanf("%d",&n);
	
	if( n > TAM_MAX) {
		printf("N maior que o tamanho máximo permitido %d\n\n", TAM_MAX);
		return;
		}
	
	leVetor( n, valores );
 	
 	imprimeVetor( n, valores );
 	
	}




