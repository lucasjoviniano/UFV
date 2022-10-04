#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n;
  map<string, int> m;
  string name;
  cin >> n;
  cin.ignore();
  cin.ignore();

  while (n--) {
    int total = 0;

    while (getline(cin, name)) {
      if (name.empty())
        break;

      m[name]++;

      total++;
    }

    for (auto it = m.begin(); it != m.end(); it++) {
      cout << it->first << " " << fixed << setprecision(4)
           << ((double)(*it).second / (double)total * 100.0) << endl;
    }

    if (n > 0) {
      cout << endl;
      m.clear();
    }
  }

  return 0;
}
