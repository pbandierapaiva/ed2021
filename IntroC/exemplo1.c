#include <stdio.h>

#define TAMANHO_MAX 200


void main() { 
	int i;
	char c;
	float f;
	int tam=0;
	float notas[TAMANHO_MAX];

	
	printf("Tamanho do int:   %d  valor: %d \tendereço: %p\n", sizeof( i ), i, &i );
	printf("Tamanho do char:  %d  valor: %c \tendereço: %p\n", sizeof( c ), c, &c );
	printf("Tamanho do float: %d  valor: %f \tendereço: %p\n", sizeof( f ), f, &f );
	printf("Tamanho do vetor: %d  valor: %f \tendereço: %p\n", sizeof( notas ), notas[0], notas );

	printf("\nEntre com o tamanho da amostra: ");
	scanf("%d", &tam);
	
	if( TAMANHO_MAX < tam ) {
		printf("Tamanho da amostra maior que TAMANHO_MAX.\n");
		return;
		}
	
	for( i=0; i<tam; i++ ) {
		printf("%d-> ", i);
		scanf("%f", &notas[i] );
		}
	for( i=0; i<tam; i++ ) {
		printf("\n%f", notas[i] );
		}
		
	printf("\n");
	

}



