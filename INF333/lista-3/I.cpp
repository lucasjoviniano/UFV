#include <iostream>
#include <vector>
using namespace std;

const int neutral = 0;
#define comp(a, b) ((a) + (b))

class BIT {
  vector<int> ft;

public:
  BIT(int n) { ft.assign(n + 1, 0); }

  int rsq(int i) {
    int sum = neutral;
    for (; i; i -= (i & -i))
      sum = comp(sum, ft[i]);
    return sum;
  }

  int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

  void update(int i, int v) {
    for (; i < (int)ft.size(); i += (i & -i))
      ft[i] = comp(v, ft[i]);
  }
};

long long input[100005];

int main() {
  ios_base::sync_with_stdio(0);

  int t;

  cin >> t;

  for (int i = 1; i <= t; i++) {
    cout << "Case " << i << ":\n";
    int n, q, idx, low, high;
    long long val;

    cin >> n >> q;
    BIT ft(n);

    for (int j = 1; j <= n; j++) {
      cin >> input[j];
      ft.update(j, input[j]);
    }

    for (int j = 1; j <= q; j++) {
      int x;

      cin >> x;

      if (x == 1) {
        cin >> idx;
        idx++;
        cout << input[idx] << '\n';
        ft.update(idx, -input[idx]);
        input[idx] = 0;
      } else if (x == 2) {
        cin >> idx;
        cin >> val;
        idx++;
        ft.update(idx, val);
        input[idx] += val;
      } else {
        cin >> low >> high;
        low++;
        high++;
        cout << ft.rsq(low, high) << '\n';
      }
    }
  }

  return 0;
}
