#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int TIME_SCAN = 5;
  const int TIME_CASH = 15;

  int n;
  cin >> n;
  vector<int> v(n, 0);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  long long min_time = 1123123123;

  for (int i = 0; i < n; i++) {
    long long total = 0;
    for (int j = 0; j < v[i]; j++) {
      int t;
      cin >> t;
      total += t;
    }
    total *= TIME_SCAN;
    total += TIME_CASH * v[i];
    min_time = min(total, min_time);
  }

  cout << min_time << "\n";
}