#include <iostream>
#include <vector>
#include <array>

void Print(std::vector<std::vector<int>> arr);
void Print(std::vector<int> & arr);
std::vector<std::vector<int>> CreateGrid(const int size);
std::vector<int> & CreateGrid(const int height, const int width);

// Segmentation and pattern algorithms
std::vector<std::vector<int>> CornerSegmentation(std::vector<std::vector<int>> && arr, int count = 4, int corner = 1) {
    int xBound = arr[0].size()-1, yBound = arr.size()-1;
    int lXBound = xBound+1, lYBound = yBound+1;
    switch (corner) {
        case 2: {
            xBound = arr[0].size()-1, yBound = 0;
            lYBound = 1;
            break;
        }
        case 3: {
            xBound = 0, yBound = arr.size()-1;
            lXBound = 1;
            break;
        }
        case 4: {
            xBound = 0, yBound = 0;
            lXBound = 1, lYBound = 1;
            break;
        }
    }
    for(int i = 0; i < count; i++) {
        for(int j = 0; j <= xBound; j++) {
            arr[j][xBound] = 1;
            arr[yBound][j] = 1;
        }
        // Multiply if starting from bottom
        xBound = lXBound/2;
        yBound = lYBound/2;
        lXBound = xBound;
        lYBound = yBound;
    }
    return arr;
}

// Snake segmentation
int PickDirection(std::array<bool, 4> & directions) {
    int value = rand() % 4;
    // 0) Left 1) Right 2) Up 3) Down
    while(!directions[value])
        value = rand() % 4;
    return value;
}

bool wallCheck(const int x, const int y, const int size) {
    return x < 0 || x > size || y < 0 || y > size;
};

// Optimise? Make recursive function and compress!
void Branch(int startX, int startY, std::vector<std::vector<int>> & arr, std::vector<std::vector<bool>> & visited, int & counter) {
    while(!wallCheck(startX, startY, arr.size())) {
        bool valid = false;
        std::array<bool, 4> directions{true,true,true,true};
        if(!wallCheck(startX-1, startY, arr.size()) && visited[startY][startX-1]) // Left
            directions[0] = false;
        if(!wallCheck(startX+1, startY, arr.size()) && visited[startY][startX+1]) // Right
            directions[1] = false;
        if(!wallCheck(startX, startY-1, arr.size()) && visited[startY-1][startX]) // Up
            directions[2] = false;
        if(!wallCheck(startX, startY+1, arr.size()) && visited[startY+1][startX]) // Down
            directions[3] = false;
        // randomly pick ONLY available spaces
        for(int i = 0; i < 4; i++) {
            if(directions[i]) { // Found at least one valid position, safe to move
                valid = true;
                break;
            }
        }
        arr[startY][startX] = 2;
        visited[startY][startX] = true;
        switch(PickDirection(directions)) {
            case 0: 
                startX--;
                break;
            case 1:
                startY--;
                break;
            case 2:
                startX++;
                break;
            case 3:
                startY++;
                break;
        }
        counter++;
    }
}

std::vector<std::vector<int>> SnakeSegment(std::vector<std::vector<int>> && arr) {
    int sX = rand() % arr[0].size(), sY = rand() % arr.size();
    int startX = sX, startY = sY;
    std::vector<std::vector<bool>> visited{};
    visited.resize(arr.size());
    for(int i = 0; i < visited.size(); i++) {
        std::vector<bool> newRow(visited.size(), false);
        visited[i] = newRow;
    }
    int counter = 1;
    std::array<bool, 4> directions = {true,true,true,true};
    bool valid = false;
    while(!wallCheck(sX, sY, arr.size())) {
        // Safety check | Prevents overlap
        if(!wallCheck(sX-1, sY, arr.size()) && visited[sY][sX-1]) // Left
            directions[0] = false;
        if(!wallCheck(sX+1, sY, arr.size()) && visited[sY][sX+1]) // Right
            directions[1] = false;
        if(!wallCheck(sX, sY-1, arr.size()) && visited[sY-1][sX]) // Up
            directions[2] = false;
        if(!wallCheck(sX, sY+1, arr.size()) && visited[sY+1][sX]) // Down
            directions[3] = false;
        // randomly pick ONLY available spaces
        for(int i = 0; i < 4; i++) {
            if(directions[i]) { // Found at least one valid position, safe to move
                valid = true;
                break;
            }
        }
        if(!valid || counter > 8) { // Recursive???
            int stopChance = rand() % 2;
            if(stopChance)
                Branch(sX,sY,arr,visited, counter);
            else
                return arr; // Finished
        }
        arr[sY][sX] = 1;
        visited[sY][sX] = true;
        switch(PickDirection(directions)) {
            case 0: 
                sX--;
                break;
            case 1:
                sY--;
                break;
            case 2:
                sX++;
                break;
            case 3:
                sY++;
                break;
        }
        counter++;
    }
    return arr;
}


// Bar segmentation
std::vector<int> randomBar(const int width) {
    std::vector<int> result{};
    for(int i = 0; i < width; i++) {
        int doesPush = rand() % 2;
        if(doesPush)
            result.push_back(i);
    }
    if(result.size() == 0)
        result.push_back(width/2);
    return result;
}

std::vector<int> & BarSegment(std::vector<int> & grid, int count = 1, int dir = 0) {
    int height = grid[grid.size()-2], width = grid[grid.size()-1];
    std::vector<int> barPositions = randomBar(width);
    for(int k = 0; k < count; k++) {
        int curPos = barPositions[rand() % barPositions.size()];
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                switch(dir){
                    case 0: grid[i+barPositions[curPos]*width] = 1; break;
                    case 1: grid[barPositions[curPos]+j*width] = 1; break;
                    case 2: {
                        grid[i+barPositions[curPos]*width] = 1;
                        grid[barPositions[curPos]+j*width] = 1;
                        break;
                    }
                }
            }
        }
    }
    return grid;
}

// Brick segmentation
    // Pixels, matrix width, matrix height, start X, start Y, rect sizeX, rect size Y
void FillQuadrant(std::vector<int> & arr, size_t aW, size_t aH, size_t sX, size_t sY, size_t rW, size_t rH) {
    for(int i = sY; i < sY+rH; i++) {
        for(int j = sX; j < sX+rW; j++) {
            arr[i+j*aW] = 1;
        }
    }
}

std::vector<int> & BrickSegmentation(std::vector<int> & arr) {
    /*
        1,1,2,2,3,3
        1,1,2,2,3,3
        4,4,5,5,6,6
        4,4,5,5,6,6
    */

    // Rewrite
    int height = arr[arr.size()-2], width = arr[arr.size()-1];
    bool newRow = false;
    for(int i = 0; i < height*width; i+=2) {
        if(width % i == 0) { // Start of new row, flip and jump
            if(!newRow)
                newRow = true;
        }
        if(newRow) {
            i+=width;
            newRow = false;
        }
        if(i % 2 == 0) {
            FillQuadrant(arr, width, height, i, i, 2, 2);
        }
    }

    /*
        std::vector<int> brickLocations{};
        // Calculate locations (top-left of bricks)
        int position = 0;
        int wCounter = 0;
        int value = 1;
        for(int i = 0; i < width; i++) { // Get correct amount calc?
            brickLocations.push_back(position);
            arr[position] = value;
            // arr[position+1*width] = value;
        
            position += 2;
            wCounter += 2;
            // Assign bricks
            //arr[position*width] = value;
            //arr[position*width+1] = value;
            if(wCounter >= width) {
                wCounter = 0;
                position *= 2;
            }
            value++;
        }
        for(int i = 0; i < brickLocations.size(); i++) {

        }
    */
    return arr;
}

int main() {
    srand(time(0));
    // Print(CornerSegmentation(CreateGrid(12)));
    // Print(SnakeSegment(CreateGrid(12)));
    // Print(BarSegment(CreateGrid(6, 6), 4, 2));
    Print(BrickSegmentation(CreateGrid(4, 6)));

    return 0;
}

std::vector<std::vector<int>> CreateGrid(const int size) {
    std::vector<std::vector<int>> result{};
    result.resize(size);
    for(int i = 0; i < size; i++) {
        std::vector<int> newRow(size, 0);
        result[i] = newRow;
    }
    return result;
}

std::vector<int> & CreateGrid(const int height, const int width) {
    static std::vector<int> result(width*height, 0); // Change
    result.push_back(height);
    result.push_back(width);
    return result;
}

void Print(std::vector<std::vector<int>> arr) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            std::cout << arr[i][j] << ' ';
        }
        putchar('\n');
    }
}

void Print(std::vector<int> & arr) {
    for(int i = 0; i < arr[arr.size()-2]; i++) {
        for(int j = 0; j < arr[arr.size()-1]; j++) 
            printf("%d,", arr[i+j*arr[arr.size()-1]]);
        putchar('\n');
    }


}