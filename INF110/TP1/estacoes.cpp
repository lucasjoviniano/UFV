#include <iostream>
//Declaração do cabeçalho string, como mostrado na página 60 do livro-texto da disciplina
#include <string>
using namespace std;

int main(){
    
    int dia, mes;
    string extenso;
    string estacaoExtenso;

    cin >> dia >> mes;

    // Testes de condições 2 a 2 usando operador ternário, para simplificar o código

    if (mes == 1 || mes == 2){
        extenso = (mes == 1) ? " de janeiro" : " de fevereiro";
        cout << dia << extenso << endl;
        cout << "Verao" << endl;
    }else if (mes == 3 && dia < 20 || mes == 3 && dia >= 20){
        estacaoExtenso = (dia < 20) ? "Verao" : "Outono";
        cout << dia << " de marco" << endl;
        cout << estacaoExtenso << endl;
    }else if (mes == 4 || mes == 5){
        extenso = (mes == 4) ? " de abril" : " de maio";
        cout << dia << extenso << endl;
        cout << "Outono" << endl;
    }else if (mes == 6 && dia < 21 || mes == 6 && dia >= 21){
        estacaoExtenso = (dia < 21) ? "Outono" : "Inverno";
        cout << dia << " de junho" << endl;
        cout << estacaoExtenso << endl;
    }else if (mes == 7 || mes == 8){
        extenso = (mes == 7) ? " de julho" : " de agosto";
        cout << dia << extenso << endl;
        cout << "Inverno" << endl;
    }else if (mes == 9 && dia < 23 || mes == 9 && dia >= 23){
        estacaoExtenso = (dia < 23) ? "Inverno" : "Primavera";
        cout << dia << " de setembro" << endl;
        cout << estacaoExtenso << endl;
    }else if (mes == 10 || mes == 11){
        extenso = (mes == 10) ? " de outubro" : " de novembro";
        cout << dia << extenso << endl;
        cout << "Primavera" << endl;
    }else if (mes == 12 && dia < 22 || mes == 12 && dia >= 22){
        estacaoExtenso = (dia < 22) ? "Primavera" : "Verao";
        cout << dia << " de dezembro" << endl;
        cout << estacaoExtenso << endl;
    }

return 0;
}