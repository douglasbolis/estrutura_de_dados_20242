#include <stdio.h>
#include "tad_tabela.h"

int main() {
  Tabela tab = loadTabela("tad_tabela.txt");
  Tabela veiculosFord;
  Veiculo v;

  printf("Veiculo mais caro:\n");
  v = getVeiculoMaisCaro(tab);
  exibeVeiculo(v);

  printf("\nVeiculo mais barato:\n");
  v = getVeiculoMaisBarato(tab);
  exibeVeiculo(v);

  veiculosFord = filtraVeiculosPelaMarca(tab, "Ford");
  printf("\nVeiculos da marca Ford:\n");
  exibeVeiculos(veiculosFord);

  return 0;
}
