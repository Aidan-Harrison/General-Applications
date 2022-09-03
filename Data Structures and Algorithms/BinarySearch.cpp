// Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

int BinarySearchIterative(const std::vector<int> & arr, const int target) {
    if(arr.size() == 0)
        return -1;
    else {
        int left = 0, right = arr.size();
        while(left < right) {
            int mid = left + (right - left) / 2 - 1;
            if(arr[mid] == target) { return arr[mid]; }
            else if(arr[mid] < target) { left = mid + 1; }
            else { right = mid - 1; }
        }
    }
    return -1;
}

int BinarySearchRecursive(const std::vector<int> & arr, int left, int right, const int target) {
	if(arr.size() == 0 || right > arr.size() || left < 0)
		return -1;
	else {
		if(left < right) {
			int mid = left + (right - left) / 2 - 1;
			if(arr[mid] == target) return arr[mid];
			else if(arr[mid] < target) return BinarySearchRecursive(arr, left = mid + 1, right, target);
			else return BinarySearchRecursive(arr, left, right = mid - 1, target);
		}
	}
	return -1;
}

std::vector<int> CreateData() {
    std::vector<int> array{};
    for(int i = 0; i < 3000; i++)
        array.push_back(rand() % 3000);
    return array;
}

int main() {
    std::vector<int> array = CreateData();    

    std::cout << BinarySearchIterative(array, 975);
    putchar('\n');
    std::cout << BinarySearchRecursive(array, 0, array.size(), 2897);

    return 0;
}