// Multi-threaded program
#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

short evenValues = 0;
short oddValues = 0;

std::atomic<int> x(0);

void EvenAccumulate(int array[], int size) {
    for(int i = 0; i < size; i++)
        if(array[i] % 2 == 0)
            evenValues++;
}

void OddAccumulate(int array[], int size) {
    for(int i = 0; i < size; i++)
        if(array[i] % 2 != 0)
            oddValues++;
}

void AtomicSum() { // Always gets the correct value
    std::vector<short> numbers{};
    for(short i = 0; i <= 20000; i++) {
        numbers.push_back(rand());
        x += numbers[i];
    }
}

int main() {
    int numbers[10] {2,6,5,9,3,3,1,7,4,2};
    std::thread t1(EvenAccumulate, numbers, 10);
    std::thread t2(OddAccumulate, numbers, 10);
    t1.join();
    t2.join();
    std::cout << "Even: " << evenValues 
              << "\nOdd: " << oddValues << '\n';

    std::thread t3(AtomicSum);
    t3.join();
    std::cout << "The sum is: " << x;

    return 0;
}