#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
}Valores;

typedef struct no{
    Valores numeros;
    struct no * proximo;
}No;

Valores lerNumeros(){
    Valores numeros;
    printf("Digite algum numero: ");
    fflush(stdin); scanf("%d",&numeros.valor);
    return numeros;
}

No* empilhar(No *topo){
    No *novo = malloc(sizeof(No));
    if(novo != NULL){
        novo->numeros = lerNumeros();
        novo->proximo = topo;
        return novo;
    }else{
        printf("\nErro ao alocar memoria...\n");
    }
    return NULL;
}

No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    } else {
        printf("\nPilha vazia\n");
    }
    return NULL;
}

void imprimirNumero(Valores numeros){
    printf("%d ",numeros.valor);
}

void imprimirPilha(No *topo){
    printf("\n-------------------- PILHA ----------------\n");
    while (topo)
    {
        imprimirNumero(topo->numeros);
        topo = topo->proximo;
    }    
    printf("\n------------------ FIM PILHA ----------------\n");
}
int main(){
    No *remover, *topo = NULL;
    int opcao;
    do{
        printf("\n0 - Sair\n1- Empilhar\n2 - Desempilhar\n3- Imprimir\n");
        fflush(stdin);
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover){
                printf("\nElemento removido com sucesso!\n");
                imprimirNumero(remover->numeros);
            }else{
                printf("\nSem no a remover.\n");
            }
            break;
        case 3:
            imprimirPilha(topo);
            break;

        default:
            if (opcao != 0)
            {
                printf("\nOpcao invalida!\n");
            }
        }
    } while (opcao != 0);
    return 0;
}