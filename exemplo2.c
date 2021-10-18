#include <stdio.h>

#define TAMANHO_MAX 200


void main() { 
	int i,j,k;
	int tamN, tamM;
	float m[TAMANHO_MAX], n[TAMANHO_MAX];
	float res[TAMANHO_MAX];

	printf("\nEntre com o tamanho da amostra N: ");
	scanf("%d", &tamN);
	printf("\nEntre com o tamanho da amostra M: ");
	scanf("%d", &tamM);
	
	if( TAMANHO_MAX < tamN ||  TAMANHO_MAX < tamM  ) {
		printf("Tamanho da amostra maior que TAMANHO_MAX.\n");
		return;
		}

	printf("\nLendo vetor N\n");	
	for( i=0; i<tamN; i++ ) {
		printf("%d-> ", i);
		scanf("%f", &n[i] );
		if(i>0) {
			if( n[i] < n[i-1] ) {
				printf("Erro na entrada\n");
				return;
				}
			}
		}
	printf("\nLendo vetor M\n");	
	for( i=0; i<tamM; i++ ) {
		printf("%d-> ", i);
		scanf("%f", &m[i] );
		if(i>0) {
			if( m[i] < m[i-1] ) {
				printf("Erro na entrada\n");
				return;
				}
			}
		}

	i=0;
	j=0;
	k=0;
	while(1) {
		if( i>=tamN ){
			for( ; j<tamM; j++) {
				res[k]=m[j];
				k++;
				}
			break;
			}
		if( j>=tamM ) {
			for( ; i<tamN; i++ ) {
				res[k]=n[i];
				k++;
				}
			break;
			}
		if(n[i]==m[j]) {
			res[k] = n[i];
			i++;
			j++;
			k++;
			}
		else {
			if( n[i] < m[j]) {
				res[k] = n[i];
				i++;
				} 
			else {
				res[k] = m[j];
				j++;
				}
			k++;
			}	
	} 

	for( i=0; i<k; i++ ) {
		printf("\n%f", res[i] );
		}
		
	printf("\n");
}
