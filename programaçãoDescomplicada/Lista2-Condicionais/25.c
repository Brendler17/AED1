// Calcule as raízes da equação de 2º grau. A variável a tem que ser diferente de zero. 
// Caso seja igual, imprima a mensagem “Não é equação do segundo grau."
// • Se ∆ < 0, não existe real. Imprima a mensagem "Não existe raiz".
// • Se ∆ = 0, existe uma raiz real. Imprima a raiz e a mensagem "Raiz única".
// • Se ∆ ≥ 0, imprima as duas raízes reais.

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x1, x2;

    printf("Digite o valor da incógnita: ");
    scanf("%f", &a);
    printf("Digite o valor do primeiro coeficiente: ");
    scanf("%f", &b);
    printf("Digite o valor do segundo coeficiente: ");
    scanf("%f", &c);

    if (a != 0)
    {
        delta = pow(b, 2) - (4 * a * c);

        if (delta == 0)
        {
            x1 = -b / (2 * a);
            printf("Raiz única: \n%.1f\n", x1);
        }
        else if (delta > 0)
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Raízes:\n%.1f\n%.1f\n", x1, x2);
        }
        else
        {
            printf("Não existe raiz.\n");
        }
    }
    else
    {
        printf("Não é equação do 2º grau.\n");
    }
}