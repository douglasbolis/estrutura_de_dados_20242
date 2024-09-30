#include <stdio.h>

struct Date {
  int day;
  int month;
  int year;
};

struct Person {
  char name[30];
  struct Date birthdate;
};

struct Date setDate(int day, int month, int year) {
  struct Date date;

  date.day = day;
  date.month = month;
  date.year = year;

  return date;
}

int main() {
  struct Person person;
  int day, month, year;

  printf("Qual seu nome? ");
  scanf("%[^\n]%*c", person.name);

  printf("Ola, %s\n", person.name);
  printf("Quando voce nasceu? [dd/mm/aaaa]: ");
  scanf("%d/%d/%d", &day, &month, &year);

  person.birthdate = setDate(day, month, year);

  printf("\n%s, voce nasceu em: %d/%d/%d.", person.name, person.birthdate.day, person.birthdate.month, person.birthdate.year);

  return 0;
}
