// Escreva uma função que receba um array de inteiros V e os endereços de duas variáveis
// inteiras, min e max, e armazene nessas variaveis o valor mínimo e máximo do array.
// Escreva tambem uma funcão main que use essa função.

#include <stdio.h>

int func(int *, int *, int [], int);

void main()
{
    int min, max, *pmin, *pmax;
    int V[10]= {5,2,15,27,3,7,15,8,6,15};
    pmin = &min;
    pmax = &max;

    func(pmin, pmax, V, 10);

    printf("Valor mínimo: %d\nValor máximo: %d\n", min, max);
}

int func(int *min, int *max, int array[], int length)
{
    *min = 50;
    *max = 0;

    for(int i=0 ; i < length ; i++){
        if(array[i] > *max){
            *max = array[i];
        } else if(array[i] < *min){
            *min = array[i];
        }
    }
}