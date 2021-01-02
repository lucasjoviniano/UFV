#include "Screen.h"
#include <string.h>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

Screen::Screen(int a, int l) : largura(l), altura(a) {
    if (a == 0 && l == 0) return;
    data = new int*[getWidth()];
    dataHeight = new int[getWidth()];
    memset(dataHeight, 0, sizeof(int) * getWidth());
    memset(data, 0, sizeof(int*) * getWidth());
}

Screen::~Screen() {
    delete []dataHeight;

    for (int i = 0; i < largura; i++) {
        if (data[i]) delete []data[i];
    }

    delete []data;
}

Screen::Screen(const Screen & obj) {
    data = NULL;
    dataHeight = NULL;

    *this = obj;
}

Screen & Screen::operator=(const Screen & obj) {
    if (this == &obj) return *this;

    dataHeight = NULL;
    data = NULL;

    altura = obj.altura;
    largura = obj.largura;

    for (int i = 0; i < largura; i++) {
        data[i] = new int[obj.dataHeight[i]];
    }
    memcpy(dataHeight, obj.dataHeight, sizeof(int*) * getWidth());

    for (int i = 0; i < largura; i++) {
        memcpy(data[i], obj.data[i], sizeof(int) * dataHeight[i]);
    }

    return *this;
}

int Screen::getHeight() const { return altura; }

int Screen::getWidth() const { return largura; }

int Screen::get(int r, int c) const {
    if (r > altura || c > largura) return WALL;
    if (r + 1 > dataHeight[c] || dataHeight[c] == 0) return EMPTY;
    return data[c][r];
}


void Screen::set(int r, int c, int val) {
    if (c >= largura || r >= altura) return;

    if (dataHeight[c] == 0) {
        //cout << "Caso: dataHeight[c] == 0\n";
        dataHeight[c] = r + 1;
        data[c] = new int[dataHeight[c]];
        for (int i = 0; i < dataHeight[c]; i++) data[c][i] = EMPTY;
        //memset(data[c], EMPTY, sizeof(int) * dataHeight[c]);
        data[c][r] = val;
        return;
    }

    if (dataHeight[c] < r + 1) {
        //cout << "Caso: dataHeight[c] < r + 1\n";
        int *v = new int[(r + 1)];
        for (int i = 0; i < r + 1; i++) v[i] = EMPTY;
        //memset(v, EMPTY, sizeof(int) * (r + 1));
        //for (int i = 0; i < r + 1; i++) //cout << v[i] << " ";
        ////cout << endl;
        memcpy(v, data[c], sizeof(int) * dataHeight[c]);
        dataHeight[c] = r + 1;
        swap(v, data[c]);
        delete []v;
        data[c][r] = val;
        return;
    }
    
    data[c][r] = val;
        
    if (data[c][dataHeight[c] - 1] == EMPTY) {
        //cout << "Caso: data[c][dataHeight[c] - 1] == EMPTY\n";
        int h = 0;
        for (int i = 0; i < dataHeight[c]; i++) {
            if (data[c][i] != EMPTY) h = i + 1;
        }

        if (h == 0) {
            dataHeight[c] = h;
            delete []data[c];
            data[c] = NULL;
        } else {
            int *v = new int[h];
            for (int i = 0; i < h; i++) v[i] = EMPTY;
            //memset(v, EMPTY, sizeof(int) * h);
            memcpy(v, data[c], sizeof(int) * h);
            dataHeight[c] = h;
            swap(data[c], v);
            delete[] v;
        }
    } 
}