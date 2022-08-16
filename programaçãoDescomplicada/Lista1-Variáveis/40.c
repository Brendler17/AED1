// Uma empresa contrata um encanador a R$ 30,00 por dia. Faça um programa que solicite o número
// de dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser paga,
// sabendo-se que são descontados 8% para imposto de renda.

#include <stdio.h>

int main()
{
    float payment = 30.00, tax = 8, total;
    int days;
    printf("Digite o número de dias trabalhados: ");
    scanf("%d", &days);
    total = (payment * days) - (payment * days) * (tax / 100);
    printf("O valor total a ser pago é: R$%.2f\n", total);

    return 0;
}