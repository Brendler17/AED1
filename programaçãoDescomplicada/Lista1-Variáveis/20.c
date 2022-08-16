// Leia um valor de massa em quilogramas e apresente-o convertido em libras. 
// A fórmula de conversão é: L = K / 0.45, sendo K a massa em quilogramas e L a massa em libras.
#include <stdio.h>

int main()
{
    float kg, lb;
    printf("Digite uma massa em quilogramas: ");
    scanf("%f", &kg);
    lb = (kg/0.45);
    printf("A massa em libras é: %.2f\n", lb);

    return 0;
}