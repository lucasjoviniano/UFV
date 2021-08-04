#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;
int main() {
  char senha[31];
  bool mai = false, min = false, dig = false, esp = false;
  cin >> senha;
  for (int i = 0; senha[i] != '\0'; i++) {
    if (islower(senha[i])) {
      min = true;
      break;
    }
  }
  for (int i = 0; senha[i] != '\0'; i++) {
    if (isupper(senha[i])) {
      mai = true;
      break;
    }
  }
  for (int i = 0; senha[i] != '\0'; i++) {
    if (isdigit(senha[i])) {
      dig = true;
      break;
    }
  }
  for (int i = 0; senha[i] != '\0'; i++) {
    if (!isalnum(senha[i])) {
      esp = true;
      break;
    }
  }
  int seg = min + mai + dig + esp;
  if (seg == 4) {
    cout << "segura" << endl;
  } else {
    if (seg == 3 || seg == 2) {
      cout << "media" << endl;
    } else {
      cout << "fraca" << endl;
    }
  }
  return 0;
}
