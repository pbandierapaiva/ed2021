
#include <stdio.h>

// alterando o valor da variável dentro de uma função
// passando a variável POR REFERÊNCIA
void func(int *n){

	*n=1000;
}



void main() { 
	int n=9;
	
	
	func( &n );

	printf("%d\n",n);
 	
	}




