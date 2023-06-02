// ATIVIDADE 4 - CÁLCULO - ADS NOTURNO - 2° SEMESTRE

/*
 * INTEGRANTES DO GRUPO:
 * CRYSTIAN EDUARDO FERRAZ SCHLEMPER
 * GIOVANI MURAKAMI LINO RODRIGUES
 * JOÃO ANTONIO COIMBRA NOVAES DETORE
 * JOÃO VITOR DA SILVEIRA EUGÊNIO
*/

#include <math.h>
#include <stdio.h>

float a, b, k;
int escolha;

void integrateXK(float k, float a, float b) {
  if (k < 0 && a * b <= 0) {
    printf("Integral não converge neses valores");
    return;
  }
  if (a < 0 && b < 0 && k < 0) {
    a = 1/((-k - 1) * (pow(a, -k - 1)));
    b = 1/((-k - 1) * (pow(b, -k - 1)));
    printf("I = %f",  b-a);
    return;
  }
    printf("I = %f", (pow(b, (k+1))/(k+1)) - (pow(a, (k+1))/(k+1)));
};

void integrate1X(float a, float b) {
  if (a * b <= 0) {
    printf("Integral não converge nesses valores");
    return;
  }
  if (a < 0 && b < 0) {
    a *= (-1);
    b *= (-1);
  }
  printf("I = %f", (log(b) - log(a)));
}

int main() {
  do {
    printf("\n");
    printf("==================================================================\n");
    printf("Seja bem-vindo(a) a calculadora de Integrais!\n");
    printf("Selecione as opções de 1 a 3\n");
    printf("==================================================================\n");
    printf("1.Integral de f(x) = x^k\n");
    printf("2.Integral de f(x) = 1/x\n");
    printf("3.Sair\n");
    while (scanf("%d", &escolha) != 1) {
      printf("Entrada inválida. Por favor, digite um valor numérico: \n");
      while (getchar() != '\n');
    }

    switch (escolha) {
    case 1:
      printf("Informe o valor de K\n");
      scanf("%f", &k);
      printf("Informe o valor de A\n");
      scanf("%f", &a);
      printf("Informe o valor de B\n");
      scanf("%f", &b);
      integrateXK(k, a, b);
      break;
    case 2:
      printf("Informe o valor de A\n");
      scanf("%f", &a);
      printf("Informe o valor de B\n");
      scanf("%f", &b);
      integrate1X(a, b);
      break;
    case 3:
      sair();
      break;
    default:
      printf("Valor inválido, digite um número entre 1 e 3");
    }
  } while (escolha != 3);

  return 0;
}

int sair() {
  printf("\n");
  printf("Saindo do programa...\n");
  exit(0);
}