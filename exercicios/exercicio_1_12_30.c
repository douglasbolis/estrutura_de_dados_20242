#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

float degreeToRad (int degree) {
  return degree * PI / 180;
}

float power (float a, int n) {
  float res = a;

  for (int i = 2; i < n; i++) {
    res = res * a;
  }

  return res;
}

int fatorial (int n) {
  int fat = 1;

  for (int i = n; i > 1; i--) {
    fat *= i;
  }

  return fat;
}

float seno (int a) {
  float res = a;
  float rad = degreeToRad(a);

  res = rad - (power(rad, 3)/fatorial(3)) + (power(rad, 5)/fatorial(5)) - (power(rad, 7)/fatorial(7));

  return res;
}

void showResult (int degree, float result) {
  printf("%3d  | %3.6f | %3.6f\n", degree, result, sin(degreeToRad(degree)));
}

int main () {
  float senoA;
  printf("Grau | Meu Seno | Seno Real\n");

  for (int i = 0; i <= 360; i++) {
    senoA = seno(i);
    showResult(i, senoA);
  }

  return 0;
}
