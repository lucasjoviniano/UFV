#include <iostream>
using namespace std;
unsigned int m, n;
long long int v;
int main() {
  cin >> m >> n;
  long long int a[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  cin >> v;
  int cont = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == v)
        cont++;
    }
    cout << cont << "\n";
    cont = 0;
  }
  return 0;
}
