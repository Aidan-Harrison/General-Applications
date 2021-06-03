#include <iostream>
#include <vector>
#include <string>
#include <tuple>

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

// Linked-List Sum:
struct LinkedNode {
    int data;
    LinkedNode *next;
    LinkedNode() :data(0), next(nullptr) {}
    LinkedNode(int val) :data(val), next(nullptr) {}
    LinkedNode(int val, LinkedNode *n) :data(val), next(n) {}
};

LinkedNode* LinkedSum(LinkedNode *l1, LinkedNode *l2) {
    LinkedNode *sum = new LinkedNode();
    // Overly complicated
    /*
        int fVal = 0, sVal = 0;
        std::string fValStr = "", sValStr = "";
        while(l1->next != nullptr) {
            fValStr.append(std::to_string(l1->data));
            l1 = l1->next;
        }
        while(l2->next != nullptr) {
            sValStr.append(std::to_string(l2->data));
            l2 = l2->next;
        }
        fVal = std::stoi(fValStr);
        sVal = std::stoi(sValStr);
    */

    while(l1 != nullptr) { // Only works assuming the lists are of the same size | Fix!
        sum->data = l1->data + l2->data;
        l1 = l1->next;
        l2 = l2->next;
    }
    // Do return!
    return sum;
}

// Valid Sudoku
bool IsValid(std::vector<std::vector<char>> &board) { // Try to do in single function | 3-4 deep loop is not good!! | Recursion??
    char value = ' ';
    std::tuple<short, short> curPos(0,0);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '0') {
                std::get<0>(curPos) = i;
                std::get<1>(curPos) = j;
                value = board[i][j];
                // Break out to checks!
            }
        }
    }
    // Horizontal
    for(int i = 0; i < 9; i++)
        if(board[std::get<0>(curPos)][i] == value)
            return false;
    // Vertical
    for(int i = 0; i < 9; i++)
        if(board[i][std::get<1>(curPos)] == value)
            return false;
    // Sub-box
    short boxX = std::get<0>(curPos) /= 3;
    short boxY = std::get<1>(curPos) /= 3;
    for(int i = boxY * 3; i < boxY * 3 + 3; i++) {
        for(int j = boxX * 3; j < boxX * 3 + 3; j++) {
            if(board[boxY][boxX] == value && i != std::get<0>(curPos) && j != std::get<1>(curPos))
                return false;
        }
    }
}

int main() {
    ReverseStringSimple("Hello");

    // Linked List Sum
    LinkedNode *f1 = new LinkedNode(2);
    LinkedNode *f2 = new LinkedNode(4);
    LinkedNode *f3 = new LinkedNode(3);

    f1->next = f2;
    f2->next = f3;

    LinkedNode *s1 = new LinkedNode(1);
    LinkedNode *s2 = new LinkedNode(5);
    LinkedNode *s3 = new LinkedNode(3);

    s1->next = s2;
    s2->next = s3;

    LinkedSum(f1, s1);



    return 0;
}