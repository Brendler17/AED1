#include <stdio.h>
#include <stdlib.h>

int main()
{
  int number, tamVetor, *vetor, *vetorInit, *vetorAux, *vetorSum;

  printf("Digite o tamanho de um vetor: ");
  scanf("%d", &tamVetor);

  vetor = (int *)malloc(sizeof(int) * tamVetor);
  vetorInit = vetor;

  for (int i = 0; i < tamVetor; i++)
  {
    *vetor = i;
    // *vetor = rand() % 100;
    vetor++;
  }

  vetor = vetorInit;
  printf("Vetor original:\n");
  for (int i = 0; i < tamVetor; i++)
  {
    printf("%d\t", *vetor);
    vetor++;
  }
  vetor = vetorInit;

  printf("\nDigite um número: ");
  scanf("%d", &number);

  // Verifica se existe número informado no vetor
  for (int i = 0; i < tamVetor; i++)
  {
    if (*vetor == number)
    {
      printf("\nO número indicado foi encontrado.\n");
      vetorAux = vetor;

      for (int j = 0; j < (tamVetor - i); j++)
      {
        vetorAux++;
        *vetor = *vetorAux;
        vetor++;
      }

      tamVetor = tamVetor - 1;
      vetor = (int *)realloc(vetorInit, sizeof(int) * tamVetor);
      
      vetorInit = vetor;
      printf("Novo vetor:\n");
      for (int i = 0; i < tamVetor; i++)
      {
        printf("%d\t", *vetor);
        vetor++;
      }
      printf("\n\n");

      free(vetorInit);

      return 0;
    }
    else
    {
      vetor++;
    }
  }

  // Verificar se existe 2 números do vetor que somados resultam no número indicado
  vetor = vetorInit;
  vetorSum = vetorInit;
  for (int i = 0; i < tamVetor; i++)
  {
    for (int j = 0; j < tamVetor; j++)
    {
      if ((*vetor + *vetorSum == number) && vetor != vetorSum)
      {
        printf("A soma de %d e %d é igual: %d.\n", *vetor, *vetorSum, number);

        vetorAux = vetor;
        for (int k = 0; k < (tamVetor - i); k++)
        {
          vetorAux++;
          *vetor = *vetorAux;
          vetor++;
        }

        tamVetor = tamVetor - 1;
        vetor = (int *)realloc(vetorInit, sizeof(int) * tamVetor);
        vetorInit = vetor;

        vetorAux = vetorSum;
        for (int k = 0; k < (tamVetor - j); k++)
        {
          vetorSum++;
          *vetor = *vetorSum;
          vetor++;
        }

        tamVetor = tamVetor - 1;
        vetor = (int *)realloc(vetorInit, sizeof(int) * tamVetor);

        vetorInit = vetor;
        printf("Novo vetor:\n");
        for (int i = 0; i < tamVetor; i++)
        {
          printf("%d\t", *vetor);
          vetor++;
        }
        printf("\n\n");

        free(vetorInit);

        return 0;
      }
      else
      {
        vetorSum++;
      }
    }
    
    vetorSum = vetorInit;
    vetor++;
  }

  printf("Número não encontrado.");
  free(vetorInit);
  return 0;
}