// Leia uma data e determine se ela e válida. Ou seja, verifique se o mês está entre 1 e 12,
// e se o dia existe naquele mês. Note que Fevereiro tem 29 dias em anos bissextos, e 28
// dias em anos não bissextos. 

#include <stdio.h>

int main()
{
    int dia, mes, ano;
    printf("Digite uma data (separada por /): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if (mes >= 1 && mes <= 12)
    {
        if (mes <= 7)
        {
            if (mes == 2)
            {
                if (ano % 4 == 0)
                {
                    if (dia >= 1 && dia <= 29)
                    {
                        printf("Data válida!\n");
                    }
                    else
                    {
                        printf("Data inválida!\n");
                    }
                }
                else
                {
                    if (dia >= 1 && dia <= 28)
                    {
                        printf("Data válida!\n");
                    }
                    else
                    {
                        printf("Data inválida!\n");
                    }
                }
            }
            else
            {
                if (mes % 2 == 0)
                {
                    if (dia >= 1 && dia <= 30)
                    {
                        printf("Data válida!\n");
                    }
                    else
                    {
                        printf("Data inválida!\n");
                    }
                }
                else
                {
                    if (dia >= 1 && dia <= 31)
                    {
                        printf("Data válida!\n");
                    }
                    else
                    {
                        printf("Data inválida!\n");
                    }
                }
            }
        }
        else
        {
            if (mes % 2 == 0)
            {
                if (dia >= 1 && dia <= 31)
                {
                    printf("Data válida!\n");
                }
                else
                {
                    printf("Data inválida!\n");
                }
            }
            else
            {
                if (dia >= 1 && dia <= 30)
                {
                    printf("Data válida!\n");
                }
                else
                {
                    printf("Data inválida!\n");
                }
            }
        }
    }
    else
    {
        printf("Data inválida!\n");
    }
}