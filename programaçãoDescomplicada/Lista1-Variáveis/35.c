// Sejam a e b os catetos de um triângulo, onde a hipotenusa é obtida pela equação: 
// hipotenusa = √a² + b². Faça um programa que receba os valores de a e b e calcule
// o valor da hipotenusa atraves da equação. Imprima o resultado dessa operacão.

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, hipotenusa;
    printf("Digite o valor do primeiro cateto: ");
    scanf("%f", &a);
    printf("Digite o valor do segundo cateto: ");
    scanf("%f", &b);
    hipotenusa = sqrt(pow(a,2) + pow(b,2));
    printf("O valor da hipotenusa é: %.2f\n", hipotenusa);

    return 0;
}