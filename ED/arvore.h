// Estrutura de dados de árvore binária

struct cel {
  int conteudo;
  struct cel *pai;
  struct cel *esq;
  struct cel *dir;
};

typedef struct cel NO;

typdef struct NO *arvore;
