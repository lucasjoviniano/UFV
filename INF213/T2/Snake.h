#ifndef SNAKE_H
#define SNAKE_H

#include "Screen.h"
#include <cstddef>
using namespace std;

class Node {
    public:
        Node(const int el): data(el), next(NULL), x(0), y(0) {}
        int data;
        Node *next;
        int x, y;
};

class Snake {
    public:
        Snake(int = 0);
        Snake(const Snake &);
        ~Snake();
        Snake & operator=(const Snake &);

        void draw(Screen &, int);
        void move(int, int, bool);
        int getLength() const;

        void push_back(int);
        void push_front(int);
    private:
        Node *dataFirst = NULL, *dataLast = NULL;

        void create();
        void destroy();
        void destroy(Node *n);
        bool checkDirection(int, int) const;

        friend class Game;
};

#endif