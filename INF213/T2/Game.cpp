#include "Game.h"
#include <string.h>
#include <iostream>
using namespace std;

Game::Game(int h, int w, int tam) : screen(Screen(h, w)), snake(Snake(tam)) {
    foods = new Food[10];
    for (int i = 0; i < 10; i++) foods[i].deactivate();

    for (int i = 0; i < tam; i++) screen.set(0, i, Screen::SNAKE);
}

Game::~Game() {
    delete []foods;
}

Game::Game(const Game &obj) {
    foods = new Food[10];
    for (int i = 0; i < 10; i++) foods[i].deactivate();

    *this = obj;
}

Game & Game::operator=(const Game & obj) {
    if (this == &obj) return *this;

    delete []foods;

    snake = obj.snake;
    screen = obj.screen;
    t = obj.t;
    memcpy(foods, obj.foods, sizeof(Food) * 10);

    return *this;
}

bool Game::step(int r, int c) {
    t++;
    int x = snake.dataLast->x + r;
    int y = snake.dataLast->y + c;

    if (snake.getLength() > 1 && snake.checkDirection(x, y)){
        x -= (2 * r);
        y -= (2 * c);
    }

    checkFood();

    if (x < 0 || y < 0 || x >= screen.getHeight() || y >= screen.getWidth()) return false;

    if (screen.get(x, y) == Screen::EMPTY) {
        snake.move(r, c, false);
        snake.draw(screen, Screen::SNAKE);

        return true;
    }

    if (screen.get(x, y) == Screen::FOOD) {
        for (int i = 0; i < 10; i++) {
            if (foods[i].x == x && foods[i].y == y) {
                screen.set(foods[i].x, foods[i].y, Screen::EMPTY);
                foods[i].deactivate();
                break;
            }
        }

        snake.move(r, c, true);
        snake.draw(screen, Screen::SNAKE);

        return true;
    }
    
    return false;
}

void Game::addFood(int r, int c, int temp) {
    if (screen.get(r, c) != Screen::EMPTY) return;
    
    for (int i = 0; i < 10; i++) {
        if (foods[i].life < 0) {
            screen.set(r, c, Screen::FOOD);

            foods[i].life = temp + t;
            foods[i].x = r;
            foods[i].y = c; 
            return;
        }
    }
}

Screen & Game::getScreen() {
    return screen;
}

int Game::getNumFood() const {
    int cont = 0;
    for (int i = 0; i < 10; i++) {
        if (foods[i].life > 0) cont++;
    }

    return cont;
}

void Game::checkFood() {
    for (int i = 0; i < 10; i++) {
        if (foods[i].life != -1 && foods[i].life < t) {
            if (screen.get(foods[i].x, foods[i].y) == Screen::FOOD) {
                screen.set(foods[i].x, foods[i].y, Screen::EMPTY);

                foods[i].deactivate();
            }
        }
    }
}