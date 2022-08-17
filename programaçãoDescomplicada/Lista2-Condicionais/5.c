// Faça um programa que receba um número inteiro e verifique se este número é par ou ímpar.

#include <stdio.h>

int main()
{
    int number;
    printf("Digite um número: ");
    scanf("%d", &number);

    if (number % 2 == 0)
    {
        printf("O número %d é par.\n", number);
    }
    else
    {
        printf("O número %d é ímpar.\n", number);
    }

    return 0;
}