#include <cmath>
#include <iomanip> //fixed e setprecision
#include <iostream>

using namespace std;
// Metodo bolha para ordenar um vetor
int Bolha(int a[], int n) {
  int temp;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
  }
}

double Media(int a[], int n) {
  double media = 0;
  for (int i = 0; i < n; i++) {
    media += a[i];
  }
  return (double)media / n;
}
double Mediana(int a[], int n) {
  double mediana;
  if (n % 2 == 0) {
    mediana = (a[n / 2 - 1] + a[n / 2 + 1 - 1]) / 2.0;

  } else {
    mediana = a[(n + 1) / 2 - 1];
  }
  return (double)mediana;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Bolha(a, n);
  cout << "Media: " << fixed << showpoint << setprecision(1) << Media(a, n)
       << endl;
  cout << "Mediana: " << fixed << showpoint << setprecision(1) << Mediana(a, n)
       << endl;
  return 0;
}
