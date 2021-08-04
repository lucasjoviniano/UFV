#include <iomanip>
#include <iostream>

using namespace std;
int n, soma, somacred;
double cra;
int main() {
  cin >> n;
  int nf[n], cred[n];
  for (int i = 0; i < n; i++) {
    cin >> nf[i];
  }
  somacred = 0;
  for (int i = 0; i < n; i++) {
    cin >> cred[i];
    somacred += cred[i];
  }
  soma = 0;
  for (int i = 0; i < n; i++) {
    soma += nf[i] * cred[i];
  }
  cout << setiosflags(ios::fixed) << setprecision(1) << double(soma) / somacred
       << endl;
  return 0;
}
