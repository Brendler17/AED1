// Leia um valor de area em acres e apresente-o convertido em metros quadrados m².
// A fórmula de conversão é M = A ∗ 4048.58, sendo M a área em metros quadrados e A a área em acres.

#include <stdio.h>

int main()
{
    float acres, m2;
    printf("Digite uma área em acres: ");
    scanf("%f", &acres);
    m2 = acres * 4048.58;
    printf("A área em metros quadrados é: %.2f\n", m2);

    return 0;
}