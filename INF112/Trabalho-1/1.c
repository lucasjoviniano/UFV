#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int** alocarMatriz(int);
void deletarMatriz(long int**,int);
void lerMatriz(long int**, int);
void multiplicarMatriz(long int**, long int**, long int**, int);

int main() {

  int n;

  scanf("%d", &n); // Lê a ordem da Matriz

  // Aloca as três matrizes necessárias
  long int** matrizA = alocarMatriz(n);
  long int** matrizB = alocarMatriz(n);
  long int** matrizC = alocarMatriz(n);

  // Lê as matrizes que vão compor o produto
  lerMatriz(matrizA, n);
  lerMatriz(matrizB, n);

  // Realiza a multiplicação
  multiplicarMatriz(matrizA, matrizB, matrizC, n);

  // Imprime a matriz na tela
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      printf("%ld ", matrizC[i][j]);
    }
    printf("%ld\n", matrizC[i][n-1]);
  }

  // Desaloca as matrizes
  deletarMatriz(matrizA, n);
  deletarMatriz(matrizB, n);
  deletarMatriz(matrizC, n);

  return 0;
}

long int** alocarMatriz(int ordem) {
  long int** m = (long int**) calloc(ordem, sizeof(long int));
  for (int i = 0; i < ordem; i++) {
    m[i] = (long int*) calloc(ordem, sizeof(long int));
    memset(m[i], 0, ordem * sizeof(long int));
  }

  return m;
}

void deletarMatriz(long int** m, int ordem) {
  for (int i = 0; i < ordem; i++) {
    free(m[i]);
  }
  free(m);
}

void lerMatriz(long int** m, int ordem) {
  for (int i = 0; i < ordem; i++) {
    for (int j = 0; j < ordem; j++) {
      scanf("%ld", &m[i][j]);
    }
  }
}

void multiplicarMatriz(long int** a, long int** b, long int** c, int n) {
  // Aplica a definição
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < n; j++)
        c[k][i] += (a[k][j] * b[j][i]);
}
