#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

void bfs(int beg, std::vector<std::vector<int>> &graph,
         std::vector<bool> &visited) {
  std::queue<int> q;
  q.push(beg);

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int u : graph[v])
      if (!visited[u]) {
        q.push(u);
        visited[u] = true;
      }
  }
}

int main() {
  while (true) {
    int n;
    std::cin >> n;

    if (n == 0)
      break;

    std::vector<std::vector<int>> graph(n + 1);

    while (true) {
      int u;
      std::cin >> u;

      if (u == 0)
        break;

      while (true) {
        int v;
        std::cin >> v;

        if (v == 0)
          break;

        graph[u].push_back(v);
      }
    }

    int count;
    std::cin >> count;

    for (int i = 0; i < count; i++) {
      int beg;
      std::cin >> beg;

      std::vector<bool> visited(n + 1, false);
      bfs(beg, graph, visited);

      std::cout << std::count(std::next(visited.begin()), visited.end(), false);

      for (int i = 1; i <= n; i++)
        if (!visited[i])
          std::cout << ' ' << i;

      std::cout << std::endl;
    }
  }
  return 0;
}
