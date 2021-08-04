#include <iostream>
using namespace std;
long long int n;
int main() {
  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    cin >> n;
    long long int val, a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ha = false;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] == a[j]) {
          ha = true;
          val = a[i];
          break;
        }
      }
    }
    if (ha) {
      cout << "SIM: " << val << endl;
    } else {
      cout << "NAO\n";
    }
  }
  return 0;
}
