#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double grauParaRad (int grau) {
  return grau * M_PI / 180.0;
}

double exponencial (double n, int exp) {
  double res = n;

  if (exp == 0) return 1;

  for (int i = 1; i < exp; i++) {
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

double senoMacLaurin(double x, int termos) {
  double seno = 0.0;
  int sinal = 0;
  int expoente = 0;

  for (int i = 0; i < termos; i++) {
    sinal = (i % 2 == 0) ? 1 : -1;
    expoente = 2 * i + 1;
    seno += sinal * (exponencial(x, expoente) / fatorial(expoente));
  }

  return seno;
}

int main () {
  int termos = 10;
  int cabecalho = 0;
  double senoMeu = 0.0;
  double senoMat = 0.0;
  double anguloRad = 0.0;
  double diferenca = 0.0;

  cabecalho = printf("Grau | Meu Seno  | Seno Real | Diferença\n");

  for (int i = 0; i < (cabecalho - 2); i++) {
    printf(i == 5 || i == 17 || i == 29 ? "|" : "-");
  }

  printf("\n");

  for (int angulo = 0; angulo <= 360; angulo++) {
    anguloRad = grauParaRad(angulo);
    senoMeu = senoMacLaurin(anguloRad, termos);
    senoMat = sin(anguloRad);
    diferenca = fabs(senoMeu - senoMat);

    printf("%4d | %9f | %9f | %8f\n", angulo, senoMeu, senoMat, diferenca);
  }

  return 0;
}
