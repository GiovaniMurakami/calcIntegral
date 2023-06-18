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

void integrate1X(float a, float b) {
  //caso o intervalo de a e b contenha 0, integral não converge
  if (a * b <= 0) {
    printf("Integral não converge nesses valores");
    return;
  }
  //módulo de A e B
  if (a < 0 && b < 0) { 
    a *= (-1);
    b *= (-1);
  }
  printf("I = %f", (log(b) - log(a)));
}

void integrateXK(float k, float a, float b) {
  int aux = k;
  //Caso k seja decimal e positivo
  //e x negativo
  //integral indefinida nesses valores
  if (k != aux && 
      k > 0 && 
      a < 0 || 
      b < 0) {
        printf("Integral não definida com k positivo e decimal e x < 0");
        return;
  }
  //Caso k seja decimal e negativo
  //e x negativo ou igual a zero
  //integral indefinida nesses valores
  if (k != aux && 
      k < 0 && 
      a <= 0 || 
      b <= 0) {
        printf("Integral não definida com k negativo e decimal e x <= 0");
        return;
  }
  //caso k = -1, necessário cálcular integral de 1/x
  if (k == -1) {
    printf("Integral não definida com k = -1!");
    return;
  }
  //caso k negativo e o intervalo de a e b contenha 0, integral não converge
  if (k < 0 && a * b <= 0) {
    printf("Integral não converge neses valores");
    return;
  }
  //caso k < 0 e diferente de -1, 
  //necessário calcular quando k < 0, 1/(-k-1) * x ^(-k-1) 
  //tanto no momento 'a' quanto no momento 'b'
  //o resultado da integral se dá por b-a
  if (a < 0 && 
      b < 0 && 
      k < 0) {
        a = 1/-((-k - 1) * (pow(a, -k - 1)));
        b = 1/-((-k - 1) * (pow(b, -k - 1)));  
        printf("I = %f",  b-a);
        return;
  }
    printf("I = %f", (pow(b, (k+1))/(k+1)) - (pow(a, (k+1))/(k+1)));
};

int main() {
  do {
    printf("\n");
    printf("==================================================================\n");
    printf("INTEGRAL DEFINIDA DE f(x) DE a até b\n");
    printf("Selecione uma das opções: 1 a 3\n");
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
      while (scanf("%f", &k) != 1) {
        printf("Entrada inválida. Por favor, digite um valor numérico: \n");
        while (getchar() != '\n');
      }
      printf("Informe o valor de A\n");
      while (scanf("%f", &a) != 1) {
        printf("Entrada inválida. Por favor, digite um valor numérico: \n");
        while (getchar() != '\n');
      }
      printf("Informe o valor de B\n");
      while (scanf("%f", &b) != 1) {
        printf("Entrada inválida. Por favor, digite um valor numérico: \n");
        while (getchar() != '\n');
      }
      integrateXK(k, a, b);
      break;
    case 2:
      printf("Informe o valor de A\n");
      while (scanf("%f", &a) != 1) {
        printf("Entrada inválida. Por favor, digite um valor numérico: \n");
        while (getchar() != '\n');
      }
      printf("Informe o valor de B\n");
      while (scanf("%f", &b) != 1) {
        printf("Entrada inválida. Por favor, digite um valor numérico: \n");
        while (getchar() != '\n');
      } 
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