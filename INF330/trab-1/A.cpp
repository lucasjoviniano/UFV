#include <iostream>
#include <vector>

int main() {
  int cases, n, m;

  std::cin >> cases;

  while (cases--) {
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> matrix[i][j];
      }
    }

    bool condition = true;

    for (int i = 0; i < m; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++)
        sum += matrix[j][i];
      if (sum != 2) {
        condition = false;
      }
    }

    std::vector<std::vector<int>> pairs(n, std::vector<int>(n));

    if (condition) {
      for (int i = 0; i < m; i++) {
        int a = -1, b = -1;
        for (int j = 0; j < n; j++) {
          if (matrix[j][i]) {
            if (a == -1) {
              a = j;
            } else if (b == -1) {
              b = j;
            } else {
              condition = false;
              break;
            }
          }
        }
        if (a == -1 || b == -1 || !condition || pairs[a][b]) {
          condition = false;
        } else {
          pairs[a][b] = 1;
        }
      }
    }
    std::cout << (condition ? "Yes" : "No") << std::endl;
  }

  return 0;
}
