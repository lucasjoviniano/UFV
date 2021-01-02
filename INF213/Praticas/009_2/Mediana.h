#ifndef MEDIANA_H
#define MEDIANA_H

#include "MyPriorityQueue.h"

class Mediana {
    public:
        void insere(int x);
        int getMediana();
    private:
        MyPriorityQueue<int> v1;
        MyPriorityQueue<int> v2;
};

#endif