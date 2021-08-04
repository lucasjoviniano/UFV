#include <iostream>

using namespace std;

int main() {
  int screen[6][6] = {0};
  bool zeros = false;
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 5; j++) {
      cin >> screen[i][j];
      if (screen[i][j] == 0)
        zeros = true;
    }
  }
  if (zeros) {
    cout << "Keep playing!" << endl;
    return 0;
  }
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 5; j++) {
      if ((screen[i][j] == screen[i - 1][j] and screen[i][j] != 0) or
          (screen[i][j] == screen[i + 1][j] and screen[i][j] != 0) or
          (screen[i][j] == screen[i][j - 1] and screen[i][j] != 0) or
          (screen[i][j] == screen[i][j + 1] and screen[i][j] != 0)) {
        cout << "Keep playing!" << endl;
        return 0;
      }
    }
  }

  cout << "Game over!" << endl;
  return 0;
}