// Types of returning
#include <iostream>
#include <vector>

int ValueReturn(int value) {
    return value += 5;
}

int* AddressReturn(int value) { // Fix | Incorrect usage | Also fix for babbage
    value += 5;
    return &value;
}

int& ReferenceReturn(std::vector<int> &array) {
    return array[2];
}

int main() {
    std::vector<int> testArray = {1,2,3,4,5};

    ValueReturn(12);
    AddressReturn(15);
    ReferenceReturn(testArray);

    return 0;
}