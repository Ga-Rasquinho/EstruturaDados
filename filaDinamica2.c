/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct{
    No *primeiro;
    No *fim;
    int tamanho;
}Fila;
//Fim structs

// Criando uma fila vazia.
void criarFila(Fila *fila){
    // Setando valores para nulo e tamanho para zero
    fila->primeiro = NULL; 
    fila->fim = NULL;
    fila->tamanho = 0;
}

void inserir_na_fila(Fila *fila, int num)
{
    No *novo = malloc(sizeof(No)); //Alocação de espaço para a variável do tipo struct No
    if (novo != NULL)
    {
        novo->valor = num;  //Atribui o valor que o método recebe
        novo->proximo = NULL;   // Define o próximo como nulo
        /* Em uma fila o valor que vem depois do número inserido deverá ser nulo */
        // OBS: a inserção de elementos sempre é no final, pois se trata de uma do tipo FIFO

        if (fila->primeiro == NULL) // Verifica se a fila é vazia
        {
            fila->primeiro = novo; // Caso a fila seja vazia o primeiro e o ultimo valor receberão o valor inserido
            fila->fim = novo;      
        }
        else    // Caso a fila não esteja vazia
        {
           fila->fim->proximo = novo;   // Aponta para o final da fila indicando que um novo valor será inserido
           fila->fim = novo; // Aponta para o novo valor inserido
        }
        fila->tamanho++; //Aumenta o tamanho da fila
    }
    else
    {
        printf("\nErro ao alocar memoria.\n");
    }
}

No *remover_da_fila(Fila *fila)
{
    No *remover = NULL;
    if (fila->primeiro != NULL) //Verifica se a primeira posição não é nula
    {
        remover = fila->primeiro;  // Atribui o primeiro valor a variável remover
        fila->primeiro = remover->proximo; // Pega o que seria o próximo elemento e atribui para a primeira posição
        fila->tamanho--; // Diminui o tamanho da fila
    }
    else
    {
        printf("\nFila vazia\n");
    }
    return remover;
}
/* Método para mostrar os dados da fila */
void imprimir(Fila *fila)
{
    No *pontAuxiliar = fila->primeiro;
    printf("\t------------ FILA -----------\n\t");
    while (pontAuxiliar != NULL)
    {
        printf("%d ", pontAuxiliar->valor);
        pontAuxiliar = pontAuxiliar->proximo;
    }

    printf("\n\t---------- FIM FILA -----------\n");
}
/* Corpo do programa*/
int main()
{
    No *r;
    Fila fila;
    int opcao, valor;

    criarFila(&fila);
    /* Menu */
    do
    {
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
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
            if (r != NULL)
            {
                printf("\nRemovido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            imprimir(&fila);
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