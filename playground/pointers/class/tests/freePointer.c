#include <stdio.h>
#include <stdlib.h>

int main () {
  int i = 5, *p;

  p = &i;
  free(p);

  printf("%d", *p);

  return 0;
}
