#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
  int a, b, c, d, n;

  while (cin >> n) {
    if (n == 0)
      break;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    bool flag = true;

    for (int i = n - 1; i >= 0 && flag; i--) {
      for (int j = 0; j < n && flag; j++) {
        if (i == j)
          continue;
        for (int k = j + 1; k < n && flag; k++) {
          if (i == k)
            continue;
          for (int l = k + 1; l < n && flag; l++) {
            if (i == l)
              continue;
            if (v[i] == v[j] + v[k] + v[l]) {
              cout << v[i] << endl;
              flag = false;
            }
          }
        }
      }
    }
    if (flag)
      cout << "no solution";
  }
}
