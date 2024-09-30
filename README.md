# IFES Estrutura de Dados 2024/2
## Resumo
### Característica Principal

Playground com exemplos desenvolvidos em linguagem C.

### Outras Atividades

Incluirá também os Trabalhos e Exercícios da disciplina.

## Execução dos Programas

### GCC

No sistema operacional Windows, temos que baixar o compilador GCC, pois não é nativo do sistema operacional.

[Baixar MinGW](https://sourceforge.net/projects/mingw/)

> Para sistemas operacionais baseados no UNIX, o GCC já vem nativo.

Pegando a onda de programas não nativos no Windows, provável que precise instalar o Git para salvar as alterações no Github.

[Baixar Git](https://git-scm.com/downloads/win)

### Compilação

`$ gcc main.c -o main.o -Wall`

1. `gcc` é o compilador;
2. `main.c` é o arquivo contendo o código em c;
3. `-o` é a flag para indicar qual o arquivo de saída do binário gerado;
4. `main.o` é o arquivo binário de saída;
5. `-Wall` é a flag que nos diz verbosamente se há algum erro/warning gerado ao compilar o `main.c`.
