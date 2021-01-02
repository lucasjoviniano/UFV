#include <iostream>
using namespace std;

int main(){
    int preco;
    int input;
    int dinheiro = 0;

    cin >> preco;
    cin >> input;

    dinheiro += input;

    while (input != 0){
        cin >> input;
        dinheiro += input;
    }

    if (dinheiro >= preco){
        cout << "Troco de " << (dinheiro - preco) << " centavos." << endl;
    } else{
        cout << "Saldo insuficiente." << endl;
    }

return 0;
}