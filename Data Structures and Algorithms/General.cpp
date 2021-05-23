#include <iostream>
#include <vector>

void ReverseStringSimple(const std::string &str) {
    for(int i = str.length(); i >= 0; i--) {
        std::cout << str[i];
    }
}

void ReverseStringRecursive(const std::string &str, int n) {
    
}

void RiverFinder(std::vector<std::vector<int>> &matrix) {
    // Search through matrix (Nested for loop)
    // Check for 1's
    // Check for all other ones horizontally or vertically (DFS)
    // Store river
    // Store already visited 1's
}

template<typename T>
void FindDuplicates(std::vector<T> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
               
        }
    }
}

int main() {
    ReverseStringSimple("Hello");

    return 0;
}