// Binary Search
#include <iostream>
#include <vector>
#include <algorithm>

// Iterative
int BinarySearchIterative(std::vector<int> &arr, const int target) {
    if(arr.size() == 0) // Edge case
        return -1;
    else {
        std::sort(arr.begin(), arr.end());
        int left = 0, right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) { return mid; }
            else if(arr[mid] < target) { left = mid + 1; }
            else { right = mid - 1; }
        }
    }
    return -1; // Failed
}

// Recursive
int BinarySearchRecursive(std::vector<int> &arr, int left, int right, int target) {
	if(arr.size() == 0)
		return -1;
	else {
		if(left < right) { // While?
			int mid = left + (right - left) / 2;
			if(arr[mid] == target) return arr[mid];
			else if(arr[mid] < target) return BinarySearchRecursive(arr, left = mid + 1, right, target);
			else return BinarySearchRecursive(arr, left, right = mid - 1, target);
		}
	}
	return -1;
}

int main() {
    return 0;
}