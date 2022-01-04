//
// listadl.h
//
// Estrutura para Lista duplamente ligada: NOD

typedef struct NoDL {
	int dado;
	struct NoDL *ant;
	struct NoDL *prox;
} NOD;

// Fila com prioridade
typedef struct  {
	NOD *prior;
	NOD *comum;
} FCP;

// Protótipos das funções

void imprimeLista( NOD * );

// Pilha
void push( int , NOD ** );
int pop( NOD ** );
int peek( NOD *);

// Fila
void entra( int , NOD ** );
int sai( NOD ** );

// Lista circular
void insere(int , NOD ** );
int retira( NOD ** );
int prox( NOD ** );

// Lista com prioridade
void imprimeListasPrioridade( FCP *);
void entraFCP( int , FCP *, int );
int saiFCP(FCP *);
