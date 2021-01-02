#include "Snake.h"

Snake::Snake(int t) {
    for (int i = 0; i < t; i++) push_back(t);
}

Snake::~Snake() {
    destroy();
}

void Snake::push_back(int el) {
    if (dataFirst == NULL) {
        dataFirst = dataLast = new Node(el);
    } else {
        int aux = dataLast->y;
        dataLast->next = new Node(el);
        dataLast = dataLast->next;
        dataLast->y = aux + 1;
    }
}

Snake::Snake(const Snake & obj) {
    dataFirst = dataLast = NULL;

    *this = obj;
}

Snake & Snake::operator=(const Snake &obj) {
    if (this == &obj) return *this;

    destroy();

    dataFirst = dataLast = NULL;

    if (obj.getLength() == 0) dataFirst = dataLast = NULL;
    else {
        Node *aux = obj.dataFirst;
        while (aux) {
            push_back(aux->data);
            aux = aux->next;
        }
    }

    return *this;
}

void Snake::push_front(int el) {
    if (dataFirst == NULL) {
        dataFirst = dataLast = new Node(el);
    } else {
        Node *aux = new Node(el);
        aux->next = dataFirst;
        dataFirst = aux;
    }
}

int Snake::getLength() const {
    Node *aux = dataFirst;

    int i = 0;
    for (i = 0; aux != NULL; i++) {
        aux = aux->next;
    }

    return i;
}

void Snake::draw(Screen &s, int state) {
    for (int i = 0; i < s.getHeight(); i++) {
        for (int j = 0; j < s.getWidth(); j++) {
            if (s.get(i, j) == Screen::SNAKE) s.set(i, j, Screen::EMPTY);
        }
    }

    Node *aux = dataFirst;

    while (aux) {
        s.set(aux->x, aux->y, state);
        aux = aux->next;
    }

    delete aux;
}

void Snake::move(int r, int c, bool isEating) {
    int a = dataLast->x;
    int b = dataLast->y;

    push_back(Screen::SNAKE);

    dataLast->x = a + r;
    dataLast->y = b + c;

    if (!isEating) {
        Node *aux = dataFirst;
        dataFirst = dataFirst->next;
        delete aux;
    }
}

void Snake::destroy() {
    destroy(dataFirst);
}

void Snake::destroy(Node *n) {
    if (n == NULL) return;
    destroy(n->next);
    delete n;
}

bool Snake::checkDirection(int px, int py) const {
    Node *aux = dataFirst;

    while(aux->next != dataLast) aux = aux->next;

    if (px == aux->x && py == aux->y) return true;
    return false;
} 