#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
    struct no *anterior;
} No;

void inserirDadoInicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->valor = num;
        novo->proximo = *lista;
        novo->anterior = NULL;
        if (*lista != NULL)
        {
            (*lista)->anterior = novo;
        }
        *lista = novo;
    }else
        {
            printf("\nErro ao alocar memoria");
        }
}


void inserirDadoFinal(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo != NULL)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (*lista == NULL)
        {
            *lista = novo;
            novo->anterior = NULL;
        }
        else
        {
            aux = *lista;
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria");
    }
}

void InserirDadoMeio(No **lista, int num, int ant)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo != NULL)
    {
        novo->valor = num;
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->valor != ant && aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            if (aux->proximo != NULL)
            {
                aux->proximo->anterior = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;          
        }
    }
    else
    {
        printf("\nErro ao alocar memoria");
    }
}

void InserirDadoOrdenado(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo != NULL)
    {
        novo->valor = num;
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            if (aux->proximo != NULL)
            {
                aux->proximo->anterior = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria");
    }
}

No *remover(No **lista, int num)
{
    No *aux, *remover = NULL;

    if (*lista != NULL)
    {
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->proximo;
            if ((*lista) != NULL)
            {
                (*lista)->anterior = NULL;
            }
        }
        else
        {
            aux = *lista;
            while (aux->proximo && aux->proximo->valor != num)
            {
                aux = aux->proximo;
            }
            if (aux->proximo != NULL)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if (aux->proximo != NULL)
                {
                aux->proximo->anterior = aux;
                }
            }
        }
    }
    return remover;
}

No *buscar(No **lista, int num)
{
    No *aux, *no = NULL;

    aux = *lista;
    while (aux && aux->valor != num)
    {
        aux = aux->proximo;
    }
    if (aux != NULL)
    {
        no = aux;
    }
    return no;
}
void imprimir(No *no)
{
    printf("\nLista: ");
    while (no)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

No *ultimo(No **lista)
{
    No *aux = *lista;
    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    return aux;
}

void imprimirContrario(No *no)
{
    printf("\nLista: ");
    while (no)
    {
        printf("%d ", no->valor);
        no = no->anterior;
    }
    printf("\n\n");
}
int main()
{

    int opcao, valor, anterior;
    No *removido, *lista = NULL;

    do
    {
        printf("\n0 - Sair\n1 - InserirInicio\n2 - inserirFim\n3 - InserirMeio\n4 - InserirOrdenado\n5 - Remover\n6 - Imprimir\n7 - Buscar\n8 - ImprimirContrario\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserirDadoInicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserirDadoFinal(&lista, valor);
            break;
        case 3:
            printf("Digite um valor para ser inserido: ");
            fflush(stdin); scanf("%d", &valor);
            printf("Depois de qual valor voce quer inserir?: ");
            fflush(stdin); scanf("%d", &anterior);
            InserirDadoMeio(&lista, valor, anterior);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            InserirDadoOrdenado(&lista, valor);
            break;
        case 5:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if (removido)
            {
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");
            break;
        case 6:
            imprimir(lista);
            break;
        case 7:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if (removido)
                printf("Elemento encontrado: %d\n", removido->valor);
            else
                printf("Elemento nao encontrado!\n");
            break;
        case 8:
            imprimirContrario(ultimo(&lista));
            break;
        default:
            if (opcao != 0)
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

