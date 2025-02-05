#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

typedef struct tipo_entrada {
  char chave[32];
  t_dado valor;
} *t_entrada;

typedef struct t_dict {
  int tam_vet_dados;
  Lista vet_dados;
} *Dict;

unsigned int fh (char *k) {
  int soma = 0;
  for (int i = 0; i < strlen(k); i++) {
    soma += k[i];
  }

  return soma;
}

Dict criaDict(int qtd_dados) {
  float fc = 0.75;
  int tam_vet = (int)qtd_dados/fc;
  
  Dict d = (Dict)malloc(sizeof(struct t_dict));
  d->tam_vet_dados = tam_vet;
  d->vet_dados = (Lista)malloc(tam_vet * sizeof(Lista));

  for (int i = 0; i < tam_vet; i++) {
    d->vet_dados[i] = NULL;
  }

  return d;
}

Dict adiciona(Dict tad_dict, char *chave, t_dado valor) {
  int cod_hash = fh(chave);
  int pos = cod_hash % tad_dict->tam_vet_dados;

  if (tad_dict->vet_dados[pos] == NULL) {
    tad_dict->vet_dados[pos] = criaLista();
  }

  t_entrada entrada = (t_entrada)malloc(sizeof(struct tipo_entrada));
  strcpy(entrada->chave, chave);
  entrada->valor = valor;
  appendLista(tad_dict->vet_dados[pos], entrada);

  return tad_dict;
}

void printLenListas(Dict tad_dict) {
  for (int i = 0; i < tad_dict->tam_vet_dados; i++) {
    if (tad_dict->vet_dados[i] !== NULL) {
      printf("%d, %d\n", i, lenLista(tad_dict->vet_dados[i]));
    }
  }
}

int main () {
  return 0;
}
