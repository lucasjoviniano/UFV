#ifndef GAME_H
#define GAME_H

#include "Screen.h"
#include "Snake.h"

struct Food {
    int x = -1;
    int y = -1;
    int life = -1;

    void deactivate() {
        x = y = life = -1;
    }
};

class Game {
    public:
        Game(int, int, int);
        Game(const Game &);
        ~Game();
        Game & operator=(const Game &);

        Screen & getScreen();
        bool step(int, int);
        int getNumFood() const;
        void addFood(int, int, int);

        void checkFood();
    private:
        Food *foods;

        Snake snake;
        Screen screen;
        int t = 0;
};

#endif