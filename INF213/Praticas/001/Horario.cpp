#include "Horario.h"
#include <iostream>

using namespace std;

Horario::Horario(int h, int m, int s) {
  setHora(h);
  setMinuto(m);
  setSegundo(s);
}

Horario::Horario(const Horario & obj) {
    *this = obj;
}

void Horario::setHora(int h) {
    if (h >= 0 && h < 24) {
        hora = h;
        return;
    }
    hora = h < 0 ? 0 : 23;
}

void Horario::setMinuto(int m) {
    if (m >= 0 && m < 60) {
        minuto = m;
        return;
    }
    minuto = m < 0 ? 0 : 59;
}

void Horario::setSegundo(int s) {
    if (s >= 0 && s < 60) {
        segundo = s;
        return;
    }
    segundo = s < 0 ? 0 : 59;
}

int Horario::getHora() const {
    return hora;
}

int Horario::getMinuto() const {
    return minuto;
}

int Horario::getSegundo() const {
    return segundo;
}

int Horario::compHorario(const Horario &hms) const {
    int dif = this->difSegundos(hms);
    if (dif == 0) return 0;
    if (dif < 0) return -1;
    return 1;
}

int Horario::difSegundos(const Horario &hms) const {
  long long first = this->segundo + this->minuto * 60 + this->hora * 360;
  long long second = hms.segundo + hms.minuto * 60 + hms.hora * 360;

  return first - second;
}

ostream& operator<<(ostream &file, const Horario &obj) {
  file << obj.hora << ' ' << obj.minuto << ' ' << obj.segundo;
  return file;
}

istream& operator>>(istream &file, Horario &obj) {
  int aux;
  file >> aux;
  obj.setHora(aux);
  file >> aux;
  obj.setMinuto(aux);
  file >> aux;
  obj.setSegundo(aux);
  return file;
}