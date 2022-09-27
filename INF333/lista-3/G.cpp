#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;

int main() {
  int t;
  cin >> t;

  cin.ignore();

  while (t--) {
    map<string, int> m;
    string tree;
    int n = 0;
    while (getline(cin, tree)) {
      if (tree.compare("") == 0)
        break;
      m[tree]++;
      n++;
    }
    for (auto i = m.begin(); i != m.end(); i++)
      cout << i->first << " " << fixed << setprecision(4)
           << i->second * 100.0 / n << endl;
    if (t)
      cout << "\n";
  }
  return 0;
}
