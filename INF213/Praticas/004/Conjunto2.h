#ifndef CONJUNTO2_H
#define CONJUNTO2_h

#include <iostream>
using namespace std;

template <class T>
class Conjunto {
    public:
        Conjunto(int = 10);
        Conjunto(const Conjunto&);
        ~Conjunto();
        bool pertence(const T&) const;
        bool insere(const T&);
        int numelementos() const;
        bool operator==(const Conjunto &) const;
        Conjunto operator+(const Conjunto &) const;
        Conjunto operator-(const Conjunto &) const;
        Conjunto operator*(const Conjunto &) const;
        Conjunto & operator=(const Conjunto &);

        template<class T1>
        friend ostream& operator <<(ostream &, const Conjunto<T1> &);

        template<class T1>
        friend istream& operator >>(istream &, Conjunto<T1> &);
    private:
        T* elementos;
        int num_elementos, tam_array;
};

template<class T>
Conjunto<T>::Conjunto(int t) {
    elementos = new T[t];
    for(int i = 0; i < t; i++) elementos[i] = T();
    tam_array = t;
    num_elementos = 0;
}

// O(n)
template<class T>
Conjunto<T>::~Conjunto() {
    delete []elementos;
}

template<class T>
Conjunto<T>::Conjunto(const Conjunto<T> & obj) {
    elementos = NULL;
    *this = obj;
}

template<class T>
bool Conjunto<T>::pertence(const T & obj) const {
    for (int i = 0; i < num_elementos; i++) {
        if (elementos[i] == obj) return true;
    }
    return false;
}

template<class T>
bool Conjunto<T>::insere(const T & obj) {
    if (num_elementos == tam_array || pertence(obj)) return false;
    elementos[num_elementos++] = obj;
    return true;
}

template<class T>
int Conjunto<T>::numelementos() const {
    return num_elementos;
}

//O(n^2)
template<class T>
bool Conjunto<T>::operator==(const Conjunto<T> & obj) const {
    if (num_elementos != obj.num_elementos) return false;
    for (int i = 0; i < num_elementos; i++) {
        if (!obj.pertence(elementos[i])) return false;
    }
    return true;
}

// melhor caso: conjuntos iguais --> O(n^2)
// pior caso: conjuntos totalmente diferentes --> O(m*(n+m)) ~~ O(n^2)
template<class T>
Conjunto<T> Conjunto<T>::operator+(const Conjunto<T> &obj) const {
    Conjunto<T> aux(tam_array + obj.tam_array);
    for (int i = 0; i < num_elementos; i++) {
        aux.insere(elementos[i]);
    }
    for (int i = 0; i < obj.num_elementos; i++) {
        aux.insere(obj.elementos[i]);
    }

    return aux;
}

template<class T>
Conjunto<T> Conjunto<T>::operator*(const Conjunto<T> & obj) const {
    Conjunto<T> aux(tam_array < obj.tam_array ? tam_array : obj.tam_array);
    for (int i = 0; i < num_elementos; i++) {
        if (obj.pertence(elementos[i])) {
            aux.insere(elementos[i]);
        }
    }

    return aux;
}

template<class T>
Conjunto<T> Conjunto<T>::operator-(const Conjunto<T> &obj) const {
    Conjunto<T> aux(tam_array);
    for (int i = 0; i < num_elementos; i++) {
        if (!obj.pertence(elementos[i])) {
            aux.insere(elementos[i]);
        }
    }

    return aux;
}

// O(max(m, n))
template<class T>
Conjunto<T> & Conjunto<T>::operator=(const Conjunto<T> & obj) {
    if (this == &obj) return *this;    
    delete []elementos;
    tam_array = obj.tam_array;
    num_elementos = obj.num_elementos;
    elementos = new T[tam_array];
    for (int i = 0; i < num_elementos; i++) 
        elementos[i] = obj.elementos[i];
    return *this;
}

template<class T1>
ostream& operator <<(ostream &file, const Conjunto<T1> &obj) {
    file << "{";
    for (int i = 0; i < obj.num_elementos; i++) {
        if (i == obj.num_elementos - 1) {
            file << obj.elementos[i];
            break;
        }
        file << obj.elementos[i] << ",";
    }

    file << "}";
    
    return file;
}

template<class T1>
istream& operator >>(istream &file, Conjunto<T1> &obj) {
    T1 aux;
    while (file) {
        file >> aux;
        obj.insere(aux);
    }
    return file;
}

#endif