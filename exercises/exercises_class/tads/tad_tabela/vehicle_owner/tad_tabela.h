/* Arquivo - Processamento de dados */

/* TAD -> ADT - Abstract Data Type */
/* TAD Proprietário de Veículos */
#ifndef tad_vehicle_owner
#define tad_vehicle_owner

typedef struct {
  char placa[30];
  char marca[30];
  char modelo[30];
  char cpfProprietario[15];
} Veiculo;

typedef struct {
  int tam;
  Veiculo veiculos[50];
} TabelaVeiculos;

typedef struct {
  char cpf[15];
  char nome[30];
  char email[30];
  char celular[16];
} Proprietario;

typedef struct {
  int tam;
  Proprietario proprietarios[20];
} TabelaProprietarios;

TabelaVeiculos loadTabelaVeiculos(char[]);
TabelaProprietarios loadTabelaProprietarios(char[]);

void exibeProprietarios(TabelaProprietarios);
void exibeVeiculos(TabelaVeiculos);
void exibeVeiculosProprietarios(TabelaProprietarios, TabelaVeiculos);

#endif
