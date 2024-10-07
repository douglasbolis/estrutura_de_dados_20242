#include <stdio.h>
#include <string.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  char titulo[21];
  char autor[21];
  char editora[21];
  Data data_publicacao;
} Livro;

Data setDate(int dia, int mes, int ano) {
  Data data;

  data.dia = dia;
  data.mes = mes;
  data.ano = ano;

  return data;
}

Livro setBook(char titulo[], char autor[], char editora[], int dia, int mes, int ano) {
  Data data = setDate(dia, mes, ano);
  Livro livro;

  strcpy(livro.titulo, titulo);
  strcpy(livro.autor, autor);
  strcpy(livro.editora, editora);
  livro.data_publicacao = data;

  return livro;
}

int main () {
  char titulo[21] = "Fahrenheit 451";
  char autor[21] = "Ray Bradbury";
  char editora[21] = "Biblioteca Azul";
  int dia = 1;
  int mes = 6;
  int ano = 2012;

  Livro livro = setBook(titulo, autor, editora, dia, mes, ano);

  printf("Titulo: %s\n", livro.titulo);
  printf("Autor: %s\n", livro.autor);
  printf("Editora: %s\n", livro.editora);
  printf("Data de publicacao: %d/%d/%d", livro.data_publicacao.dia, livro.data_publicacao.mes, livro.data_publicacao.ano);

  return 0;
}
