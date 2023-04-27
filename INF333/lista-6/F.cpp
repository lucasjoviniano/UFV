#include <bits/stdc++.h>
using namespace std;

double npv(vector<int> &cfs, double irr) {
  double res = 0;
  for (auto it = cfs.rbegin(); it != cfs.rend(); it++) {
    res /= (1.0 + irr);
    res += *it;
  }
  return res;
}

int main() {
  int t, v;
  while (true) {
    cin >> t;
    if (t == 0)
      break;

    vector<int> cfs;

    for (int i = 0; i < t + 1; i++) {
      cin >> v;
      cfs.push_back(v);
    }

    double low = -1, high = 10000;

    while (high - low > 1e-5) {
      double mid = (low + high) / 2;
      double val = npv(cfs, mid);
      if (val > 0)
        low = mid;
      else
        high = mid;
    }

    cout << fixed << setprecision(2) << low << endl;
  }
}
