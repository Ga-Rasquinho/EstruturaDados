#include <stdio.h>
#include <stdlib.h>

int main(){
    int *x;
    int valor = 35;
    int result;
    x = &valor;


    printf("Valor do ponteiro: %d", *x);
    return 0;
}