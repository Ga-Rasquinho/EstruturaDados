#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao;
    int vet[5] = {5, 4, 3, 2, 1};
    int i, x, z, aux;
    for (i = 0; i < 5; i++)
    {
        for (x = 0; x < 4; x++)
        {
            if (vet[x] > vet[x + 1])
            {
                aux = vet[x];
                vet[x] = vet[x + 1];
                vet[x + 1] = aux;
            }
        }
    }
    for (z = 0; z < 5; z++)
    {
        printf("%d\t", vet[z]);
    }
    int inicial = 0;
    int meio;
    int final = 4;
    int dadoEncontrado = 0;
    printf("\nBuscar valor: ");
    fflush(stdin);
    scanf("%i", &opcao);

    while (inicial <= final && dadoEncontrado == 0)
    {
        meio = (inicial + final) / 2;
        if (vet[meio] == opcao)
        {
            dadoEncontrado++;
        }
        if (vet[meio] > opcao)
        {
            final = --meio;
        }
        else
        {
            inicial = ++meio;
        }
    }
    if (dadoEncontrado > 0)
    {
        printf("\nDado encontrado na posicao: %i", meio);
    }
    else
    {
        printf("Dado nao encontrado");
    }
    return 0;
}