// Faça um programa que armazena nomes:
// • O programa deve armazenar todos os nomes na mesma string.
// • O tamanho da string deve crescer e diminuir conforme nomes
// forem colocados ou removidos. Não pode ter desperdício de memória.
// • Faça o seguinte menu:
// 1) Adicionar nome
// 2) Remover nome
// 3) Listar
// 4) Sair

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int menuOption;
    char *names, *pNames;
    size_t tamString;

    printf("1) Adicionar Nome\n");
    printf("2) Remover Nomes\n");
    printf("3) Listar Nomes\n");
    printf("4) Sair\n");

    do
    {
        printf("\nSelecione uma opção: ");
        scanf("%d", &menuOption);

        switch (menuOption)
        {
        case 1:
            printf("Digite o Nome: ");
            // se for 1º nome
            if (names == NULL)
            {
                names = (char *)malloc(sizeof(char) * 15);
                scanf("%s", names);
                tamString = strlen(names) + 1;
                names = (char *)realloc(names, sizeof(char) * tamString);
            }
            else
            {
                names = (char *)realloc(names, sizeof(char) * (tamString + 15));
                pNames = names;

                while (*pNames != '\0')
                {
                    pNames++;
                }

                *pNames = '/';
                pNames++;
                scanf("%s", pNames);
                tamString = strlen(names) + 1;
                names = (char *)realloc(names, sizeof(char) * tamString);
            }
            break;
        case 2:
            pNames = names;
            pNames = pNames + strlen(names);

            while (*pNames != '/')
            {
                pNames--;
            }

            *pNames = '\0';
            tamString = strlen(names) + 1;
            names = (char *)realloc(names, sizeof(char) * tamString);

            break;
        case 3:
            tamString = strlen(names);
            pNames = names;
            for (int i = 0; i < tamString; i++)
            {
                if (*pNames != '/')
                {
                    printf("%c", *pNames);
                }
                else
                {
                    printf("\n");
                }
                pNames++;
            }
            break;
        case 4:
            free(names);
            return 0;
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    } while (menuOption != 4);
}