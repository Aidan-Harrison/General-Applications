#include <iostream>
#include <vector>

// Check entire file, all producing different results!!

// Solution 1
int MaxSumSub(std::vector<int> &arr) {
    int currentSum = 0;
    int largestSum = 0;
    int i = arr.size() / 2 - 1;
    int j = arr.size() / 2;
    std::vector<int> existingValues{};
    while(i > 0 && j < arr.size()-1) {
        existingValues.push_back(arr[i]);
        existingValues.push_back(arr[j]);
        for(int k = 0; k < existingValues.size(); k++)
            currentSum += existingValues[k];
        if(currentSum > largestSum)
            largestSum = currentSum;
        i--;
        j++;
        currentSum = 0;
    }
    return largestSum;
}

// Solution 2
int MaxSumSub2(std::vector<int> &arr) {
    int currentSum = 0;
    int largestSum = 0;
    for(int i = 0; i < arr.size(); i++) {    
        for(int j = 0; j < arr.size(); j++) {
            currentSum += arr[j] + arr[j+1];
            if(currentSum > largestSum)
                largestSum = currentSum;
        }
    }
    return largestSum;
}

int KadanesAlgorithm(std::vector<int> &arr) {
    int largestSum = 0;
    int currentSum = 0;
    for(int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];
        if(currentSum > largestSum)
            largestSum = currentSum;
        if(currentSum < 0)
            currentSum = 0;
    }
    return largestSum;
}

int main() {
    std::vector<int> array{-2,-3,4,-1,-2,1,5,-3};
    std::cout << MaxSumSub(array) << '\n';
    std::cout << MaxSumSub2(array) << '\n';
    std::cout << KadanesAlgorithm(array) << '\n';

    return 0;
}