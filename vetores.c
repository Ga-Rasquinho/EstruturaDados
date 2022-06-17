#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet1[5] = {5,6,7,8,9};
    int vet2[5] = {0,1,2,3,4};
    int vet3[10];
    int i;
    int x = 5;
    int aux;

    for (i = 0; i < 5; i++){
        vet3[i] = vet1[i];
        vet3[x] = vet2[i];
        x++;
    }
    
    for(i = 0; i < 10; i++){
        for(x = 0; x < 9; x++){
            if(vet3[x] < vet3[x + 1]){
                aux = vet3[x];
                vet3[x] = vet3[x + 1];
                vet3[x + 1] = aux;
            }
        }
    }
    
    return 0;
}