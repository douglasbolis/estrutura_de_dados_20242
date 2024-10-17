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

Tabela criaTabela();
Tabela filtraVeiculosPelaMarca(Tabela, char[]);

Veiculo criaVeiculo(char[], char[], char[], double);
Veiculo getVeiculoMaisCaro(Tabela);
Veiculo getVeiculoMaisBarato(Tabela);

void exibeVeiculo(Veiculo);
void exibeVeiculos(Tabela);
