// Leia um valor em real e a cotação do dólar. 
// Em seguida, imprima o valor correspondente em dólares.

#include <stdio.h>

int main()
{
    float real, quotation;
    printf("Digite um valor em reais: ");
    scanf("%f", &real);
    printf("Digite a cotação do dólar: ");
    scanf("%f", &quotation);
    printf("O valor em dólares é: %.2f\n", (real/quotation));

    return 0;
}