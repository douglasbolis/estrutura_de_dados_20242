#include<stdio.h>
#include "tad_rectangle.h"

int main() {
  Rectangle r = createRectangle(1.5, 2.5);

  printf("Retangulo: \n");
  printf("- Lado maior: %.2lf\n", getLadoMaior(r));
  printf("- Lado menor: %.2lf\n", getLadoMenor(r));
  printf("- Area: %.2lf\n", getArea(r));
  printf("- Perimetro: %.2lf\n", getPerimetro(r));
  printf("- Diagonal: %.2lf\n", getDiagonal(r));

  return 0;
}
