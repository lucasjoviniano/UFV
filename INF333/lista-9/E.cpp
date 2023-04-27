#include <bits/stdc++.h>
#include <limits>

using namespace std;

int edmons_karp(int s, int t, vector<vector<int>> &graph) {
  int sum = 0;

  vector<int> parent(graph.size(), 0);
  vector<vector<int>> flow(graph.size(), vector<int>(graph.size(), 0));

  while (true) {
    vector<int> capacity(graph.size());

    capacity[s] = numeric_limits<int>::max();

    queue<int> q;
    q.push(s);

    while (!q.empty() && capacity[t] == 0) {
      int curr = q.front();
      q.pop();

      for (int i = 1; i < graph.size(); i++) {
        if (capacity[i] == 0 && graph[curr][i] > flow[curr][i]) {
          q.push(i);
          parent[i] = curr;
          capacity[i] = min(capacity[curr], graph[curr][i] - flow[curr][i]);
        }
      }
    }

    if (capacity[t] == 0)
      break;

    for (int c = t; c != s; c = parent[c]) {
      flow[parent[c]][c] += capacity[t];
      flow[c][parent[c]] -= capacity[t];
    }
    sum += capacity[t];
  }
  return sum;
}

int main() {
  int num, capacity, m, n1, n2, b, d;

  while (cin >> num) {
    int n = 2 * num + 1;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= num; i++) {
      cin >> capacity;
      graph[i][i + num] = capacity;
    }

    cin >> m;

    for (int i = 1; i <= m; i++) {
      cin >> n1 >> n2 >> capacity;
      graph[n1 + num][n2] = capacity;
    }

    cin >> b >> d;

    for (int i = 1; i <= b; i++) {
      cin >> n1;
      graph[0][n1] = numeric_limits<int>::max();
    }

    for (int i = 1; i <= d; i++) {
      cin >> n1;
      graph[n1 + num][n] = numeric_limits<int>::max();
    }

    cout << edmons_karp(0, n, graph) << endl;
  }
}
