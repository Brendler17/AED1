#include <stdio.h>

int main() {
  int number;
  int hundred, ten, unit;

  printf("Digite um número inteiro de até 3 digitos (100-999): ");
  scanf("%d", &number);

  if (100 > number || number > 999) {
    printf("Número inválido!");
    return 1;
  }

  hundred = number / 100;
  ten = (number / 10) % 10;
  unit = number % 10;

  printf("O número invertido é %d", unit);
  printf("%d", ten);
  printf("%d.\n\n", hundred);

  return 0;
}
