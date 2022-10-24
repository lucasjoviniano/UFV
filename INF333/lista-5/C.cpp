#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

int main() {
  int n;
  pair<double, double> p;

  while (true) {
    cin >> n;
    if (n == 0)
      break;
    vector<pair<double, double>> v(n);

    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
    }

    cin >> p.first >> p.second;

    bool c = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
      if (((v[i].second <= p.second + EPS && p.second < v[j].second) ||
           (v[j].second <= p.second + EPS && p.second < v[i].second)) &&
          (p.first - EPS < (v[j].first - v[i].first) *
                                   (p.second - v[i].second) /
                                   (v[j].second - v[i].second) +
                               v[i].first)) {
        c ^= true;
      }
    }

    if (c) {
      cout << "T\n";
    } else {
      cout << "F\n";
    }
  }
}
