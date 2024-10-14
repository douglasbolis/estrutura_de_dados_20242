#include<math.h>
#include "tad_rectangle.h"

Rectangle createRectangle(double a, double b) {
  Rectangle r = { a, b };
  return r;
}

double getArea(Rectangle r) {
  return r.ladoA * r.ladoB;
}

double getPerimetro(Rectangle r) {
  return 2 * r.ladoA + 2 * r.ladoB;
}

double getLadoMaior(Rectangle r) {
  return r.ladoA > r.ladoB ? r.ladoA : r.ladoB;
}

double getLadoMenor(Rectangle r) {
  return r.ladoA < r.ladoB ? r.ladoA : r.ladoB;
}

double getDiagonal(Rectangle r) {
  return sqrt(pow(r.ladoA, 2) + pow(r.ladoB, 2));
}
