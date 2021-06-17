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

// Shifts all the negative values of an array to one side, then sort (<< DO THIS!) | Fix, ignoring one of the values
std::vector<int> ShiftNegative(std::vector<int> &arr) {
	if(arr.size() == 0)
		return arr;
	else {
		for(int i = 0; i < arr.size(); i++) {
			if(arr[i] < 0) {
				arr.push_back(arr[i]);
				arr.erase(arr.begin()+i);
			}
		}
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
			// map[arr[i]]++; // Add elements to map
			if(map.find(arr[i]) != map.end())
				map[arr[i]]++;
		}
		// Could do in place by clearing array and re-purposing
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



int main() {


	return 0;
}