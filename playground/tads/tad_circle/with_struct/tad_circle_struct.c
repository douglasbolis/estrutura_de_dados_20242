#include "tad_circle_struct.h"

Circle createCircle(double raio) {
  Circle c = { raio };
  return c;
}

double getCircuferencia(Circle c) {
  return 2 * 3.141592 * c.raio;
}

double getArea(Circle c) {
  return 3.141592 * c.raio * c.raio;
}

double getRaio(Circle c) {
  return c.raio;
}

double getDiametro(Circle c) {
  return c.raio * 2;
}
