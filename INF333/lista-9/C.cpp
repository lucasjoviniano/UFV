#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, const vector<vector<int>> &graph, vector<bool> &visited,
         vector<int> &computer) {
  visited[u] = true;
  int v;
  for (int i = 0; i < graph[u].size(); i++) {
    v = graph[u][i];
    if (computer[v] == -1 ||
        (!visited[computer[v]] && dfs(computer[v], graph, visited, computer))) {
      computer[v] = u;
      return true;
    }
  }
  return false;
}

int max_flow(vector<int> &computer, const vector<vector<int>> &graph,
             vector<bool> &visited, vector<int> &quant) {
  fill(computer.begin(), computer.end(), -1);
  int result = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < quant[i]; j++) {
      fill(visited.begin(), visited.end(), false);
      if (dfs(i, graph, visited, computer))
        result++;
      else
        return 0;
    }
  }
  return result;
}

int main() {
  string s;
  vector<int> quant(26);
  vector<int> computer(10, -1);
  vector<bool> visited(26, false);
  vector<vector<int>> graph(26);

  while (getline(cin, s)) {
    int n = 0;
    for (int i = 0; i < 26; i++) {
      graph[i].clear();
      quant[i] = 0;
    }

    do {
      int x = s[0] - 'A';
      quant[x] = s[1] - '0';
      n += quant[x];

      for (int i = 3; i < s.size() - 1; i++) {
        graph[x].push_back(s[i] - '0');
      }
    } while (getline(cin, s) && !s.empty());

    if (n > 10) {
      printf("!");
    } else if (max_flow(computer, graph, visited, quant) == n) {
      for (int i = 0; i < 10; i++) {
        if (computer[i] == -1) {
          cout << "_";
        } else {
          cout << char(computer[i] + 'A');
        }
      }
    } else {
      cout << "!";
    }

    cout << endl;
  }
  return 0;
}
