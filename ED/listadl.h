//
// listadl.h
//
// Estrutura para Lista duplamente ligada: NOD

typedef struct NoD {
	int dado;
	struct NoD *ant;	
	struct NoD *prox;
	} NO; 
	
	
// Protótipos das funções

void imprimeLista( NO * );

// Pilha
void push( int , NO ** );
int pop( NO ** );
int peek( NO *);

// Fila
void entra( int , NO ** );
int sai( NO ** );

// Lista circular
void insere(int , NO ** );
int retira( NO ** );
int prox( NO ** );


