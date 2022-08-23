// Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro,
// real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de
// cada variável usando os ponteiros. Imprima os valores das variáveis antes e após as modificações.

#include <stdio.h>

void main()
{
    int inteiro = 1, *p;
    float real = 2.4, *q;
    char caractere = 'c', *r;

    printf("%d \n", inteiro);
    printf("%f \n", real);
    printf("%c \n", caractere);

    p = &inteiro;
    q = &real;
    r = &caractere;

    *p = 5;
    *q = 8.7;
    *r = 'f';

    printf("\n%d \n", inteiro);
    printf("%f \n", real);
    printf("%c \n", caractere);
}