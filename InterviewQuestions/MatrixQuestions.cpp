#include <iostream>
#include <vector>
#include <map>

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
std::tuple<int,int> SearchSortedMatrix(std::vector<std::vector<int>> &matrix, int target) {
    // Because we know how the array is sorted we can apply a two pointer technique to narrow down to the answer
    std::tuple<int,int> coords{};
    int i = 0, j = matrix.size();
    while(i < j) {
        if(matrix[i][j] == target) {
            std::get<0>(coords) = i;
            std::get<1>(coords) = j;
            std::cout << i << " " << j << "\n";
            return coords;
        }
        else if(matrix[i][j] < target)
            i++;
        else
            j--;
    }
    std::get<0>(coords) = -1;
    std::get<1>(coords) = -1;
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

int main() {
    std::vector<std::vector<int>> matrix2{{1, 2, 3, 4, 5},
                                          {6, 7, 8, 9, 10},
                                          {11,12,13,14,15},
                                          {16,17,18,19,20},
                                          {21,22,23,24,25}};
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
    */

   SpiralTraversalSimple(matrix2);

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