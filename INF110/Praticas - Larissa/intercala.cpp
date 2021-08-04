#include <iostream>
using namespace std;
unsigned int n;
int main() {
  cin >> n;
  long long int a[n], b[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int j = 0; j < n; j++)
    cin >> b[j];

  for (int i = 0; i < n; i++)
    cout << a[i] << " " << b[i] << " ";

  cout << "\n";
  return 0;
}
