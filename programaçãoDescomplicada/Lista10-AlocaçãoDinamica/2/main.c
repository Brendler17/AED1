// Faça um programa que leia do usuário o tamanho de um vetor a ser lido e faça a alocação
// dinâmica de memória. Em seguida, leia do usuário seus valores e imprima o vetor lido.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamVetor, *vetor, *vetorInit;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamVetor);

    vetor = (int *)malloc(sizeof(int) * tamVetor);

    if(vetor == NULL){
        printf("Memória não alocada.");
        return 1;
    }

    vetorInit = vetor;

    printf("Digite %d números: ", tamVetor);
    for(int i=0 ; i < tamVetor ; i++){
        scanf("%d", &(*vetor));
        vetor++;
    }

    vetor = vetorInit;

    printf("Os números digitados foram: ");
    for(int i=0 ; i < tamVetor ; i++){
        printf(" %d", *vetor);
        vetor++;
    }
    printf("\n");

    free(vetorInit);
}