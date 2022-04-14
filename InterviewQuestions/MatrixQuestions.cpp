#include <iostream>
#include <vector>
#include <thread>
#include <map>
#include <utility>

// Replace river sizes with new one, bloated solution
std::vector<std::vector<int>> GetUnvisitedNeighbours(int i, int j, std::vector<std::vector<int>> &visited, std::vector<std::vector<int>> &river) {
    std::vector<std::vector<int>> neighbours{};
    // We want to avoid underflow and overflow
    if(i > 0 && !visited[i-1][j]) 
        neighbours.push_back({i-1, j});

    if(i < river.size() - 1 && !visited[i+1][j]) 
        neighbours.push_back({i+1, j});

    if(j > 0 && !visited[i][j-1])
        neighbours.push_back({i, j-1});

    if(j < river.size()-1 && !visited[i][j+1])
        neighbours.push_back({i, j+1});

    return neighbours;
}

void DFS(int i, int j, std::vector<std::vector<int>> &visisted, std::vector<std::vector<int>> &river, std::vector<int> &sizes) {
    int riverSize = 0;
    std::vector<std::vector<int>> stack{{i,j}};
    while(stack.size() != 0) {
        std::vector<int> currentNode = stack.back();
        stack.pop_back();
        i = currentNode[0];
        j = currentNode[1];
        if(visisted[i][j])
            continue;
        visisted[i][j] = true;
        if(river[i][j] == 0)
            continue;
        std::vector<std::vector<int>> unvisitedNeighbours = GetUnvisitedNeighbours(i,j,visisted,river);
        for(std::vector<int> neighbour : unvisitedNeighbours)
            stack.push_back(neighbour);
    }
    if(riverSize > 0)
        sizes.push_back(riverSize);
}   

std::vector<int> RiverSizes(std::vector<std::vector<int>> &river) {
    std::vector<int> riverSizes{};
    std::vector<std::vector<int>> isVisited(river.size(), std::vector<int>(river[0].size(), false));
    isVisited.resize(river.size());
    isVisited[0].resize(river[0].size());
    for(int i = 0; i < river.size(); i++) {
        for(int j = 0; j < river[i].size(); j++) {
            if(!isVisited[i][j]) {
                DFS(i, j, isVisited, river, riverSizes); // Check! Failing function call!!
            }
        }
    }
    return riverSizes;
}

// Search Sorted Matrix
std::pair<int,int> SearchSortedMatrix(std::vector<std::vector<int>> &matrix, int target) {
    // Because we know how the array is sorted we can apply a two pointer technique to narrow down to the answer
    std::pair<int,int> coords{-1,-1};
    int i = 0, j = matrix.size();
    while(i < j) {
        if(matrix[i][j] == target) {
            coords.first = i;
            coords.second = j;
            std::cout << i << " " << j << "\n";
            return coords;
        }
        else if(matrix[i][j] < target)
            i++;
        else
            j--;
    }
    return coords;
}

std::vector<int> SpiralTraversalSimple(std::vector<std::vector<int>> &mat) { // Replace with Depth first search!!!!!
    std::vector<int> traversal{};
    if(mat.size() * mat[0].size() == 0) //?
        return traversal;
    std::vector<std::vector<bool>> visited{};

    // Each for loop is a direction reaching the end of what can be added
    // Repeat until done with matrix
    // REPLACE WITH DFS | REMOVE BELOW
    int i = 0;
    int j = 0;
    while(visited.size() * visited[0].size() != mat.size() * mat[0].size()) {
        if(i != mat.size() && !visited[i][0])
            i++;
        if(j != mat[0].size() && !visited[0][j])
            i--;
        visited[i][j] = true;
        traversal.push_back(mat[i][j]);
    }
    for(auto i : traversal)
        std::cout << i << ", ";

    return traversal;
}

void SpiralTraversalOther(std::vector<std::vector<int>> & arr) {
    int totalAmountofElements = arr.size() * arr[0].size();
    int numTraversed = 0;
    std::pair<int,int> traverser{0,0};
    while (numTraversed < totalAmountofElements){
        traverser.first++;
        if(traverser.first == arr[0].size())
            traverser.second++;
        if(traverser.second == arr.size())
            traverser.first--;
    }
}

void LineTraversal(std::vector<std::vector<int>> & arr) {
    for(int i = 0; i < arr[0].size(); i++) {
        for(int j = 0; j < arr.size(); j++) {
            std::cout << arr[i][j];
        }
    }
}

// Matrix Blip
void Blip(std::vector<std::vector<int>> &arr, const int n) {
    for(unsigned int i = 0; i < arr.size(); i++) {
        for(unsigned int j = 0; j < arr[0].size(); j++) {
            if(arr[i][j] == n) {
                arr[i-1][j]++;
                arr[i+1][j]++;
                arr[i][j-1]++;
                arr[i][j+1]++;
            }
        }
    }
}

// Fix and Optimise!
void BlipOther(std::vector<std::vector<int>> &arr, const int n, const char direction) {
    for(unsigned int i = 0; i < arr.size(); i++) {
        for(unsigned int j = 0; j < arr[0].size(); j++) {
            if(arr[i][j] == n) {
                switch(direction) {
                    case 'l':  {
                        for(int left = j; left > 0; left--)
                            arr[i][left]++;
                        break;
                    }
                    case 'r':  {
                        for(int right = j; right < arr.size(); right++)
                            arr[i][right]++;
                        break;
                    }
                    case 'u':  {
                        for(int up = i; up > 0; up--)
                            arr[up][j]++;
                        break;
                    }
                    case 'd':  {
                        for(int down = i; down < arr.size(); down++)
                            arr[down][j]++;
                        break;
                    }
                }
            }
        }
    }
}

// Cross rotate
void CrossRotate(std::vector<std::vector<int>> &arr, const int n) {
    for(unsigned int i = 0; i < arr.size(); i++) {
        for(unsigned int j = 0; j < arr[0].size(); j++) {
            if(arr[i][j] == n) {
                int right = arr[i][j+1]; // Store right
                int left = arr[i][j-1]; // Store left
                arr[i][j+1] = arr[i-1][j]; // Right = up
                arr[i][j-1] = arr[i+1][j]; // Left = down
                arr[i+1][j] = right; // Down = right
                arr[i-1][j] = left; // Up = left
            }
        }
    }
}

void SquareRotate(std::vector<std::vector<int>> &arr, const int n) { // Add corner rotation!
    for(unsigned int i = 0; i < arr.size(); i++) {
        for(unsigned int j = 0; j < arr[0].size(); j++) {
            if(arr[i][j] == n) {
                while(1) {
                    int right = arr[i][j+1]; // Store right
                    int left = arr[i][j-1]; // Store left
                    arr[i][j+1] = arr[i-1][j]; // Right = up
                    arr[i][j-1] = arr[i+1][j]; // Left = down
                    arr[i+1][j] = right; // Down = right
                    arr[i-1][j] = left; // Up = left
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
            }
        }
    }
}

void Distribution(std::vector<std::vector<int>> & mat) {
    // Given a matrix, distribute values with large chunks of the same and pockets of different
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            int value = rand() % 1;
            if(value < 0.15)
                mat[i][j] = -2;
        }
    }
}

void DiagonalBlip(std::vector<std::vector<int>> & arr, const int target) {
    std::vector<std::pair<int,int>> directions{{1,1},{-1,-1},{1,-1},{-1,1}};
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr.size(); j++) {
            if(arr[i][j] == target) {
                for(std::pair<int,int> dir : directions) {
                    int newRow = i + dir.first;
                    int newCol = j + dir.second;
                    arr[newRow][newCol] += target;
                }
            }
        }
    }
}

void BridgeGenerator(std::vector<std::vector<char>> & arr, std::vector<std::vector<int>> & elevationMap) {
    int h = arr.size();
    int w = arr[0].size();
    auto boundsCheck = [&](const int x, const int y) {
        return 0 < x || x > w || 0 < y || y > h;
    };
    std::vector<std::pair<int,int>> directions{{0,1},{1,0},{-1,0},{0,-1}};
    for(unsigned int row = 0; row < arr.size(); row++) {
        for(unsigned int col = 0; col < arr[0].size(); col++) {
            for(std::pair<int,int> dir : directions) {
                int newRow = row + dir.first; 
                int newCol = col + dir.second;
                while(arr[newRow][newCol] != 'B') {
                    if(boundsCheck(newRow,newCol) && arr[newRow][newCol] != 'B') {
                    // Check until next available location, if any
                        int choice = rand() % 1;
                        if(choice > 0.75) {
                            if(elevationMap[newRow][newCol] == elevationMap[row][col])
                                arr[newRow][newCol] = '=';
                            else if(elevationMap[newRow][newCol] > elevationMap[row][col])
                                arr[newRow][newCol] = '^';
                            else
                                arr[newRow][newCol] = '-';
                        }
                        else {
                            std::cout << "NO GEN!\n";
                        }
                    }
                }
            }
        }
    }    
}

void PrintMatrix(std::vector<std::vector<int>> & arr) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr.size(); j++)
            std::cout << arr[i][j] << ',';
        putchar('\n');
    }
}

int main() {
    std::vector<std::vector<int>> matrix2{{1, 2, 3, 4, 5},
                                        {6, 7, 8, 9, 10},
                                        {11,12,13,14,15},
                                        {16,17,18,19,20},
                                        {21,22,23,24,25}};
    std::vector<std::vector<int>> 
    /*
    std::tuple<int,int> result = SearchSortedMatrix(matrix2, 19);

    std::vector<std::vector<int>> matrix{{1,0,0,1,0},
                                        {1,0,1,0,0},
                                        {0,0,1,0,1},
                                        {1,0,1,0,1},
                                        {1,0,1,1,0}};
    std::vector<int> sizes{}; // Check!
    sizes = RiverSizes(matrix); // Not assigning
    for(auto i : sizes)
        std::cout << i;
    SpiralTraversalSimple(matrix2);
    */

    PrintMatrix(matrix2);
    putchar('\n');
    DiagonalBlip(matrix2, 18);
    putchar('\n');
    PrintMatrix(matrix2);

    return 0;
}

    // Check for 1's
    // Search for adjacent (Horizontal or vetical only) 1's
    // Mark each 1 as being counted
    // Count river size
    // Push river size to array
    // Reset size before checking for another river
    // Repeat

    // Depth-First search
    // Think of this as a series of unconnected graphs
    // Run the search on each graph and return its size
