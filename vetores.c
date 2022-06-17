// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Variaveis para busca binaria
    int inicio;
    int meio;
    int final;
    int dadoEncontrado;
    int busca;    
    // Vetores   
    int vet1[5] = {5,6,7,8,9};
    int vet2[5] = {0,1,2,3,4};
    int vet3[10];
    // Variaveis auxiliares
    int i;
    int x = 5;
    int aux;
    // Unindo vetores diferentes
    for (i = 0; i < 5; i++){
        vet3[i] = vet1[i];
        vet3[x] = vet2[i];
        x++;
    }
    // Bubble sort para ordernar os vetores
    for(i = 0; i < 10; i++){
        for(x = 0; x < 9; x++){
            if(vet3[x] > vet3[x + 1]){
                aux = vet3[x];
                vet3[x] = vet3[x + 1];
                vet3[x + 1] = aux;
            }
        }
    }
    // Mostrar valores na tela
    for(i = 0; i < 10; i++){
        printf("[%d]\t", vet3[i]);
    }
    printf("\nDigite o valor que deseja buscar: ");
    fflush(stdin); scanf("%d", &busca);
    // Inicializacao dos valores
    inicio = 0;
    final = 9;
    dadoEncontrado = 0;
    // Busca binaria
    while(inicio <= final && dadoEncontrado == 0){
        meio = (inicio + final) / 2;
        if(vet3[meio] == busca){
            printf("Dado encontrado na posicao: #%d", meio);
            dadoEncontrado++;
        }if(vet3[meio] > busca){
            final = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }
    return 0;
}