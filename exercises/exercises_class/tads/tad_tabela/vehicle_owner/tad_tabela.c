#include<stdio.h>
#include<string.h>
#include "tad_tabela.h"

TabelaVeiculos loadTabelaVeiculos(char nomeArq[]) {
  TabelaVeiculos tab;
  FILE *arq = fopen(nomeArq, "rt");
  char *token;
  char entrada[100];

  tab.tam = 0;

  // Descartando primeira linha
  fgets(entrada, 100, arq);
  printf("\nLinha: %s", entrada);

  while (!feof(arq)) {
    fgets(entrada, 100, arq);
    printf("\nLinha: %s", entrada);
    entrada[strlen(entrada) - 1] = '\0';

    // Placa
    token = strtok(entrada, ",");
    strcpy(tab.veiculos[tab.tam].placa, token);

    // Marca
    token = strtok(NULL, ",");
    strcpy(tab.veiculos[tab.tam].marca, token);

    // Modelo
    token = strtok(NULL, ",");
    strcpy(tab.veiculos[tab.tam].modelo, token);

    // CPF do proprietario
    token = strtok(NULL, ",");
    strcpy(tab.veiculos[tab.tam].cpfProprietario, token);

    tab.tam++;
  }

  fclose(arq);

  return tab;
}

TabelaProprietarios loadTabelaProprietarios(char nomeArq[]) {
  TabelaProprietarios tab;
  FILE *arq = fopen(nomeArq, "rt");
  char *token;
  char entrada[100];

  tab.tam = 0;

  // Descartando primeira linha
  fgets(entrada, 100, arq);

  while (!feof(arq)) {
    fgets(entrada, 100, arq);
    entrada[strlen(entrada) - 1] = '\0';

    // CPF do proprietario
    token = strtok(entrada, ",");
    strcpy(tab.proprietarios[tab.tam].cpf, token);

    // Nome
    token = strtok(NULL, ",");
    strcpy(tab.proprietarios[tab.tam].nome, token);

    // E-mail
    token = strtok(NULL, ",");
    strcpy(tab.proprietarios[tab.tam].email, token);

    // Celular
    token = strtok(NULL, ",");
    strcpy(tab.proprietarios[tab.tam].celular, token);

    tab.tam++;
  }

  fclose(arq);

  return tab;
}

Proprietario buscaProprietario(TabelaProprietarios tabP, char nome[]) {
  Proprietario p;
  int i = 0;

  while (p.nome == NULL && i < tabP.tam) {
    if (strcmp(tabP.proprietarios[i].nome, nome) == 0) {
      p = tabP.proprietarios[i];
    }
    i++;
  }

  return p;
}

TabelaVeiculos filtraVeiculosProprietario(Proprietario p, TabelaVeiculos tabV) {
  TabelaVeiculos tabOwner;
  tabOwner.tam = 0;

  for (int i = 0; i < tabV.tam; i++) {
    if (strcmp(tabV.veiculos[i].cpfProprietario, p.cpf) == 0) {
      tabOwner.veiculos[tabOwner.tam] = tabV.veiculos[i];
      tabOwner.tam++;
    }
  }

  return tabOwner;
}

void exibeVeiculos(TabelaVeiculos tabV) {
  Veiculo v;

  for (int i = 0; i < tabV.tam; i++) {
    v = tabV.veiculos[i];
    printf("\n%s - %s - %s - %s", v.placa, v.marca, v.modelo, v.cpfProprietario);
  }
}

void exibeProprietarios(TabelaProprietarios tabP) {
  Proprietario v;

  for (int i = 0; i < tabP.tam; i++) {
    v = tabP.proprietarios[i];
    printf("\n%s - %s %s - %s", v.cpf, v.nome, v.email, v.celular);
  }
}

void exibeVeiculosProprietario(Proprietario p, TabelaVeiculos tabV) {
  Veiculo v;

  printf("\nProprietario: %s", p.nome);
  
  for (int i = 0; i < tabV.tam; i++) {
    v = tabV.veiculos[i];
    printf("\n%s - %s %s", v.placa, v.marca, v.modelo);
  }
}

void exibeVeiculosProprietarios(TabelaProprietarios tabP, TabelaVeiculos tabV) {
  TabelaVeiculos newTabV;
  Proprietario p;

  for (int i = 0; i < tabP.tam; i++) {
    p = tabP.proprietarios[i];
    newTabV = filtraVeiculosProprietario(p, tabV);
    exibeVeiculosProprietario(p, newTabV);
  }
}
