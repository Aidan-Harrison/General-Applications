// Sorting Algorithms
#include <iostream>
#include <vector>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort:
std::vector<int> BubbleSort(std::vector<int> &arr) {
    if(arr.size() == 0) return arr; // Invalid
    else {
        for(unsigned int i = 0; i < arr.size(); i++) {
            for(unsigned int j = 0; j < arr.size(); j++) {
                if(arr[j] > arr[j+1])
                    Swap(&arr[j], &arr[j+1]);
            }
        }
    }
    for(unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ", ";
    return arr;
}

// Quick Sort:


int main() {
    std::vector<int> array{5,3,2,1,4,6,9,7,8};
    BubbleSort(array);
    return 0;
}