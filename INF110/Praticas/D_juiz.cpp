#include <cstring>
#include <iostream>
using namespace std;
int main() {

  char aluno[1001], correto[1001];
  cin.getline(aluno, 1001);
  cin.getline(correto, 1001);

  if (strcmp(aluno, correto) == 0) {
    cout << "Accepted" << endl;
    return 0;
  } else {
    while (strchr(aluno, ' ') != NULL)
      for (int i = 0; aluno[i] != '\0'; i++) {
        if (aluno[i] == ' ') {
          for (int j = i; aluno[j] != '\0'; j++) {
            aluno[j] = aluno[j + 1];
          }
        }
      }
    while (strchr(correto, ' ') != NULL)
      for (int i = 0; correto[i] != '\0'; i++) {
        if (correto[i] == ' ') {
          for (int j = i; correto[j] != '\0'; j++) {
            correto[j] = correto[j + 1];
          }
        }
      }

    if (strcmp(aluno, correto) == 0) {
      cout << "Presentation Error" << endl;
      return 0;
    } else
      cout << "Wrong Answer" << endl;
  }

  return 0;
}
