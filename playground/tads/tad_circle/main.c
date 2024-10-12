#include <stdio.h>
#include "./with_struct/tad_circle_struct.h"
// #include "./without_struct/tad_circle_double.h"

int main() {
  Circle circle = createCircle(2.5);

  printf("Circulo:\n- Raio: %.2lf\n- Area: %.2lf", getRaio(circle), getArea(circle));

  return 0;
}