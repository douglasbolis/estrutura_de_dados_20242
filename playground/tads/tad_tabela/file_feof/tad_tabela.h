/* Arquivos - Processamento de dados */

/* TAD Tabela de Veículos -> ADT - Abstract Data Type */
#ifndef tad_vehicle_table
#define tad_vehicle_table

typedef struct {
  char placa[30];
  char marca[30];
  char modelo[30];
  double valor;
} Veiculo;

typedef struct {
  int tam;
  int total;
  Veiculo veiculos[10];
} Tabela;

Tabela loadTabela(char*);
Tabela filtraVeiculosPelaMarca(Tabela, char[]);

Veiculo criaVeiculo(char[], char[], char[], double);
Veiculo getVeiculoMaisCaro(Tabela);
Veiculo getVeiculoMaisBarato(Tabela);

void exibeVeiculo(Veiculo);
void exibeVeiculos(Tabela);

#endif
