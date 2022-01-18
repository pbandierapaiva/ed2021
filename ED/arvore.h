// Estrutura de dados de árvore binária

struct cel {
  int conteudo;
  struct cel *esq;
  struct cel *pai;
  struct cel *dir;
} ;
//
typedef struct cel NO;

typedef NO *arvore;

void insere(arvore *, int  );
arvore busca(arvore , int);
void travessia(arvore );
int altura(arvore );

arvore rotacaoDireita(arvore *);
arvore rotacaoEsquerda(arvore *);
