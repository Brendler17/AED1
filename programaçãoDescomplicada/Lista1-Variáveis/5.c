// Leia um número real e imprima a quinta parte deste número.

#include <stdio.h>

int main()
{

    float number;
    printf("Digite um número: ");
    scanf("%f", &number);
    printf("A quinta parte de %.2f é: %.2f.\n", number, (number / 5));

    return 0;
}