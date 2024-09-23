#include <stdio.h>
#include <stdlib.h>

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

float seno (float a) {
  return a - (power(a, 3)/fatorial(3)) + (power(a, 5)/fatorial(5)) - (power(a, 7)/fatorial(7));
}

void showResult (float degree, float result) {
  printf("%.1f  | %3.3f\n", degree, result);
}

int main () {
  float senoA;
  printf("Grau | Seno de A\n");

  for (float i = 0.0; i <= 6.3; i += 0.1) {
    senoA = seno(i);
    showResult(i, senoA);
  }

  return 0;
}