#include <stdio.h>
#include <conio.h>
// Structs
typedef struct NodeItem
{
    int info;
    struct NodeItem *next;
} node;

typedef struct
{
    node *head, *tail;
} queue;

// Assinatura de métodos
queue *newQueue();
node *newNode(int info);
void enqueue(queue *q, int value);
int dequeue(queue *q);
int isQueueEmpty(queue *q);
void showQueue(queue *q);

int main()
{
    int a, b;
    int c, d;
    queue *fila = newQueue();
    showQueue(fila);
    enqueue(fila, 5);
    enqueue(fila, 15);
    enqueue(fila, 22);
    enqueue(fila, 7);
    a = dequeue(fila);
    b = dequeue(fila);
    printf("Valores removidos: %d %d\n", a, b);
    showQueue(fila);
    return 0;
}

queue *newQueue()
{
    queue *q = (queue *) malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
}
node *newNode(int info)
{
    node *n = (node *)malloc(sizeof(node));
    n->info = info;
    n->next = NULL;
}
void enqueue(queue *q, int value)
{
    node *n = newNode(value);
    if (isQueueEmpty(q))
    {
        q->head = n;
        q->tail = n;
    }
    else
    {
        q->tail->next = n;
        q->tail = n;
    }
}

int dequeue(queue *q)
{
    node *n;
    int aux;
    if (isQueueEmpty(q))
    {
        printf("Fila vazia, nao e possivel remover um valor");
        return -1;
    }
    n = q->head;
    aux = n->info;
    q->head = n->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(n);
    return aux;
}
int isQueueEmpty(queue *q)
{
    return q->head == NULL;
}

void showQueue(queue *q)
{
    node *n;
    if (isQueueEmpty(q))
    {
        printf("Fila Vazia");
    }
    else
    {
        printf("Fila: \n");
    }
    n = q->head;
    while (n != NULL)
    {
        printf(" [%2d]", n->info);
        n = n->next;
    }
    printf("\n");
}