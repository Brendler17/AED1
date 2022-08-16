// Leia uma temperatura em graus Kelvin e apresente-a convertida em graus Celsius.
// A fórmula de conversão é: C = K − 273.15, sendo C a temperatura em Celsius e K a temperatura em Kelvin.

#include <stdio.h>

int main()
{

    float kelvin, celsius;
    printf("Digite uma temperatura em Kelvin: ");
    scanf("%f", &kelvin);
    celsius = kelvin - 273.15;
    printf("A temperatura em Celsius é: %.2f\n", celsius);

    return 0;
}