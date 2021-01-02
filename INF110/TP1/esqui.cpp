#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double distancia;
    double nota1, nota2, nota3, nota4, nota5;
    double k120 = 120.0;
    double maior;
    double menor;
    double pontos;
    double nota;

    cin >> distancia >> nota1 >> nota2 >> nota3 >> nota4 >> nota5; 


    //Avaliando a restrição da distância
    if (distancia == k120){
        pontos = 60;
    } else if (distancia >= k120){
        distancia -= k120;
        pontos = (distancia * 1.8) + 60;
    } else if (distancia <= k120){
        distancia = k120 - distancia;
        pontos = 60 - (distancia * 1.8);
    }

    //Descobrindo a maior nota
    if (nota1 >= nota2 && nota1 >= nota3 && nota1 >= nota4 && nota1 >= nota5){
        maior = nota1;
    } else if (nota2 >= nota1 && nota2 >= nota3 && nota2 >= nota4 && nota2 >= nota5){
        maior = nota2;
    } else if (nota3 >= nota1 && nota3 >= nota2 && nota3 >= nota4 && nota3 >= nota5){
        maior = nota3;
    } else if (nota4 >= nota1 && nota4 >= nota2 && nota4 >= nota3 && nota4 >= nota5){
        maior = nota4;
    } else if (nota5 >= nota1 && nota5 >= nota2 && nota5 >= nota3 && nota5 >= nota4){
        maior = nota5;
    }

    //Descobrindo a menor nota
    if (/*nota1 != maior &&*/ nota1 <= nota2 && nota1 <= nota3 && nota1 <= nota4 && nota1 <= nota5){
        menor = nota1;
    } else if (/*nota2 != maior &&*/ nota2 <= nota1 && nota2 <= nota3 && nota2 <= nota4 && nota2 <= nota5){
        menor = nota2;
    } else if (/*nota3 != maior &&*/ nota3 <= nota1 && nota3 <= nota2 && nota3 <= nota4 && nota3 <= nota5){
        menor = nota3;
    } else if (/*nota4 != maior &&*/ nota4 <= nota1 && nota4 <= nota2 && nota4 <= nota3 && nota4 <= nota5){
        menor = nota4;
    }
    else if (/*nota5 != maior &&*/ nota5 <= nota1 && nota5 <= nota2 && nota5 <= nota3 && nota5 <= nota4)
    {
        menor = nota5;
    }

    nota = (nota1 + nota2 + nota3 + nota4 + nota5) - (maior + menor);

    cout << fixed << setprecision(1) << (pontos + nota) << endl;

return 0;
}