#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <map>
#include <set>

void AllPossiblePairs(std::vector<int> &arr) {
    for(unsigned int i = 0; i < arr.size(); i++)
        for(unsigned int j = 0; j < arr.size(); j++)
            std::cout << arr[i] << ", " << arr[j] << "   ";
}

// Find missing number n - n assuming order of 1,2,3,4,5,etc...
int FindMissing(std::vector<int> &arr) {
	if(arr.size() == 0)
		return -1;
	else {
        int difference = 0;
        for(unsigned int i = 2; i < arr.size()-1; i++) {
            int fVal = arr[i];
            int sVal = arr[i+1];
            if(fVal > sVal) {
                difference = fVal - sVal;
                if(difference > 1)
                    return fVal-1;
            }
            difference = sVal - fVal;
            if(difference > 1)
                return sVal-1;
        }
	}	
	return -1;
}

bool FindDuplicateOfTarget(std::vector<int> &arr, const int target) {
	if(arr.size() == 0)
		return false;
	else {
		std::sort(arr.begin(), arr.end());
		for(int i = 0; i < arr.size()-1; i++) {
			if(arr[i] == target && arr[i++] == target)
				return true;
		}
	}
	return false;
}

bool FindDuplicateOfTargetMap(std::vector<int> &arr, const int target) { 
    if(arr.size() == 0)
        return false;
    else {
        std::unordered_map<int,int> map;
        for(int i = 0; i < arr.size(); i++)
            map.insert(std::pair<int,int>(i, arr[i]));
        for(auto i : arr)
            if(i == target)
                if(map.count(i) > 1) 
                    return true;
    }
    return false;
}

std::vector<int> FindAllDuplicatesNaive(std::vector<int> &arr) {
    if(arr.size() <= 1)
        return arr;
    else {
        std::vector<int> duplicates{};
        for(unsigned int i = 0; i < arr.size(); i++) {
            for(unsigned int j = 0; j < arr.size()-1; j++) {
                if(arr[j] > arr[j+1])
                    duplicates.push_back(arr[j]);
            }
        }
    }
    return arr;
}

// Find all values which have duplicate members
std::vector<int> FindAllDuplicates(std::vector<int> &arr) {
    if(arr.size() <= 1)
        return arr;
    else {
        std::vector<int> duplicates{};
        std::unordered_map<int,int> map;
        for(auto i : arr)
            map[i]++;
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second > 1)
                duplicates.push_back(it->first);
        }
        return duplicates;
    }
    return arr;
}

void RemoveElement(std::vector<int> &arr, const int target) {
    for(unsigned int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) {
            // Shift all elements down by one starting from here
            for(unsigned int j = i; j < arr.size()-1; j++) {
                arr[j] = arr[j+1];
            }
        }
    }
    arr.pop_back();
}

void RemoveDuplicates(std::vector<int> &arr) {
    // Find duplicate
    // Shift all elements assuming next element is not also a duplicate
    //  - If the above case is true, store cur duplicate position and iterate until a non-duplicate is found
    //  - Then swap and return iterating from where the original duplicate was found
    // Repeat
    // Map version is superior?
    // Need to account for duplicate adjacent elements
    std::set<int> s;
    for(int i = 0; i < arr.size(); i++) {
        s.insert(arr[i]);
    }
}

void RemoveDuplicatesMap(std::vector<int> &arr) {
    std::unordered_map<int,int> map;
    for(auto i : arr)
        map[i]++;
    for(unsigned int i = 0; i < arr.size()-1; i++) {
        if(map.count(arr[i]) > 1 && arr[i] != arr[i+1])
            arr[i] = arr[i+1];
    }
}

// Given an unsorted array, find the largest and smallest numbers, (THE ARRAY IS NOT ALLOWED TO BE SORTED) | Sort then return first and/or last otherwise
// Iterative version: Base algorithm, compare values to one another until the largest and smallest are found
std::tuple<int,int> LargestSmallestUnsorted(std::vector<int> &arr) {
	std::tuple<int,int> values;
	if(arr.size() <= 1) {
		return values;
	}
	else {
		int largest = INT_MIN, smallest = INT_MAX; 
        for(unsigned int i = 0; i < arr.size(); i++) {
            if(arr[i] > largest)
                largest = arr[i];
            if(arr[i] < smallest)
                smallest = arr[i];
        }

		std::get<0>(values) = largest;
		std::get<1>(values) = smallest;
	}
	return values;
}

// Effcient Version: (Map). Given that we cannot do any sorting, we can use an unordered map to quickly search for the largest and smallest
std::tuple<int,int> LargestSmallestUnsortedMap(std::vector<int> &arr) {
    std::tuple<int,int> results;
    if(arr.size())
        return results;
    else {
        int smallest = 0;
        int largest = 0;
        std::unordered_map<int,int> m;
        for(auto i : arr)
            m[i]++;
        for(std::unordered_map<int,int>::iterator it; it != m.end(); it++) {
            if(it->second < smallest) 
                smallest = it->second;
            else if(it->second > largest)
                smallest = it->second;
        }
        std::get<0>(results) = smallest;
        std::get<1>(results) = smallest;
    }
    return results;
}

// Shifts all the negative values of an array to one side, then sort positive and negative sides | Fix! One element out of place
std::vector<int> ShiftNegative(std::vector<int> &arr) {
	if(arr.size() == 0)
		return arr;
	else {
		int amountShifted = 0;
		for(unsigned int i = 0; i < arr.size(); i++) {
			if(arr[i] < 0) {
				arr.push_back(arr[i]);
				arr.erase(arr.begin()+i);
				amountShifted++;
			}
		}
        // Array zeroing?
		std::sort(arr.begin(), arr.end() - amountShifted); // Sort positives
		std::sort(arr.begin() + amountShifted, arr.end());
	}
    for(auto i : arr)
        std::cout << i << ", ";
	return arr;
}

// Find all elements that appear more then or equal to n times
std::vector<int> CommonElements(std::vector<int> &arr, int times) { // Fix! | Get pushing | Only want to push back one occurence of element
	if(arr.size() == 0)
		return arr;
	else {
		std::vector<int> count{};
		std::unordered_map<int,int> map;
        for(auto i : arr)
            map[i]++;
        // Fix from here
        for(auto i : arr)
            if(map.count(i) >= times)
                count.push_back(i);
        for(auto i : count)
            std::cout << i << ", ";
        return count;
	}
	return arr; 
}

// Converts a regular array into a circular one | Do!
std::vector<int> CyclicArray(std::vector<int> &arr, const int element) {
	if(arr.size() == 0)
		return arr;
	else {
		// Do!
		arr[0] = element;
	}
	return arr;
}

// Assuming their are two non-empty arrays, check if one array is a sub-array of the other, in relative order
bool ValidSubSequence(std::vector<int> &arr1, std::vector<int> &arr2) {
	int correct = 0;
	for(unsigned int i = 0; i < arr2.size(); i++) {
		if(arr1[correct] == arr2[i])
			correct++;
		if(correct == arr1.size())
			return true;
	}
	return false;
}

// Same as previous but order is not relevant
bool ValidSubSequenceNonRelative(std::vector<int> &arr1, std::vector<int> &arr2) {
	int correct = 0;
	std::unordered_map<int,int> m;
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

// Given an array, sorted in increasing order, return an array of the squares of each number
std::vector<int> SortedSquaredArray(std::vector<int> &arr) {
	if(arr.size() == 0)
		return arr;
	else {
		std::vector<int> newArr;
		for(auto i : arr) 
			newArr.push_back(i * i);
		return newArr;
	}
	return arr;
}

void MoveElementToEndSimple(std::vector<int> &arr, int element) {
	for(unsigned int i = 0; i < arr.size(); i++) {
        if(arr[i] == element) {
            arr.push_back(arr[i]);
            arr.erase(arr.begin() + i);
        }
    }
}

void MoveToEnd(std::vector<int> &arr, int element) {
    int moveElement = 0;
    int shiftPos = 0;
    for(unsigned int i = 0; i < arr.size(); i++) {
        if(arr[i] == element) {
            moveElement = arr[i];
            shiftPos = i;
            break;
        }
    }
    for(unsigned int i = shiftPos; i < arr.size()-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[arr.size()-1] = moveElement;
}

bool MonotonicArray(std::vector<int> &arr) {
	bool increasing = true, decreasing = true;
	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] > arr[i+1])
			increasing = false;
		if(arr[i] < arr[i+1])
			decreasing = false;
	}
	if(increasing && decreasing) return false; // Both can't be true
    return true;
}

// Find exactly 3 numbers in an array whose sum is equal to the target
std::tuple<int,int,int> ThreeNumberSumIter(std::vector<int> &arr, int sum) { // Iterative approach using pointers
    std::tuple<int,int,int> numbers{0,0,0};
    if(arr.size() < 3)
        return numbers;
    else {
        std::sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) {
            int left = i + 1;
            int right = arr.size()-1;
            while(left < right) {
                if(arr[i] + arr[left] + arr[right] == sum) {
                    std::cout << arr[i] << ", " << arr[left] << ", " << arr[right] << "\n";
                    std::get<0>(numbers) = arr[i];
                    std::get<1>(numbers) = arr[left];
                    std::get<2>(numbers) = arr[right];
                    return numbers;
                }
                else if (arr[i] + arr[left] + arr[right] < sum)
                    left++;
                else
                    right--;
            }
        }
        return numbers;
    }
    return numbers;
}

bool ThreeNumberSumMap(std::vector<int> &arr, int sum) { // Change return!
    if(arr.size() < 3)
        return false;
    else {
        std::map<int, int> m;
        for(auto i : arr)
            m[i]++;
        for(int i = 0; i < arr.size(); i++) {
            int left = i + 1;
            int right = arr.size()-1;
            if(sum - m[i] == sum) // Check!
                return true;
        }
    }
	return false;
}

// Does not take into account flat peaks
int LongestPeakNonStrict(std::vector<int> &arr) { // Check, seems totally fine, can't figure out the issue
	int longest = 0;
    int curPeak = 1;
    for(unsigned int i = 0; i < arr.size()-1; i++) {
        if(arr[i+1] > arr[i]) {
            curPeak++;
            if(curPeak > longest)
                longest = curPeak;
        }
        if(arr[i+1] < arr[i]) {
            curPeak = 0;
        }
    }
    return longest;
}

int BinarySearch(std::vector<int> &arr, const int target) { // Assuming the array is already sorted
	if(arr.size() == 0)
		return -1;
	else {
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

// Find smallest or largest value in an unsorted array of 'distinct' integers.
// Reverse for largest
int KthSmallestSimple(std::vector<int> &arr, int k) { // Expensive
    std::sort(arr.begin(), arr.end());
    return arr[k-1];
}

int KthSmallestSet(std::vector<int> &arr, int k) {
    std::set<int> s(arr.begin(), arr.end());
    std::set<int>::iterator it = s.begin();
    std::advance(it, k-1);
    return *it;
}

// Given an array, find the shortest continuos sub-array which when sorted, sorts the whole array (Ascending order)
    // - Sub array to be sorted will always be contiguous
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Approach 1
int FindUnsortedSubArray(std::vector<int> &arr) {
    int left = 0;
    int right = 0;
    if(arr.size() == 0)
        return -1;
    else {
        std::vector<int> sortedArr(arr);
        std::sort(sortedArr.begin(), sortedArr.end());
        for(unsigned int i = 0; i < arr.size(); i++) {
            if(arr[i] != sortedArr[i]) {
                left = i;
                break;
            }
        }
        for(unsigned int j = arr.size()-1; j > 0; j--) {
            if(arr[j] != sortedArr[j]) {
                right = j;
                break;
            }
        }
    }
    return right - left + 1;
}

int ShortestUnsortedSubArray(std::vector<int> &arr) {
    int left = arr.size();
    int right = 0;
    for(int i = 0; i < arr.size()-1; i++) {
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[j] < arr[i]) {
                right = std::max(right, j);
                left = std::max(left, i);
            }
        }
    }
    return right - left < 0 ? 0 : right - left;
}

int ShortestUnsortedSubArrayBetter(std::vector<int> &arr) {
    // Create a clone of the array
    // Sort that array
    // Use that sorted array in place of the non sorted array
    // This lets us use a single iteration instead of a nested loop
    // We can use a single because we know what the sorted array is 
    // supposed to be
    std::vector<int> copyArr(arr);
    std::sort(copyArr.begin(), copyArr.end());
    int start = arr.size();
    int end = 0;
    for(int i = 0; i < copyArr.size(); i++) {
        if(copyArr[i] != arr[i]) {
            start = std::min(start, i);
            end = std::max(end, i);
        }
    }
    return start - end < 0 ? 0 : start - end;
}

std::vector<int> FindUnsortedSubArrayVector(std::vector<int> &arr) {
    if(arr.size() == 0)
        return arr;
    else {
        int left = 0;
        int right = 0;
        std::vector<int> sortedArray(arr);
        std::sort(sortedArray.begin(), sortedArray.end());
        for(unsigned int i = 0; i < arr.size(); i++)
            if(arr[i] == sortedArray[i])
                left = i;
        for(unsigned int j = arr.size(); j > 0; j--)
            if(arr[j] == sortedArray[j])
                right = j;
        return sortedArray;
    }
    return arr; 
}

// Given an array of n elements, where each element is at most k away from its target position. Sort the array efficiently
std::vector<int> SortKSortedArray(std::vector<int> &arr, const int k) {
    // Insertion Sort
    int j;
    for(unsigned int i = 1; i < arr.size(); i++) {
        j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            Swap(&arr[j-1], &arr[j]);
            j = j - 1;
        }
    }


    for(auto i : arr)
        std::cout << i << ", ";

    return arr;
}

std::vector<std::vector<int>> MergeOverlappingIntervals(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> result{};
    if(intervals.size() <= 1)
        return intervals;
    else {
        std::sort(intervals.begin(), intervals.end());
        std::vector<int> firstInterval = intervals[0];
        for(auto i : firstInterval)
            std::cout << i << ", ";
        putchar('\n');
        for(auto i : intervals) {
            std::cout << "Compare:" << i[0] << " to " << firstInterval[1] << "|\n";
            if(i[0] <= firstInterval[1])
                firstInterval[1] = std::max(i[1], firstInterval[1]);
            else {
                result.push_back(firstInterval);
                firstInterval = i;
            }
        }
        result.push_back(firstInterval);
    }
    return result;
}

// Given an array of integers representing building heights, check which buildings can see the sun
int SunsetViews(std::vector<int> &arr) {
    if(arr.size() == 0)
        return 0;
    else {
        int result = 0;
        int tallest = arr[0];
        result++; // First building will always see sunlight
        for(unsigned int i = 1; i < arr.size(); i++) {
            if(arr[i] > tallest) {
                result++;
                tallest = arr[i];
            }
        }
        return result;
    }
    return 0;
}

// Given a staircase of n steps, where a person can hop either 1 or 2 steps at a time. Find all possible ways of traversing the staircase
int StaircaseTraversal(const int n) {
    
}

void ReverseArray(std::vector<int> &arr) {
    for(unsigned int i = 0; i < arr.size() / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arr.size() - i -1];
        arr[arr.size() -i - 1] = temp;
    }
}

int SmallestDifference(std::vector<int> &arr) {
    int curDiff = 0;
    int smallDiff = INT_MAX;
    for(unsigned int i = 0; i < arr.size()-1; i++) {
        if(arr[i] > arr[i+1])
            curDiff = arr[i] - arr[i+1];
        else
            curDiff = arr[i+1] - arr[i];
        if(curDiff < smallDiff)
            smallDiff = curDiff;
    }
    return smallDiff;
}

int NonAdjacentMaxSum(std::vector<int> &arr) {
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    for(int i = 1; i < arr.size(); i++) {
        excl_new = incl> excl ? incl : excl;

        incl = excl + arr[i];
        excl = excl_new;
    }
    return ((incl > excl) ? incl : excl);
}

int main() {
    std::vector<int> testArray{1,2,3,4,5,6,7,8,9,10};
    std::cout << "Reverse Array:\n";
    ReverseArray(testArray);
    for(auto i : testArray)
        std::cout << i << ',';

    std::cout << "\nAll possible pairs:\n";
    std::vector<int> array{1,2,3};
    AllPossiblePairs(array);

    std::cout << "\nFind all duplicates:\n";
    std::vector<int> dupArray{1,2,3,1,1,1,2,5,6,5,5,9,7,1};
    std::cout << "Duplicate of target: " << FindDuplicateOfTarget(dupArray, 1) << '\n';
    std::cout << "Duplicate of target (Map): " << FindDuplicateOfTargetMap(dupArray, 1) << '\n';
    std::cout << "All Duplicates:\n";
    FindAllDuplicates(dupArray);

    std::cout << "\nShift negative:\n";
	std::vector<int> data{1,-2,15,-67,-8,-3,45,90,123,-4,14};
	ShiftNegative(data);

	putchar('\n');

    std::vector<int> commonData{2,2,2,2,1,6,7,7,5,5,5,5,5,5,5,9,3,8};
    std::vector<int>result(CommonElements(commonData, 4)); // Check initialisation
    for(auto i : result)
        std::cout << i << ", ";

	putchar('\n');

	std::vector<int> data2{-2, 1, 4, 8, 11};
	std::vector<int> sArray = SortedSquaredArray(data2);
	for(auto i : sArray)
		std::cout << i << ", ";

	putchar('\n');
    std::cout << "Valid Sub-Sequence:\n";

    std::vector<int> a1{3,4,5};
    std::vector<int> a2{1,2,3,4,5,6,7,8};
    std::cout << ValidSubSequence(a1, a2);   
    std::cout << ValidSubSequenceNonRelative(a1, a2);   

	putchar('\n');
    std::cout << "Monotonic Array:\n";
	std::vector<int> data3{1,2,3,4,5,6,7,7};
	std::cout << MonotonicArray(data3);

	putchar('\n');
    std::cout << "Three Number Sum:\n";
	std::vector<int> data4{12,3,4,1,6,9}; // CHANGE
	ThreeNumberSumIter(data4, 24);

	putchar('\n');

	std::vector<int> peakData{1,3,1,2,3,5,6,7,9,12,8,7,2,1};
	std::cout << LongestPeakNonStrict(peakData);

	putchar('\n');

    std::cout << KthSmallestSimple(data4, 5);
	putchar('\n');
    std::cout << KthSmallestSet(data4, 5);

    putchar('\n');
    std::cout << "Sort K Sorted Array Simple:\n";
    std::vector<int> kArray{10,9,8,7,4,70,60,50};
    SortKSortedArray(kArray, 4);

    putchar('\n');

    std::cout << "Find Unsorted Sub-Array:\n";
    std::vector<int> data5{2,6,4,8,10,9,15};
    std::cout << FindUnsortedSubArray(data5);

    putchar('\n');

    std::cout << "Merge Overlapping intervals:\n";
    std::vector<std::vector<int>> inter{{1,3}, {2,6}, {8,10}, {15,18}};
    std::vector<std::vector<int>> interResult = MergeOverlappingIntervals(inter);
    for(unsigned int i = 0; i < interResult.size(); i++)
        for(unsigned int j = 0; j < interResult[0].size(); j++)
            std::cout << interResult[i][j] << ", ";

    std::cout << "\nSunset Views:\n";
    std::vector<int> buildings{7,4,8,2,9};
    std::cout << SunsetViews(buildings);

    std::cout << "\nStaircase Traversal:\n";
    std::cout << StaircaseTraversal(4);

	return 0;
}