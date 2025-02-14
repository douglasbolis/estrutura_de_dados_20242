#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadmatriz.h"
#include "tadlista.h"

tadmatriz cria_mat(int qlinhas, int qcolunas) {
  tadmatriz mat = (tadmatriz)malloc(sizeof(struct t_matriz));

  mat->linhas = qlinhas;
  mat->colunas = qcolunas;
  mat->dados = (Lista *)malloc(qlinhas * sizeof(Lista));

  for(int i = 0; i < qlinhas; i++) {
    mat->dados[i] = new_lista();

    for(int j = 0; j < qcolunas; j++) {
      float *dado = malloc(sizeof(float));
      *dado = 0.0;
      appendLista(mat->dados[i], dado);
    }
  }

  return mat;
}

void set_elem(tadmatriz tadA, int linha, int coluna, float valor) {
  if (tadA != NULL && linha >= 0 && linha < tadA->linhas && coluna >= 0 && coluna < tadA->colunas) {
    float *elem = elemLista(tadA->dados[linha], coluna);
    *elem = valor;
  }
}

float get_elem(tadmatriz tadA, int linha, int coluna) {
  float *elem = NULL;

  if (tadA != NULL && linha >= 0 && linha < tadA->linhas && coluna >= 0 && coluna < tadA->colunas) {
    elem = elemLista(tadA->dados[linha], coluna);
  }
  
  return *elem;
}

int get_linhas(tadmatriz matA) {
  int linhas = 0;

  if(matA!= NULL) {
    linhas = matA->linhas;
  }

  return linhas;
}

int get_colunas(tadmatriz matA) {
  int colunas = 0;

  if(matA!= NULL) {
    colunas = matA->colunas;
  }

  return colunas;
}

tadmatriz soma(tadmatriz tadA, tadmatriz tadB) {
  if(tadA == NULL || tadB == NULL || tadA->linhas != tadB->linhas || tadA->colunas != tadB->colunas) {
    return NULL;
  }

  tadmatriz tadS = cria_mat(tadA->linhas, tadA->colunas);
  float elemA = 0.0;
  float elemB = 0.0;
  float soma = 0.0;

  for(int i = 0; i < tadA->linhas; i++) {
    for(int j = 0; j < tadA->colunas; j++) {
      elemA = get_elem(tadA, i, j);
      elemB = get_elem(tadB, i, j);
      soma = elemA + elemB;
      set_elem(tadS, i, j, soma);
    }
  }

  return tadS;
}

tadmatriz multi(tadmatriz tadA, tadmatriz tadB) {
  if(tadA == NULL || tadB == NULL || tadA->colunas != tadB->linhas) {
    return NULL;
  }

  tadmatriz tadM = cria_mat(tadA->linhas, tadB->colunas);
  float elemA = 0.0;
  float elemB = 0.0;
  float soma = 0.0;

  for(int i = 0; i < tadA->linhas; i++) {
    for(int j = 0; j < tadB->colunas; j++) {
      soma = 0.0;

      for(int k = 0; k < tadA->colunas; k++) {
        elemA = get_elem(tadA, i, k);
        elemB = get_elem(tadB, k, j);
        soma += elemA * elemB;
      }

      set_elem(tadM, i, j, soma);
    }
  }
  return tadM;
}

tadmatriz neg(tadmatriz tadA) {
  float valor = 0.0;
  float novoValor = 0.0;

  if (tadA != NULL) {
    for(int i = 0; i < tadA->linhas; i++) {
      for(int j = 0; j < tadA->colunas; j++) {
        valor = get_elem(tadA, i, j);
        novoValor = -1 * valor;
        set_elem(tadA, i, j, novoValor);
      }
    }
  }

  return tadA;
}

tadmatriz transp(tadmatriz tadA) {
  if(tadA == NULL) {
    return tadA;
  }

  tadmatriz tadT = cria_mat(tadA->colunas, tadA->linhas);
  float valor = 0.0;

  for(int i = 0; i < tadA->linhas; i++) {
    for(int j = 0; j < tadA->colunas; j++) {
      valor = get_elem(tadA, i, j);
      set_elem(tadT, j, i, valor);
    }
  }

  return tadT;
}

tadmatriz carrega(char *filename) {
  FILE *arq1 = fopen(filename, "rt");
  char linha[64];
  char *token;
  int i = 0, linhas = 0;
  int j = 0, colunas = 0;

  while (!feof(arq1)) {
    fgets(linha, 64, arq1);

    // Fiz vários testes e para não contabilizar a última linha(sem informação) do arquivo tive que fazer essa verificação
    if (strlen(linha) > 6) {
      // Contabilizando o total de linhas da nova matriz
      linhas++;

      token = strtok(linha, " \t\n");

      while (token != NULL) {
        token = strtok(NULL, " \t\n");
        j++;
      }

      // Contabilizando o total de colunas da nova matriz
      if (colunas == 0) {
        colunas = j;
      }
    }
  }
  fclose(arq1);
  
  // Reabrindo novamento o arquivo
  FILE *arq2 = fopen(filename, "rt");
  tadmatriz mat = cria_mat(linhas, colunas);

  while (!feof(arq2)) {
    fgets(linha, 64, arq2);
    
    if (strlen(linha) > 6) {
      j = 0;

      token = strtok(linha, " \t\n");

      while(token != NULL && j < colunas) {
        float valor = atof(token);
        set_elem(mat, i, j, valor);
        token = strtok(NULL, " \t\n");
        j++;
      }

      i++;
    }
  }
  fclose(arq2);

  return mat;
}

tadmatriz salva(tadmatriz tadA, char *filename) {
  FILE *arq = fopen(filename, "w");
  float valor = 0.0;

  for (int i = 0; i < tadA->linhas; i++) {
    for (int j = 0; j < tadA->colunas; j++) {
      valor = get_elem(tadA, i, j);
      // Adiciona o valor do elemento no arquivo
      fprintf(arq, "\t%.2f", valor);
    }
    // Adiciona uma quebra de linha após cada linha
    fprintf(arq, "\n");
  }
  
  fclose(arq);

  return tadA;
}
