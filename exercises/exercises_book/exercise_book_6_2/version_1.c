#include <stdio.h>
#include <math.h>

typedef struct {
  int a;
  int b;
} NumComplexo;

int main () {
  NumComplexo numA = { 0, 0 };
  NumComplexo numB = { 0, 0 };

  printf("Numero complexo A: %d + %di\n", numA.a, numA.b);
  printf("Numero complexo B: %d + %di\n", numB.a, numB.b);

  return 0;
}
