#include <iostream>
using namespace std;

int main() {
    int batata = 430;
    int suco = 270;
    int guarana = 143;

    char produto;
    char tipo;
    int valor;
    int total = 0;
    int troco;

    cin >> produto;
    cin >> tipo >> valor;

    while (valor != 0)
    {
        //Cálculo do total inserido, transformando o valor das cédulas para centavos.
        total = (tipo == 'M') ? total + valor : total + (valor * 100);
        cin >> tipo >> valor;
    }

    if (produto != '1' && produto != '2' && produto != '3')
    {
        cout << "Produto inexistente." << endl;
    }
    else if (produto == '1' && total > batata)
    {
        troco = total - batata;
    }
    else if (produto == '2' && total > suco)
    {
        troco = total - suco;
    }
    else if (produto == '3' && total > guarana)
    {
        troco = total - guarana;
    }
    else
    {
        cout << "Saldo insuficiente." << endl;
    }

    if ((produto == '1' && total >= batata) || (produto == '2' && total >= suco) || (produto == '3' && total >= guarana)) {
        while (troco > 0) {
            if (troco >= 10000) {
                cout << "C 100" << endl;
                troco -= 10000;
            }
            else if (troco >= 5000) {
                cout << "C 50" << endl;
                troco -= 5000;
            }
            else if (troco >= 2000) {
                cout << "C 20" << endl;
                troco -= 2000;
            }
            else if (troco >= 1000) {
                cout << "C 10" << endl;
                troco -= 1000;
            }
            else if (troco >= 500) {
                cout << "C 5" << endl;
                troco -= 500;
            }
            else if (troco >= 200) {
                cout << "C 2" << endl;
                troco -= 200;
            }
            else if (troco >= 100) {
                cout << "M 100" << endl;
                troco -= 100;
            }
            else if (troco >= 50) {
                cout << "M 50" << endl;
                troco -= 50;
            }
            else if (troco >= 25) {
                cout << "M 25" << endl;
                troco -= 25;
            }
            else if (troco >= 10) {
                cout << "M 10" << endl;
                troco -= 10;
            }
            else if (troco >= 5) {
                cout << "M 5" << endl;
                troco -= 5;
            }
            else if (troco >= 1) {
                cout << "M 1" << endl;
                troco -= 1;
            }
        }
        }

    return 0;
}