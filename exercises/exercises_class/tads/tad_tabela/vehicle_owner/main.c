#include<stdio.h>
#include "tad_tabela.h"

int main() {
  TabelaProprietarios tabP = loadTabelaProprietarios("bdproprietarios.txt");
  TabelaVeiculos tabV = loadTabelaVeiculos("bdveiculos.txt");

  // printf("Proprietarios\n");
  // exibeProprietarios(tabP);
  // printf("\nVeiculos\n");
  // exibeVeiculos(tabV);

  printf("=== x Proprietarios x Veiculos x ===\n");
  exibeVeiculosProprietarios(tabP, tabV);

  return 0;
}
