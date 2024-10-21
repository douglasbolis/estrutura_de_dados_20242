#include "tad_tabela.c"

TabelaVeiculo newTabelaVeiculos() {
  TabelaVeiculos tab;
  tab.tam = 0;

  return tab;
}

TabelaVeiculo loadTabelaVeiculos(char *nomeArq) {
  TabelaVeiculos tab = newTabelaVeiculos();
  FILE *arq = fopen(nomeArq, "r");
  const char s[2] = "-";
  char *token;
  char entrada[128];

  // Descartando primeira linha
  fgets(entrada, 128, arq);

  while (!feof(arq)) {
    fgets(entrada, 128, arq);
    entrada[strlen(entrada) - 1] = '\0'

    // Placa
    token = strtok(entrada, s);
    strcpy(tab.veiculos[tab.aux].placa, token);

    // Marca
    token = strtok(entrada, s);
    strcpy(tab.veiculos[tab.aux].marca, token);

    // Modelo
    token = strtok(entrada, s);
    strcpy(tab.veiculos[tab.aux].modelo, token);

    // CPF do proprietario
    token = strtok(entrada, s);
    strcpy(tab.veiculos[tab.aux].cpfProprietario, token);

    tab.aux++;
  }

  fclose(arq);

  return tab;
}

TabelaProprietario loadTabelaProprietarios(char *nomeArq) {
  TabelaProprietarios tab = newTabelaProprietarios();
  FILE *arq = fopen(nomeArq, "r");
  const char s[2] = "-";
  char *token;
  char entrada[128];

  // Descartando primeira linha
  fgets(entrada, 128, arq);

  while (!feof(arq)) {
    fgets(entrada, 128, arq);
    entrada[strlen(entrada) - 1] = '\0'

    // CPF do proprietario
    token = strtok(entrada, s);
    strcpy(tab.proprietarios[tab.aux].cpf, token);

    // Nome
    token = strtok(entrada, s);
    strcpy(tab.proprietarios[tab.aux].nome, token);

    // E-mail
    token = strtok(entrada, s);
    strcpy(tab.proprietarios[tab.aux].email, token);

    // Celular
    token = strtok(entrada, s);
    strcpy(tab.proprietarios[tab.aux].celular, token);

    tab.aux++;
  }

  fclose(arq);

  return tab;
}

Proprietario buscaProprietario(TabelaProprietario tabP, char nome[]) {
  Proprietario p;
  int i = 0;

  while (p == NULL && i < tabP.tam) {
    if (strcmp(tabP.proprietarios[i].nome, nome) == 0) {
      p = tabP.proprietarios[i];
    }
    i++;
  }

  return p;
}

TabelaVeiculos filtraVeiculosProprietario(Proprietario p, TabelaVeiculos tabV);

void listaVeiculos(TabelaVeiculos);
void listaProprietarios(TabelaProprietario);

void listaVeiculosProprietario(Proprietario, TabelaVeiculos);
void listaVeiculosProprietarios(TabelaProprietario, TabelaVeiculos);