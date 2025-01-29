#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlista.h"

typedef struct {
  char id[128];
  char nome[128];
  char descricao[128];
} t_projeto;

typedef struct {
  char id[128];
  char nome[128];
} t_membro;

typedef struct {
  char id_membro[128];
  char id_projeto[128];
} t_relacao;

Lista load_projetos(char *fileName) {
  Lista lstProjetos = criaLista();
  FILE *arq = fopen(fileName, "rt");
  t_projeto *pproj = (t_projeto *)malloc(sizeof(t_projeto));
  char linha[128];
  char *token;

  while (!feof(arq)) {
    fgets(linha, 128, arq);

    // Sinalizando fim da string
    linha[strlen(linha) - 1] = '\0';

    // Id
    token = strtok(linha, ",");
    strcpy(pproj->id, token);

    // Nome
    token = strtok(NULL, ",");
    strcpy(pproj->nome, token);

    // Descrição
    token = strtok(NULL, ",");
    strcpy(pproj->descricao, token);

    appendLista(lstProjetos, pproj);
  }

  fclose(arq);

  return lstProjetos;
}

Lista load_membros(char *fileName) {
  Lista lstMembros = criaLista();
  FILE *arq = fopen(fileName, "rt");
  t_membro *pmembro = (t_membro *)malloc(sizeof(t_membro));
  char linha[128];
  char *token;

  while (!feof(arq)) {
    fgets(linha, 128, arq);

    // Sinalizando fim da string
    linha[strlen(linha) - 1] = '\0';

    // Id
    token = strtok(linha, ",");
    strcpy(pmembro->id, token);

    // Nome
    token = strtok(NULL, ",");
    strcpy(pmembro->nome, token);

    appendLista(lstMembros, pmembro);
  }

  fclose(arq);

  return lstMembros;
}

Lista load_relacoes(char *fileName) {
  Lista lstRelacoes = criaLista();
  FILE *arq = fopen(fileName, "rt");
  t_relacao *prelacao = (t_relacao *)malloc(sizeof(t_relacao));
  char linha[128];
  char *token;

  while (!feof(arq)) {
    fgets(linha, 128, arq);

    // Sinalizando fim da string
    linha[strlen(linha) - 1] = '\0';

    // Id membro
    token = strtok(linha, ",");
    strcpy(prelacao->id_membro, token);

    // Id relação
    token = strtok(NULL, ",");
    strcpy(prelacao->id_projeto, token);

    appendLista(lstRelacoes, prelacao);
  }

  fclose(arq);

  return lstRelacoes;
}

Lista membros_projeto(char *id_proj, Lista lst_relacoes, Lista lst_membros) {
  Lista lstMembrosProjeto = criaLista();
  int j = 0, achou = 0;

  for (int i = 0; i < lenLista(lst_relacoes); i++) {
    t_relacao *prelacao = dadoLista(lst_relacoes, i);
    t_membro *pmembro;

    if (strcmp(prelacao->id_projeto, id_proj) == 0) {
      achou = 0;
      while ((achou = 0) && (j < lenLista(lst_membros))) {
        pmembro = dadoLista(lst_membros, j);
        if (strcmp(pmembro->id, prelacao->id_membro) == 0) {
          achou = 1;
        }
        j++;
      }
      appendLista(lstMembrosProjeto, pmembro);
    }
  }

  return lstMembrosProjeto;
}

Lista projetos_membro(char *id_mem, Lista lst_relacoes, Lista lst_projetos) {
  Lista lstProjetosMembro = criaLista();
  int j = 0, achou = 0;

  for (int i = 0; i < lenLista(lst_relacoes); i++) {
    t_relacao *prelacao = dadoLista(lst_relacoes, i);
    t_projeto *pprojeto;

    if (strcmp(prelacao->id_membro, id_mem) == 0) {
      achou = 0;
      while ((achou = 0) && (j < lenLista(lst_projetos))) {
        pprojeto = dadoLista(lst_projetos, j);
        if (strcmp(pprojeto->id, prelacao->id_projeto) == 0) {
          achou = 1;
        }
        j++;
      }
      appendLista(lstProjetosMembro, pprojeto);
    }
  }

  return lstProjetosMembro;
}

void printListaMembros(Lista lst_membros) {
  t_membro *pmembro;

  for (int i = 0; i < lenLista(lst_membros); i++) {
    pmembro = dadoLista(lst_membros, i);
    printf("%s, %s\n", pmembro->id, pmembro->nome);
  }
  printf("\n");
}

void printListaProjetos(Lista lst_projetos) {
  t_projeto *pprojeto;

  for (int i = 0; i < lenLista(lst_projetos); i++) {
    pprojeto = dadoLista(lst_projetos, i);
    printf("%s, %s, %s\n", pprojeto->id, pprojeto->nome, pprojeto->descricao);
  }
  printf("\n");
}

void printListaRelacoes(Lista lst_relacoes) {
  t_relacao *prelacao;

  for (int i = 0; i < lenLista(lst_relacoes); i++) {
    prelacao = dadoLista(lst_relacoes, i);
    printf("%s, %s\n", prelacao->id_membro, prelacao->id_projeto);
  }
  printf("\n");
}

int main() {
  Lista listaProjetos = load_projetos("bdprojetos.txt");
  Lista listaMembros = load_membros("bdmembros.txt");
  Lista listaRelacoes = load_relacoes("bdrelacoes.txt");
  Lista listaMembrosProjeto, listaProjetosMembro;
  char escolha[128];
  char id_membro[128];
  char id_projeto[128];

  printListaMembros(listaMembros);
  printListaProjetos(listaProjetos);
  printListaRelacoes(listaRelacoes);

  do {
    printf("MENU APP LISTA\n==============================\n");
    printf("1. Membros de um Projeto\n");
    printf("2. Projetos de um membro\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao:\n==============================\n");
    scanf("%s", escolha);

    if (strcmp(escolha, "1") == 0) {
      printf("Qual a id do Projeto: \n");
      scanf("%s", id_projeto);

      listaMembrosProjeto = membros_projeto(id_projeto, listaRelacoes, listaMembros);
      printf("Projetos que o Membro participou\n");
      printListaMembros(listaMembrosProjeto);
    } else
    if (strcmp(escolha, "2") == 0) {
      printf("Qual a id do Membro: \n");
      scanf("%s", id_membro);

      listaProjetosMembro = projetos_membro(id_membro, listaRelacoes, listaProjetos);
      printf("Membros participaram do Projeto\n");
      printListaProjetos(listaProjetosMembro);
    }
  } while (strcmp(escolha, "3") != 0);

  return 0;
}
