#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void next(vector<int> &v) {
  int i, j;

  for (i = v.size() - 1; i > 0; i--) {
    if (v[i - 1] < v[i])
      break;
  }

  if (i == 0) {
    cout << "-1\n";
    return;
  }

  int x = v[i - 1], smallest = i;

  for (j = i + 1; j < v.size(); j++) {
    if (v[j] > x && v[j] < v[smallest])
      smallest = j;
  }

  swap(v[smallest], v[i - 1]);

  sort(v.begin() + i, v.end());

  for (const auto &c : v) {
    cout << c;
  }
  cout << '\n';
}

int main() {
  int n, c;

  cin >> n;

  while (n--) {
    cin >> c;
    vector<int> v(c, 0);
    for (int i = 0; i < c; i++) {
      cin >> v[i];
    }

    next(v);
  }
}
