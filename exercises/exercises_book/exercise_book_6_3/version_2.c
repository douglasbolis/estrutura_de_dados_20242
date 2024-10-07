#include <stdio.h>
# include <math.h>

typedef struct {
  int x;
  int y;
} Point;

Point getPoint(char message[]) {
  Point point;

  printf("%s [x y] ", message);
  scanf("%d %d", &point.x, &point.y);

  return point;
}

double getDistance(Point P, Point Q) {
  double a = pow(Q.x - P.x, 2);
  double b = pow(Q.y - P.y, 2);

  return pow(a + b, 0.5);
}

int main() {
  Point P, Q;
  double d = 0.0;

  P = getPoint("Diga os valores para o ponto P:");
  Q = getPoint("Diga os valores para o ponto Q:");

  printf("\nPontos inseridos no plano:");
  printf("\nP: (%d, %d)", P.x, P.y);
  printf("\nQ: (%d, %d)", Q.x, Q.y);

  d = getDistance(P, Q);

  printf("\nDistancia entre os pontos: %.2f.", d);

  return 0;
}