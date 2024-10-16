#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tad_tabela.h"

Tabela newTabela() {
  Tabela taAux;
  taAux.tam = 0;
  taAux.total = 10;

  return taAux;
}

Tabela criaTabela() {
  Tabela tabela = newTabela();
  Veiculo Veiculo;
  char entrada[30];

  for (int i = 0; i < tabela.total; i++) {
    char valorAux[30] = "";

    // Placa
    fgets(entrada, 30, stdin);
    entrada[strlen(entrada) - 1] = '\0';
    strcpy(tabela.veiculos[i].placa, entrada);

    // Marca
    fgets(entrada, 30, stdin);
    entrada[strlen(entrada) - 1] = '\0';
    strcpy(tabela.veiculos[i].marca, entrada);

    // Modelo
    fgets(entrada, 30, stdin);
    entrada[strlen(entrada) - 1] = '\0';
    strcpy(tabela.veiculos[i].modelo, entrada);

    // Valor
    fgets(entrada, 30, stdin);
    entrada[strlen(entrada) - 1] = '\0';
    strcpy(valorAux, entrada);
    tabela.veiculos[i].valor = atof(valorAux);

    // Mais um veículo adicionado
    tabela.tam++;
  }

  return tabela;
}

Veiculo criaVeiculo(char placa[], char marca[], char modelo[], double valor) {
  Veiculo c;

  strcpy(c.placa, placa);
  strcpy(c.marca, marca);
  strcpy(c.modelo, modelo);
  c.valor = valor;

  return c;
}

Veiculo getVeiculoMaisCaro(Tabela tabela) {
  Veiculo aux;

  if (tabela.tam != 0) {
    aux = tabela.veiculos[0];

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
    aux = tabela.veiculos[0];

    for (int i = 1; i < tabela.total; i++) {
      if (tabela.veiculos[i].valor < aux.valor) {
        aux = tabela.veiculos[i];
      }
    }
  }

  return aux;
}

Tabela filtraVeiculosPelaMarca(Tabela t, char marca[]) {
  Tabela tabAux = newTabela();

  for (int i = 0; i < t.tam; i++) {
    if (strcmp(t.veiculos[i].marca, marca) == 0) {
      tabAux.veiculos[tabAux.tam] = t.veiculos[i];
      tabAux.tam++;
    }
  }

  return tabAux;
}

void exibeVeiculo(Veiculo v) {
  printf("%s - %s %s - $%2.lf\n", v.placa, v.marca, v.modelo, v.valor);
}

void exibeVeiculos(Tabela t) {
  for (int i = 0; i < t.tam; i++) {
    exibeVeiculo(t.veiculos[i]);
  }
}
