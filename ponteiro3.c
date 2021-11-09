/*
	Exemplo de alocação dinâmica de memória
*/
#include <stdio.h>
#include <stdlib.h>


int *leVetor(int num) {
	int *p, *vet;
	int val;
	
	printf("\nAlocando %d bytes\n", num*sizeof(int));
	vet = malloc( num * sizeof(int) );		
	if( ! vet ) {   // Não conseguiu alocar espaço, retorna ponteiro nulo 
		return vet;
		}
	p = vet;
	
	while( num>0 ) {
		printf("-> ");
		scanf("%d", &val);
		*p = val;
		num--;
		p++; // próximo endereço de inteiro no vetor
		}
	return vet;
}

void imprimeVetor(int num, int *vet) {
	printf("\n\nVetor:\n");
	while( num>0 ) {
		printf("%d\n", *vet);
		vet++;
		num--;
		}
}

float media(int num, int *v) {
	int acum=0;
	
	for( int i=0;i<num;i++) {
		acum += v[i];
		}
	return acum/num;
}

void main() { 
	int *valores;
	int n;
	
	printf("Entre tamanho da série: ");
	scanf("%d",&n);
	
	valores = leVetor( n );
	
	if( ! valores ) {
		printf("N maior que o tamanho disponível de memória \n\n");
		return;
		}
		
	printf("Média %f\n", media(n, valores));	
		
		
		
	imprimeVetor( n, valores );

	free(valores); 	
	}




