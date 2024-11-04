#include <stdio.h>
#include <string.h>

#define TAM_NOMES 3
#define TAM_SOBRENOMES 5
#define TAM_COMPLETO 100
#define TAM_PALAVRA 20

typedef char Nome[TAM_PALAVRA];  // Definindo um tipo 'Nome' para armazenar strings de até 19 caracteres

int main() {
    // Arrays de nomes e sobrenomes usando o tipo 'Nome'
    Nome nomes[TAM_NOMES] = {"Alice", "Carlos", "Fernanda"};
    Nome sobrenomes[TAM_SOBRENOMES] = {"Silva", "Santos", "Oliveira", "Pereira", "Costa"};

    // Variável para armazenar o nome completo
    char nome_completo[TAM_COMPLETO];
    int indice_nome = 0;  // Índice do nome (pode ser alterado)
    int indices_sobrenomes[3] = {0, 1, 2};  // Índices dos sobrenomes (pode ser alterado)

    // Limpa o buffer do nome completo
    strcpy(nome_completo, "");

    // Concatena o nome com os sobrenomes
    strcat(nome_completo, nomes[indice_nome]);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenomes[indices_sobrenomes[0]]);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenomes[indices_sobrenomes[1]]);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenomes[indices_sobrenomes[2]]);

    // Exibe o nome completo
    printf("Nome completo: %s\n", nome_completo);

    return 0;
}
