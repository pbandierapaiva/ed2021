

typedef struct vizinho {
int id_vizinho;
struct vizinho *prox;
}TVizinho;

typedef struct grafo{
int id_vertice;
TVizinho *prim_vizinho;
struct grafo *prox;
}TGrafo;

void insereNo(TGrafo **g, int id) {
  TGrafo *novo, *ptr, *ant;

  novo = malloc(sizeof(TGrafo));
  novo->id_vertice = id;
  novo->prim_vizinho = NULL;
  novo->prox = NULL;

  ant =NULL;
  ptr = (*g);

  while(ptr!=NULL) {
      ant = ptr;
      ptr = ptr->prox;
  }
  if(ant!=NULL)
    ant->prox = novo
  else {
    *g = novo;
    return
  }
}

void insereAresta(TGrafo *g, int idOrigem, int idDestino) {
  TGrafo *ptr;
  TVizinho *viz,*ant, *novo;

  ptr = g;
  while(ptr!=NULL) {
    if( ptr->id_vertice== idOrigem ){
      viz = ptr->prim_vizinho;
      ant=NULL;
      while(viz!=NULL) {
          if(viz->id_vizinho==idDestino){
              return
          }
          ant=viz;
          viz = viz->prox;
      }
      novo = malloc(sizeof(TVizinho));
      novo->id_vizinho = idDestino;
      novo->prox=NULL;
      if( ant==NULL ) {
          ptr->prim_vizinho=novo;
        }
      else {
        ant->prox=novo;
      }

    }

  }



}

int main() {
  TGrafo *G=NULL;


}
