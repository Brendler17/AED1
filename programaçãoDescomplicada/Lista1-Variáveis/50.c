// Implemente um programa que calcule o ano de nascimento de uma pessoa a partir de
// sua idade e do ano atual.

#include <stdio.h>

int main()
{
    int age, year, birth, hadBirthday;
    printf("Digite sua idade: ");
    scanf("%d", &age);
    printf("Digite o ano atual: ");
    scanf("%d", &year);
    printf("Você já fez aniversário esse ano?\n1-Sim\n2-Não\nSua escolha: ");
    scanf("%d", &hadBirthday);

    if (hadBirthday == 1)
    {
        birth = year - age;
    }
    else
    {
        birth = year - age - 1;
    }

    printf("Seu nascimento foi em %d.\n", birth);

    return 0;
}