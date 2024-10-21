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
  Veiculo veiculos[];
} TabelaVeiculos;

typedef struct {
  char cpf[15];
  char nome[30];
  char email[30];
  char celular[16];
} Proprietario;

typedef struct {
  int tam;
  Proprietario proprietarios[];
} TabelaProprietario;

TabelaVeiculo loadTabelaVeiculos(char*);
TabelaProprietario loadTabelaProprietarios(char*);

Proprietario buscaProprietario(TabelaProprietario, char*);
TabelaVeiculos filtraVeiculosProprietario(Proprietario, TabelaVeiculos);

void listaVeiculos(TabelaVeiculos);
void listaProprietarios(TabelaProprietario);

void listaVeiculosProprietario(Proprietario, TabelaVeiculos);
void listaVeiculosProprietarios(TabelaProprietario, TabelaVeiculos);

#endif
