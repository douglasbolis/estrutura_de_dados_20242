/*
  Escreva um programa para construir uma lista de UFs.
  Uma UF é uma tripla de nome da uf, sigla da uf, regiao da uf. 
  Crie um arquivo de dados do tipo csv com algumas ufs de exemplo.
  Leia o arquivo e armazene na lista.
  Por ultimo, solicite ao usuário uma região (ex:. se, ne, nt, sl) e 
  exiba todas as ufes cadastradas dessa regiao. 
  Sugestão: use o chatgpt para criar o arquivo de dados. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlista.h"

typedef struct {
  char nome[32];
  char sigla[4];
  char regiao[16];
} t_uf;

t_uf criaUf(char *entrada) {
  t_uf *puf = (t_uf *)malloc(sizeof(t_uf));
  char *token;

  entrada[strlen(entrada) - 1] = '\0';

  // Nome
  token = strtok(entrada, ",");
  strcpy(puf->nome, token);

  // Sigla
  token = strtok(NULL, ",");
  strcpy(puf->sigla, token);

  // Região
  token = strtok(NULL, ",");
  strcpy(puf->regiao, token);

  return puf;
}

Lista criaListaUf(char *nomeArq) {
  Lista listUf = criaLista();
  FILE *arq = fopen(nomeArq, "rt");
  t_uf *puf;
  char linha[64];

  // Descartando primeira linha
  fgets(linha, 64, arq);

  while (!feof(arq)) {
    fgets(linha, 64, arq);
    puf = criaUf(linha);
    appendLista(listUf, puf);
  }

  fclose(arq);

  return listUf;
}

Lista filtraUfRegiao(Lista listaUf, char *regiao) {
  Lista listaRegiao;

  for (int i = 0; i < lenLista(listaUf); i++) {
    t_uf *uf = dadoLista(listaUf, i);
    if (strcmp(uf->regiao, regiao) == 0) {
      appendLista(listaRegiao, uf);
    }
  }

  return listaRegiao;
}

void printUfs(Lista listaUf) {
  for (int i = 0; lenLista(listaUf); i++) {
    t_uf *uf = dadoLista(listaUf, i);
    printf("%s,%s,%s\n", uf->nome, uf->sigla, uf->regiao);
  }
}

int main() {
  char regiao[16];
  t_list_uf listUf = criaListaUf("list_ufs.csv");
  t_list_uf listRegiao;

  printf("Insira uma região (ex:. se, ne, nt, sl): ");
  scanf("%s", regiao);

  listRegiao = filtraUfRegiao(listUf, regiao);

  if (lenLista(listRegiao) == 0) {
    printf("Nenhum estado encontrado.\n");
  } else {
    printUfs(listRegiao);
  }

  return 0;
}
