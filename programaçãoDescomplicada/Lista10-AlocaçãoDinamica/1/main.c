// Crie um programa que:
// (a) Aloque dinamicamente um array de 5 numeros inteiros,
// (b) Peça para o usuario digitar os 5 números no espaço alocado,
// (c) Mostre na tela os 5 números,
// (d) Libere a memória alocada.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *pInit;

    p = (int *)malloc(sizeof(int) * 5);

    if(p == NULL){
        printf("Memória não alocada.");
        return 1;
    }

    pInit = p;

    printf("Digite 5 números: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &*p);
        p++;
    }

    p = pInit;

    printf("Os números digitados foram: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", *p);
        p++;
    }
    printf("\n");

    free(pInit);
}