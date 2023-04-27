#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

void floyd_warshall(vector<vector<bool>> &graph) {

  for (int k = 0; k < graph.size(); k++) {
    for (int i = 0; i < graph.size(); i++) {
      for (int j = 0; j < graph.size(); j++) {
        graph[i][j] = (graph[i][j] | (graph[i][k] & graph[k][j]));
      }
    }
  }
}

bool dfs(const vector<vector<int>> &graph, int beg, int mouse_pos,
         vector<bool> &visited) {

  if (beg == mouse_pos)
    return true;

  visited[beg] = true;

  for (int u : graph[beg]) {
    if (!visited[u]) {
      if (dfs(graph, u, mouse_pos, visited)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int t;
  string s;

  cin >> t;

  while (t--) {
    int n;

    cin >> n;

    int u, v, cat_house, mouse_house;

    cin >> u >> v;
    cat_house = u - 1;
    mouse_house = v - 1;

    vector<vector<bool>> cat(n, vector<bool>(n, false));
    vector<vector<bool>> mouse(n, vector<bool>(n, false));
    vector<vector<int>> graph(n, vector<int>());

    cat[cat_house][cat_house] = true;
    mouse[mouse_house][mouse_house] = true;

    while (cin >> u >> v) {
      if (u == -1 && v == -1) {
        break;
      }

      cat[u - 1][v - 1] = true;
    }

    cin.ignore();

    while (true) {
      getline(cin, s);

      if (s.empty())
        break;

      stringstream ss(s);
      ss >> u >> v;

      mouse[u - 1][v - 1] = true;
      graph[u - 1].push_back(v - 1);
    }

    floyd_warshall(cat);
    floyd_warshall(mouse);

    bool res_one = false, res_two = false;

    vector<bool> visited_one(all(cat[cat_house]));
    vector<bool> visited_two(all(mouse[mouse_house]));

    for (int i = 0; i < visited_one.size(); i++) {
      if (visited_one[i] && visited_two[i]) {
        res_one = true;
        break;
      }
    }

    if (!visited_one[mouse_house]) {
      for (int w : graph[mouse_house]) {
        if (!visited_one[w]) {
          res_two |= dfs(graph, w, mouse_house, visited_one);
        }
      }
    }

    if (res_one) {
      cout << "Y ";
    } else {
      cout << "N ";
    }

    if (res_two) {
      cout << "Y";
    } else {
      cout << "N";
    }

    cout << endl;

    if (t)
      cout << endl;
  }
}
