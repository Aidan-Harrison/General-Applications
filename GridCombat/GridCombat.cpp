#include <iostream>
#include <array>
#include <utility>
#include <stack>
// Grid Combat

// Do BFS or DFS UNIT_RANGE away from unit!!!

std::array<std::array<int,20>, 20> grid{};

struct Unit {
    int range = 3;
    int team = 0;
    int x = 0, y = 0;
};

struct Stack {
    int top = 0;
    std::array<Unit*, 10> stack;

    inline bool IsFull() const {
        return top == stack.size();
    }
    inline bool IsEmpty() const {
        return top == 0;
    }
    void Push(Unit * u) {
        if(IsFull())
            return;
        else {
            top++;
            stack[top] = u;
        }
    }
    Unit* Pop() {
        if(isEmpty())
            return null;
        else {
            Unit * unit = stack[top];
            stack[top] = null;
            top--;
            return unit;
        }
    }

    inline Unit* Top() {
        return stack[top];
    }
};

void Display() {
    for(unsigned int row = 0; row < grid.size(); row++) {
        for(unsigned int col = 0; col < grid[0].size(); col++)
            std::cout << grid[row][col] << ',';
        putchar('\n');
    }
}

Unit* Combat(Unit &u) {
    int w = grid[0].size(), h = grid.size();
    auto inside=[&](const int x, const int y) {
        return 0 <= x && x <= w && 0 <= y && y <= h;
    };
    std::vector<std::pair<int,int>> directions{{0,u.range},{u.range,0},{u.range,u.range}};
    std::vector<std::vector<bool>> visited{};
    visited.resize(grid.size());
    for(int i = 0; i < grid.size(); i++)
        visited[i].resize(grid[0].size());
    for(unsigned int row = 0; row < grid.size(); row++) {
        for(unsigned int col = 0; col < grid[0].size(); col++) {
            if(row == unit.x && col == unit.y) {
                std::stack<std::pair<int,int>> stack;
                stack.push({row,col});
                while(!stack.empty()) {
                    std::pair<int,int> pos = stack.top();
                    s.pop();
                    for(std::pair<int,int> dir : directions) {
                        int new_row = row + dir.first;
                        int new_col = col + dir.second;
                        if(inside(new_row, new_col) && !visited[new_row][new_col]) 
                            return; // Check for any other enemy unit
                    }
                }
            }
        }
    }
    return u;
}

void Game() {
    Stack newStack;
    Display();
    while(!newStack.IsEmpty())
        Stack.Push(Combat(newStack.Pop()));
}

int main() {
    Unit testUnit;
    Combat(testUnit); // Remove once tested
    Game();

    return 0;
}