#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "tadmatriz.h"

tadmatriz carregaMatriz(char *matriz) {
  tadmatriz matInter, matResult = NULL;
  char filename[16];

  if (matriz[0] == '-') {
    strcpy(filename, &matriz[1]);
    strcat(filename, ".txt");

    matInter = carrega(filename);
    matResult = neg(matInter);
  } else if (matriz[0] == 'T') {
    strcpy(filename, &matriz[1]);
    strcat(filename, ".txt");

    matInter = carrega(filename);
    matResult = transp(matInter);
  } else {
    strcpy(filename, &matriz[0]);
    strcat(filename, ".txt");

    matResult = carrega(filename);
  }

  return matResult;
}

void processaLinha(char *linha) {
  tadmatriz matA, matB, matAux, matResult = NULL;

  char operacao[3][3];
  char *token;
  char filenameAux[32] = "";

  // Divide a linha em tokens separados por espaço
  // Matriz 1
  token = strtok(linha, " \n");
  strcpy(operacao[0], token);
  // Operador
  token = strtok(NULL, " \n");
  strcpy(operacao[1], token);
  // Matriz 2
  token = strtok(NULL, " \n");
  strcpy(operacao[2], token);

  matA = carregaMatriz(operacao[0]);
  matB = carregaMatriz(operacao[2]);

  if (operacao[1][0] == '+') {
    matResult = soma(matA, matB);
  } else if (operacao[1][0] == '-') {
    matAux = neg(matB);
    matResult = soma(matA, matAux);
  } else if (operacao[1][0] == 'x') {
    matResult = multi(matA, matB);
  }

  // Gerando nome do arquivo de saída
  if (strlen(operacao[0]) > 1) {
    if (operacao[0][0] == '-') {
      strcat(filenameAux, "menos");
    } else if (operacao[0][0] == '+') {
      strcat(filenameAux, "mais");
    } else if (operacao[0][0] == 'x') {
      strcat(filenameAux, "vezes");
    } else if (operacao[0][0] == 'T') {
      strcat(filenameAux, "transp");
    }
    strcat(filenameAux, &operacao[0][1]);
  } else {
    strcat(filenameAux, &operacao[0][0]);
  }

  if (operacao[1][0] == '-') {
    strcat(filenameAux, "menos");
  } else if (operacao[1][0] == '+') {
    strcat(filenameAux, "mais");
  } else if (operacao[1][0] == 'x') {
    strcat(filenameAux, "vezes");
  }

  if (strlen(operacao[2]) > 1) {
    if (operacao[2][0] == '-') {
      strcat(filenameAux, "menos");
    } else if (operacao[2][0] == '+') {
      strcat(filenameAux, "mais");
    } else if (operacao[2][0] == 'x') {
      strcat(filenameAux, "vezes");
    } else if (operacao[2][0] == 'T') {
      strcat(filenameAux, "transp");
    }
    strcat(filenameAux, &operacao[2][1]);
  } else {
    strcat(filenameAux, &operacao[2][0]);
  }

  strcat(filenameAux, ".txt");
  salva(matResult, filenameAux);
}

int main() {
  FILE *arq = fopen("matops.txt", "rt");
  char linha[64];

  while (!feof(arq)) {
    fgets(linha, 64, arq);
    processaLinha(linha);
  }

  fclose(arq);

  return 0;
}
