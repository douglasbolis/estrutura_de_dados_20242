#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  char placa[8];
  char marca[16];
  char modelo[16];
  char cpfProprietario[32];
} t_item_v;

typedef struct {
  char cpf[32];
  char nome[64];
  char email[64];
  char celular[32];
} t_item_p;

typedef struct {
  char placa[10];
  char data[10];
  float valor;
} t_item_m;

typedef struct {
  int tam;
  int total;
  t_item_v veiculos[100];
} t_tab_v;

typedef struct {
  int tam;
  int total;
  t_item_p proprietarios[100];
} t_tab_p;

typedef struct {
  int tam;
  int total;
  t_item_m multas[100];
} t_tab_m;

t_tab_v loadTabV(char fileName[]) {
  FILE *arq = fopen(fileName, "rt");
  int tamLinha = 128;
  char *token;
  char linha[tamLinha];

  t_tab_v tabV;
  tabV.tam = 0;
  tabV.total = 100;

  // Descartando primeira linha
  fgets(linha, tamLinha, arq);

  // Processa até chegar ao fim do arquivo ou atingir 100 itens
  while (!feof(arq) && (tabV.tam < tabV.total)) {
    fgets(linha, tamLinha, arq);
    linha[strlen(linha) - 1] = '\0';

    // Placa
    token = strtok(linha, ",");
    strcpy(tabV.veiculos[tabV.tam].placa, token);

    // Marca
    token = strtok(NULL, ",");
    strcpy(tabV.veiculos[tabV.tam].marca, token);

    // Modelo
    token = strtok(NULL, ",");
    strcpy(tabV.veiculos[tabV.tam].modelo, token);

    // CPF do proprietario
    token = strtok(NULL, ",");
    strcpy(tabV.veiculos[tabV.tam].cpfProprietario, token);

    tabV.tam++;
  }

  fclose(arq);

  return tabV;
}

t_tab_p loadTabP(char fileName[]) {
  FILE *arq = fopen(fileName, "rt");
  int tamLinha = 128;
  char *token;
  char linha[tamLinha];

  t_tab_p tabP;
  tabP.tam = 0;
  tabP.total = 100;

  // Descartando primeira linha
  fgets(linha, tamLinha, arq);

  // Processa até chegar ao fim do arquivo ou atingir 100 itens
  while (!feof(arq) && (tabP.tam < tabP.total)) {
    fgets(linha, tamLinha, arq);
    linha[strlen(linha) - 1] = '\0';

    // Cpf
    token = strtok(linha, ",");
    strcpy(tabP.proprietarios[tabP.tam].cpf, token);

    // Nome
    token = strtok(NULL, ",");
    strcpy(tabP.proprietarios[tabP.tam].nome, token);

    // Email
    token = strtok(NULL, ",");
    strcpy(tabP.proprietarios[tabP.tam].email, token);

    // Celular
    token = strtok(NULL, ",");
    strcpy(tabP.proprietarios[tabP.tam].celular, token);

    tabP.tam++;
  }

  fclose(arq);

  return tabP;
}

t_tab_m loadTabM(char fileName[]) {
  FILE *arq = fopen(fileName, "rt");
  int tamLinha = 128;
  char *token;
  char linha[tamLinha];

  t_tab_m tabM;
  tabM.tam = 0;
  tabM.total = 100;

  // Descartando primeira linha
  // fgets(linha, tamLinha, arq);

  // Processa até chegar ao fim do arquivo ou atingir 100 itens
  while (!feof(arq) && (tabM.tam < tabM.total)) {
    fgets(linha, tamLinha, arq);
    linha[strlen(linha) - 1] = '\0';

    // Placa
    token = strtok(linha, ",");
    strcpy(tabM.multas[tabM.tam].placa, token);

    // Data
    token = strtok(NULL, ",");
    strcpy(tabM.multas[tabM.tam].data, token);

    // Valor
    token = strtok(NULL, ",");
    tabM.multas[tabM.tam].valor = atof(token);

    tabM.tam++;
  }

  fclose(arq);

  return tabM;
}

t_tab_v getVeiculosProprietario(t_tab_v tabV, t_item_p p) {
  t_tab_v tabVP;
  tabVP.tam = 0;
  tabVP.total = 100;

  for (int i = 0; i < tabV.tam; i++) {
    if (strcmp(tabV.veiculos[i].cpfProprietario, p.cpf) == 0) {
      tabVP.veiculos[tabVP.tam] = tabV.veiculos[i];
      tabVP.tam++;
    }
  }

  return tabVP;
}

t_tab_m getMultasVeiculo(t_tab_m tabM, t_item_v v) {
  t_tab_m tabMV;
  tabMV.tam = 0;
  tabMV.total = 100;

  for (int i = 0; i < tabM.tam; i++) {
    if (strcmp(tabM.multas[i].placa, v.placa) == 0) {
      tabMV.multas[tabMV.tam] = tabM.multas[i];
      tabMV.tam++;
    }
  }

  return tabMV;
}

void fazRelatorio(t_tab_v tv, t_tab_p tp, t_tab_m tm) {
  float valorTotalMultasP = 0.0, maiorValorTotalMultas, menorValorTotalMultas;
  int totalMultasP = 0, maiorTotalMultas, menorTotalMultas;
  char maiorValorMultasNomeP[64], menorValorMultasNomeP[64];
  
  t_tab_v tabV;
  t_tab_m tabM;

  tabV.tam = 0;
  tabV.total = 100;
  tabM.tam = 0;
  tabM.total = 100;

  printf("RELATORIO VALOR TOTAL (R$) E QUANTIDADE DE MULTAS POR PROPRIETARIO\n\n");

  for(int i = 0; i < tp.tam; i++) {
    tabV = getVeiculosProprietario(tv, tp.proprietarios[i]);
    valorTotalMultasP = 0.0;
    totalMultasP = 0;

    for(int j = 0; j < tabV.tam; j++) {
      tabM = getMultasVeiculo(tm, tabV.veiculos[j]);
      totalMultasP += tabM.tam;

      for(int k = 0; k < tabM.tam; k++) {
        valorTotalMultasP += tabM.multas[k].valor;
      }
    }
      
    if (i == 0) {
      strcpy(maiorValorMultasNomeP, tp.proprietarios[i].nome);
      strcpy(menorValorMultasNomeP, tp.proprietarios[i].nome);
      maiorValorTotalMultas = valorTotalMultasP;
      maiorTotalMultas = totalMultasP;
      menorValorTotalMultas = valorTotalMultasP;
      menorTotalMultas = totalMultasP;
    } else {
      if (valorTotalMultasP > maiorValorTotalMultas) {
        strcpy(maiorValorMultasNomeP, tp.proprietarios[i].nome);
        maiorValorTotalMultas = valorTotalMultasP;
        maiorTotalMultas = totalMultasP;
      }
      if (valorTotalMultasP < menorValorTotalMultas) {
        strcpy(menorValorMultasNomeP, tp.proprietarios[i].nome);
        menorValorTotalMultas = valorTotalMultasP;
        menorTotalMultas = totalMultasP;
      }
    }

    printf("%s%10.2f%5d multas\n", tp.proprietarios[i].nome, valorTotalMultasP, totalMultasP);
  }

  printf(". . .                . .\n\n");
  printf("MAIOR INFRATOR %s, %.2f %d multas\n", maiorValorMultasNomeP, maiorValorTotalMultas, maiorTotalMultas);
  printf("MENOR INFRATOR %s, %.2f %d multas\n", menorValorMultasNomeP, menorValorTotalMultas, menorTotalMultas);
}

int main() {
  t_tab_v tabV = loadTabV("tabveiculos.txt");
  t_tab_p tabP = loadTabP("tabproprietarios.txt");
  t_tab_m tabM = loadTabM("tabmultas.txt");

  fazRelatorio(tabV, tabP, tabM);

  return 0;
}
