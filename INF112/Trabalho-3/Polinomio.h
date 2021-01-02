#ifndef __POLINOMIO
#define __POLINOMIO

#include <iostream>
#include <complex>

using namespace std;

class ArgumentoInvalidoExcept{
};

class PosicaoInvalidaExcept{
};

class RaizInexistenteExcept{
};

class Polinomio {
  public:
    // métodos a serem implementados
    // /* construtores e destrutores */      
  
       
    // construtor padrão. Deve representar o número 0
	 
    Polinomio();
    
    // Cria um Polinomio a partir de um número inteiro (positivo ou negativo)

    Polinomio(const int);


    // Cria um Polinomio a partir de um vetor de coeficientes. Os coeficientes
    // deverão ser os coeficientes do polinômio (Posição 0 será a_0, posição 1 será a_1, ...). 
    // O primeiro parâmetro representa o grau do polinômio.
    Polinomio(unsigned int n, double *a);

    // Construtor de cópia

    Polinomio(const Polinomio &);

    // destrutor

    ~Polinomio();

    unsigned int getGrau() const;

    /* Operadores */

    // atribuição
    
    Polinomio & operator=(const Polinomio &);

    // soma

    Polinomio operator+(const Polinomio &) const; // adiciona dois Polinômios
    Polinomio operator+(const double &) const;       // adiciona um polinômio a um número
    Polinomio & operator+=(const Polinomio &);
    Polinomio & operator+=(const double &);
		

    // subtração (segue o mesmo padrão da adição)

    Polinomio operator-(const Polinomio &) const;
    Polinomio operator-(const double &) const;
    Polinomio & operator-=(const Polinomio &);
    Polinomio & operator-=(const double &);
		

    // multiplicação

    // TODO: você também deve implementar a multiplicação por um número à esquerda

    Polinomio operator*(const Polinomio &) const;
    Polinomio operator*(const double &) const;
    friend Polinomio operator*(const double&, const Polinomio&);
    Polinomio & operator*=(const Polinomio &);
    Polinomio & operator*=(const double &);


    // divisão por um polinômio de grau 1 da forma (x - a)
    // deve lançar 'ArgumentoInvalidoExcept' se o denominador não for da forma especificada acima
    // Sugestão: https://pt.wikipedia.org/wiki/Algoritmo_de_Briot-Ruffini

    Polinomio operator/(const Polinomio &) const;
    Polinomio & operator/=(const Polinomio &);
    
    // divide os coeficiente por um número 
    Polinomio operator/(const double &) const;
    Polinomio & operator/=(const double &);

    // resto da divisão por um polinômio de grau 1 da forma (x - 1)
    // deve lançar 'ArgumentoInvalidoExcept' se o denominador não for da forma especificada acima
    // Sugestão: https://pt.wikipedia.org/wiki/Algoritmo_de_Briot-Ruffini
    
    Polinomio operator%(const Polinomio &) const;
    Polinomio & operator%=(const Polinomio &);


    // Retorna i-ésimo coeficiente

    // Deve lançar 'PosicaoInvalidaExcept' se houver tentativa de acessar um bit não existente
    // Posição 0 indica o coeficiente do termo constante 

    double operator[](int) const; 
    double operator[](int);

    // incrementos (adicionar 1) ao termo constante
    Polinomio operator++();
    Polinomio operator++(int);

    // decrementos
    Polinomio operator--();
    Polinomio operator--(int);

    /* Comparação */
		

    // igualdade

    // Verificar se dois polinômios tem o mesmo grau e mesmos coeficientes
    bool operator==(const Polinomio &) const;
    bool operator!=(const Polinomio &) const;

    bool operator<(const Polinomio &) const;
    bool operator>(const Polinomio &) const;

    bool operator<=(const Polinomio &) const;
    bool operator>=(const Polinomio &) const;
    /* Entrada Saída */
		

    // lê/imprime de streams de entrada e saída

    friend istream& operator>>(istream &, Polinomio &);
    friend ostream& operator<<(ostream &, const Polinomio &);

    /* Operações (sem operadores) */

    // retorna a derivada do polinômio

    Polinomio derivada() const;

    // avalia.
    // Dado um número 'a', calcula P(a)
    // sugestão https://en.wikipedia.org/wiki/Horner%27s_method

    double avalia(double) const;

    // resolve P(x) = 0. Encontra as raízes reais do polinômio
    // o parâmetro inteiro é o número de raízes encontradas
    // Se não encontrar raízes, deve lançar uma exceção
    // sugestão: use o método de Newton para encontrar uma raiz, 
    // use o algoritmo de divisão para simplificar o polinômio...

    friend double newton(double, Polinomio &, Polinomio &);
    double* bhaskara(int &) const;
    double* cardano(int &) const;
    double * resolve(int &) const;
    complex<double>* resolveComplexas(int&) const;

    Polinomio integral() const;

    double integral(double, double) const;

  private:
    // Ponteiro que vai representar o polinômio
    // cada posição representa o grau relacionado ao coeficiente
    double *poli;
    //Grau do polinomio
    //Lembrando que o tamanho é grau + 1
    unsigned int grau;
};

#endif
