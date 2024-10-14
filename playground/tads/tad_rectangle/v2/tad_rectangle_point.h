typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  char[21] name;
  Point pontoA;
  Point pontoB;
} Rectangle;

Rectangle createRectangle(char[], Point, Point);
Rectangle createRectangle(char[], double, double, double, double);
Rectangle createRectangle(double, double);

Point createPoint(double, double);
Point getPontoA(Rectangle);
Point getPontoB(Rectangle);

double getAltura(Rectangle);
double getLargura(Rectangle);
double getLadoMaior(Rectangle);
double getLadoMenor(Rectangle);

double getArea(Rectangle);
double getPerimetro(Rectangle);
double getDiagonal(Rectangle);
