#include <cstring>
#include <cmath>
#include <vector>
#include <complex>
#include "Polinomio.h"
#include "Eigen/Core"
#include "Eigen/Eigenvalues"

using namespace std;

Polinomio::Polinomio() {
  this->poli = new double[1];
  *poli = 0;
  this->grau = 0;
}

Polinomio::Polinomio(const int k) {
  this->poli = new double;
  this->grau = 0;
  *poli = k;
}

void checkPolinomio(unsigned int &n, double *v) {
  if (v[n - 1] != 0) {
    return;
  } else {
    n--;
    checkPolinomio(n, v);
  }
}

Polinomio::Polinomio(unsigned int n, double *a) {
  //checkPolinomio(n, a);
  this->poli = new double[n + 1];
  this->grau = n;
  memcpy(this->poli, a, (n + 1) * sizeof(double));
}

Polinomio::Polinomio(const Polinomio &obj) {
  this->poli = new double[obj.grau + 1];
  this->grau = obj.grau;
  memcpy(this->poli, obj.poli, (obj.grau + 1) * sizeof(double));
}

Polinomio::~Polinomio() {
  delete [] poli;
}

unsigned int Polinomio::getGrau() const{
  return this->grau;
}

Polinomio & Polinomio::operator=(const Polinomio &obj) {
  delete [] poli;
  this->poli = new double[obj.grau + 1];
  this->grau = obj.grau;
  memcpy(this->poli, obj.poli, (obj.grau + 1) * sizeof(double));
  return *this;
}

Polinomio Polinomio::operator+(const Polinomio &obj) const{
  int n = this->grau > obj.grau ? this->grau : obj.grau;
  double* v = new double[n + 1];
  double a, b;
  for (int i = 0; i <= n; i++) {
    a = i > this->grau ? 0 : this->poli[i];
    b = i > obj.grau ? 0 : obj.poli[i];
    v[i] = a + b;
  }
  Polinomio aux(n, v);
  return aux;
}

Polinomio Polinomio::operator+(const double &coeficiente) const{
  Polinomio aux = *this;
  aux.poli[0] += coeficiente;
  return aux;
}

Polinomio & Polinomio::operator+=(const Polinomio &obj) {
  double a;
  if (obj.grau > this->grau) {
    double* v = new double[obj.grau + 1];

    for (int i = 0; i <= obj.grau; i++) {
      a = i > this->grau ? 0 : this->poli[i];
      v[i] = a + obj.poli[i];
    }

    swap(this->poli, v);
    this->grau = obj.grau;
    
    delete [] v;
    
    return *this;
  }
  
  for (int i = 0; i <= obj.grau; i++) {
    a = i > obj.grau ? 0 : obj.poli[i];
    this->poli[i] += a;
  }
  
  return *this;
}

Polinomio & Polinomio::operator+=(const double &coeficiente) {
  this->poli[0] += coeficiente;
  
  return *this;
}

Polinomio Polinomio::operator-(const Polinomio &obj) const{
  int n = this->grau > obj.grau ? this->grau : obj.grau;
  double* v = new double[n + 1];
  double a, b;
  for (int i = 0; i <= n; i++) {
    a = i > this->grau ? 0 : this->poli[i];
    b = i > obj.grau ? 0 : obj.poli[i];
    v[i] = a - b;
  }
  Polinomio aux(n, v);
  return aux;
}

Polinomio Polinomio::operator-(const double &coeficiente) const{
  Polinomio aux(this->grau, this->poli);
  aux.poli[0] -= coeficiente;
  return aux;
}

Polinomio & Polinomio::operator-=(const Polinomio &obj) {
  double a;
  if (obj.grau > this->grau) {
    double* v = new double[obj.grau + 1];

    for (int i = 0; i <= obj.grau; i++) {
      a = i > this->grau ? 0 : this->poli[i];
      v[i] = a - obj.poli[i];
    }

    swap(this->poli, v);
    this->grau = obj.grau;
    
    delete [] v;
    
    return *this;
  }
  
  for (int i = 0; i <= obj.grau; i++) {
    a = i > obj.grau ? 0 : obj.poli[i];
    this->poli[i] -= a;
  }
  
  return *this;
}

Polinomio & Polinomio::operator-=(const double &coeficiente) {
  this->poli[0] -= coeficiente;
  
  return *this;
}

Polinomio Polinomio::operator*(const Polinomio &obj) const {
  double* v = new double[this->grau + obj.grau + 1];
  memset(v, '0', (this->grau + obj.grau + 1) * sizeof(double));
  for (int i = 0; i <= this->grau; i++)
    for (int j = 0; j <= obj.grau; j++)
      v[i + j] += this->poli[i] * obj.poli[j];
  Polinomio aux(this->grau + obj.grau, v);
  delete [] v;
  return aux;
}

Polinomio Polinomio::operator*(const double &termo) const {
  Polinomio aux = *this;
  for (int i = 0; i <= this->grau; i++)
    aux.poli[i] *= termo;
  return aux;
}

Polinomio operator*(const double &termo, const Polinomio &p){
  Polinomio aux = p;
  return aux * termo;
}

Polinomio & Polinomio::operator*=(const Polinomio &obj) {
  double* v = new double[this->grau + obj.grau + 1];
  memset(v, '0', (this->grau + obj.grau + 1) * sizeof(double));
  for (int i = 0; i <= this->grau; i++)
    for (int j = 0; j <= obj.grau; j++)
      v[i + j] += this->poli[i] * obj.poli[j];
  swap(v, this->poli);
  this->grau += obj.grau;
  delete [] v;
  return *this;
}

Polinomio & Polinomio::operator*=(const double &termo){
  for (int i = 0; i <= this->grau; i++)
    this->poli[i] *= termo;
  return *this;
}

Polinomio Polinomio::operator/(const Polinomio &obj) const {
  if(obj.grau != 1 || this->grau == 0) throw ArgumentoInvalidoExcept(); 
  double* v = new double[this->grau];
  v[this->grau - 1] = this->poli[this->grau];
  if (obj.poli[0] > 0) obj.poli[0] *= -1;
  for (int i = this->grau - 2; i >= 0; i--) {
    v[i] = (v[i + 1] * obj.poli[0]) + this->poli[i + 1];
  }
  v[0] = (v[0] * obj.poli[0]) + this->poli[0];
  Polinomio aux(this->grau - 1, v);
  delete [] v;
  return aux;
}

Polinomio & Polinomio::operator/=(const Polinomio &obj){
  if(obj.grau != 1) throw ArgumentoInvalidoExcept(); 
  if(obj.poli[1] != 1) throw ArgumentoInvalidoExcept();
  double* v = new double[this->grau];
  v[this->grau - 1] = this->poli[this->grau];
  if (obj.poli[0] > 0) obj.poli[0] *= -1;
  for (int i = this->grau - 2; i >= 0; i--) {
    v[i] = (v[i + 1] * obj.poli[0]) + this->poli[i + 1];
  }
  v[0] = (v[0] * obj.poli[0]) + this->poli[0];
  swap(this->poli, v);
  delete [] v;
  this->grau--;
  return *this;
}

Polinomio Polinomio::operator/(const double & termo) const{
  if(termo == 0) throw ArgumentoInvalidoExcept();
  Polinomio aux = *this; 

  for (int i = 0; i <= this->grau; i++)
    aux.poli[i] /= termo;
  return aux;
}

Polinomio & Polinomio::operator/=(const double & termo){
  if(termo == 0) throw ArgumentoInvalidoExcept();

  for (int i = 0; i <= this->grau; i++)
    this->poli[i] /= termo;
  return *this;
}

Polinomio Polinomio::operator%(const Polinomio &obj) const {
  if(obj.grau != 1) throw ArgumentoInvalidoExcept(); 
  if(obj.poli[1] != 1) throw ArgumentoInvalidoExcept();
  // Segundo o Teorema do Resto:
  // O resto da divisão de um polinômio p(x) por x - a é
  // o valor número de p(a)
  double resto = this->avalia(obj.poli[0]);
  Polinomio aux(resto);
  return aux;
}

Polinomio & Polinomio::operator%=(const Polinomio &obj){
  if(obj.grau != 1) throw ArgumentoInvalidoExcept(); 
  if(obj.poli[1] != 1) throw ArgumentoInvalidoExcept();
  double* v = new double;
  *v = this->avalia(obj.poli[0]);
  swap(this->poli, v);
  this->grau = 0;
  delete [] v;
  return *this;
}

double Polinomio::operator[](int i) const {
  if(i > this->grau) throw PosicaoInvalidaExcept(); 
  return this->poli[i];
}

double Polinomio::operator[](int i) {
  if(i > this->grau) throw PosicaoInvalidaExcept(); 
  return this->poli[i];
}

Polinomio Polinomio::operator++() {
  this->poli[0]++;
  return *this;
}

Polinomio Polinomio::operator++(int i) {
  Polinomio aux = *this;
  aux.poli[0]++;
  return aux;
}

Polinomio Polinomio::operator--() {
  this->poli[0]--;
  return *this;
}

Polinomio Polinomio::operator--(int i) {
  Polinomio aux = *this;
  aux.poli[0]--;
  return aux;
}

bool Polinomio::operator==(const Polinomio &obj) const {
  if (this->grau != obj.grau) return false;
  for (int i = 0; i <= this->grau; i++)
    if (fabs(this->poli[i] - obj.poli[i]) > this->poli[i] * .0000000001) return false;
  return true;
}

bool Polinomio::operator!=(const Polinomio &obj) const {
  return !(*this == obj);
}

bool Polinomio::operator<(const Polinomio &obj) const {
  if (this->grau > obj.grau) return false;
  for (int i = 0; i <= this->grau; i++)
    if ((this->poli[i] - obj.poli[i]) > this->poli[0] * .0000000001) return false;
  return true;
}

bool Polinomio::operator>(const Polinomio &obj) const {
  return obj < *this;
}

bool Polinomio::operator<=(const Polinomio &obj) const {
  return !(obj < *this);
}

bool Polinomio::operator>=(const Polinomio &obj) const {
  return !(*this < obj);
}

istream& operator>>(istream &file, Polinomio & obj) {
  for (int i = 0; !file.eof() && (i <= obj.grau); i++) {
    file >> obj.poli[i];
  }
  return file;
}

ostream& operator<<(ostream &file, const Polinomio &obj) {
  for (int i = 0; i <= obj.grau; i++) {
    if (i == 0) {
      file << obj[i];
    } else if (obj[i] == 0) {
      continue;
    } else if (i == 1) {
      file << obj.poli[i] << "x";
    } else if (obj[i] == 1) {
      file << "x^" << i;
    } else {
      file << obj[i] << "x^" << i;
    }

    if (i != obj.grau && obj[i + 1] > 0) {
      file << " + ";
    } else if (i != obj.grau && obj[i + 1] < 0) {
      file << " ";
    }
  }
  
  return file;
}

Polinomio Polinomio::derivada() const {
  if (this->grau == 0) {
    Polinomio aux;
    return aux;
  }
  double* v = new double[this->grau];
  for (int i = 1; i <= this->grau; i++) {
    v[i-1] = i * poli[i];
  }
  Polinomio aux(this->grau - 1, v);
  delete [] v;
  return aux;
}

double Polinomio::avalia(double x) const {
  double valor = this->poli[this->grau];
  for (int i = this->grau - 1; i >= 0; i--) {
    valor *= x;
    valor += this->poli[i];
  }
  return valor;
}

double newton(double chute, Polinomio & obj, Polinomio & dx) {
  double raiz = 0;
  for (int i = 0; i < 50; i++) {
    raiz = chute - (obj.avalia(chute) / dx.avalia(chute));
    if (fabs(raiz - chute) < 0.000000000000001) return raiz;
    chute = raiz;
  }
  return chute;
}

double* Polinomio::bhaskara(int &num) const{
 double delta = pow(this->poli[1], 2) - (4 * this->poli[2] * this->poli[0]); 
 double* raizes;
 if (delta < 0) {
   num = 0;
   throw RaizInexistenteExcept();
 }
 if (delta == 0) {
   raizes = new double;
   num = 1;
   *raizes = (-this->poli[1] + sqrt(delta)) / (2 * this->poli[2]);
   return raizes;
 }
 raizes = new double[2];
 raizes[0] = (-this->poli[1] + sqrt(delta)) / (2 * this->poli[2]);
 raizes[1] = (-this->poli[1] - sqrt(delta)) / (2 * this->poli[2]);
 num = 2;

 return raizes;
}

// Quando eu escrevi só eu e deus sabíamos como funcionava
// agora só deus sabe
double* Polinomio::resolve(int &num) const {
  double* raizes;

  if (this->grau == 0) throw RaizInexistenteExcept();

  if (this->grau == 1) {
    raizes = new double[1];
    *raizes = (-this->poli[0]) / this->poli[1];
    num = 1;
    return raizes;
  }

  if (this->grau == 2) {
      raizes = this->bhaskara(num);
      return raizes;
  }

  raizes = new double[this->grau];
  memset(raizes, '0', sizeof(double) * this->grau);
  Polinomio aux = *this;
  Polinomio dx = this->derivada();
  double* v = new double[2];
  v[0] = 0;
  v[1] = 1;
  Polinomio binomio(1, v);
  delete [] v;
  double raiz = 0;
  for (int i = 0; aux.grau >= 1; i++) {
    raiz = newton(raiz, aux, dx);
    raizes[i] = raiz;
    binomio.poli[0] = raiz;
    aux /= binomio;
    dx = aux.derivada();
  }

  vector<double> check;
  for (int i = 0; i < this->grau; i++) {
    double r = this->avalia(raizes[i]);
    if (r < 0.00000000001 && r > -0.0000000001) {
      check.push_back(raizes[i]);
    }
  }

  delete [] raizes;
  if (check.size() == 0) throw RaizInexistenteExcept();
  raizes = new double[check.size()];

  num = check.size();

  for (int i = 0; i < check.size(); i++)
    raizes[i] = check[i];
  
  return raizes;
}

complex<double>* Polinomio::resolveComplexas(int &num) const {
  if (this->grau == 0) throw RaizInexistenteExcept();
  Eigen::Matrix<complex<double>, Eigen::Dynamic, Eigen::Dynamic> raizesC;

  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> comp(this->grau, this->grau);

  comp.col(0) = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>::Zero(this->grau, 1);

  comp.block(0, 1, this->grau, this->grau - 1) = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>::Identity(this->grau, this->grau - 1);

  for (int i = 0; i < this->grau; i++)
    comp(this->grau - 1, i) = (-this->poli[i]) / this->poli[this->grau];

  raizesC = comp.eigenvalues();

  complex<double>* raizes = new complex<double>[this->grau];

  for (int i = 0; i < this->grau; i++) raizes[i] = raizesC(i);

  num = this->grau;
  return raizes;
}

Polinomio Polinomio::integral() const {
  double* v = new double[this->grau + 2];
  for (int i = 0; i <= this->grau; i++)
    v[i + 1] = this->poli[i] / (i + 1);
  v[0] = 0;
  Polinomio aux(this->grau + 1, v);
  delete [] v;
  return aux;
}

double Polinomio::integral(double a, double b) const {
  Polinomio sdx = this->integral();
  if (a > b) swap(a, b);
  return (sdx.avalia(b) - sdx.avalia(a));
}
