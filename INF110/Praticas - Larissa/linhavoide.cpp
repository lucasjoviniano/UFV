#include <iostream>
using namespace std;

void linha(int n) {

  for (int i = 0; i < n; i++)
    cout << "-";

  cout << endl;
}

int main() {
  linha(20);

  return 0;
}
