// Faça um programa para converter uma letra maiúscula em letra minúscula. Use a tabela
// ASCII para resolver o problema.

#include <stdio.h>

int main(){
    char maiuscula, minuscula;
    printf("Digite a letra maiúscula: ");
    scanf("%c", &maiuscula);
    minuscula = maiuscula + 32;
    printf("A letra minúscula é: %c\n", minuscula);

    return 0;
}