# IFES Estrutura de Dados 2024/2
## TAD TABELA VEICULO
### Características Principais

```c
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
```

## Como compilar e rodar
### Complicação
#### Passo 1

Compilação do código fonte do TAG TABELA.

O primeiro passo para o tad tabela dar certo, primeiro eu (no papel do desenvolvedor do código fonte) fornececerei o arquivo binário gerado a partir do meu código fonte juntamente com o arquivo cabeçalho contendo todas as informações úteis, como se fosse um tipo de documenteção do meu código fonte.

```bash
$ gcc -c tad_tabela.c
```

O comando acima irá gerar um arquivo binário do código `tad_tabela.c`, chamado `tad_tabela.o`, que você poderá usar como parte do seu código (simulando o papel do usuário final) a ser desenvolvido como prática de uso do tad.

#### Passo 2

Ao implementar o seu código, você deverá incluir o arquivo cabeçalho contendo todas as informações necessárias para que você consiga fazer uso do meu código fonte.

```c
// Exemplo:
#include "tad_tabela.h"
```

#### Passo 3

Com o arquivo binário do código fonte e o arquivo cabeçalho documentando o que está visível para você, é hora de você começar a desenvolver o seu código e assim usar o tad tabela.

```c
#include...
```

### Executando sua aplicação

Após finalizar o seu código vamos para a parte em que o gcc concatena todos os arquivos binários num só e gera o binário final, onde você poderá rodar e testar se está tudo em ordem.

Vamos lá...

#### Passo 1

Compilando sua aplicação:

```bash
$ gcc main.c tad_tabela.o -o main.bin -Wall
```

O comando de terminal acima diz que:

1. Será compilado o seu código fonte `main.c` + o meu código fonte `tad_tabela.o`, esse último é o binário mesmo.
2. E o `-o main.bin`, você está dizendo para o `gcc` salvar o binário final no arquivo main.bin.
3. O `-Wall` é apenas uma flag do compilador `gcc` para exibir, verbosamente, se existe algum erro ou warning que necessite de atenção.

#### Passo 2

Para rodar a sua aplicação você deve rodar o seguinte comando:

```bash
$ main.bin < tab_tabela.txt
```

Dependendo do sistema operacional na qual você está rodando sua aplicação, talvez o comando acima não funcione e você deve rodar de outra maneira, como:

```bash
$ ./main.bin < tab_tabela.txt
```

O comando de terminal acima diz que:

1. O arquivo binário(sua aplicação) `main.bin` será executado pelo terminal.
2. Por conta do meu binário gerado (`tad_tabela.o`) a sua aplicação está preparada para ler de um arquivo os dados a serem processados.
3. Daí vem o `tab_tabela.txt`, que é o arquivo texto contendo os dados de veículos a serem armazenados e processados.
4. E para ligar os dois arquivos `main.bin` e `tad_tabela.txt`, o caracter `<` fará esse trabalho.

### Arquivo `tad_tabela.txt`

O arquivo de dados `tad_tabela.txt` contém os dados necessários para serem executados.
Nele há um padrão que o `tad_tabela.o` espera e deve seguir a seguinte ordem:

```txt
ABC1D23
Ford
Mustang GT
350000
```

Onde:
1. `ABC1D23` é a placa do veículo;
2. `Ford` é a marca do veículo;
3. `Mustang GT` é o modelo do veículo;
4. `350000` é o valor do veículo;
