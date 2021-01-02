#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

template<class T>
class MyMatrix {
    public:
        MyMatrix(int, int *, bool);
        ~MyMatrix();
        T & get(int, int) const;
        void set(int, int, const T&);
        int getNumRows() const;
        int getNumElems() const;
        int getNumCols(int) const;
        void resizeRow(int, int);
        void resizeNumRows(int);
        bool isRagged() const;
        void convertToRagged();
        void convertToTraditional();
        void print() const;

        MyMatrix<T> & operator=(const MyMatrix &);
        MyMatrix(const MyMatrix &);
    protected:
        int rows, size;
        T* ragged;
        int* start;
        int* tam;
        T** matriz;
    private:
        void destroy();
        void create();
};

template<class T>
MyMatrix<T>::MyMatrix(int lin, int* cols, bool rag): rows(lin){
    // Calcula o size
    size = 0;
    for (int i = 0; i < rows; i++) size += cols[i];

    // Se for ragged
    if (rag) {
        // Declara os membros de dados usados pela forma tradicional como NULL
        tam = NULL;
        matriz = NULL;
        // Declara o start com 1 elemento a mais para guardar o final
        start = new int[rows + 1];
        // A primeira linha começa na posição 0
        start[0] = 0;
        // Calcula as próximas posições baseadas nos tamanhos das linhas
        for (int i = 1; i <= rows; i++) {
            start[i] = start[i - 1] + cols[i - 1];
        }
        // Cria a matriz ragged baseada na quantidade total de elementos
        ragged = new T[size];
    } else {
        // Inicia os membros de dados usados pela ragged como NULL
        start = NULL;
        ragged = NULL;
        tam = new int[rows];
        // Copia o vetor recebido para o vetor de tamanhos
        memcpy(tam, cols, sizeof(int) * rows);
        // Cria o vetor de ponteiros
        matriz = new T*[rows];
        // Aloca as linhas caso elas tenham algum elemento
        for (int i = 0; i < rows; i++) {
            if (tam[i] > 0) matriz[i] = new T[tam[i]];
            else matriz[i] = NULL;
        }
    }
}

template<class T>
MyMatrix<T>::MyMatrix(const MyMatrix &obj) {
    create();
    *this = obj;
}

template<class T>
MyMatrix<T> & MyMatrix<T>::operator=(const MyMatrix &obj) {
    if (this == &obj) return *this;
    destroy();
    // Copia os mebros de dados estáticos
    size = obj.size;
    rows = obj.rows;
    if (obj.isRagged()) {
        // Aloca os membros de dados da versão ragged
        ragged = new T[size];
        if (size == 0) return *this;
        start = new int[rows + 1];
        // Copia os valores
        memcpy(ragged, obj.ragged, sizeof(T) * size);
        memcpy(start, obj.start, sizeof(int) * (rows + 1));
        matriz = NULL;
        tam = NULL;
    } else {
        tam = new int[rows];
        matriz = new T*[rows];
        memcpy(tam, obj.tam, sizeof(int) * rows);
        for (int i = 0; i < rows; i++) {
            if (tam[i] > 0) {
                matriz[i] = new T[tam[i]];
                memcpy(matriz[i], obj.matriz[i], sizeof(T) * tam[i]);
            } else {
                matriz[i] = NULL;
            }
        }
        ragged = NULL;
        start = NULL;
    }

    return *this;
}

template<class T>
void MyMatrix<T>::destroy() {
    if (ragged == NULL && matriz == NULL) {
        size = rows = 0;
        return;
    }
    if (isRagged()) {
        delete [] ragged;
        delete [] start;
    } else {
        for (int i = 0; i < rows; i++)  {
            if (matriz[i] != NULL) delete [] matriz[i];
        }
        delete [] matriz;
        delete [] tam;
    }
    size = 0;
    rows = 0;
}

template<class T>
void MyMatrix<T>::create() {
    matriz = NULL;
    start = NULL;
    tam = NULL;
    ragged = NULL;
    size = rows = 0;
}

template<class T>
MyMatrix<T>::~MyMatrix() {
    destroy();
}

template<class T>
T & MyMatrix<T>::get(int l, int c) const {
    if (isRagged()) {
        return ragged[start[l] + c];
    } else {
        return matriz[l][c];
    }
}

template<class T>
void MyMatrix<T>::set(int l, int c, const T & elem) {
    if (isRagged()) {
        ragged[start[l] + c] = elem;
    } else {
        matriz[l][c] = elem;
    }
}

template<class T>
int MyMatrix<T>::getNumRows() const {
    return rows;
}

template<class T>
int MyMatrix<T>::getNumElems() const {
    return size;
}

template<class T>
int MyMatrix<T>::getNumCols(int l) const {
    if (isRagged()) {
        return start[l + 1] - start[l];
    } else {
        return tam[l];
    }
}

template<class T>
void MyMatrix<T>::resizeRow(int r, int t) {
    if (isRagged()) {
        // Pega o tamanho da linha
        int r_tam = start[r + 1] - start[r];
        // Pega o maior
        int b = t > r_tam ? r_tam : t;
        T *v = new T[(size - r_tam) + t];
        // Copia a parte do vetor antes da linha que vamos modificar
        memcpy(v, ragged, sizeof(T) * (start[r] + b));
        // Caso a quantidade de elementos seja maior, inicializa com o construtor padrão
        if (t > r_tam) {
            for (int i = start[r] + b; i < start[r] + t; i++) v[i] = T();
        }
        // Copia a parte do vetor depois da linha que vamos modificar;
        memcpy(&v[start[r] + t], &ragged[start[r + 1]], sizeof(T) * (size - start[r + 1]));
        // 2 3 4 5 6 7 8
        // 0 1 4 7
        // Atualiza as posições de início das linhas
        for (int i = r + 1; i <= rows; i++) {
            start[i] += (t - r_tam);
        }
        
        size = start[rows];
        delete [] ragged;
        ragged = v;
    } else {
        if (t == 0) {
            delete []matriz[r];
            matriz[r] = NULL;
            size -= tam[r];
            tam[r] = 0;
            return;
        }
        // Pega o menor entre os dois
        int m = t > tam[r] ? tam[r] : t;
        // Cria um novo vetor pra linha e copia os valores antigos
        T* v = new T[t];
        memcpy(v, matriz[r], sizeof(T) * m);
        if (t > tam[r]) {
            memset(&v[tam[r]], T(), sizeof(T) * (t - tam[r]));
        }
        size += (t - tam[r]);
        tam[r] = t;
        delete [] matriz[r];
        matriz[r] = v;
    }

    tam[linha] > elementos
    elementos > tam[li]
}

template<class T>
void MyMatrix<T>::resizeNumRows(int n) {
    // Se o número não for alterado, só retorna
    if (n == rows) return;
    if (isRagged()) {
        if (n > rows) {
            // Cria um vetor auxiliar pro start
            int *v = new int[n + 1];
            // Copia o conteúdo do start pro auxiliar
            memcpy(v, start, sizeof(int) * (rows + 1));
            // Como as linhas tem com 0 elementos, todas começam na mesma posição
            for (int i = rows + 1; i <= n; i++) v[i] = v[rows];
            delete [] start;
            rows = n;
            start = v;
        } else {
            int *v = new int[n + 1];
            memcpy(v, start, sizeof(int) * (n + 1));
            T *a = new T[v[n]];
            memcpy(a, ragged, sizeof(T) * v[n]);
            delete [] start;
            delete [] ragged;
            start = v;
            ragged = a;
            rows = n;
            size = start[rows];
        }
    } else {
        if (n > rows) {
            // Declara um vetor com o novo número de linhas
            int *v = new int[n];
            // Copia os valores antigos dos tamanhos
            memcpy(v, tam, sizeof(int) * rows);
            // Define os novos tamanhos como 0
            memset(&v[rows], 0, sizeof(int) * (n - rows));
            T **a = new T*[n];
            memcpy(a, matriz, sizeof(T*) * rows);
            for (int i = rows; i < n; i++) a[i] = NULL;
            delete [] matriz;
            delete [] tam;
            matriz = a;
            tam = v;
            rows = n;
        } else {
            int *v = new int[n];
            memcpy(v, tam, sizeof(int) * n);
            T **a = new T*[n];
            for (int i = 0; i < n; i++) {
                a[i] = matriz[i];
            }
            //memcpy(a, matriz, sizeof(T*) * n);
            for (int i = n; i < rows; i++) {
                if (matriz[i] != NULL) delete [] matriz[i];
            }
            delete [] matriz;
            delete [] tam;
            matriz = a;
            tam = v;
            size = 0;
            for (int i = 0; i < n; i++) size += tam[i];
            rows = n;
        }
    }
}

template<class T>
bool MyMatrix<T>::isRagged() const {
    return ragged != NULL && matriz == NULL;
}

template<class T>
void MyMatrix<T>::convertToRagged() {
    // Se já for ragged, retorna
    if (isRagged()) return;
    // Cria o vetor ragged
    ragged = new T[size];
    // Cria o start
    start = new int[rows + 1];
    // A primeira linha começa na posição 0
    start[0] = 0;
    // Calcula o início das próximas linhas
    for (int i = 1; i <= rows; i++) {
        start[i] = start[i - 1] + tam[i - 1];
    }
    // Copia as linhas para o vetor ragged
    for (int i = 0; i < rows; i++) {
        if (tam[i] > 0) {
            memcpy(&ragged[start[i]], matriz[i], sizeof(T) * tam[i]);
            delete [] matriz[i];
        } 
    }
    // Deleta os membros usados pela matriz traditional
    delete [] matriz;
    delete [] tam;
    matriz = NULL;
    tam = NULL;
}

template<class T>
void MyMatrix<T>::convertToTraditional() {
    // Se já for traditional, retorna
    if (!isRagged()) return;
    // Declara o vetor de tamanhos
    tam = new int[rows];
    // Calcula o tamanho de cada linha
    for (int i = 0; i < rows; i++) {
        tam[i] = start[i + 1] - start[i];
    }
    // Declara o vetor de vetores
    matriz = new T*[rows];
    for (int i = 0; i < rows; i++) {
        // Se tiver elementos, aloca a linha e copia
        if (tam[i] > 0) {
            matriz[i] = new T[tam[i]];
            memcpy(matriz[i], &ragged[start[i]], sizeof(T) * tam[i]);
        } else {
            matriz[i] = NULL;
        }
    }
    // Deleta os membros usados pela ragged
    delete [] ragged;
    delete [] start;
    ragged = NULL;
    start = NULL;
}

template<class T>
void MyMatrix<T>::print() const {
    cout << "Rows: " << getNumRows() << endl;
    cout << "Elems: " << getNumElems() << endl;
    if (isRagged()) {
        int e = 0;
        for (int i = 0; i < rows; i++) {
            int s = start[i + 1] - start[i];
            if (s == 0) {
                cout << "0:\n";
                continue;
            }
            cout << s << ": ";
            for (int j = e; j < e + s - 1; j++) cout << ragged[j] << " ";
            cout << ragged[e + s - 1] << endl;
            e += s;
        }
    } else {
        for (int i = 0; i < rows; i++) {
            if (tam[i] == 0) {
                cout << "0:\n"; 
                continue;
            } 
            cout << tam[i] << ": ";
            for (int j = 0; j < tam[i] - 1; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << matriz[i][tam[i] - 1] << endl;
        }
    }
}

#endif