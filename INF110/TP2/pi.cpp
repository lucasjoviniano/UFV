#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


//Seleção do método de cálculo.
char intro(){
    char n;
    cout << "Digite a letra correspondente para escolher uma sequencia: " << endl;
    cout << "L - Leibniz" << endl;
    cout << "W - Wallis" << endl;
    cout << "E - Euler" << endl;
    cout << "V - Viete" << endl;
    cout << "M - Método Probabilístico" << endl;

    cin >> n;
    cout << endl;

    return n;
}

void leibniz(int termos){
    long double n = 0.0;

    for (int i = 0; i < termos; i++){

        //Cálculo do somatório da fórmula de Leibniz.
        n += ((pow(-1.0, i)) / (2.0 * i + 1.0));
        cout << "A[" << i + 1 << "] = " << fixed << setprecision(18) << n * 4.0 << endl;
    }
}

void wallis(int termos){
    long double n = 1.0;

    //Cálculo do produtório da fórmula de Wallis.
    for(int i = 1; i <= termos; i++){
        n = n * ((2.0 * i) / ((2.0 * i) - 1.0)) * ((2.0 * i) / ((2.0 * i) + 1.0));
        cout << "A[" << i << "] = " << fixed << setprecision(18) << n * 2 << endl;
    }
}

void euler(int termos){
    long double n = 0;
    int m = 1;

    //Cálculo do somatório da fórmula de Euler, tendo m como o número primo.
    for(int i = 1; i <= termos; i++){
        n += (1.0 / m);
        m += (2*i) + 1;
        cout << "A[" << i << "] = " << fixed << setprecision(18) << sqrt(n * 6) << endl;
    }
}

void viete(int termos){
    long double n = 1;
    long double a;
    a = sqrt(2);

    //Cálculo do produtório da fórmula de Viète, tendo a como o termo anterior à i.
    for(int i = 1; i <= termos; i++){
        n *= (a / 2);
        a = sqrt(2 + a);
        cout << "A[" << i << "] = " << fixed << setprecision(18) << (2/n) << endl;
    }
}

int sorteio(int raio){
    int diametro = raio * 2;

    srand(time(NULL));

    int x;

    x = rand() % diametro;

    return x;
}

void probabilistico(int raio, int numpontos){
    // y,  x
    int diametro = raio * 2;
    double centro;
    int x, y;
    int cont = 0;

    centro = diametro/2;

    cout << "Centro: " << centro << endl;

    for(int i = 0; i < numpontos; i++){
        
            x = sorteio(raio);
            y = sorteio(raio);
    
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;

        if(sqrt(pow(x - centro, 2) + pow(y - centro, 2)) > raio){
            cont++;
        }
    }

    cout << numpontos - cont << endl;
}

int main(){
    int n;
    int raio, pontos;
    char p;

    p = intro();

    if(p != 'M'){
        cout << "Insira o numero de termos: ";
        cin >> n;

        switch (p) {
        case 'L':
            leibniz(n);
            break;
        case 'W':
            wallis(n);
            break;
        case 'E':
            euler(n);
            break;
        case 'V':
            viete(n);
            break;
        }
    } else{
        cout << "Insira o raio: ";
        cin >> raio;
        cout << "Insira a quantidade de pontos: "; 
        cin >> pontos;
        probabilistico(raio, pontos);
    }

    return 0;
}