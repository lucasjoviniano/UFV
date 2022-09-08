#include <iostream>
#include <vector>

const std::vector<int> getInitialPositions(int n) {
  int car, position, err;

  std::vector<int> v(n, -1);

  for (int i = 0; i < n; i++) {
    std::cin >> car >> position;
    // std::cout << "car: " << car << ", position: " << position << std::endl;

    int initialPosition = i + position;

    if (initialPosition <= 0 && initialPosition > n) {
      err = 1;
    }

    if (v[initialPosition] != -1) {
      err = 1;
    }

    if (err == 1)
      continue;

    v[initialPosition] = car;
  }

  if (err == 1)
    return {};
  else
    return v;
}

int main() {
  int n;

  std::cin >> n;

  while (n != 0) {
    // std::cout << "n = " << n << std::endl;
    std::vector<int> v = getInitialPositions(n);

    if (v.size() > 0) {
      for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1)
          std::cout << v[i];
        else
          std::cout << v[i] << " ";
      }
      std::cout << "\n";
    } else {
      std::cout << "-1\n";
    }

    std::cin >> n;
  }

  return 0;
}
