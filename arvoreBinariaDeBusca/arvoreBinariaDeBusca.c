/*
    Arvore Binaria de Busca

    Gustavo Rodrigues Ribeiro - 202003570
    Luca Mascarenhas Plaster - 202014610
    Maria Heloisa de Paula Souza - 202003599
*/

#include "arvoreBinariaDeBusca.h"

int main(){

    criarArvoreVazia();
    printf("Aperte ENTER para continuar");
    fflush(stdin);
    continuar = getchar();
    system("cls");
    funcaoSwitch();
}

void funcaoSwitch(){
    int operacao = 1, elemento;
    arvoreBinaria *arvore =  criarArvoreVazia();

    while(operacao != 0){

        //system ("cls");

        printf("-----------Arvore Binaria de Busca----------\n");
        printf("0 - Finalizar o progama\n");
        printf("1 - Exibir arvore binaria\n");
        printf("2 - Inserir elemento na arvore binaria\n");
        scanf("%d", &operacao);


        switch (operacao)
        {

        case 1:
            exibirArvore(arvore);
            printf("\n");
            break;

        case 2:
            printf("\nDigite o elemento que deseja inserir na arvore\n");
            scanf("%d", &elemento);
            inserirArvore(&arvore, elemento);
        
            break;


        }   
    }
    destruirArvore(arvore);

    return 0;
}

arvoreBinaria *criarArvoreVazia(){
    return NULL;
}

//Destruir a árvore
void destruirArvore(arvoreBinaria *arv){
    free (arv);
}

void exibirArvore(arvoreBinaria *arv){
    printf("<");
    if (!confereArvore(arv)){
        printf("%d", arv->info); //Mostra a raiz
        exibirArvore(arv->esq); //subárvore à esquerda
        exibirArvore(arv->dir); //subárvore à direita
    }
    printf(">");
}

int confereArvore(arvoreBinaria *arv){
    if(arv == NULL) return 1; 
    else return 0;
}

void inserirArvore(arvoreBinaria **arv, int elemento){
    if (*arv ==  NULL){
        *arv = (arvoreBinaria*)malloc(sizeof(arvoreBinaria));
        (*arv)->dir = NULL; //Subárvore à direita é NULL 
        (*arv)->esq = NULL; //Subárvore à esquerda é NULL 
        (*arv)->info = elemento;//Armazena informação

    }else{
        if(elemento < (*arv)->info){ //Se o numero for menor vai para a esquerda
            inserirArvore(&(*arv)->esq, elemento);
        }
        if(elemento > (*arv)->info){ //Se o numero for maior vai para a direita
            inserirArvore(&(*arv)->esq, elemento);
        }
    }

}