// Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
// apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada
// valor lido.

#include <stdio.h>

int main()
{
    int *p, array[5];
    p = &array[0];

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um número: ");
        scanf("%d", p);
        p++;
    }

    p = &array[0];

    for (int i = 0; i < 5; i++)
    {
        printf("O dobro de %d é %d.\n", *p, (*p) * 2);
        p++;
    }
}