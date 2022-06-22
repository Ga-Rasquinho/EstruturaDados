#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Funciona apenas no windows
#include <time.h>
#define TAM 10
/* Corpo do Programa */
int main(){
	int a, i, j, aux, vet[TAM];
	/* Gerando númeroes aleatórios dentro do vetor */
	srand(time(NULL));
	for(a = 0; a < TAM; a++){
		vet[a] = rand () % 100;
	}
	
	for(i = 1; i < TAM; i++){
		aux = vet[i];
		j = i - 1;
		
		while((j >= 0) && (aux < vet[j])){
			vet[j + 1] = vet[j];
			j--;
		}
		vet[j + 1] = aux;
	}
	
	getch();
	return 0;
}