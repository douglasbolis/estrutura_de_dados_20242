#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int id;
  char nome[64];
  char categoria[32];
  char marca[32];
  float preco;
  int garantia;
  int qtdEstoque;
} t_item;

typedef struct {
  int tam;
  int total;
  t_item itens[100];
} t_tabela;

t_tabela loadTab(char fileName[]) {
  FILE *arq = fopen(fileName, "rt");
  int tamLinha = 128;
  char *token;
  char linha[tamLinha];

  t_tab_m tab;
  tab.tam = 0;
  tab.total = 100;

  // Descartando primeira linha
  fgets(linha, tamLinha, arq);

  // Processa até chegar ao fim do arquivo ou atingir 100 itens
  while (!feof(arq) && (tab.tam < tab.total)) {
    fgets(linha, tamLinha, arq);
    linha[strlen(linha) - 1] = '\0';

    // Id
    token = strtok(linha, ",");
    tab.itens[tab.tam].id = atoi(token);

    // Nome
    token = strtok(NULL, ",");
    strcpy(tab.itens[tab.tam].nome, token);

    // Categoria
    token = strtok(NULL, ",");
    strcpy(tab.itens[tab.tam].categoria, token);

    // Marca
    token = strtok(NULL, ",");
    strcpy(tab.itens[tab.tam].marca, token);

    // Preço
    token = strtok(NULL, ",");
    tab.itens[tab.tam].preco = atof(token);

    // Garantia
    token = strtok(NULL, ",");
    tab.itens[tab.tam].garantia = atoi(token);

    // Quantidade em estoque
    token = strtok(NULL, ",");
    tab.itens[tab.tam].qtdEstoque = atoi(token);

    tab.tam++;
  }

  fclose(arq);

  return tab;
}

void fazRelatorio(t_tabela tab) {
  printf("RELATORIO TOTAL EM ESTOQUE POR MARCA (R$ E QUANT. TOTAIS)\n\n");

  for (int i = 0; i < tab.tam; i++) {
    
  }
  
  printf(". . .                . .\n\n");
  printf("MAIOR TOTAL EM ESTOQUE: ");
  printf("MENOR TOTAL EM ESTOQUE: ");
}

int main() {
  t_tabela tab = loadTabV("tabti.txt");

  fazRelatorio(tab);

  return 0;
}
