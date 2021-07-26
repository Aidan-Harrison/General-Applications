#include <iostream>
#include <list>
#include <iterator>
#include <string>

// Print function
void PrintList(const std::list<int> &list) {
    for(auto i : list)
        std::cout << i << ", ";
}

// Problems:
// Prints the middle most element of a list
void PrintMiddle(const std::list<int> &list) {
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

// Picks a node in the list and increments its value by 1
void IncrementNode(int data, std::list<int> &list) {
    for(std::list<int>::iterator it; it != list.end(); it++) {
        if(*it == data)
            it++;
    }
}

int SumOfList(const std::list<int> &l1, const std::list<int> &l2) {
    std::string firstNum = "";
    std::string secondNum = "";
    for(std::list<int>::iterator it; it != l1.end(); it++) firstNum.append(std::to_string(*it));
    for(std::list<int>::iterator it; it != l2.end(); it++) secondNum.append(std::to_string(*it));
    return std::stoi(firstNum) + std::stoi(secondNum);
}

int main() {
    std::list<int> testList({5,9,14,24,46,98,124});
    std::list<int> t2{{1,2,3,4,5,6,7,8,9}};

    std::cout << SumOfList(testList, t2);

    putchar('\n');

    PrintMiddle(testList);
    DeleteMiddle(testList);
    PrintList(testList);
    IncrementNode(46, testList);
    PrintList(testList);

    return 0;
}