#include<math.h>
#include "tad_rectangle_point.h"

Point createPoint(double a, double b) {
  Point p = { a, b }

  return p;
}

Rectangle createRectangle(char[] name, Point pointA, Point pointB) {
  Rectangle r = { name, pointA, pointB }

  return r;
}

Rectangle createRectangle(char[] name, double a, double b, double c, double d) {
  Point pa = createPoint(a, b);
  Point pb = createPoint(c, d);

  return createRectangle(name, pa, pb);
}

Rectangle createRectangle(double a, double b) {
  Point pa = createPoint(0, 0);
  Point pb = createPoint(a, b);

  return createRectangle("", pa, pb);
}

Point getPontoA(Rectangle r) {
  return r.pontoA;
}

Point getPontoB(Rectangle r) {
  return r.pontoB;
}

double getAltura(Rectangle r) {
  return abs(r.pontoB.y - r.pontoA.y);
}

double getLargura(Rectangle r) {
  return abs(r.pontoB.x - r.pontoA.x);
}

double getLadoMaior(Rectangle r) {
  double alt = getAltura(r);
  double larg = getLargura(r);

  return alt > larg ? alt : larg;
}

double getLadoMenor(Rectangle) {
  double alt = getAltura(r);
  double larg = getLargura(r);

  return alt < larg ? alt : larg;
}

double getArea(Rectangle r) {
  double alt = getAltura(r);
  double larg = getLargura(r);

  return alt * larg;
}

double getPerimetro(Rectangle r) {
  double alt = getAltura(r);
  double larg = getLargura(r);

  return 2 * alt + 2 * larg;
}

double getDiagonal(Rectangle r) {
  double alt = getAltura(r);
  double larg = getLargura(r);

  return sqrt(pow(alt, 2) + pow(larg, 2));
}
