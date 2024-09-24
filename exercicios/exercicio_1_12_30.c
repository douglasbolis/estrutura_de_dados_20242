#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float grauParaRad (int grau) {
  return grau * M_PI / 180;
}

double exponencial (float n, int exp) {
  double res = n;

  if (exp == 0) return 1;

  for (int i = 2; i < exp; i++) {
    res *= n;
  }

  return res;
}

long fatorial (int n) {
  long fat = 1;

  for (int i = n; i > 1; i--) {
    fat *= i;
  }

  return fat;
}

int normalizaAngulo (int grau) {
  int grau1aVolta = grau % 360;

  if (grau1aVolta <= 90) {
    return grau1aVolta;
  } else if (grau1aVolta <= 180) {
    return 180 - grau1aVolta;
  } else if (grau1aVolta <= 270) {
    return grau1aVolta - 180;
  } else {
    return 360 - grau1aVolta;
  }
}

double meuSeno (int angulo, int termos) {
  double termo = 0.0;
  double res = 0.0;
  float rad = 0.0;
  int novoAngulo = 0;
  int exp = 0;

  novoAngulo = normalizaAngulo(angulo);
  // rad = grauParaRad(angulo);
  rad = grauParaRad(novoAngulo);

  for (int i = 0; i < termos; i++) {
    exp = 2 * i + 1;
    termo = exponencial(rad, exp)/fatorial(exp);

    if (i % 2 == 0) {
      res += termo;
    } else {
      res -= termo;
    }
  }

  // return res;
  return angulo > 180 && angulo < 360 ? -res : res;
}

int main () {
  int cabecalho = 0;
  int termos = 33;
  double senoMeu = 0.0;
  double senoMat = 0.0;

  cabecalho = printf("Grau | Meu Seno  | Seno Real | Diferença\n");

  for (int i = 0; i < cabecalho; i++) {
    printf(i == 5 || i == 17 || i == 29 ? "|" : "-");
  }

  printf("\n");

  for (int angulo = 0; angulo <= 360; angulo++) {
    senoMeu = meuSeno(angulo, termos);
    senoMat = sin(grauParaRad(angulo));
    printf("%4d | %9f | %9f | %9f\n", angulo, senoMeu, senoMat, senoMeu - senoMat);
  }

  return 0;
}
