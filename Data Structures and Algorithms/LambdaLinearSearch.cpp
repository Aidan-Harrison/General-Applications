// Lambda Linear Search
#include <iostream>
#include <vector>
#include <functional>

int LinearSearch(int arr[], const int size, const int target, const std::function<void(int)> &func) {
    for(unsigned int i = 0; i < size; i ++) {
        if(arr[i] == target)
            func(arr[i]);
    }
}

int PureLambda(std::vector<int> &arr, int target, const std::function<int(std::vector<int>,int)> &searchFunc, const std::function<void(int)> &printFunc) {
    printFunc(target);
    searchFunc(arr, target);
}

int main() {
    std::vector<int> vec{1,2,3,4,5,6,7,8,9};
    int array[5] = {1,2,3,4,5};
    auto lambdaSearch = [](std::vector<int> arr, int target) { for(int i : arr) if(i == target) return target; }; // Check capture!
    auto lambdaPrint = [](int value) { std::cout << "Target: " << value << '\n'; };

    // Single lambda
    LinearSearch(array, 5, 3, lambdaPrint);

    // Double Lambda
    PureLambda(vec, 6, lambdaSearch, lambdaPrint);

    return 0;
}