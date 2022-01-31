// Arcabouço para programa de coleta e processamento
// de dados de avaliação

#include <stdio.h>
#include <stdlib.h>

int main() {
  int nal,nav, val;

  printf("Quantidade de alunos: ");
  scanf("%d",&nal);
  printf("Número de avaliações: ");
  scanf("%d",&nav);

  // alocação dinâmica de memória

  for(int i=0;i<nav;i++) {
    printf("\n---\nAvaliação %d\n", i+1);
    for(int j=0;j<nal;j++){
      printf("%d > ",j+1);
      scanf("%d", &val);
      //
      // Processamento das entradas
      //
    }

  printf("\nResultado final:")
  // processamento e impressão dos resultados

  }

}
