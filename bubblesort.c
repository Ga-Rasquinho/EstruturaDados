/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Funciona apenas no windows
#include <time.h>
#define TAM 10 /* Constante */
/* Variáveis globais */
int i, contador, x, vet[TAM], guardar, contPrintar;
/* Corpo do programa */
int main(){
	/* Gerando númeroes aleatórios dentro do vetor */
	srand(time(NULL));
	for(i = 0; i < TAM; i++){
		vet[i] = rand () % 100;
	}
	/* Ordenação */
	for(contador = 0; contador < TAM; contador++){
		for(x = 0; x < TAM - 1; x++){
			if(vet[x] > vet[x + 1]){
				guardar = vet[x];
				vet[x] = vet[x + 1];
				vet[x + 1] = guardar;
			}
		}
	}
	/* Mostrar os números dos vetores na tela já ordenados*/
	for(contPrintar = 0; contPrintar < TAM; contPrintar++){
		printf("%d\t", vet[contPrintar]);
	}
	getch();
	return 0;
}