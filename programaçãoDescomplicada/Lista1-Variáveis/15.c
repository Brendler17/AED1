// Leia um ângulo em radianos e apresente-o convertido em graus. 
// A fórmula de conversão é: G = R ∗ 180/π, sendo G o ângulo em graus e R em radianos e π = 3.14.

#include <stdio.h>

int main()
{
    float rad, graus;
    printf("Digite um ângulo em radianos: ");
    scanf("%f", &rad);
    graus = (rad * 180.0) / 3.14159;
    printf("O ângulo em graus é: %.5f\n", graus);

    return 0;
}