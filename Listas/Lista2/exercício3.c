// Faça uma agenda capaz de incluir, apagar, buscar e listar
// quantas pessoas o usuário desejar, porém, toda a informação
// incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
// Não pergunte para o usuário quantas pessoas ele vai incluir.
// Não pode alocar espaço para mais pessoas do que o
// necessário.
// Cada pessoa tem nome[10], idade e telefone.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    void *pBuffer;
    int menuOption, *numberPeoples;
    char searchName[10];
    size_t tamPeople;

    tamPeople = (sizeof(char) * 10) + (sizeof(int) * 1) + (sizeof(int) * 1);

    do
    {
        printf("--------------------MENU--------------------\n");
        printf("1) Adicionar Pessoa\n");
        printf("2) Remover Pessoa\n");
        printf("3) Buscar Pessoa\n");
        printf("4) Listar Agenda\n");
        printf("5) Sair\n");
        printf("--------------------------------------------\n");
        printf("\nSelecione uma opção: ");
        scanf("%d", &menuOption);

        switch (menuOption)
        {
        case 1:
            // SE FOR 1ª PESSOA
            if (pBuffer == NULL)
            {
                // USANDO POSIÇÃO 1 PARA ARMAZENAR QTDE PESSOAS
                pBuffer = malloc((sizeof(int) * 1) + tamPeople);
                numberPeoples = pBuffer;
                *numberPeoples = 1;

                printf("\n-------------ADICIONANDO PESSOA-------------\n");
                printf("Digite o nome: ");
                scanf("%s", (char *)pBuffer + (sizeof(int) * 1));
                printf("Digite a idade: ");
                scanf("%d", (int *)(pBuffer + (sizeof(int) * 1) + (sizeof(char) * 10)));
                printf("Digite o telefone: ");
                scanf("%d", (int *)(pBuffer + (sizeof(int) * 1) + (sizeof(char)) * 10 + (sizeof(int) * 1)));
                printf("\n\n");
            }
            // SE JÁ POSSUIR AO MENOS 1 PESSOA
            else
            {
                // INCREMENTA Nº DE PESSOAS
                *numberPeoples = *numberPeoples + 1;

                pBuffer = realloc(pBuffer, (sizeof(int) * 1) + (*numberPeoples * tamPeople));
                numberPeoples = pBuffer;
                pBuffer = pBuffer + (sizeof(int) * 1) + ((*numberPeoples - 1) * tamPeople);

                printf("\n-------------ADICIONANDO PESSOA-------------\n");
                printf("Digite o nome: ");
                scanf("%s", (char *)pBuffer);
                printf("Digite a idade: ");
                scanf("%d", (int *)(pBuffer + (sizeof(char) * 10)));
                printf("Digite o telefone: ");
                scanf("%d", (int *)(pBuffer + (sizeof(char)) * 10 + (sizeof(int) * 1)));
                printf("\n\n");

                pBuffer = numberPeoples;
            }

            break;
        case 2:
            pBuffer = pBuffer + (sizeof(int) * 1);
            printf("--------------REMOVENDO PESSOA--------------\n");
            printf("Digite o nome da pessoa: ");
            scanf("%s", searchName);

            for (int i = 0; i < *numberPeoples; i++)
            {
                if (strcmp(searchName, pBuffer + (tamPeople * i)) == 0)
                {
                    pBuffer = pBuffer + (tamPeople * i);
                    printf("\nPessoa encontrada!\n");

                    // LÓGICA PARA SOBRESCEVER A POSIÇÃO DO BUFFER
                    // PULANDO TODOS NOMES P ESQUERDA
                    // AO FIM RETIRAR TAMANHO DE 1 NOME DO BUFFER

                    // printf("Nome: %s\n", (char *)pBuffer);
                    // printf("Idade: %d\n", *(int *)(pBuffer + (sizeof(char) * 10)));
                    // printf("Telefone: %d\n", *(int *)(pBuffer + (sizeof(char) * 10) + (sizeof(int) * 1)));
                    // printf("\n\n");
                    // pBuffer = numberPeoples;
                    break;
                }
            }

            break;
        case 3:
            pBuffer = pBuffer + (sizeof(int) * 1);
            printf("\n--------------BUSCANDO PESSOA---------------\n");
            printf("Digite o nome da pessoa: ");
            scanf("%s", searchName);

            for (int i = 0; i < *numberPeoples; i++)
            {
                if (strcmp(searchName, pBuffer + (tamPeople * i)) == 0)
                {
                    pBuffer = pBuffer + (tamPeople * i);
                    printf("\nPessoa encontrada!\n");
                    printf("Nome: %s\n", (char *)pBuffer);
                    printf("Idade: %d\n", *(int *)(pBuffer + (sizeof(char) * 10)));
                    printf("Telefone: %d\n", *(int *)(pBuffer + (sizeof(char) * 10) + (sizeof(int) * 1)));
                    printf("\n\n");
                    pBuffer = numberPeoples;
                    break;
                }
            }

            // NÃO EXECUTAR SE ACHAR NOME
            // printf("Pessoa não encontrada!\n");
            pBuffer = numberPeoples;
            break;
        case 4:
            pBuffer = numberPeoples;
            pBuffer = pBuffer + (sizeof(int) * 1);

            printf("\n\n--------------LISTANDO AGENDA---------------\n");
            for (int i = 0; i < *numberPeoples; i++)
            {
                printf("Nome: %s\n", (char *)pBuffer);
                printf("Idade: %d\n", *(int *)(pBuffer + (sizeof(char) * 10)));
                printf("Telefone: %d\n", *(int *)(pBuffer + (sizeof(char) * 10) + (sizeof(int) * 1)));
                printf("\n\n");

                pBuffer = pBuffer + tamPeople;
            }

            pBuffer = numberPeoples;

            break;
        case 5:
            free(pBuffer);
            return 0;
            break;
        default:
            printf("\nDigite uma opção válida!\n\n");
            break;
        }
    } while (menuOption != 5);
}