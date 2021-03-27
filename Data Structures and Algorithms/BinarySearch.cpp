// Binary Search
#include <iostream>
#include <vector>
#include <algorithm>

// Rudamentary
int BinarySearch(const std::vector<int> &arr, const int target) {
    if(arr.size() == 0) // Edge case
        return -1;
    else {
        std::sort(arr.begin(), arr.end());
        int left = 0, right = arr.size()-1;
        int mid = left + (right - left) / 2;
        while(left <= right) {
            if(arr[mid] == target) { return mid; }
            else if(arr[mid] > target) { left = mid + 1; }
            else { right = mid - 1; }
        }
    }
    return -1; // Failed
}

// Recursive
int BinarySearchRecursive(const std::vector<int> &arr, const int target) {
    if(arr.size() == 0) 
        return -1;
    else {
        return 0;
    }
    return 0;
}

int main() {
    return 0;
}