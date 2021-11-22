/*****************************************************************************
matrizes2.c - Multiplica duas matrizes
*/


#include <stdio.h>

#define MAXLIN 100
#define MAXCOL 100

int main(){
	int A[MAXLIN][MAXCOL];		
	int B[MAXLIN][MAXCOL];		
	int C[MAXLIN][MAXCOL];

	int nLinA, nColA, nLinB, nColB;
	int i,j,k,l;
	int numero;
	
	// Solicita tamanho das matrizes
	printf("Multiplicação de matrizes\n");
	printf("Entre com número de linhas da matriz A: ");
	scanf("%d", &nLinA);
	printf("Entre com número de colunas da matriz A: ");
	scanf("%d", &nColA);
	printf("Entre com número de linhas da matriz B: ");
	scanf("%d", &nLinB);
	printf("Entre com número de colunas da matriz B: ");
	scanf("%d", &nColB);
	
	if( nLinA>MAXLIN || nColA>MAXCOL || nLinB>MAXLIN || nColB>MAXCOL) {
		printf("Você excedeu o número de linhas ou colunas permitidas (%d,%d)\n",MAXLIN, MAXCOL);
		return -1;
		}
	if( nLinA != nColB || nColA != nLinB )	{
		printf("Os números de linha e coluna das matrizes têm que permitir multiplixação\n");
		printf("Matriz A (%d x %d) e Matriz B (%d x %d)\n",nLinA,nColA,nLinB,nColB);
		return -1;
		}
	
	// Lê matriz A
	printf("Entre com dados da matriz A");
	for(i=0;i<nLinA;i++) {
		printf("\nlinha %d ",i);
		for(j=0;j<nColA;j++) {
			printf("A(%d,%d) -> ",i,j);
			scanf("%d", &numero);
			A[i][j] = numero;
			}
		}
	
	// Lê matriz B
	printf("Entre com dados da matriz B");
	for(i=0;i<nLinB;i++) {
		printf("\nlinha %d ",i);
		for(j=0;j<nColB;j++) {
			printf("B(%d,%d) -> ",i,j);
			scanf("%d", &numero);
			B[i][j] = numero;
			}
		}	
		
	// C ( nLinA x nColB )
	for(i=0;i<nLinA;i++) {
		for(j=0;j<nColB;j++) {			
			for(k=0;k<nColA;k++) {
				C[i][j] += A[i][k]*B[k][j];
				}	
			}
		}
	
	
	// Imprime matriz C
	printf("\nSoma das matrizes A e B\n");	
	for(i=0;i<nLinA;i++) {
		printf("\n");
		for(j=0;j<nColB;j++) {
			printf("%d\t",C[i][j]);
			}
		}
	

	printf("\n");

	return 0;
}
