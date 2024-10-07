#include <stdio.h>
#include <string.h>

int main() {
  char vet[10] = "Café";
  int tam = strlen(vet);

  printf("%s.\n", vet);
  printf("%d.\n", tam);

  for (int i = 0; i < tam; i++) {
    printf("%c", vet[i]);
  }

  return 0;
}