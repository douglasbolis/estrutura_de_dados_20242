#ifndef __TAD_MATRIZ_DOUGLAS__
#define __TAD_MATRIZ_DOUGLAS__

#include "tadlista.h"

typedef struct t_matriz {
  int linhas;
  int colunas;
  Lista *dados;
} *tadmatriz;

tadmatriz cria_mat(int qlinhas, int qcolunas);
void set_elem(tadmatriz tadA, int linha, int coluna, float valor);
float get_elem(tadmatriz tadA, tint linha, int coluna);
int get_linhas(tadmatriz matA);
int get_colunas(tadmatriz matA);
tadmatriz soma(tadmatriz tadA, tadmatriz tadB);
tadmatriz multi(tadmatriz tadA, tadmatriz tadB);
tadmatriz neg(tadmatriz tadA);
tadmatriz transp(tadmatriz tadA);
tadmatriz carrega(char *filename);
tadmatriz salva(tadmatriz tadA, char *filename);

#endif
