#include<stdio.h>
#include "tad_tabela.h"

int main() {
  TabelaProprietarios tabP = loadTabelaProprietarios("bdproprietarios.txt");
  // TabelaVeiculos tabV = loadTabelaVeiculos("bdveiculos.txt");

  exibeProprietarios(tabP);
  // exibeVeiculos(tabV);
  // exibeVeiculosProprietarios(tabP, tabV);

  return 0;
}
