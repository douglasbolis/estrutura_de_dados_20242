#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char t_name[64];

int randint(int min, int max) {
  return min + rand() % (max - min + 1);
}

int in(t_name surname, t_name newSurname[], int tam) {
  for (int i = 0; i < tam; i++) {
    if (strcmp(surname, newSurname[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

void join(t_name name, t_name newSurname[], char charJoin[], int tam) {
  for (int i = 0; i < tam; i++) {
    strcat(name, charJoin);
    strcat(name, newSurname[i]);
  }
}

void generate_fullname(t_name names[], int tamNames, t_name surnames[], int tamSurnames, int tam, t_name fullname) {
  srand(time(NULL));

  tam--;
  t_name newSurname[tam];
  int tamNewSurnames = 0;
  
  // Escolhe um nome aleatório e copia para fullname
  strcpy(fullname, names[randint(0, tamNames - 1)]);

  // Gera sobrenomes únicos e os armazena em newSurname
  while (tamNewSurnames < tam) {
    t_name randomName;
    strcpy(randomName, surnames[randint(0, tamSurnames - 1)]);

    if (!in(randomName, newSurname, tamNewSurnames)) {
      strcpy(newSurname[tamNewSurnames++], randomName);
    }
  }

  // Concatena os sobrenomes gerados ao nome completo
  join(fullname, newSurname, " ", tamNewSurnames);
}

int main() {
  t_name fullname;
  t_name names[10] = { "ana", "beatriz", "caio", "douglas", "eliseu", "fabio", "gregori", "helena", "inacio", "jameliz" };
  t_name surnames[10] = { "andrade", "finazzi", "gomes", "leiva", "menezes", "naves", "oliveira", "rocha", "silva", "yan" };

  // Tamanho dos arrays names e surnames
  int tamNames = sizeof(names) / sizeof(names[0]);
  int tamSurnames = sizeof(surnames) / sizeof(surnames[0]);

  // Gera um nome completo com 1 nome e 3 sobrenomes
  generate_fullname(names, tamNames, surnames, tamSurnames, 4, fullname);

  printf("Nome completo: %s\n", fullname);

  return 0;
}
