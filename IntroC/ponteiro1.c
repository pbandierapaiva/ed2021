
#include <stdio.h>

// alterando o valor da variável dentro de uma função
// passando a variável POR REFERÊNCIA
void func(char *ptr){

	*ptr=100;
	printf("Endereço de ptr: %x %ud\n", (unsigned long)ptr, (unsigned long)ptr );
	
	ptr++;
	printf("Endereço de ptr: %x %ud\n", (unsigned long)ptr, (unsigned long)ptr );
	
}



void main() { 
	char n=9;
	
	
	func( &n );
	

	printf("%d\n",n);
 	
	}




