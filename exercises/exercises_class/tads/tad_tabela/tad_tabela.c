#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tad_tabela.h"

Tabela criaTabela() {
  int total = 10;
  char line[64];
  Veiculo veiculos[total] = [];
  Tabela tabela = { 0, total, veiculos };

  for (int i = 0; i < total; i++) {
    // Adiciona 1 veiculo
    tabela.tam++;
    // Placa
    fgets(line, 30, stdin);
    strcpy(tabela.veiculos[i].placa, line);
    // Marca
    fgets(line, 30, stdin);
    strcpy(tabela.veiculos[i].marca, line);
    // Modelo
    fgets(line, 30, stdin);
    strcpy(tabela.veiculos[i].modelo, line);
    // Valor
    fgets(line, 30, stdin);
    tabela.veiculos[i].modelo = atof(line);
  }

  return tabela;
}

Veiculo criaVeiculo(char[] placa, char[] marca, char[] modelo, double valor) {
  Veiculo c = { placa, marca, modelo, valor };

  return c;
}

Veiculo getVeiculoMaisCaro(Tabela tabela) {
  Veiculo aux;

  if (tabela.tam != 0) {
    for (int i = 1; i < tabela.total; i++) {
      if (tabela.veiculos[i].valor > aux.valor) {
        aux = tabela.veiculos[i];
      }
    }
  }

  return aux;
}

Veiculo getVeiculoMaisBarato(Tabela tabela) {
  Veiculo aux;

  if (tabela.tam != 0) {
    for (int i = 1; i < tabela.total; i++) {
      if (tabela.veiculos[i].valor < aux.valor) {
        aux = tabela.veiculos[i];
      }
    }
  }

  return aux;
}

Tabela filtraVeiculosPelaMarca(Tabela t, char[] marca) {
  Tabela auxTab = criaTabela();

  for (int i = 0; i < t.tam; i++) {
    if (strcmp(t.veiculos[i].marca, marca) == 0) {
      auxTab.veiculos[auxTab.tam] = t.veiculos[i];
      auxTab.tam++;
    }
  }

  return auxTab;
}

void exibeVeiculo(Veiculo v) {
  printf("Placa '%s' - Marca '%s' - Modelo '%s' - 'Valor' %2.lf\n", v.placa, v.marca, v.modelo, v.valor);
}

void exibeVeiculos(Tabela t) {
  for (int i = 0; i < t.tam; i++) {
    exibeVeiculo(t.veiculos[i]);
  }
}
