// Peça ao usuário para digitar três valores inteiros e imprima a soma deles.

#include <stdio.h>

int main()
{

    int a, b, c;

    printf("Digite 3 números: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("A soma dos números é: %d.\n", (a + b + c));

    return 0;
}