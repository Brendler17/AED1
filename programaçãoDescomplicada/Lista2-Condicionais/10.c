// Faça um programa que receba a altura e o sexo de uma pessoa e calcule e mostre seu
// peso ideal, utilizando as seguintes formulas (onde h corresponde a altura):
// • Homens: (72.7 ∗ h) − 58
// • Mulheres: (62.1 ∗ h) − 44.7

#include <stdio.h>

int main()
{
    float height, weight;
    int gender;

    printf("Digite a sua altura: ");
    scanf("%f", &height);
    printf("Digite o seu gênero:\n1 - Masculino\n2 - Feminino\nSua escolha: ");
    scanf("%d", &gender);

    if(gender == 1){
        weight = (72.7 * height) - 58;
        printf("Seu peso ideal é de %.2fkg.\n", weight);
    } else {
        weight = (62.1 * height) - 44.7;
        printf("Seu peso ideal é de %.2fkg.\n", weight);
    }

    return 0;
}