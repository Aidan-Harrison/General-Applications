// Project Euler C/C++
#include <iostream>

// Smallest Multiple
/*
    2520 is the smallest number that can be divided by each of
    the numbers from 1 to 10 without any remainder.

    What is the smallest positiv number that is evenly divisible
    by all of the numbers from 1 to 20?
*/
void SmallestMultiple() {
    float value = 2520;
    float result = 0;
    int correct = 0;
    while(correct != 10) {
        value++;
        for(int i = 0; i < 10; i++) {
            result = value / i;
            if(result / 1 == 0) {
                correct++;
            }
            else {
                correct = 0;
            }
        }
    }
    std::cout << "Found: " << value << '\n';
}

int main() {
    SmallestMultiple();

    std::cin.get();
    return 0;
}