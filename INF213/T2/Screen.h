#ifndef SCREEN_H
#define SCREEN_H

class Screen {
    public:
        Screen(int = 0, int = 0);
        Screen(const Screen &);
        ~Screen();
        Screen & operator=(const Screen &);
        int getWidth() const;
        int getHeight() const;
        int get(int, int) const;
        void set(int, int, int);

        static const int FOOD = 1;
        static const int SNAKE = 2;
        static const int EMPTY = 3;
        static const int WALL = 0;
    private:
        int largura, altura;
        int** data;
        int *dataHeight;
};

#endif