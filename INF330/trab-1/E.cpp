#include <iostream>
#include <string>
#include <vector>

int component = 0;

void dfs(const std::vector<std::string> &table,
         std::vector<std::vector<bool>> &visited, int l, int c) {
  if (l < 0 || l >= table.size() || c < 0 || c >= table[l].length() ||
      visited[l][c] || table[l][c] != '1')
    return;

  visited[l][c] = true;
  component++;

  dfs(table, visited, l + 1, c);
  dfs(table, visited, l - 1, c);
  dfs(table, visited, l, c + 1);
  dfs(table, visited, l, c - 1);
  dfs(table, visited, l - 1, c - 1);
  dfs(table, visited, l + 1, c + 1);
  dfs(table, visited, l + 1, c - 1);
  dfs(table, visited, l - 1, c + 1);
}

int main() {
  int n;
  std::string aux;
  std::cin >> n;
  std::getline(std::cin, aux);
  std::getline(std::cin, aux);

  while (n--) {
    std::vector<std::string> v;
    while (std::getline(std::cin, aux)) {
      if (aux.length() == 0)
        break;

      v.push_back(aux);
    }

    std::vector<std::vector<bool>> visited(
        v.size(), std::vector<bool>(v[0].length(), false));

    int biggest = 0;

    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].length(); j++) {
        if (v[i][j] == '1' && !visited[i][j]) {
          dfs(v, visited, i, j);
          biggest = std::max(biggest, component);
          component = 0;
        }
      }
    }

    std::cout << biggest << std::endl;

    if (n > 0)
      std::cout << std::endl;
  }

  return 0;
}
