#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadmatriz.h"
#include "tadlista.h"

tadmatriz cria_mat(int qlinhas, int qcolunas) {
  tadmatriz mat = (tadmatriz)malloc(sizeof(struct t_matriz));

  mat->linhas = qlinhas;
  mat->colunas = qcolunas;
  mat->dados = (Lista)malloc(qlinhas * sizeof(Lista));

  for(int i = 0; i < qlinhas; i++) {
    mat->dados[i] = new_lista();

    for(int j = 0; j < qcolunas; j++) {
      t_dado *dado = (float *)malloc(sizeof(float));
      *dado = 0.0;
      appendLista(mat->dados[i], dado);
    }
  }

  return mat;
}

void set_elem(tadmatriz tadA, int linha, int coluna, float valor) {
  if (tadA != NULL && linha >= 0 && linha < tadA->linhas && coluna >= 0 && coluna < tadA->colunas) {
    t_dado *elem = elemLista(tadA->dados[linha], coluna);
    *elem = valor;
  }
}

float get_elem(tadmatriz tadA, int linha, int coluna) {
  if (tadA == NULL || linha < 0 || linha >= tadA->linhas || coluna < 0 || coluna >= tadA->colunas) {
    return NULL;
  }
  
  return elemLista(tadA->dados[linha], coluna);
}

int get_linhas(tadmatriz matA) {
  return matA.linhas;
}

int get_colunas(tadmatriz matA) {
  return matA.colunas;
}

tadmatriz soma(tadmatriz tadA, tadmatriz tadB) {
  
}

tadmatriz multi(tadmatriz tadA, tadmatriz tadB) {
  
}

tadmatriz neg(tadmatriz tadA) {
  
}

tadmatriz transp(tadmatriz tadA) {
  
}

tadmatriz carrega(char *filename) {
  
}

tadmatriz salva(tadmatriz tadA, char *filename) {
  
}
