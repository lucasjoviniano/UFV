#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

bool erdos_gallai(const std::vector<int> &v) {

  if (std::accumulate(v.begin(), v.end(), 0) % 2 != 0) {
    return false;
  }

  for (int k = 0; k <= v.size(); k++) {
    long long dk = std::accumulate(v.begin(), v.begin() + k, 0);
    long long mdk =
        std::accumulate(v.begin() + k, v.end(), 0,
                        [k](int a, int b) { return a + std::min(k, b); });

    if (dk > k * (k - 1) + mdk) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, t;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> t;

    if (t == 0) {
      std::cout << "HAPPY\n";
      continue;
    }

    std::vector<int> v(t, 0);
    for (int j = 0; j < t; j++)
      std::cin >> v[j];

    if (v.size() == 1 && v[0] != 0) {
      std::cout << "SAD\n";
      continue;
    }

    std::sort(v.begin(), v.end(), std::greater<>());

    std::cout << (erdos_gallai(v) ? "HAPPY\n" : "SAD\n");
  }

  return 0;
}
