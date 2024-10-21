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

Tabela loadTabela(char *nomeArq) {
  Tabela tabela = newTabela();
  FILE *file = fopen(nomeArq, "r");

  while (!feof(file)) {
    char entrada[30];
    char placa[30];
    char marca[30];
    char modelo[30];
    char valorAux[30];
    double valor;

    // Placa
    fgets(entrada, 30, file);
    entrada[strlen(entrada) - 1] = '\0';
    strcpy(placa, entrada);

    // Marca
    fgets(entrada, 30, file);
    entrada[strlen(entrada) - 1] = '\0';
    strcpy(marca, entrada);

    // Modelo
    fgets(entrada, 30, file);
    entrada[strlen(entrada) - 1] = '\0';
    strcpy(modelo, entrada);

    // Valor
    fgets(entrada, 30, file);
    entrada[strlen(entrada) - 1] = '\0';
    strcpy(valorAux, entrada);
    valor = atof(valorAux);

    // Mais um veículo adicionado
    tabela.veiculos[tabela.tam] = criaVeiculo(placa, marca, modelo, valor);
  }

  fclose(file);

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
  if (strlen(v.placa) != 0) {
    printf("%s - %s %s - $%2.lf\n", v.placa, v.marca, v.modelo, v.valor);
  } else {
    printf("Veículo não encontrado.\n");
  }
}

void exibeVeiculos(Tabela t) {
  if (t.tam == 0) {
    printf("Nenhum veiculo encontrado.\n");
  }

  for (int i = 0; i < t.tam; i++) {
    exibeVeiculo(t.veiculos[i]);
  }
}
