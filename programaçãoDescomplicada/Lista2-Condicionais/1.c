// Faça um programa que receba dois números e mostre qual deles é o maior.

#include <stdio.h>

int main()
{
    int a, b;
    printf("Digite dois números: ");
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        printf("O número %d é maior que o número %d.\n", a, b);
    }
    else if (a == b)
    {
        printf("Os números são iguais.\n");
    }
    else
    {
        printf("O número %d é maior que o número %d.\n", b, a);
    }

    return 0;
}