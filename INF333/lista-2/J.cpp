#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int bubble(std::vector<int> &v) {
  if (v.size() == 0 || v.size() == 1)
    return 0;

  int moves = 0;

  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = v.size() - 1; j > i; j--) {
      if (v[j] < v[j - 1]) {
        std::swap(v[j], v[j - 1]);
        moves++;
      }
    }
  }

  return moves;
}

int main() {
  std::string line;
  std::getline(std::cin, line);
  std::stringstream ss(line);

  int n;

  ss >> n;
  for (int i = 0; i < n; i++) {
    std::getline(std::cin, line);
    ss.clear();
    ss.str(line);
    int l;
    ss >> l;

    std::getline(std::cin, line);
    ss.clear();
    ss.str(line);
    std::vector<int> v(l);
    for (int i = 0; i < l; i++)
      ss >> v[i];

    std::cout << "Optimal train swapping takes " << bubble(v) << " swaps.\n";
  }

  return 0;
}
