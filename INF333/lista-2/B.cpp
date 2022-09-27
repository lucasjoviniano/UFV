#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

  int numBeds;
  int numWalkedAway;
  string customers;
  set<char> beds;
  set<char> leave;
  cin >> numBeds;

  while (numBeds != 0) {
    cin >> customers;
    leave.clear();
    beds.clear();
    for (string::iterator ch = customers.begin(); ch != customers.end(); ch++) {
      if (leave.find(*ch) == leave.end()) {
        if (beds.find(*ch) != beds.end()) {
          beds.erase(*ch);
        } else if (beds.size() < numBeds) {
          beds.insert(*ch);
        } else {
          leave.insert(*ch);
        }
      }
    }
    int numDesistentes = leave.size();
    if (numDesistentes == 0)
      cout << "All customers tanned successfully.\n";
    else
      cout << numDesistentes << " customer(s) walked away.\n";

    cin >> numBeds;
  }
}
