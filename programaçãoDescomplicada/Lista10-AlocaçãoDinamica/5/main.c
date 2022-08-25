// Faça um programa que leia um numero N e:
// • Crie dinamicamente e leia um vetor de inteiro de N posições;
// • Leia um numero inteiro X e conte e mostre os múltiplos desse número que existe no vetor.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x, mult, *vetor, *vetorInit;

    printf("Digite um número: ");
    scanf("%d", &n);

    vetor = (int *)malloc(sizeof(int) * n);

    vetorInit = vetor;

    printf("Digite %d números: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", vetor);
        vetor++;
    }

    printf("Digite outro número: ");
    scanf("%d", &x);

    vetor = vetorInit;

    for (int i = 0; i < n; i++)
    {
        if (*vetor % x == 0)
        {
            printf("%d é múltiplo de %d.\n", *vetor, x);
            mult++;
            vetor++;
        }
        else
        {
            vetor++;
        }
    }
    printf("O número %d tem %d números múltiplos no vetor.\n", x, mult);

    free(vetorInit);
}