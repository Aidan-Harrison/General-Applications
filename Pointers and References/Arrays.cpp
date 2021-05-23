#include <iostream>

int main() {
    int x[] = {1,2,3};

    // The following two are the same thing | Arrays default to the address of the first element
    int *head = x; // First element, do not need to specify reference
    int *head2 = &x[0]; // Must specify reference, directly accessing first element

    return 0;
}