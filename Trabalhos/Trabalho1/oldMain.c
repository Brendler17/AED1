#include <stdio.h>
#include <stdlib.h>

// #define RAND_MAX = 50;

int main()
{
  int number, tamVetor, *vetor, *vetorInit, *vetorAux, *vetorSum;

  printf("Digite o tamanho de um vetor: ");
  scanf("%d", &tamVetor);

  vetor = (int *)malloc(sizeof(int) * tamVetor);

  vetorInit = vetor;

  for (int i = 0; i < tamVetor; i++)
  {
    // *vetor = rand();
    *vetor = i;
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
      // i--;

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

      if ((*vetor + *vetorSum) == number && *vetor != *vetorSum)
      {
        printf("Números encontrados.");
        // printf("%d\n%d", *vetor, *vetorSum);
        // vetorAux = vetor;
        // for (int k = 0; k < (tamVetor - i); k++)
        // {
        //   vetorAux++;
        //   *vetor = *vetorAux;
        //   vetor++;
        // }
        // vetorAux = vetorSum;
        // for (int k = 0; k < (tamVetor - i); k++)
        // {
        //   vetorAux++;
        //   *vetorSum = *vetorAux;
        //   vetorSum++;
        // }

        // tamVetor = tamVetor - 2;
        // vetor = (int *)realloc(vetorInit, sizeof(int) * tamVetor);
        // vetorInit = vetor;
      }
      else
      {
        vetorSum++;
      }
    }
    vetor++;
  }
}

// 0 1 2 3 4
// 6