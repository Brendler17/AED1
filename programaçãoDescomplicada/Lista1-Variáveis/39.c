// A importância de R$780.000,00 será dividida entre três ganhadores de um concurso.
// Sendo que da quantia total:
// • O primeiro ganhador recebera 46%;
// • O segundo recebera 32%;
// • O terceiro recebera o restante;
// Calcule e imprima a quantia ganha por cada um dos ganhadores.

#include <stdio.h>

int main()
{
    float valorTotal = 78000, ganhador1, ganhador2, ganhador3;

    ganhador1 = (valorTotal * 46) / 100;
    ganhador2 = (valorTotal * 32) / 100;
    ganhador3 = (valorTotal * (100 - (46+32))) / 100;

    printf("Primeiro ganhador fica com R$%.2f\n", ganhador1);
    printf("Segundo ganhador fica com R$%.2f\n", ganhador2);
    printf("Terceiro ganhador fica com R$%.2f\n", ganhador3);

    return 0;
}