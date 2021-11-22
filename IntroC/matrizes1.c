/*****************************************************************************
matrizes1.c - Soma duas matrizes
*/


#include <stdio.h>

#define MAXLIN 100
#define MAXCOL 100

int main(){
	int A[MAXLIN][MAXCOL];		
	int B[MAXLIN][MAXCOL];		
	int C[MAXLIN][MAXCOL];

	int nLin, nCol;
	int i,j;
	int numero;
	
	// Solicita tamanho das matrizes
	printf("Soma de matrizes\nEntre com número de linhas das matrizes: ");
	scanf("%d", &nLin);
	printf("Entre com número de colunas das matrizes: ");
	scanf("%d", &nCol);
	if( nLin>MAXLIN || nCol>MAXCOL ) {
		printf("Você excedeu o número de linhas ou colunas permitidas (%d,%d)\n",MAXLIN, MAXCOL);
		return -1;
		}
	
	// Lê matriz A
	printf("Entre com dados da matriz A");
	for(i=0;i<nLin;i++) {
		printf("\nlinha %d ",i);
		for(j=0;j<nCol;j++) {
			printf("(%d,%d) -> ",i,j);
			scanf("%d", &numero);
			A[i][j] = numero;
			}
		}
	
	// Lê matriz B
	printf("Entre com dados da matriz B");
	for(i=0;i<nLin;i++) {
		printf("\nlinha %d ",i);
		for(j=0;j<nCol;j++) {
			printf("(%d,%d) -> ",i,j);
			scanf("%d", &numero);
			B[i][j] = numero;
			}
		}	
	// Soma A + B e coloca em C
	for(i=0;i<nLin;i++) {
		for(j=0;j<nCol;j++) {
			C[i][j] = A[i][j]+B[i][j];
			}	
		}
	
	// Imprime matriz C
	printf("\nSoma das matrizes A e B\n");	
	for(i=0;i<nLin;i++) {
		printf("\n");
		for(j=0;j<nCol;j++) {
			printf("%d\t",C[i][j]);
			}
		}
	

	printf("\n");

	return 0;
}
