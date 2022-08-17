// Faça um programa que receba três números e mostre-os em ordem crescente.

#include <stdio.h>

int main()
{
    int a, b, c, aux;

    printf("Digite 3 números: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b)
    {
        aux = a;
        a = b;
        b = aux;
    }
    if (a > c)
    {
        aux = a;
        a = c;
        c = aux;
    }
    if (b > c)
    {
        aux = b;
        b = c;
        c = aux;
    }

    printf("Os números em ordem crescente são: %d %d %d.\n", a, b, c);

    return 0;
}