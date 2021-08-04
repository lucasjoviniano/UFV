#include <cstring>
#include <iostream>

using namespace std;

struct TipoPartida {
  char time1[31], time2[31];
  int placar1, placar2;
};

struct pontuacao {
  char time[31];
  int pont = 0;
};

int main() {
  TipoPartida partida[50];
  int qtd, pontu = 0;
  char x;
  char selec[31];

  cin >> qtd;
  for (int i = 0; i < qtd; i++) {
    cin >> partida[i].time1;
    cin >> partida[i].placar1;
    cin >> x;
    cin >> partida[i].placar2;
    cin >> partida[i].time2;
    cin.ignore();
  }
  // cin.ignore();

  // cin.ignore();

  for (int num = 0; num < 4; num++) {
    cin >> selec;
    pontuacao final;
    strcpy(final.time, selec);

    for (int i = 0; i < qtd; i++) {
      if (strcmp(partida[i].time1, selec) == 0) {
        if (partida[i].placar1 > partida[i].placar2) {
          final.pont += 3;
        } else if (partida[i].placar1 == partida[i].placar2) {
          final.pont += 1;
        }
      }
      if (strcmp(partida[i].time2, selec) == 0) {
        if (partida[i].placar1 < partida[i].placar2) {
          final.pont += 3;
        } else if (partida[i].placar1 == partida[i].placar2) {
          final.pont += 1;
        }
      }
    }
    cout << final.time << " " << final.pont << endl;
  }

  return 0;
}