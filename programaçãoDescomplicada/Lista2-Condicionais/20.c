// Dados tres valores, A, B, C, verificar se eles podem ser valores dos lados de um triângulo e,
// se forem, se é um triângulo escaneleno, equilátero ou isósceles, considerando os seguintes conceitos:
// • O comprimento de cada lado de um triângulo é menor do que a soma dos outros dois lados.
// • Chama-se equilátero o triângulo que tem três lados iguais.
// • Denominam-se isósceles o triângulo que tem o comprimento de dois lados iguais.
// • Recebe o nome de escaleno o triângulo que tem os três lados diferentes.

#include <stdio.h>

int main()
{
    float ladoA, ladoB, ladoC;

    printf("Digite o primeiro valor: ");
    scanf("%f", &ladoA);
    printf("Digite o segundo valor: ");
    scanf("%f", &ladoB);
    printf("Digite o terceiro valor: ");
    scanf("%f", &ladoC);

    if ((ladoA < ladoB + ladoC) && (ladoB < ladoA + ladoC) && (ladoC < ladoA + ladoB))
    {
        if ((ladoA == ladoB) && (ladoA == ladoC) && (ladoB == ladoC))
        {
            printf("O triângulo é equilátero pois tem os 3 lados iguais.\n");
        }
        else if ((ladoA != ladoB) && (ladoA != ladoC) && (ladoB != ladoC))
        {
            printf("O triângulo é escaleno pois tem os 3 lados diferentes.\n");
        }
        else
        {
            printf("O triângulo é isósceles pois tem 2 lados iguais.\n");
        }
    }
    else
    {
        printf("Não é triângulo.\n");
    }

    return 0;
}