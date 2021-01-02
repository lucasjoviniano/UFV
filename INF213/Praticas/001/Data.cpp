#include "Data.h"
#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

Data::Data(int d, int m, int a) {
  setDia(d);
  setMes(m);
  setAno(a);
}

Data::Data(const Data & obj) {
  *this = obj;
}

void Data::setDia(int d) {
  if (d >= 1 && d <= 30) {
    dia = d;
    return;
  }
  dia = d < 1 ? 1 : 30;
}

void Data::setMes(int m) {
  if (m >= 1 && m <= 12) {
    mes = m;
    return;
  }
  mes = m < 1 ? 1 : 12;
}

void Data::setAno(int a) {
  if (a >= 2018 && a <= 2020) {
    ano = a;
    return;
  }
  ano = a < 2018 ? 2018 : 2020;
}

int Data::getDia() const {
  return dia;
}

int Data::getMes() const {
  return mes;
}

int Data::getAno() const {
  return ano;
}

int Data::compData(const Data &dt) const {
  int d = this->difDias(dt);
  if (d == 0) {
    return 0;
  } else if (d < 0){
    return -1;
  } else {
    return 1;
  }
}

int Data::difDias(const Data &dt) const {
  long long first = this->dia + this->mes * 30 + this->ano * 365;
  long long second = dt.dia + dt.mes * 30 + dt.ano * 365;

  return first - second;
}

void Data::imprime() const {
  cout << setfill('0') << setw(2) << dia << '/'
  << setw(2) << mes << '/'
  << ano << endl;
}

ostream& operator<<(ostream &file, const Data &d) {
  file << d.dia << ' ' << d.mes << ' ' << d.ano;
  return file;
}

istream& operator>>(istream &file, Data &obj) {
  int aux;
  file >> aux;
  obj.setDia(aux);
  file >> aux;
  obj.setMes(aux);
  file >> aux;
  obj.setAno(aux);
  return file;
}