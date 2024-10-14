typedef struct {
  char placa[21];
  char marca[21];
  char modelo[21];
  double valor;
} Veiculo;

typedef struct {
  int tam;
  int total;
  Veiculo[] veiculos;
} Tabela;

Tabela criaTabela();
Tabela filtraVeiculosPelaMarca(Tabela, char[]);

Veiculo criaVeiculo(char[], char[], char[], double);
Veiculo getVeiculoMaisCaro(Tabela);
Veiculo getVeiculoMaisBarato(Tabela);

void exibeVeiculo(Veiculo);
void exibeVeiculos(Tabela);
