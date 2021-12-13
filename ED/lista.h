//
// lista.h
//
// Estrutura para Lista simplesmente ligada: NO

typedef struct No {
	int dado;
	struct No *prox;
	} NO; 
	
	
// Protótipos das funções

void imprimeLista( NO * );

// Pilha
void push( int , NO ** );
int pop( NO ** );
int peek( NO *);

//
