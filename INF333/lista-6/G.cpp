#include <bits/stdc++.h>
using namespace std;

double p, q, r, s, t, u;

double f(double x) {
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bisecao() {
  double x, hi = 1, lo = 0;
  for (int i = 1; i <= 100; i++) {
    x = (hi + lo) / 2;
    if (f(x) * f(lo) <= 0)
      hi = x;
    else
      lo = x;
  }
  return x;
}

int main() {
  while (cin >> p >> q >> r >> s >> t >> u) {
    if (f(1) * f(0) > 0)
      cout << "No solution\n";
    else
      cout << fixed << setprecision(4) << bisecao() << endl;
  }

  return 0;
}
