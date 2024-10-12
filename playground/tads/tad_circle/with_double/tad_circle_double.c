#include "tad_circle_double.h"

Circle createCircle(double raio) {
  return raio;
}

double getCircuferencia(Circle c) {
  return 2 * 3.141592 * c;
}

double getArea(Circle c) {
  return 3.141592 * c * c;
}

double getRaio(Circle c) {
  return c;
}

double getDiametro(Circle c) {
  return c * 2;
}
