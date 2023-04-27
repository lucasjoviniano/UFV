#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
  vector<int> representante;

public:
  void createSet(int tam) {
    representante.resize(tam);
    for (int i = 0; i < tam; i++)
      representante[i] = i;
  }
  // Retorna o representante do conjunto que contem
  // o elemento "elemento"
  int findSet(int elemento) {
    if (representante[elemento] == elemento)
      return elemento;
    // Compressao do caminho...
    representante[elemento] = findSet(representante[elemento]);
    return representante[elemento];
  }
  void mergeSets(int i, int j) { representante[findSet(i)] = findSet(j); }
  bool isSameSet(int i, int j) { return (findSet(i) == findSet(j)); }
};

double dist(const pair<int, int> &u, const pair<int, int> &v) {
  double a = u.first - v.first;
  double b = u.second - v.second;

  return sqrt((a * a) + (b * b));
}

int main() {
  int t, s, p;
  cin >> t;

  while (t--) {
    cin >> s >> p;

    vector<pair<int, int>> points(p);
    vector<pair<double, pair<int, int>>> edges;

    for (int i = 0; i < p; i++) {
      cin >> points[i].first >> points[i].second;

      for (int j = 0; j < i; j++) {
        double d = dist(points[i], points[j]);
        edges.push_back(make_pair(d, make_pair(i, j)));
      }
    }

    sort(edges.begin(), edges.end());

    UnionFind uf;

    uf.createSet(p);

    double ans = 0;
    int cn = 0;

    for (int i = 0; i < edges.size() && cn < p - s; i++) {
      int u = edges[i].second.first;
      int v = edges[i].second.second;

      if (!uf.isSameSet(u, v)) {
        uf.mergeSets(u, v);
        ans = edges[i].first;
        cn++;
      }
    }

    cout << fixed << setprecision(2) << ans << endl;
  }
}
