#include <bits/stdc++.h>
using namespace std;

struct fraction {
  int M;
  int D;
};

int main() {
  int m, n;
  while (cin >> n >> m) {
    if (m == 1 && n == 1)
      break;

    fraction L = {0, 1}, M = {1, 1}, R = {1, 0};

    while (true) {
      long double t1 = (long double)m / n, t2 = (long double)M.M / M.D;
      if (t1 < t2) {
        cout << "R";
        R = M;
        M.M += L.M;
        M.D += L.D;
      } else if (t1 > t2) {
        cout << "L";
        L = M;
        M.M += R.M;
        M.D += R.D;
      } else {
        cout << endl;
        break;
      }
    }
  }
  return 0;
}
