// Escreva um programa que leia as coordenadas x e y de pontos no R² e calcule sua
// distância da origem (0, 0).

#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, d;
    printf("Digite a coordenada x: ");
    scanf("%f", &x);
    printf("Digite a coordenada y: ");
    scanf("%f", &y);
    d = sqrt(pow(x, 2) + pow(y, 2));
    printf("A distância do ponto (%.f, %.f) é %.2f.\n", x, y, d);

    return 0;
}