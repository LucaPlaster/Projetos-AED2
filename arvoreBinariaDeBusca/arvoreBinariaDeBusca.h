#include <stdio.h>
#include <stdlib.h>

typedef struct arvBinaria{
    int info;
    struct arvBinaria *esq;
    struct arvBinaria *dir;
}arvoreBinaria;

int continuar;

void funcaoSwitch();                                    //Switch case
arvoreBinaria* criarArvoreVazia();                      //Cria árvore vazia
void destruirArvore(arvoreBinaria *arvore);             //Destruir arvore
void exibirArvore(arvoreBinaria *arvore);               //Mostrar arvore
int confereArvore(arvoreBinaria *arvore);               //Verificar se arvore esta vazia
void inserirArvore(arvoreBinaria **arvore, int info);   //Insere um dado na árvore
