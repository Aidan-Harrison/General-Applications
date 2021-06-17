#include <iostream>
#include <list>
#include <iterator>

// Print function
void PrintList(std::list<int> &list) {
    putchar('\n');
    for(auto i : list)
        std::cout << i << ", ";
}

// Prints the middle most element of a list
void PrintMiddle(std::list<int> &list) {
    auto front = list.begin(); // Create iterator | Can write (std::list<int>::iterator)
    std::advance(front, list.size()/2);
    std::cout << *front;
}

void DeleteMiddle(std::list<int> &list) {
    auto front = list.begin();
    std::advance(front, list.size()/2);
    list.erase(front); // Takes previous node and changes next value
    for(std::list<int>::iterator it; it != list.end(); it++)
        std::cout << *it << ", ";
}

// Picks a node in the linked list and increments it by 1
void IncrementNode(int data, std::list<int> &list) {
    for(std::list<int>::iterator it; it != list.end(); it++) {
        if(*it == data)
            it++;
    }
}

int main() {
    std::list<int> testList({5,9,14,24,46,98,124});
    PrintMiddle(testList);
    // DeleteMiddle(testList);
    PrintList(testList);
    IncrementNode(46, testList);
    PrintList(testList);

    return 0;
}