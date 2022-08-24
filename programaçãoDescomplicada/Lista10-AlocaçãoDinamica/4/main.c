// Faça um programa que receba do usuário o tamanho de uma string e chame uma
// funcão para alocar dinamicamente essa string. Em seguida, o usuário deverá informar o
// conteúdo dessa string. O programa imprime a string sem suas vogais.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *allocation(int x);

int main()
{
    int tamString, remove = 0;
    char *string, *stringAux, *stringInit;

    printf("Digite o número de caracteres: ");
    scanf("%d", &tamString);

    string = allocation(tamString);

    if (string == NULL)
    {
        printf("Memória não alocada.");
    }

    printf("Digite a palavra: ");
    scanf("%s", &(*string));

    if (strlen(string) > (tamString))
    {
        printf("Erro! Palavra maior que o número de caracteres.\n");
        return 1;
    }

    stringInit = string;

    for (int i = 0; i < tamString; i++)
    {
        if (*string == 'A' || *string == 'a' || *string == 'E' || *string == 'e' || *string == 'I' || *string == 'i' || *string == 'O' || *string == 'o' || *string == 'U' || *string == 'u')
        {
            stringAux = string;
            stringAux++;
            while (*string != '\0')
            {
                *string = *stringAux;
                string++;
                stringAux++;
            }
            remove++;
            string = stringInit + remove;
            i--;
        }
        else
        {
            string++;
        }
    }

    string = (char *)realloc(stringInit, tamString - remove);

    printf("%s\n", string);

    free(string);
}

char *allocation(int x)
{
    char *heap;

    heap = (char *)malloc(sizeof(char) * x + 1);

    return heap;
}