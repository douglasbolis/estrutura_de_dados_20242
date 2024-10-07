#include <stdio.h>
#include <math.h>

typedef struct {
  int a;
  int b;
} NumComplexo;

NumComplexo somaComplexos(NumComplexo numX, NumComplexo numY) {
  NumComplexo res = { numX.a + numY.a, numX.b + numY.b };
  return res;
}

int main () {
  NumComplexo numA = { 5, 7 };
  NumComplexo numB = { 3, -12 };
  NumComplexo soma;

  printf("Numero complexo A: %d + %di\n", numA.a, numA.b);
  printf("Numero complexo B: %d + %di\n", numB.a, numB.b);

  soma = somaComplexos(numA, numB);

  printf("Resultado de A + B: %d + %di\n", soma.a, soma.b);

  return 0;
}
