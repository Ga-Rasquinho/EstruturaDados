#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

void inserir_na_fila(No **fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->valor = num; // Um mesmo ponteiro pode apontar para duas variaveis diferentes sem alterar seu valor?
        novo->proximo = NULL;
        if (*fila == NULL)
        {
            *fila = novo;
        }
        else
        {
            aux = *fila;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria.\n");
    }
}
No *remover_da_fila(No **fila)
{
    No *remover = NULL;
    if (*fila)
    {
        remover = *fila;
        *fila = remover->proximo;
    }
    else
    {
        printf("\nFila vazia\n");
    }
    return remover;
}
void imprimir(No *fila)
{
    printf("\t------------ FILA -----------\n\t");
    while (fila)
    {
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }

    printf("\n\t---------- FIM FILA -----------\n");
}
int main()
{
    No *r, *fila = NULL;
    int opcao, valor;

    do
    {
        printf("\t0 -Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite um valor: ");
            fflush(stdin);
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor);
            break;
        case 2:
            r = remover_da_fila(&fila);
            if (r)
            {
                printf("\nRemovido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            imprimir(fila);
            break;

        default:
            if (opcao != 0)
            {
                printf("\nOpcao invalida\n");
            }
            break;
        }
    } while (opcao != 0);
    return 0;
}