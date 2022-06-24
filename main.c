#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  FILE *arq;
  int d;
  char palavra[20], busca[20];

  arq = fopen("arq.txt", "a+");

  struct relatorio {
    char produtos[20];
    int quantidade;
  };

  struct relatorio estoque[100];

  if (arq == NULL) {
    printf("o arquivo nao existe");
    exit(0);
  }

  printf("digite a quantidade de produtos que serao gravados \n");
  scanf("%i", &d);

  for (int i = 0; i < d; i++) {
    printf("digite o nome do produto\n");
    scanf("%s", estoque[i].produtos);

    fprintf(arq, "%s", estoque[i].produtos);

    printf("digite a quantidade de produtos em estoque \n");
    scanf("%i", &estoque[i].quantidade);

    fprintf(arq, " %i \n", estoque[i].quantidade);
  }
 
  int m;
  printf(
      "digite a quantidade de produtos que necessitam trocar a quantidade \n");
  scanf("%d", &m);

  for (int g = 0; g < m; g++) {

    int linhas = 0;
    while (fgets(estoque[linhas].produtos, 20, arq) != NULL) {
      linhas++;
    }

    printf("digite o nome do produto \n");
    scanf("%s", palavra);
    int f;

    fclose(arq);

    fopen("arq.txt", "r");
    for (int h = 0; h < linhas; h++) {
      fscanf(arq, "%s %d", estoque[h].produtos, &estoque[h].quantidade);
      if (strcmp(estoque[h].produtos, palavra) == 0) {

        printf("digite a nova quantidade do item no estoque \n");
        scanf("%d", &f);

        estoque[h].quantidade = f;
      }
    }
    fclose(arq);

    fopen("arq.txt", "w");
    for (int h = 0; h < linhas; h++) {
      fprintf(arq, "%s %d \n", estoque[h].produtos, estoque[h].quantidade);
    }
    fclose(arq);
  }

  return 0;
}