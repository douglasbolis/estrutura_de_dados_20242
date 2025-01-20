/* 
   Construa um programa que carregue uma lista de inteiros de um arquivo e determine
   o maior e o menor número. */
#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

int main(){
    FILE *arq;
    Lista lst = criaLista();
    int *pnum;
    int maior, menor;
    char s[8];

    arq = fopen("numeros.txt","rt");
    while(!feof(arq)){
    	fgets(s,7,arq);
    	pnum = (int *)malloc(sizeof(int));
    	*pnum = atoi(s);
    	appendLista(lst,pnum);
    }
    fclose(arq);

    pnum = dadoLista(lst,0);
    maior = *pnum;
    menor = *pnum;
    for(int i=1; i < lenLista(lst); i++){
    	pnum = dadoLista(lst,i);
    	if(*pnum > maior)
    		maior = *pnum;
    	else {
    		if(*pnum < menor)
    			menor = *pnum;
    	}    	
    }

    free(pnum);
    destroiLista(lst);

    printf("Menor numero encontrado: %d\n", menor);
    printf("Maior numero encontrado: %d\n", maior);

	return 0;
}
