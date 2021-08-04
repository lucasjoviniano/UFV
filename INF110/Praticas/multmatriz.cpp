#include <iomanip>
#include <iostream>

using namespace std;
int main() {
  // Multiplicar uma matriz A[m][n], por B[p][q]. Seu resultado ser� C[i][j].
  int A[100][100], B[100][100], C[100][100];
  int p, q, m, n;
  int i, j, k;
  cin >> m >> n;
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      cin >> A[i][j];

  cin >> p >> q;
  for (i = 0; i < p; i++)
    for (j = 0; j < q; j++)
      cin >> B[i][j];

  if (n != p)
    cout << "Imposs�vel multiplicar\n";
  else {
    for (i = 0; i < m; i++)
      for (j = 0; j < q; j++) {
        C[i][j] = 0;
        for (k = 0; k < n; k++)
          C[i][j] += A[i][k] * B[k][j];
      }
  }

  for (i = 0; i < m; i++)
    for (j = 0; j < q; j++)
      cout << setw(4) << C[i][j];
  cout << endl;

  return 0;
}
