#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no{
    int num;
    struct no *proximo;
};

No* criarNo(){
    No* novo = (No*) malloc(sizeof(No));
    return novo;
}

No* inserirInicio(No* lista, int dado){
    No *novoNo = criarNo();
    novoNo->num = dado;
    if(lista == NULL){
        lista=novoNo;
        novoNo->proximo = NULL;
    } else { 
        novoNo->proximo = lista;
        lista=novoNo;
    }
    return lista;
}
void imprimirLista(No* lista){
    No *aux = lista;
    while(aux != NULL){
        printf("%d\t", aux->num);
        aux = aux->proximo;
    }
}
int main(){
    No *lista = NULL;
    lista = inserirInicio(lista, 10);
    lista = inserirInicio(lista, 20);
    imprimirLista(lista);
    return 0;
}