#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
  int month, day, hour, mins, loc;
  bool isExit;
  int getTime() { return mins + hour * 60 + day * 24 * 60; }
};

int main() {
  int t;
  string in;
  cin >> t;
  cin.ignore();
  cin.ignore();

  while (t--) {
    int fares[24] = {};
    map<string, vector<Node>> licenseToRecord;
    for (int i = 0; i < 24; i++)
      cin >> fares[i];
    cin.ignore();

    while (getline(cin, in) && !in.empty()) {
      stringstream ss(in);
      string plate, command;
      char ignore;
      Node r;
      ss >> plate >> r.month >> ignore >> r.day >> ignore >> r.hour >> ignore >>
          r.mins >> command >> r.loc;
      r.isExit = command == "exit";
      licenseToRecord[plate].push_back(r);
    }

    for (auto &p : licenseToRecord) {
      sort(p.second.begin(), p.second.end(),
           [](Node a, Node b) { return a.getTime() < b.getTime(); });
      int totalCents = 200;

      for (int i = 0; i < p.second.size(); i++)
        if (!p.second[i].isExit && i + 1 < p.second.size() &&
            p.second[i + 1].isExit) {
          int dist = abs(p.second[i].loc - p.second[i + 1].loc);
          totalCents += dist * fares[p.second[i].hour];
          totalCents += 100;
        }

      if (totalCents != 200)
        cout << p.first << " $" << setprecision(2) << fixed
             << totalCents / 100.0 << endl;
    }

    if (t)
      cout << endl;
  }
}
