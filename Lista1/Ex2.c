#include <stdio.h>

int main()
{
    int menuOption;
    char names, *p;

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
            printf("Digite o Nome\n");
            // alocação dinâmica de memória para armazenar o nome
            // separar os nomes por /0
            // setar um ponteiro ao final do nome /0
            break;
        case 2:
            // remover memória alocada partindo de /0 até encontrar outro /0
            break;
        case 3:
            printf("%s\n", names);
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    } while (menuOption != 4);
}
