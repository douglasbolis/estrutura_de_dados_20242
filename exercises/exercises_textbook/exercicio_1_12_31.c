#include <stdio.h>
#include <stdlib.h>

float calculaPi (float precisao) {
  int i = 0;
  float pi = 0.0;
  float termo = 4/(2 * i + 1);

  while (termo >= precisao) {
    if (i % 2 == 0) {
      pi += termo;
    } else {
      pi -= termo;
    }

    i++;
    termo = 4.0/(2 * i + 1);
  }

  return pi;
}

int main () {
  float pi = 0.0;
  float precisao = 0.0001;

  pi = calculaPi(precisao);
  printf("Valor de PI: %f\n", pi);

  return 0;
}