#include <stdio.h>
#include <stdlib.h>

int main () {
  int *p, i = 5;

  p = malloc(i * sizeof(int));

  for (int j = 0; j < i; j++) {
    *(p + j) = j * 10;
  }

  for (int j = 0; j < i; j++) {
    printf("%d\n", *(p + j));
  }

  free(p);

  printf("%p\n", p);

  return 0;
}
