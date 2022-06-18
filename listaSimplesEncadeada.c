#include <stdio.h>
#include <stdlib.h>
// Struct para receber a insercao de dados
typedef struct no
{
    int num;
    struct no *proximo;
} No;
// Aloca um novo no na memoria
No *criarNo()
{
    No *novo = (No *)malloc(sizeof(No));
    return novo;
}
// Inserindo dados na lista
No *inserirInicio(No *lista, int dado)
{
    No *novoNo = criarNo();
    novoNo->num = dado;
    if (lista == NULL)
    {
        lista = novoNo;
        novoNo->proximo = NULL;
    }
    else
    {
        novoNo->proximo = lista;
        lista = novoNo;
    }
    return lista;
}
void imprimirLista(No *lista)
{
    No *aux = lista;
    while (aux != NULL)
    {
        printf("%d\t", aux->num);
        aux = aux->proximo;
    }
}
int main()
{
    No *lista = NULL;
    int opcao;
    printf("Caso deseje interromper a lista digite -1\n");
    do
    {
        printf("\nDigite um dado: ");
        fflush(stdin);
        scanf("%d", &opcao);
        lista = inserirInicio(lista, opcao);
        imprimirLista(lista);
    } while (opcao > 0);
    printf("Fim do programa.");
    return 0;
}