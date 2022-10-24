#include <iostream>
#include <vector>
using namespace std;

struct Piece {
  int l, r;
};

int n, m, right, left, tmp;

vector<int> v;
vector<Piece> pieces(m);

bool backtrack(int dots, int curr) {
  if (curr == n)
    return (dots == ::right);

  for (int i = 0; i < pieces.size(); i++) {
    if (!v[i]) {
      if (pieces[i].l == dots) {
        v[i] = true;
        if (backtrack(pieces[i].r, curr + 1))
          return true;
        v[i] = false;
      }

      if (pieces[i].r == dots) {
        v[i] = true;
        if (backtrack(pieces[i].l, curr + 1))
          return true;
        v[i] = false;
      }
    }
  }

  return false;
}

int main() {

  while (true) {
    cin >> n;
    if (n == 0)
      break;
    pieces.clear();
    v.clear();

    cin >> m >> ::tmp >> ::left >> ::right >> ::tmp;
    pieces.resize(m);
    v.resize(m);

    for (int i = 0; i < m; i++) {
      cin >> pieces[i].l >> pieces[i].r;
    }

    if (backtrack(::left, 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
