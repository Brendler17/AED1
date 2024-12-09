#include <stdio.h>

int main() {
  float price;

  printf("Digite o valor antigo do produto: ");
  scanf("%f", &price);

  if (price < 50.0) {
    printf("O novo valor do produto aumentou 5%% e está R$%.2f\n\n", price + (price * 5) / 100);
  }

  if (price >= 50 && price <= 100) {
    printf("O novo valor do produto aumentou 10%% e está R$%.2f\n\n", price + (price * 10) / 100);
  }

  if (price > 100) {
    printf("O novo valor do produto aumentou 55%% e está R$%.2f\n\n", price + (price * 15) / 100);
  }

  return 0;
}
