// Pointer assignment and references
#include <iostream>

int main() {
    int a{0}, b{0};
    
    std::cout << "Enter the value of 'a': "; std::cin >> a;
    std::cout << "Enter the value of 'b': "; std::cin >> b;

    int* ptrA = &a;
    int* ptrB = &b;

    std::cout << "ptrA has a value of " << *ptrA << " with an address of " << &ptrA << '\n';
    std::cout << "ptrB has a value of " << *ptrB << " with an address of " << &ptrB;

    return 0;
}