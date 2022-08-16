// Leia uma temperatura em graus Celsius e apresente-a convertida em graus Fahrenheit.
// A formula de conversão é: F = C∗(9.0/5.0)+32.0, sendo F a temperatura em Fahrenheit e C a temperatura em Celsius.

#include <stdio.h>

int main()
{

    float celsius, farhenheit;
    printf("Digite uma temperatura em Celsius: ");
    scanf("%f", &celsius);
    farhenheit = celsius * (9.0 / 5.0) + 32.0;
    printf("A temperatura em Farhenheit é: %.2f\n", farhenheit);

    return 0;
}