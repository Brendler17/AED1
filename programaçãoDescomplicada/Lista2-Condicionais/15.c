// Usando switch, escreva um programa que leia um inteiro entre 1 e 7 e imprima o dia
// da semana correspondente a este número. Isto é, domingo se 1, segunda-feira se 2, e
// assim por diante.

#include <stdio.h>

int main()
{
    int number;

    printf("Digite um número de 1 a 7: ");
    scanf("%d", &number);

    switch (number)
    {
    case 1:
        printf("Domingo.\n");
        break;
    case 2:
        printf("Segunda.\n");
        break;
    case 3:
        printf("Terça.\n");
        break;
    case 4:
        printf("Quarta.\n");
        break;
    case 5:
        printf("Quinta.\n");
        break;
    case 6:
        printf("Sexta.\n");
        break;
    case 7:
        printf("Sábado.\n");
        break;
    default:
        printf("Não é um número válido.\n");
        break;
    }

    return 0;
}