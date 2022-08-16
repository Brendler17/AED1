// Leia um número real e imprima o resultado do quadrado desse número.

#include <stdio.h>
#include <math.h>

int main()
{

    float number, square;
    printf("Digite um número: ");
    scanf("%f", &number);
    square = pow(number, 2);
    printf("O quadrado de %.2f é: %.2f\n", number, square);

    return 0;
}