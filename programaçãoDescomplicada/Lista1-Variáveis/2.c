// Faça um programa que leia um numero real e o imprima.

#include <stdio.h>

int main()
{

    float number;

    printf("Digite um número: ");
    scanf("%f", &number);
    printf("O número digitado foi %.2f\n", number);

    return 0;
}