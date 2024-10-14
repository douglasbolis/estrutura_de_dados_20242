#include <stdio.h>
#include "tad_tabela.h"

int main() {
  Tabela tab = criaTabela();
  Tabela veiculosFord;
  Veiculo v;

  printf("Veiculo mais caro:\n");
  v = getVeiculoMaisCaro(tab);
  exibeVeiculo(v);

  printf("Veiculo mais barato:\n");
  v = getVeiculoMaisBarato(tab);
  exibeVeiculo(v);

  veiculosFord = filtraVeiculosPelaMarca(tab, "FORD");
  exibeVeiculos(veiculosFord);

  return 0;
}
