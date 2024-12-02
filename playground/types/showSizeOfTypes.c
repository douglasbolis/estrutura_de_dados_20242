#include <stdio.h>
#include <values.h>

int main() {
  printf("sizeof(char) == %d\n", sizeof(char));
  printf("sizeof(short) == %d\n", sizeof(short));
  printf("sizeof(int) == %d\n", sizeof(int));
  printf("sizeof(long int) == %d\n", sizeof(long int));
  printf("sizeof(float) == %d\n", sizeof(float));
  printf("sizeof(double) == %d\n", sizeof(double));
  printf("sizeof(long double) == %d\n", sizeof(long double));
  // printf("Faixa do long double: Mínimo == %Lg *** Máximo == %Lg\n", LDBL_MIN, LDBL_MAX);
  printf("sizeof(long long) == %d\n", sizeof(long long));
  printf("sizeof(long) == %d\n", sizeof(long));

  return 0;
}
