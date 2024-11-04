#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char t_name[64];

int randint(int min, int max) {
  return min + rand() % (max - min + 1);
}

int in(t_name surname, t_name newSurname[]) {
  int tam = sizeof(newSurname) / sizeof(newSurname[0]);

  for (int i = 0; i < tam; i++) {
    if (strcmp(surname, newSurname[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

void join(t_name name, t_name newSurname[]) {
  int tam = sizeof(newSurname) / sizeof(newSurname[0]);

  for(int i = 0; i < tam; i++) {
    strcat(name, " ");
    strcat(name, newSurname[i]);
  }
}

void generate_fullname(t_name names[], t_name surnames[], int tam, t_name fullname) {
  srand(time(NULL));

  tam--;
  t_name newSurname[tam];
  t_name randomName;
  int tamNewSurnames = 0;
  int tamNames = (int)(sizeof(names) / sizeof(names[0]));
  int tamSurnames = sizeof(surnames) / sizeof(surnames[0]);

  strcpy(fullname, names[randint(0, tamNames-1)]);

  while (tamNewSurnames < tam) {
    strcpy(randomName, surnames[randint(0, tamSurnames-1)]);

    if(!in(randomName, newSurname)) {
      strcpy(newSurname[tamNewSurnames++], randomName);
    }
  }

  join(fullname, newSurname);
}

int main() {
  t_name fullname = "";
  t_name names[64] = { "ana", "beatriz", "caio", "douglas", "eliseu", "fabio", "gregori", "helena", "inacio", "jameliz" };
  t_name surnames[64] = { "andrade", "finazzi", "gomes", "leiva", "menezes", "naves", "oliveria", "rocha", "silva", "yan" };

  generate_fullname(names, surnames, 4, fullname);

  printf("Nome completo: %s\n", fullname);

  return 0;
}
