// Faça um programa que leia do usuário o tamanho de um vetor a ser lido e faça a alocação
// dinâmica de mémoria. Em seguida, leia do usuário seus valores e mostre quantos dos
// números são pares e quantos são ímpares.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor, *vetorInit, tamVetor, par = 0, impar = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamVetor);

    vetor = (int *)malloc(sizeof(int) * tamVetor);

    if (vetor == NULL)
    {
        printf("Memória não alocada.");
        return 1;
    }

    vetorInit = vetor;

    printf("Digite %d números: ", tamVetor);
    for (int i = 0; i < tamVetor; i++)
    {
        scanf("%d", &(*vetor));
        vetor++;
    }

    vetor = vetorInit;

    for (int i = 0; i < tamVetor; i++)
    {
        if (*vetor % 2 == 0)
        {
            par++;
        }
        else
        {
            impar++;
        }
        vetor++;
    }

    printf("Você digitou %d números pares.\n", par);
    printf("Você digitou %d números ímpares.\n", impar);

    free(vetorInit);
}