#include <iostream>
#include <vector>

// Change to recursive
T BinarySearch(std::vector<T> &arr, T target) {
    if(arr.size() == 0)
        return;
    int left = 0;
    int right = arr.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return arr[mid];
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int Factorial(int x) {
    if(x == 1)
        return 1;
    else
        return x * Factorial(x-1));
}

void SumOfNumbers(int n) {
    
}

int main() {

    return 0;
}