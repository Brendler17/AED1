// Considere a seguinte declaração: int A, *B, **C, ***D; Escreva um programa que leia a
// variável a e calcule e exiba o dobro, o triplo e o quádruplo desse valor utilizando apenas
// os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D
// o quádruplo.

#include <stdio.h>

void main()
{
    int a, *b, **c, ***d;

    printf("Digite um número: ");
    scanf("%d", &a);

    b = &a;
    printf("O dobro do número é %d.\n", (*b) * 2);

    c = &b;
    printf("O triplo do número é %d.\n", (**c) * 3);

    d = &c;
    printf("O quádruplo do número é %d.\n", (***d) * 4);
}