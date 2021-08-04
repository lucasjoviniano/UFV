#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>


using namespace std;

double area(double a, double b, double c) {
  double s = (a + b + c) / 2;
  double areaS;
  areaS = sqrt(s * (s - a) * (s - b) * (s - c));
  return areaS;
}

struct Ponto {
  int x, y;
};
double distancia(int x, int y) {
  double hip;
  hip = sqrt((x * x) + (y * y));
  return hip;
}
int main() {
  // Ponto p0 = P
  // Ponto p1 = Q
  // Ponto p2 = R
  // a = P-Q, b = P-R, c = Q-R
  double a, b, c;
  double resp;
  int ax, bx, cx;
  int ay, by, cy;
  Ponto p[3];
  for (int i = 0; i < 3; i++) {
    cin >> p[i].x >> p[i].y;
  }
  //***Adquirir os valores do eixo X***//
  if (p[0].x >= p[1].x)
    ax = p[0].x - p[1].x;
  else
    ax = p[1].x - p[0].x;

  if (p[0].x >= p[2].x)
    bx = p[0].x - p[2].x;
  else
    bx = p[2].x - p[0].x;

  if (p[1].x >= p[2].x)
    cx = p[1].x - p[2].x;
  else
    cx = p[2].x - p[1].x;

  //***Adquirir os valores do eixo Y***//
  if (p[0].y >= p[1].y)
    ay = p[0].y - p[1].y;
  else
    ay = p[1].y - p[0].y;

  if (p[0].y >= p[2].y)
    by = p[0].y - p[2].y;
  else
    by = p[2].y - p[0].y;

  if (p[1].y >= p[2].y)
    cy = p[1].y - p[2].y;
  else
    cy = p[2].y - p[1].y;

  //***Adquirir os valores das distâncias***//
  a = distancia(ax, ay);
  b = distancia(bx, by);
  c = distancia(cx, cy);

  resp = area(a, b, c);
  cout << fixed << setprecision(2) << resp << endl;
  return 0;
}

/*int coord[2][3];
                for(int i=0;i<3;i++){
                        for(int j=0;j<2;j++){
                                cin>>coord[j][i];
                        }
                }

for(int k=0;k<1;k++){
                for(int l=1;l<3;l++){
                */