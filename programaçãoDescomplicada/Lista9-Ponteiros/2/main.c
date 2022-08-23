// Escreva um programa que contenha duas variáveis inteiras.
// Compare seus endereços e exiba o maior endereço.

#include <stdio.h>

int main()
{
    int a, b;

    if (&a > &b)
    {
        printf("O endereço de A (%p) é maior que o endereço de B (%p)", a, b);
    }
    else
    {
        printf("O endereço de B (%p) é maior que o endereço de A (%p)", b, a);
    }
}