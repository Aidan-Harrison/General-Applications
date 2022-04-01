#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>
#include <ncurses.h>
#include <thread>

#define getF std::get<0>
#define getS std::get<1>

// Multi-thread so objects can move


namespace Global {
    WINDOW * gameWindow;
    int screenWidth = 60, screenHeight = 35;
}
using namespace Global;

// Frogger
namespace Frog {
    int x = 14, y = 34;
    int lives = 3;
    const char * graphic = "#";
    bool moveL = false, moveR = false, moveU = false, moveD = false;
}

struct Car {
    int x = 6, y = 0;
    int length = 2; // Max 5
    int speed = 1; // Max 3
    bool isLeft = false; // Possibly remove
    std::string body;
    Car(const int lane, const int l, const int s, const int startingX, const bool left = false) : y(lane), length(l), speed(s), x(startingX), isLeft(left)
    {
        for(int i = 0; i <= length; i++)
            body.append("/");
        if(left)
            body[0] = '&';
        else
            body[body.length()-1] = '&';
    }
    ~Car() {}
};

struct Log {
    int x, y;
    int speed = 1;
    int length = 2;
};

namespace GameManager {
    int score = 0;
    std::vector<std::pair<bool,int>> holePositions{{false, screenWidth*0.20},{false, screenWidth*0.40},{false, screenWidth*0.60},{false, screenWidth*0.80},{false, screenWidth-1}}; // Y is always 1
    int carMaxY = 25;
    int carMinY = 33;
    std::vector<Car> cars{};
}

void Input() {
    // printw("%d", key);
    while(1) {
        const int key = getch();
        switch(key) {
            case 119: {
                Frog::moveU = true;
                Frog::y--; 
                break;
            }
            case KEY_DOWN: {
                Frog::moveD = true;
                Frog::y++; 
                break;
            }
            case KEY_LEFT: {
                Frog::moveL = true;
                Frog::x--; 
                break;
            }
            case KEY_RIGHT: {
                Frog::moveR = true;
                Frog::x++; 
                break;
            }
            case 0: exit(0);
        }
    }
}

void Setup() {
    // Cars | Add offset between cars
    int lane = GameManager::carMaxY;
    for(int i = 0; i < 15; i++) {
        int speed = rand() % 3;
        speed++;
        int length = rand() % 4;
        length++;
        int left = rand() % 2;
        int xPos = rand() % screenWidth;
        Car newCar(lane, length, speed, xPos, left);
        GameManager::cars.push_back(newCar);
        if(i % 3 == 0 && lane < GameManager::carMinY)
            lane++;
    }
}

void Logic() {
        if(GameManager::score == 5)
            exit(0);
        // Input(wgetch(gameWindow));
        mvwprintw(gameWindow, Frog::y, Frog::x, Frog::graphic);
        mvwprintw(gameWindow, 0, (screenWidth/2)-1, "FROGGER");
        std::string tempStr = std::to_string(GameManager::score);
        const char * scoreChar = tempStr.c_str();
        mvwprintw(gameWindow, 0, screenWidth-5, scoreChar);
        mvwprintw(gameWindow, 0, 1+(screenWidth/3), "%d", Frog::lives);

        // Cars
        for(int i = 0; i < GameManager::cars.size(); i++) {
            switch (GameManager::cars[i].isLeft) {
                case false: GameManager::cars[i].x+=GameManager::cars[i].speed; break;
                case true: GameManager::cars[i].x-=GameManager::cars[i].speed; break;
            }
            mvwprintw(gameWindow, GameManager::cars[i].y, GameManager::cars[i].x, GameManager::cars[i].body.c_str());
            switch(GameManager::cars[i].isLeft) {
                case false: mvwprintw(gameWindow, GameManager::cars[i].y ,GameManager::cars[i].x - GameManager::cars[i].length - GameManager::cars[i].speed, " "); break;
                case true: mvwprintw(gameWindow, GameManager::cars[i].y ,GameManager::cars[i].x + GameManager::cars[i].length+GameManager::cars[i].speed, " "); break;
            }
            
            // Looping
            if(GameManager::cars[i].x <= 1)
                GameManager::cars[i].x = screenWidth-1;
            else if(GameManager::cars[i].x >= screenWidth-1)
                GameManager::cars[i].x = 1;

            // Collision | Add car length, partial AABB
            if(Frog::x == GameManager::cars[i].x && Frog::y == GameManager::cars[i].y) {
                Frog::lives--;
                Frog::y = screenHeight-1;
                Frog::x = (screenWidth/2)-1;
            }
        }

        // Collision
        for(int i = 0; i < GameManager::holePositions.size(); i++) {
            switch(getF(GameManager::holePositions[i])) {
                case false: mvwprintw(gameWindow, 1, getS(GameManager::holePositions[i]), "@");break;
                case true: mvwprintw(gameWindow, 1, getS(GameManager::holePositions[i]), "X"); break;
            }
            if(Frog::y == 1 && Frog::x == getS(GameManager::holePositions[i]) && getF(GameManager::holePositions[i]) == false) {
                GameManager::score++;
                Frog::y = screenHeight-1;
                Frog::x = (screenWidth/2)-1;
                getF(GameManager::holePositions[i]) = true;
            }
        }
            
        // Bounds Checking
        if(Frog::x <= 1)
            Frog::x++;
        else if(Frog::x >= screenWidth-1)
            Frog::x--;
        if(Frog::y <= 1)
            Frog::y++;
        else if(Frog::y >= screenHeight-1)
            Frog::y--;

        // Manual ghost clearing
        if(Frog::moveL) mvwprintw(gameWindow, Frog::y, Frog::x+1, " ");
        if(Frog::moveR) mvwprintw(gameWindow, Frog::y, Frog::x-1, " ");
        if(Frog::moveU) mvwprintw(gameWindow, Frog::y+1, Frog::x, " ");
        if(Frog::moveD) mvwprintw(gameWindow, Frog::y-1, Frog::x, " ");
        //mvwdelch(gameWindow, Frog::y-1, Frog::x);
        wrefresh(gameWindow); // | wgetch() calls automatically

        // Reset
        Frog::moveL = false;
        Frog::moveR = false;
        Frog::moveU = false;
        Frog::moveD = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
}

std::thread Game() {
    // mvwprintw(gameWindow, 1, 1, "%d", GameManager::cars.size());
    keypad(gameWindow, TRUE);
    box(gameWindow, 0, '=');
    std::thread logicThread(Input);
    while(Frog::lives > 0) {
        Logic();
    }
    return logicThread;
}

int main() {
    initscr();
    curs_set(0);
    keypad(gameWindow, TRUE);
    noecho();
    gameWindow = newwin(screenHeight,screenWidth,0,0);

    Setup();

    std::thread lThread = Game();

    endwin();

    lThread.join();
    return 0;
}