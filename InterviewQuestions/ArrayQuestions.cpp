#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <map>

// Find missing number n - n assuming order of 1,2,3,4,5,etc...
int FindMissing(std::vector<int> &arr) {
	if(arr.size() == 0)
		return -1;
	else {
		std::sort(arr.begin(), arr.end());
		int difference = 0;
		for(unsigned int i = 0; i < arr.size(); i++) {
			// Check difference, if greater then 1, missing
			for(unsigned int j = 0; j < arr.size(); j++) {
				difference = arr[j] - arr[j++];
				if(difference > 1)
					return arr[j++];
				difference = 0;
			}
		}
	}	
	return -1; // Failed
}

int FindDuplicateOfTarget(int target, std::vector<int> &arr) {
	if(arr.size() == 0)
		return false;
	else {
		std::sort(arr.begin(), arr.end());
		for(int i = 0; i < arr.size(); i++) {
			if(arr[i] == target)
				if(arr[i++] == target)
					return true;	
		}
	}
	return false;
}

// Given an unsorted array, find the largest and smallest numbers, (THE ARRAY IS NOT ALLOWED TO BE SORTED) | Sort then return first & last otherwise
// Iterative version: Base algorithm, compare values to one another until the largest and smallest are found
std::tuple<int,int> LargestSmallestUnsorted(std::vector<int> &arr) {
	if(arr.size() <= 1) {
		std::tuple<int,int> failedArr(-1,-1);
		return failedArr;
	}
	else {
		std::tuple<int,int> values;
		std::vector<int> copy = arr; // We need a copy else the 'smallest' calculation will be working on an altered array
		int largest = 0, smallest = 0;
		for(int i = 0; i < copy.size(); i++) {
			for(int j = 0; j < copy.size(); j++) {
				if(copy[j] > copy[i]) {
					largest = copy[j];
					copy[i] = largest; // Compare against new value
				}
			}
		}
		for(int i = 0; i < arr.size(); i++) {
			for(int j = 0; j < arr.size(); j++) {
				if(arr[j] < arr[i]) {
					smallest = arr[j];
					arr[i] = smallest;
				}
			}
		}
		std::get<0>(values) = largest;
		std::get<1>(values) = smallest;
		return values;
	}
	std::tuple<int,int> failedArr(-1,-1);
	return failedArr;
}

// Effcient Version: (Map). Given that we cannot do any sorting, we can use an unordered map to quickly search for the largest and smallest
void LargestSmallestUnsortedFast(std::vector<int> &arr) {
	if(arr.size() <= 1)
		return;
	else {
		std::unordered_map<char, int> m;
		std::max_element(m.begin(), m.end()); // Lambda?
	}
}

// Shifts all the negative values of an array to one side, then sort positive and negative sides | Fix!
std::vector<int> ShiftNegative(std::vector<int> &arr) {
	if(arr.size() == 0)
		return arr;
	else {
		int amountShifted = 0;
		for(int i = 0; i < arr.size(); i++) {
			if(arr[i] < 0) {
				arr.push_back(arr[i]);
				arr.erase(arr.begin()+i);
				amountShifted++;
			}
		}
		std::sort(arr.begin(), arr.end() - amountShifted); // Sort positives
		std::sort(arr.begin() + amountShifted, arr.end());
	}
	return arr;
}

// Find all elements that appear more then or equal to n times
std::vector<int> CommonElements(int times, std::vector<int> &arr) {
	if(arr.size() == 0)
		return arr;
	else {
		std::vector<int> count{};
		std::map<char,int> map; // Unordered?
		for(int i = 0; i < arr.size(); i++) {
			if(map.find(arr[i]) != map.end())
				map[arr[i]]++;
		}
		for(std::map<char,int>::iterator it; it != map.end(); it++)
			if(it->second >= times)
				count.push_back(it->second);
		return count;
	}
	return arr; 
}

// Converts a regular array into a circular one | Do!
std::vector<int> CyclicArray(int element, std::vector<int> &arr, int size) {
	if(arr.size() == 0)
		return arr;
	else {
		arr.push_back(element); // Check! overwrite
		if(arr.size() == size) {
			arr.resize(size);
			arr[0] = element;
		}
	}
	return arr;
}

// Assuming their are two non-empty arrays, check if one array is a sub-array of the other, in relative order
bool ValidSubSequence(std::vector<int> &arr1, std::vector<int> &arr2) {
	int check = 0;
	for(unsigned int i = 0; i < arr2.size(); i++) {
		if(arr1[check] == arr2[i])
			check++;
		if(check == arr1.size())
			return true;
	}
	return false;
}

// Same as previous but order is not relevant
bool ValidSubSequenceNonRelative(std::vector<int> &arr1, std::vector<int> &arr2) {
	int correct = 0;
	std::map<int,int> m;
	for(auto i : arr1)
		m[i]++;
	for(auto i : arr2) {
		if(m.count(i) == 1) // We don't want to be counting duplicates
			correct++;
		if(correct = arr1.size())
			return true;
	}
	return false;
}

// Given an array, sorted in increasing order, return an array of the squares of ecah number, sorted in increasing order
std::vector<int> SortedSquaredArray(std::vector<int> &arr) {
	if(arr.size() == 0)
		return arr;
	else {
		std::vector<int> newArr;
		for(auto i : arr) {
			newArr.push_back(i * i);
		}
		std::sort(newArr.begin(), newArr.end());
		return newArr;
	}
	return arr;
}

// Move the first element to the end | Do a one liner!
void MoveElementToEnd(std::vector<int> &arr) {
	arr.push_back(arr[0]);
	arr.erase(arr.begin());
}

bool MonotonicArray(std::vector<int> &arr) { // Check! Not working as intended
	bool increasing = true, decreasing = true;
	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] > arr[i++])
			increasing = false;
		if(arr[i] < arr[i++])
			decreasing = false;
	}
	if(increasing && decreasing) return false; // Both can't be true
	return true; // Has to be increasing or decreasing otherwise
}

// Find exactly 3 numbers in an array whose sum is equal to the target
bool ThreeNumberSumIter(std::vector<int> &arr, int sum) { // Iterative approach using pointers
	std::sort(arr.begin(), arr.end());
	for(int i = 0; i < arr.size(); i++) {
		int left = i + 1;
		int right = arr.size()-1;
		while(left < right) {
			if(arr[i] + arr[left] + arr[right] == sum) {
				std::cout << arr[i] << arr[left] << arr[right] << '\n';
				return true;
			}
			else if (arr[i] + arr[left] + arr[right] < sum)
				left++;
			else
				right--;
		}
	}
	return false;
}

bool ThreeNumberSumMap(std::vector<int> &arr, int sum) { // Come back to this
	std::map<int, int> m;
	for(auto i : arr)
		m[i]++;
	for(int i = 0; i < arr.size(); i++) {
		// Same as before but using a map instead of a while loop
		int left = i + 1;
		int right = arr.size()-1;
		if(sum - m[i] == sum) // Check!
			return true;
	}
	return false;
}

// Does not take into account flat peaks
int LongestPeakNonStrict(std::vector<int> &arr) { // Check, seems totally fine, can't figure out the issue
	if(arr.size() < 3) // Mountain sub-arrays can only exist in sizes >= 3
		return -1;
	else {
		int length = 0, longest = 0;
		bool incrementing = true;
		for(int i = 0; i < arr.size(); i++) {
			std::cout << incrementing;
			if(arr[i] < arr[i++]) {
				length++;
				incrementing = true;
			}
			else if(arr[i] > arr[i++]) {
				length++;
				incrementing = false;
			}
			if(arr[i] < arr[i++] && !incrementing) { // New mountain
				if(length > longest)
					longest = length;
				length = 0;
			}
		}
		return longest;
	}
	return -1;
}

int BinarySearch(std::vector<int> &arr, const int target) {
	if(arr.size() == 0)
		return -1;
	else {
		std::sort(arr.begin(), arr.end());
		int left = 0;
		int right = arr.size()-1;
		while(left < right) {
			int mid = left + (right - left) / 2;
			if(arr[mid] == target) return arr[mid];
			else if(arr[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
	}
	return -1;
}

// Set left and right
int BinarySearchRecursive(std::vector<int> &arr, const int target, int left, int right) {
	if(arr.size() == 0)
		return -1;
	else {
		if(left < right) {
			int mid = left + (right - left) / 2;
			if(arr[mid] == target) return arr[mid];
			else if(arr[mid] < target) BinarySearchRecursive(arr, target, left = mid + 1, right);
			else BinarySearchRecursive(arr, target, left, right = mid - 1);
		}
	}
	return -1;
}

int main() {
	std::vector<int> data{1,-2,15,-67,-8,-3,45,90,123,-4,14};
	ShiftNegative(data);
	for(auto i : data)
		std::cout << i << ", ";

	putchar('\n');

	std::vector<int> data2{-2, 1, 4, 8, 11};
	std::vector<int> sArray = SortedSquaredArray(data2);
	for(auto i : sArray)
		std::cout << i << ", ";

	putchar('\n');

	std::vector<int> data3{1,2,3,4,5,6,7,7};
	std::cout << MonotonicArray(data3);

	putchar('\n');

	std::vector<int> data4{12,3,4,1,6,9}; // CHANGE
	std::cout << ThreeNumberSumIter(data4, 24);

	putchar('\n');

	std::vector<int> peakData{1,3,1,2,3,5,6,7,9,12,8,7,2,1};
	std::cout << LongestPeakNonStrict(peakData);

	return 0;
}