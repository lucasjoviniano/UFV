#include <iostream>
using namespace std;

int main(){
    int batata = 430;
    int suco = 270;
    int guarana = 143;

    char produto;
    char tipo;
    int valor;
    int total = 0;

    cin >> produto;
    cin >> tipo >> valor;

    while (valor != 0){

        //Cálculo do total inserido, transformando o valor das cédulas para centavos.
        total = (tipo == 'M') ? total + valor : total + (valor * 100);

        cin >> tipo >> valor;

        /*if (tipo == 'M') {
            total += valor;
            cin >> tipo >> valor;
        }
        else if (tipo == 'C') {
            valor = valor * 100;
            total += valor;
            cin >> tipo >> valor;
        }*/
    }

    if (produto != '1' && produto != '2' && produto != '3'){
        cout << "Produto inexistente." << endl;
    }
    else if (produto == '1' && total > batata) {
        cout << "Troco de " << total - batata << " centavos." << endl;
    }
    else if (produto == '2' && total > suco) {
        cout << "Troco de " << total - suco << " centavos." << endl;
    }
    else if (produto == '3' && total > guarana) {
        cout << "Troco de " << total - guarana << " centavos." << endl;
    }
    else {
        cout << "Saldo insuficiente." << endl;
    }

return 0;
}