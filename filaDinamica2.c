/*
Autor: Gabriel Fernandes Rasquinho - SP3084094
Desafio proposto: construcao de uma fila encadeada dinamica.
*/
/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

// Structs
typedef struct resultado
{
    int valorFoiEncontrado;
    int valor;
    int quantidadeOcorrencia;
} Resultado;
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct
{
    No *primeiro;
    No *fim;
    int tamanho;
} Fila;
// Fim structs

// Criando uma fila vazia.
void criarFila(Fila *fila)
{
    // Setando valores para nulo e tamanho para zero
    fila->primeiro = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}
/* Metodo para inserir */
void inserirNaFila(Fila *fila, int num)
{
    No *novo = malloc(sizeof(No)); // Alocacao de espaco para a variavel do tipo struct No
    if (novo != NULL)
    {
        novo->valor = num;    // Atribui o valor que o método recebe
        novo->proximo = NULL; // Define o próximo como nulo
        /* Em uma fila o valor que vem depois do número inserido devera ser nulo */
        // OBS: a insercao de elementos sempre e no final, pois se trata de uma do tipo FIFO

        if (fila->primeiro == NULL) // Verifica se a fila e vazia
        {
            fila->primeiro = novo; // Caso a fila seja vazia o primeiro e o ultimo valor receberão o valor inserido
            fila->fim = novo;
        }
        else // Caso a fila não esteja vazia
        {
            fila->fim->proximo = novo; // Aponta para o final da fila indicando que um novo valor sera inserido
            fila->fim = novo;          // Aponta para o novo valor inserido
        }
        fila->tamanho++; // Aumenta o tamanho da fila
    }
    else
    {
        printf("\nErro ao alocar memoria.\n");
    }
}
/* Metodo para remover */
No *removerDaFila(Fila *fila)
{
    No *remover = NULL;
    if (fila->primeiro != NULL) // Verifica se a primeira posicao nao e nula
    {
        remover = fila->primeiro;          // Atribui o primeiro valor a variavel remover
        fila->primeiro = remover->proximo; // Pega o que seria o próximo elemento e atribui para a primeira posicao
        fila->tamanho--;                   // Diminui o tamanho da fila
    }
    else
    {
        printf("\n\t*----Nao ha valor para remover----*\n\n");
    }
    return remover;
}
/* Metodo para mostrar os dados da fila */
void imprimir(Fila *fila)
{
    No *pontAuxiliar = fila->primeiro;
    printf("__________  FILA  __________\n");
    while (pontAuxiliar != NULL)
    {
        printf("[%d] ", pontAuxiliar->valor);
        pontAuxiliar = pontAuxiliar->proximo;
    }

    printf("\n__________ FIM FILA __________\n\n");
}
/* Metodo para buscar */
Resultado buscar(Fila *fila, int valor)
{
    No *buscar = fila->primeiro;
    Resultado resultado = {0, 0, 0}; // Inicializando valores
    while (buscar != NULL)
    {
        if (buscar->valor == valor)
        {
            resultado.valor = buscar->valor; // Retornando o valor no qual foi buscado
            resultado.valorFoiEncontrado = 1;
            resultado.quantidadeOcorrencia++; // Verificando quantas vezes o valor aparece
        }
        buscar = buscar->proximo;
    }
    return resultado;
}
/* Metodo para limpar a fila */
No limparFila(Fila *fila)
{
    No *limpar;
    if (fila->primeiro != NULL)
    {
        /* While para percorrer toda a fila e apagar todos os dados */
        while (fila->primeiro != NULL)
        {
            limpar = removerDaFila(fila);
            free(limpar);
        }
        printf("\n\t*----Fila limpada com sucesso----*\n\n");
    }
    else
    {
        printf("\n\t*----Nao ha elemento para limpar----*\n\n");
    }
}
/* Corpo do programa*/
int main()
{
    No *r;
    Fila fila;
    int opcao, valor, busca;
    Resultado retorno;
    criarFila(&fila);
    /* Menu */
    do
    {
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\t4 - Buscar\n\t5 - Verificar Tamanho da Fila\n\t6 - Limpar Fila\n");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite um numero inteiro: ");
            fflush(stdin);
            scanf("%d", &valor);
            inserirNaFila(&fila, valor);
            break;
        case 2:
            r = removerDaFila(&fila);
            if (r != NULL)
            {
                printf("\nValor removido: %d\n\n", r->valor);
                free(r);
            }
            break;
        case 3:
            imprimir(&fila);
            break;
        case 4:
            printf("\nDigite um valor inteiro para ser buscado: ");
            fflush(stdin);
            scanf("%d", &busca);
            retorno = buscar(&fila, busca);
            if (retorno.valorFoiEncontrado == 0)
            {
                printf("\nValor nao encontrado\n\n");
            }
            else
            {
                printf("\n*----Valor [%d] encontrado----*\n", retorno.valor);
                printf("Quantidade de vezes que o valor aparece: %d\n\n", retorno.quantidadeOcorrencia);
            }
            break;
        case 5:
            if (fila.tamanho == 0)
            {
                printf("\n\t*----Fila Vazia----*\n\n");
            }
            else
            {
                printf("\nTamanho da fila: %d\n\n", fila.tamanho);
            }
            break;
        case 6:
            limparFila(&fila);
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
