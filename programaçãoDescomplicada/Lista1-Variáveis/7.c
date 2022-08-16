// Leia uma temperatura em graus Fahrenheit e apresente-a convertida em graus Celsius.
// A formula de conversão é: C = 5.0 ∗ (F − 32.0)/9.0, sendo C a temperatura em Celsius e F a temperatura em Fahrenheit.

#include <stdio.h>

int main()
{

    float farenheit, celsius;
    printf("Digite uma temperatura em Farhenheit: ");
    scanf("%f", &farenheit);
    celsius = 5.0 * (farenheit - 32.0) / 9.0;
    printf("A temperatura em Celsius é: %.2f\n", celsius);

    return 0;
}