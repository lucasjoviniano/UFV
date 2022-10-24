#include <bits/stdc++.h>
const double PI = acos(-1);
using namespace std;

int main() {
  double r, n;

  while (cin >> r >> n) {
    if (n == 1) {
      cout << fixed << setprecision(10) << r << " " << 0.0 << " " << 0.0
           << endl;
      continue;
    }

    if (n == 2) {
      cout << fixed << setprecision(10) << r / 2.0 << " " << 0.0 << " "
           << PI * r * r / 2.0 << endl;
      continue;
    }

    double ang = PI / n;
    double alpha = sin(ang);
    double a = (r * alpha) / (1.0 + alpha);
    double a2 = sqrt((r - a) * (r - a) - a * a);
    double b = n * a * (a2 - (PI / 2 - ang) * a);
    double c = PI * r * r - b - (n * PI * a * a);

    cout << fixed << setprecision(10) << a << " " << b << " " << c << endl;
  }

  return 0;
}
