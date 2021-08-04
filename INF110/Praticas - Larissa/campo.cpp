#include <iostream>
using namespace std;
int m, n, b, x, y;
int main() {
  cin >> m >> n >> b;
  char a[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = '-';
    }
  }
  for (int k = 0; k < b; k++) {
    cin >> x >> y;
    a[x - 1][y - 1] = 'B';
  }
  if (m == 1) {
    if (a[0][0] != 'B') {
      if (a[0][1] == 'B')
        a[0][0] = 49;
    }
    for (int j = 1; (j < n - 1); j++) {
      if (a[0][j] != 'B') {
        char cont = 48;
        if (a[0][j - 1] == 'B')
          cont++;
        if (a[0][j + 1] == 'B')
          cont++;
        a[0][j] = cont;
      }
    }
    if (a[0][n - 1] != 'B') {
      if (a[0][n - 2] == 'B')
        a[0][n - 1] = 49;
    }
  } else {
    if (n == 1) {
      if (a[0][0] != 'B') {
        if (a[1][0] == 'B')
          a[0][0] = 49;
      }
      for (int i = 1; (i < m - 1); i++) {
        if (a[i][0] != 'B') {
          char cont = 48;
          if (a[i - 1][0] == 'B')
            cont++;
          if (a[i + 1][0] == 'B')
            cont++;
          a[i][0] = cont;
        }
      }
      if (a[m - 1][0] != 'B') {
        if (a[m - 2][0] == 'B')
          a[m - 1][0] = 49;
      }
    } else {
      if (m > 1 && n > 1) {
        // primeiro elemento da primeira linha a_{11}
        if (a[0][0] != 'B') {
          char cont = 48;
          if (a[0][1] == 'B')
            cont++;
          if (a[1][0] == 'B')
            cont++;
          if (a[1][1] == 'B')
            cont++;
          a[0][0] = cont;
        }
        // primeira linha de a_{21} a a_{(n-1)1}
        for (int j = 1; (j < n - 1); j++) {
          if (a[0][j] != 'B') {
            char cont = 48;
            if (a[0][j - 1] == 'B')
              cont++;
            if (a[0][j + 1] == 'B')
              cont++;
            if (a[1][j - 1] == 'B')
              cont++;
            if (a[1][j] == 'B')
              cont++;
            if (a[1][j + 1] == 'B')
              cont++;
            a[0][j] = cont;
          }
        }
        // ultimo elemento da primeira linha a_{n1}
        if (a[0][n - 1] != 'B') {
          char cont = 48;
          if (a[0][n - 2] == 'B')
            cont++;
          if (a[1][n - 2] == 'B')
            cont++;
          if (a[1][n - 1] == 'B')
            cont++;
          a[0][n - 1] = cont;
        }
        //�ltima linha - m-�sima linha
        // primeiro elemento
        if (a[m - 1][0] != 'B') {
          char cont = 48;
          if (a[m - 2][0] == 'B')
            cont++;
          if (a[m - 2][1] == 'B')
            cont++;
          if (a[m - 1][1] == 'B')
            cont++;
          a[m - 1][0] = cont;
        }
        // m-�sima linha de a_{m2} a a_{(m-1)1}
        for (int j = 1; (j < n - 1); j++) {
          if (a[m - 1][j] != 'B') {
            char cont = 48;
            if (a[m - 1][j - 1] == 'B')
              cont++;
            if (a[m - 1][j + 1] == 'B')
              cont++;
            if (a[m - 2][j - 1] == 'B')
              cont++;
            if (a[m - 2][j] == 'B')
              cont++;
            if (a[m - 2][j + 1] == 'B')
              cont++;
            a[m - 1][j] = cont;
          }
        }
        //�ltimo elemento da m �sima linha
        if (a[m - 1][n - 1] != 'B') {
          char cont = 48;
          if (a[m - 2][n - 2] == 'B')
            cont++;
          if (a[m - 2][n - 1] == 'B')
            cont++;
          if (a[m - 1][n - 2] == 'B')
            cont++;
          a[m - 1][n - 1] = cont;
        }
        // coluna
        // primeiro elemento da primeira coluna a_{11}
        if (a[0][0] != 'B') {
          char cont = 48;
          if (a[0][1] == 'B')
            cont++;
          if (a[1][0] == 'B')
            cont++;
          if (a[1][1] == 'B')
            cont++;
          a[0][0] = cont;
        }
        // primeira coluna de a_{12} a a_{1(n-1)}
        for (int i = 1; (i < m - 1); i++) {
          if (a[i][0] != 'B') {
            char cont = 48;
            if (a[i - 1][0] == 'B')
              cont++;
            if (a[i + 1][0] == 'B')
              cont++;
            if (a[i - 1][1] == 'B')
              cont++;
            if (a[i][1] == 'B')
              cont++;
            if (a[i + 1][1] == 'B')
              cont++;
            a[i][0] = cont;
          }
        }
        // ultimo elemento da primeira coluna a_{1n}
        if (a[m - 1][0] != 'B') {
          char cont = 48;
          if (a[m - 2][0] == 'B')
            cont++;
          if (a[m - 2][1] == 'B')
            cont++;
          if (a[m - 1][1] == 'B')
            cont++;
          a[m - 1][0] = cont;
        }
        //�ltima coluna - n-�sima linha
        // primeiro elemento
        if (a[m - 1][n - 1] != 'B') {
          char cont = 48;
          if (a[m - 2][n - 2] == 'B')
            cont++;
          if (a[m - 2][n - 1] == 'B')
            cont++;
          if (a[m - 1][n - 2] == 'B')
            cont++;
          a[m - 1][n - 1] = cont;
        }
        // n-�sima coluna de a_{m2} a a_{m(n-1)}
        for (int i = 1; (i < m - 1); i++) {
          if (a[i][n - 1] != 'B') {
            char cont = 48;
            if (a[i - 1][n - 1] == 'B')
              cont++;
            if (a[i + 1][n - 1] == 'B')
              cont++;
            if (a[i - 1][n - 2] == 'B')
              cont++;
            if (a[i][n - 2] == 'B')
              cont++;
            if (a[i + 1][n - 2] == 'B')
              cont++;
            a[i][n - 1] = cont;
          }
        }
        //�ltimo elemento da n �sima coluna
        if (a[m - 1][n - 1] != 'B') {
          char cont = 48;
          if (a[m - 2][n - 2] == 'B')
            cont++;
          if (a[m - 2][n - 1] == 'B')
            cont++;
          if (a[m - 1][n - 2] == 'B')
            cont++;
          a[m - 1][n - 1] = cont;
        }
        // centro
        for (int i = 1; i < m - 1; i++) {
          for (int j = 1; j < n - 1; j++) {
            char cont = 48;
            if (a[i][j] != 'B') {
              if (a[i - 1][j - 1] == 'B')
                cont++;
              if (a[i - 1][j] == 'B')
                cont++;
              if (a[i - 1][j + 1] == 'B')
                cont++;
              if (a[i][j - 1] == 'B')
                cont++;
              if (a[i][j + 1] == 'B')
                cont++;
              if (a[i + 1][j - 1] == 'B')
                cont++;
              if (a[i + 1][j] == 'B')
                cont++;
              if (a[i + 1][j + 1] == 'B')
                cont++;
              a[i][j] = cont++;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 48) {
        cout << '-';
      } else {
        cout << a[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}
