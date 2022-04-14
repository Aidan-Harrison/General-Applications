#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <utility>

int screenWidth = 800, screenHeight = 600;

std::vector<std::vector<char>> canvasPrimer {
    {'W','W','W','W','R','R','R','R','R','W','W','W','W','W','W'},
    {'W','W','W','W','B','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','B','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','B','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','B','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','B','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','B','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
    {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'}
};

struct stack {
    int top = -1;
    std::pair<int,int> stack[100];
    inline const bool full() const { return top == 100 ? true : false; }
    inline const bool empty() const { return top == -1 ? true : false; }
    void push(std::pair<int,int> newP) {
        if(full())
            return;
        top++;
        stack[top] = newP;
    }
    std::pair<int,int> pop() {
        if(empty())
            return {-1,-1};
        std::pair<int,int> ret = stack[top];
        stack[top] = {-1,-1};
        top--;
        return ret;
    }
};

struct grid {
    int sizeX, sizeY;
    struct pixel {
        int x, y; // Pointless??
        sf::Color col = sf::Color::White; // Pointless?
        sf::RectangleShape pix;
        pixel() {}
        pixel(const int _x, const int _y)
        {
            pix.setSize(sf::Vector2f(25.0f,25.0f));
            pix.setOrigin(pix.getSize().x/2, pix.getSize().y/2);
            pix.setPosition(sf::Vector2f(_x, _y));
            pix.setFillColor(col);
        }
    };
    std::vector<std::vector<pixel>> canvas{};
    grid(const int x, const int y)
        :sizeX(x), sizeY(y)
    {
        canvas.resize(x);
        for(unsigned int i = 0; i < canvas.size(); i++)
            canvas[i].resize(y);
        float xOffset = 0.0, yOffset = 0.0;
        for(int i = 0; i < canvas.size(); i++) {
            for(int j = 0; j < canvas[0].size(); j++) {
                pixel newPixel(xOffset, yOffset);
                canvas[i][j] = newPixel;
                xOffset += 25.0f;
                if(xOffset >= screenWidth) {
                    yOffset += 25.0f;
                    xOffset = 0.0;
                }
            }
        }
    }
    // Primer constructor
    grid(std::vector<std::vector<char>> & primer)
    {
        float xOffset = 0.0, yOffset = 0.0;
        canvas.resize(primer.size());
        for(int i = 0; i < primer.size(); i++)
            canvas[i].resize(primer.size());
        for(int row = 0; row < canvas.size(); row++) {
            for(int col = 0; col < canvas[0].size(); col++) {
                if(xOffset >= screenWidth) {
                    yOffset += 25.0f;
                    xOffset = 0.0;
                }
                pixel newPixel(xOffset, yOffset);
                canvas[row][col] = newPixel;
                switch(primer[row][col]) {
                    case 'W': canvas[row][col].pix.setFillColor(sf::Color::White);  break;
                    case 'R': canvas[row][col].pix.setFillColor(sf::Color::Red);    break;
                    case 'G': canvas[row][col].pix.setFillColor(sf::Color::Green);  break;
                    case 'B': canvas[row][col].pix.setFillColor(sf::Color::Blue);   break;
                    case 'Y': canvas[row][col].pix.setFillColor(sf::Color::Yellow); break;
                }
                xOffset += 25.0f;
            }
        }
    }
};

void FillOther(std::vector<std::vector<char>> & canvas, const int x, const int y, const char fillCol) {
    int h = canvas.size();
    int w = canvas[0].size();
    auto boundsCheck = [&](const int _x, const int _y) {
        return 0 <= x && x <= w && 0 <= y && y <= h;
    };
    std::vector<std::pair<int,int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    std::vector<std::vector<bool>> visited{};
    visited.resize(canvas.size());
    for(int i = 0; i < visited.size(); i++)
        visited[i].resize(canvas[0].size());
    for(unsigned int row = 0; row < canvas.size(); row++) {
        for(unsigned int col = 0; col < canvas[0].size(); col++) {
            if(row == x && col == y && !visited[row][col]) {
                stack newStack;
                newStack.push({row,col});
                canvas[row][col] = fillCol;
                visited[row][col] = true;
                while(!newStack.empty()) {
                    std::pair<int,int> pos = newStack.pop();
                    for(std::pair<int,int> dir : directions) {
                        int newRow = pos.first + dir.first;
                        int newCol = pos.second + dir.second;
                        if(boundsCheck(newRow,newCol) && canvas[newRow][newCol] != fillCol && !visited[newRow][newCol]) {
                            newStack.push({newRow,newCol});
                            canvas[newRow][newCol] = fillCol;
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
        }
    }
}

void Fill(grid & g, const int x, const int y, sf::Color colour) {
    int w = g.canvas[0].size();
    int h = g.canvas.size();
    auto boundsCheck =[&](const int x, const int y) {
        return 0 < x && x <= w && 0 < y && y <= h;
    };
    std::vector<std::vector<bool>> visited{};
    visited.resize(g.canvas.size());
    for(int i = 0; i < g.canvas.size(); i++)
        visited[i].resize(g.canvas[0].size());
    std::vector<std::pair<int,int>> directions{{0,1}, {1,0},{0,-1},{-1,0}};
    for(unsigned int row = 0; row < g.canvas.size(); row++) {
        for(unsigned int col = 0; col < g.canvas[0].size(); col++) {
            if(row == x && col == y) {
                sf::Color selectedCol = g.canvas[row][col].col;
                stack newStack;
                newStack.push({row,col});
                visited[row][col] = true;
                g.canvas[row][col].pix.setFillColor(colour);
                while(!newStack.empty()) {
                    std::pair<int,int> newPos = newStack.pop();
                    for(std::pair<int,int> dir : directions) {
                        int newRow = newPos.first + dir.first;
                        int newCol = newPos.second + dir.second;
                        if(boundsCheck(newRow, newCol) && g.canvas[newRow][newCol].col == selectedCol && !visited[newRow][newCol]) {
                            newStack.push({newRow,newCol});
                            g.canvas[newRow][newCol].pix.setFillColor(colour);
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
        }
    }
}

void PrintRaw(std::vector<std::vector<char>> & canvas) {
    for(int i = 0; i < canvas.size(); i ++) {
        for(int j = 0; j < canvas[0].size(); j++)
           std::cout << canvas[i][j] << ','; 
        putchar('\n');
    }
}

int main(int argc, char const** argv) {
    grid newGrid(canvasPrimer);
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML window");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F) {
                FillOther(canvasPrimer, 12,12, 'G');
                // Fill(newGrid, 12,12, sf::Color::Green);
                PrintRaw(canvasPrimer);
            }
        }

        window.clear();
        for(unsigned int i = 0; i < newGrid.canvas.size(); i++)
            for(unsigned int j = 0; j < newGrid.canvas[0].size(); j++)
                window.draw(newGrid.canvas[i][j].pix);
        window.display();
    }
    return EXIT_SUCCESS;
}
