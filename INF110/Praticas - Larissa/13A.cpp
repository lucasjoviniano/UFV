#include <iomanip>
#include <iostream>

using namespace std;

struct Horario {
  int horas, minutos;
};

void escreve(Horario h) {
  if (h.horas < 13) {
    if (h.horas == 12)
      cout << setw(2) << setfill('0') << h.horas << ':' << setw(2)
           << setfill('0') << h.minutos << " PM" << endl;
    else if (h.horas == 0)
      cout << "12:" << setw(2) << setfill('0') << h.minutos << " AM" << endl;
    else
      cout << setw(2) << setfill('0') << h.horas << ':' << setw(2)
           << setfill('0') << h.minutos << " AM" << endl;

  } else {
    h.horas -= 12;
    cout << setw(2) << setfill('0') << h.horas << ':' << setw(2) << setfill('0')
         << h.minutos << " PM" << endl;
  }
}

int main() {
  Horario time;
  int qtd;
  cin >> qtd;
  for (int i = 0; i < qtd; i++) {
    cin >> time.horas >> time.minutos;
    escreve(time);
  }

  return 0;
}