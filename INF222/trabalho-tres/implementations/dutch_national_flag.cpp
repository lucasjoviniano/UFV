#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

std::vector<double> my_dutch(const std::vector<double> &unordered) {
  std::vector<double> less_than;
  std::vector<double> equal;
  std::vector<double> greater_than;

  std::copy_if(unordered.begin(), unordered.end(),
               std::back_inserter(less_than), [](double v) { return v < 0; });

  std::copy_if(unordered.begin(), unordered.end(), std::back_inserter(equal),
               [](double v) { return v == 0; });

  std::copy_if(unordered.begin(), unordered.end(),
               std::back_inserter(greater_than),
               [](double v) { return v > 0; });

  std::vector<double> ans;
  ans.reserve(unordered.size());

  ans.insert(ans.end(), less_than.begin(), less_than.end());
  ans.insert(ans.end(), equal.begin(), equal.end());
  ans.insert(ans.end(), greater_than.begin(), greater_than.end());

  return ans;
}

std::vector<double> djikstra_dutch(const std::vector<double> &unordered) {
  std::vector<double> values(unordered.begin(), unordered.end());
  int i = 0, j = 0, mid = 0, k = values.size() - 1;

  while (j <= k) {
    if (values[j] < mid) {
      std::swap(values[i++], values[j++]);
    } else if (values[j] > mid) {
      std::swap(values[j], values[k--]);
    } else {
      j++;
    }
  }

  return values;
}

int main() {
  std::vector<double> values{0,     1.618, 3.14, 2.718, -1.41,
                             0.577, 0,     0,    -9.8,  0};

  std::vector<double> result{-1.41, -9.8, 0,      0,     0,
                             0,     3.14, 0.5577, 1.618, 2.718};

  for (double i : djikstra_dutch(values)) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for (double i : my_dutch(values)) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  assert(djikstra_dutch(values) == result);
}
