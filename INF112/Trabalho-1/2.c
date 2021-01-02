#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int** alocarMatriz(int); // Aloca as Matrizes
void deletarMatriz(long int**,int); // Desaloca as Matrizes
void lerMatriz(long int**, int); // Lê os elementos da matriz
long int** multiplicarMatriz(long int**, long int**, int); // Função recursiva da multiplicação
long int** submatriz(long int**, int, int, int); // Responsável pela divisão da matriz
long int** soma(long int**, long int**, int); // Soma as matrizes
void somaB(long int**, long int**, long int**, int n); // Variação da função de soma
void subtraiB(long int**, long int**, long int**, int n); // Variação da função de subtração
long int** subtrai(long int**, long int**, int); // Subtrai as Matrizes
void produto(long int**, long int**, long int**, int);
void uniao(long int**, long int**, long int**, long int**, long int**, int); // Junta pedaçõs das matrizes
void imprimeMatriz(long int**, int); // Imprime a matriz na tela
int potencia(int); // Verifica se a dimensão inserida é uma potência de 2

int main() {
  int n, k;

  // Lê a ordem da Matriz
  scanf("%d", &n);
  
  // Declara as matrizes
  long int** matrizA = NULL;
  long int** matrizB = NULL;
  long int** matrizC = NULL;

  // Verifica se a ordem da matriz é uma potência de 2
  if (potencia(n) == 0) { // Se não for
    k = 2;
    while (k < n)  
      k *= 2; // Acha a potência mais próxima
  } else { // Se o n for uma potência de 2
    k = n;
  }

  // Aloca as matrizes A e B de ordem k x k
  matrizA = alocarMatriz(k);
  matrizB = alocarMatriz(k);

  // Lê as matrizes
  lerMatriz(matrizA, n);
  lerMatriz(matrizB, n);
    
  // Resultado do produto A x B
  matrizC = multiplicarMatriz(matrizA, matrizB, k);

  // Imprime o resultado
  imprimeMatriz(matrizC, n);

  // Desaloca as matrizes
  deletarMatriz(matrizA, k);
  deletarMatriz(matrizB, k);
  deletarMatriz(matrizC, k);

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

void lerMatriz(long int** m, int ordem) {
  for (int i = 0; i < ordem; i++) {
    for (int j = 0; j < ordem; j++) {
      scanf("%ld", &m[i][j]);
    }
  }
}

void deletarMatriz(long int** m, int ordem) {
  for (int i = 0; i < ordem; i++) {
    free(m[i]);
  }
  free(m);
}

int potencia(int n) {
  while(n >= 2) 
    n/= 2;      // Realiza divisões sucessivas enquanto n não for menor que 2
  if (n % 2 == 0)
    return 1; // Se for divisível por 2, é uma potência de 2
  else
    return 0; // Se não for divisível por 2, não é uma potência de 2
}
void produto(long int** a, long int** b, long int** c, int ordem) {
  // Aplica a definição
    for (int k = 0; k < ordem; k++)
      for (int i = 0; i < ordem; i++)
        for (int j = 0; j < ordem; j++)
          c[k][i] += (a[k][j] * b[j][i]);
}

long int** multiplicarMatriz(long int** a, long int** b, int n) {
  long int** c = alocarMatriz(n);
  if (n <= 32) { // Se a matriz tiver poucos elementos, reliza a multiplicação direto
    produto(a, b, c, n);
  } else {
    // Cria as submatrizes de A e B
    long int** a11 = submatriz(a, n, 0, 0);
    long int** a12 = submatriz(a, n, 0, n/2);
    long int** a21 = submatriz(a, n, n/2, 0);
    long int** a22 = submatriz(a, n, n/2, n/2);
    long int** b11 = submatriz(b, n, 0, 0);
    long int** b12 = submatriz(b, n, 0, n/2);
    long int** b21 = submatriz(b, n, n/2, 0);
    long int** b22 = submatriz(b, n, n/2, n/2);

    // Aloca duas matrizes auxiliares
    long int** mA = alocarMatriz(n/2);
    long int** mB = alocarMatriz(n/2);

    // Realiza as operações com as matrizes M que resultarão nas submatrizes de C 
    // e, consequentemente, na matriz C em si
    somaB(a11, a22, mA, n/2);
    somaB(b11, b22, mB, n/2);
    long int** m1 = multiplicarMatriz(mA, mB, n/2); // M1 = (a11 + a22)(b11 + b22)
    somaB(a21, a22, mA, n/2);
    long int** m2 = multiplicarMatriz(mA, b11, n/2); // M2 = (a21 + a22)b11
    subtraiB(b12, b22, mA, n/2);
    long int** m3 = multiplicarMatriz(a11, mA, n/2); // M3 = a11(b12 - b22)
    subtraiB(b21, b11, mA, n/2);
    long int** m4 = multiplicarMatriz(a22, mA, n/2); // M4 = a22(b21 - b22)
    somaB(a11, a12, mA, n/2);
    long int** m5 = multiplicarMatriz(mA, b22, n/2); // M5 = (a11 + a12)b22
    subtraiB(a21, a11, mA, n/2);
    somaB(b11, b12, mB, n/2);
    long int** m6 = multiplicarMatriz(mA, mB, n/2); // M6 = (a21 - a11)(b11 + b12)
    subtraiB(a12, a22, mA, n/2);
    somaB(b21, b22, mB, n/2);
    long int** m7 = multiplicarMatriz(mA, mB, n/2); // M7 = (a12 - a22)(b21 + b22)
    
    subtraiB(m4, m5, mA,  n/2);
    somaB(m1, m7, mB, n/2);
    long int** c11 = soma(mA, mB, n/2); // C11 = m1 + m4 - m5 + m7
    long int** c12 = soma(m3, m5, n/2); // C12 = m3 + m5
    long int** c21 = soma(m2, m4, n/2); // C21 = m2 + m4
    subtraiB(m1, m2, mA, n/2);
    somaB(m3, m6, mB, n/2);
    long int** c22 = soma(mA, mB, n/2); // C22 = m1 - m2 + m3 + m6

    // "Transfere" os valores das submatrizes de C para a matriz C em si
    for (int i = 0; i < n/2; i++) {
      memcpy(c[i], c11[i], (n/2)* sizeof(long int));  
      memcpy((c[i] + n/2), c12[i], (n/2) * sizeof(long int));
      memcpy((c[i + n/2]), c21[i], (n/2) * sizeof(long int));
      memcpy((c[i + n/2] + n/2), c22[i], (n/2) * sizeof(long int));
    }

    // Desaloca as matrizes
    deletarMatriz(a11, n/2);
    deletarMatriz(a12, n/2);
    deletarMatriz(a21, n/2);
    deletarMatriz(a22, n/2);
    deletarMatriz(b11, n/2);
    deletarMatriz(b12, n/2);
    deletarMatriz(b21, n/2);
    deletarMatriz(b22, n/2);
    deletarMatriz(mA, n/2);
    deletarMatriz(mB, n/2);
    deletarMatriz(m1, n/2);
    deletarMatriz(m2, n/2);
    deletarMatriz(m3, n/2);
    deletarMatriz(m4, n/2);
    deletarMatriz(m5, n/2);
    deletarMatriz(m6, n/2);
    deletarMatriz(m7, n/2);
    deletarMatriz(c11, n/2);
    deletarMatriz(c12, n/2);
    deletarMatriz(c21, n/2);
    deletarMatriz(c22, n/2);
  }
  return c;
}

long int** submatriz(long int **m, int n, int in_linha, int in_coluna) {
  long int** sub = alocarMatriz(n/2);
  for (int i = 0; i < n/2; i++)
    memcpy(sub[i], m[i + in_linha] + in_coluna, (n/2) * sizeof(long int));
  return sub;
}

long int** soma(long int** a, long int** b, int n) {
  long int** aux = alocarMatriz(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      aux[i][j] = a[i][j] + b[i][j];

  return aux;
}

void somaB(long int** a, long int** b, long int** soma, int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      soma[i][j] = a[i][j] + b[i][j];
}

long int** subtrai(long int** a, long int** b, int n) {
  long int** aux = alocarMatriz(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      aux[i][j] = a[i][j] - b[i][j];

  return aux;
}

void subtraiB(long int** a, long int** b, long int** soma, int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      soma[i][j] = a[i][j] - b[i][j];
}
void imprimeMatriz(long int** m, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-1; j++) {
      printf("%ld ", m[i][j]);
    }
    printf("%ld\n", m[i][n-1]);
  }
}
