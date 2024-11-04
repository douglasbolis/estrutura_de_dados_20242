#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int min, int max, int seed) {
  return min + seed % (max - min + 1);
}

int main() {
  srand(time(NULL));

  int a = 10;
  int r = rand();

  printf("%d\n", r);
  printf("%d\n", randint(0, a-1, r));

  return 0;
}
