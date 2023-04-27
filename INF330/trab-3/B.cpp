#include <bits/stdc++.h>

using namespace std;

int dist(const string &a, const string &b) {
  int ans = 0;

  for (int i = 0; i < 4; ++i)
    ans += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i]));

  return ans;
}

int prim(vector<vector<pair<int, int>>> &graph) {

  priority_queue<pair<int, int>> q;

  vector<bool> visited(graph.size());

  q.push(make_pair(0, 0));
  int c = 0, ans = 0;

  while (c < graph.size()) {
    int u = q.top().second;
    int v = -q.top().first;

    q.pop();

    if (!visited[u]) {
      visited[u] = true;
      c++;
      ans += v;

      for (int i = 0; i < graph[u].size(); ++i)
        q.push(make_pair(-graph[u][i].second, graph[u][i].first));
    }
  }

  return ans;
}

int main() {
  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    vector<string> keys(n, "");

    int lowest = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
      cin >> keys[i];
      lowest = min(lowest, dist(keys[i], "0000"));
    }

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        int w = dist(keys[i], keys[j]);
        graph[i].push_back(make_pair(j, w));
        graph[j].push_back(make_pair(i, w));
      }

    cout << prim(graph) + lowest << '\n';
  }
}
