#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <map>
#include <set>
#include <array>
#include <stack>

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
        for(unsigned int i = 0; i < arr.size()-1; i++) {
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
			if(arr[i] == target && arr[i+1] == target)
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

// Find all values which have duplicate members
template<typename T>
std::vector<T> FindAllDuplicates(std::vector<T> &arr) {
    if(arr.size() <= 1)
        return arr;
    else {
        std::vector<T> duplicates{};
        std::unordered_map<T,int> map;
        for(auto i : arr)
            map[i]++;
        for(auto it = map.begin(); it != map.end(); it++)
            if(it->second > 1)
                duplicates.push_back(it->first);
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
std::pair<int,int> LargestSmallestUnsorted(std::vector<int> &arr) {
	std::pair<int,int> values;
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
std::vector<int> CommonElements(std::vector<int> &arr, const int n) {
	if(arr.size() == 0)
		return arr;
	else {
		std::vector<int> count{};
		std::unordered_map<int,int> map;
        for(auto i : arr)
            map[i]++;
        for(auto it = map.begin(); it != map.end(); it++)
            if(it->second >= n)
                count.push_back(it->first);
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

void MoveElementToEndSimple(std::vector<int> &arr, int element) {
	for(unsigned int i = 0; i < arr.size(); i++) {
        if(arr[i] == element) {
            arr.push_back(arr[i]);
            arr.erase(arr.begin() + i);
        }
    }
}

void MoveToEnd(std::vector<int> &arr, int element) {
    int moveElement = 0, shiftPos = 0;
    for(unsigned int i = 0; i < arr.size(); i++) {
        if(arr[i] == element) { 
            moveElement = arr[i];
            shiftPos = i;
            break; // Moves firt encounter
        }
    }
    for(unsigned int i = shiftPos; i < arr.size()-1; i++)
        arr[i] = arr[i+1];
    arr[arr.size()-1] = moveElement;
}

// Given a sub-array, shift to end
void MoveSubToEnd(std::vector<int> &arr, std::vector<int> &sub) {
    int startingPos = -1, endingPos = 0;
    int counter = 0;
    for(unsigned int i = 0; i < arr.size(); i++) {
        if(arr[i] == sub[counter]) {
            if(counter == 0)
                startingPos = i;
            counter++;
        }
        else 
            counter = 0;
        if(counter == sub.size())
            endingPos = i+1;
    }
    for(auto i : sub)
        arr.push_back(i);
    arr.erase(arr.begin() + startingPos, arr.end() - endingPos);
}

// Do manual version of above! | Replace vector functions

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
std::array<int,3> ThreeNumberSumIter(std::vector<int> &arr, int sum) { // Iterative approach using pointers
    std::array<int,3> numbers{0,0,0};
    if(arr.size() < 3)
        return numbers;
    else {
        std::sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) {
            int left = i + 1;
            int right = arr.size()-1;
            while(left < right) {
                if(arr[i] + arr[left] + arr[right] == sum) {
                    numbers[0] = arr[i];
                    numbers[1] = arr[left];
                    numbers[2] = arr[right];
                    return numbers;
                }
                else if (arr[i] + arr[left] + arr[right] < sum)
                    left++;
                else
                    right--;
            }
        }
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
int LongestPeakNonStrict(std::vector<int> & arr) { // Check, seems totally fine, can't figure out the issue
	int longest = 0, curPeak = 1;
    for(unsigned int i = 0; i < arr.size()-1; i++) {
        if(arr[i+1] > arr[i]) {
            curPeak++;
            if(curPeak > longest)
                longest = curPeak;
        }
        if(arr[i+1] < arr[i])
            curPeak = 0;
    }
    return longest;
}

int BinarySearch(std::vector<int> &arr, const int target) { // Assuming the array is already sorted | Else add sort
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
			else if(arr[mid] < target) BinarySearchRecursive(arr, target, mid + 1, right);
			else BinarySearchRecursive(arr, target, left, mid - 1);
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

int ShortestUnsortedSubArrayOther(std::vector<int> &arr) {
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
        for(unsigned int i = 0; i < arr.size(); i++) {
            if(arr[i] != sortedArray[i]) {
                left = i;
                break;
            }
        }
        for(unsigned int j = arr.size(); j > 0; j--)
            if(arr[j] != sortedArray[j]) {
                right = j;
                break;
            }
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
    int result = 1; // First building will always see sunlight
    int tallest = arr[0];
    for(unsigned int i = 1; i < arr.size(); i++) {
        if(arr[i] > tallest) {
            result++;
            tallest = arr[i];
        }
    }
    return result;
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
        if(arr[i] > arr[i+1]) // Cheaper then abs()
            curDiff = arr[i] - arr[i+1];
        else
            curDiff = arr[i+1] - arr[i];
        if(curDiff < smallDiff)
            smallDiff = curDiff;
    }
    return smallDiff;
}

// Gets the differences of all adjacent values
std::vector<int> differences(std::vector<int> & arr) {
    int curDiff{};
    std::vector<int> diffs{};
    for(unsigned int i = 0; i < arr.size()-1; i++) {
        if(arr[i] > arr[i+1])
            curDiff = arr[i] - arr[i+1];
        else
            curDiff = arr[i+1] - arr[i];
        diffs.push_back(curDiff);
    }
    return diffs;
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

// Order array into a matrix | Improve
std::vector<std::vector<int>> MatrixPack(std::vector<int> &array) {
    int counter = 0;
    std::vector<std::vector<int>> matrix{};
    matrix.resize(array.size()/2);
    int test = array.size() + 1;
    int otherTest = array.size()/2 + 1;
    int amount = test / otherTest;
    for(int i = 0; i < amount; i++)
        matrix[i].resize(array.size()/2);
    std::sort(array.begin(), array.end());
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = array[counter];
            counter++;
        }
        counter++;
    }
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << '|';
        putchar('\n');
    }
    return matrix;
}

// Encrpyts an array by scrambling the elements and decrpyts by knowing how it was scrambled
std::vector<int> ScrambleEncrypt(std::vector<int> &arr) {
    std::vector<int> moves{};
    int sRandIndex = 0;
    int fRandIndex = 0;
    for(int i = 0; i < arr.size(); i++) {
        sRandIndex = rand() % arr.size();
        fRandIndex = rand() % arr.size();
        moves.push_back(fRandIndex);
        moves.push_back(sRandIndex);
        int temp = arr[fRandIndex];
        arr[fRandIndex] = arr[sRandIndex];
        arr[sRandIndex] = temp;
    }
    return moves;
}

void ScrambleDecrypt(std::vector<int> &arr, std::vector<int> &moves) {
    for(int i = 0; i < arr.size(); i++) {
        arr[moves[i]] == arr[moves[i+1]];
    }
}

// Split Array -- DO
    // Given a threshold number, split an array into two sub-arrays
    // Quick sort esque partition, have a pivot/middle element
void Pivot(std::vector<int> &arr, const int value, const int threshold) {
    while(value < threshold) {
        Swap(&arr[value], &arr[value+1]);
    }
}

// Returns second half of array and shaves off from first
std::vector<int> SplitArray(std::vector<int> &arr, const int split) {
    std::vector<int> half{};
    for(unsigned int i = split; i < arr.size(); i++)
        half.push_back(arr[i]);
    for(unsigned int i = arr.size(); i > split; i--)
        arr.pop_back();
    return half;
}

// Split array into x amount of other arrays | Do!
void FractionArray(std::vector<int> & arr, const int fraction) {
    std::vector<std::vector<int>> fractions{};
    if(fraction == 1)
        return;
    // Find fraction size
    int fracSize{};
    if(fracSize * fraction == arr.size()) {
        for(int i = 0; i < arr.size(); i++) {
            if(i % fraction == 0) {

            }
        }
    }

    // 1 = return
    // 2 = half
    // 3 = third
    // etc.

}

// Blip
    // Given an integers position n, increase values by 1 from n's position - n and + n
void Blip(std::vector<int> &arr, const int n) {
    int leftBlip = n - n - 1;
    int rightBlip = n + n - 1;
    if(rightBlip > arr.size() || leftBlip < 0)
        return;
    for(unsigned int i = leftBlip; i < rightBlip; i++)
        if(i != n)
            arr[i]++;
}

void Blip2(std::vector<int> &arr, const int n, bool right = true) {
    int leftBlip = n - n - 1;
    int rightBlip = n + n - 1;
    if(rightBlip * 2 > arr.size() || leftBlip - leftBlip < 0)
        return;
    if(right)
        for(unsigned int i = n; i < rightBlip * 2; i++)
            if(i != n)
                arr[i]+=n;
    else 
        for(unsigned int i = n; i < leftBlip - leftBlip; i++)
            if(i != n)
                arr[i]+=n; 
}

void BetterBlip(std::vector<std::vector<int>> &arr, const int n) {
    int w = arr[0].size(), h = arr.size();
    std::vector<std::pair<int,int>> directions{{0,1},{1,0},{1,1},{-1,-1},{0,-1}};
    auto inside=[&](const int x, const int y) {
        return 0 <= x && x <= w && 0 <= y && y <= h;
    };  
    for(int row = 0; row < arr.size(); row++) {
        for(int col = 0; col < arr[0 ].size(); col++) {
            if(arr[row][col] == n) {
                for(std::pair<int,int> dir : directions) {
                    int new_row = row + dir.first;
                    int new_col = col + dir.second;
                    if(inside(new_row, new_col))
                        arr[new_row][new_col] += n;
                }
            }
        }
    }
}

// Given an array, create multiple blip ranges
    // Example:
        /*
            1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
            n = 7
            Create 7
            !-1-! !-2-! !-3-! !---4--! !--5---! !--6--!  !-7-!
            1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
            Each blips gets increased by its appropiate number
            Numbers in first blip increased by 1
            Numbers in fourth blip increased by 4
        */

void SegmentedBlip(std::vector<int> & arr, const int n) {
    if(n * 2 > arr.size()) // Minimum segment size of 2
        return;
    int counter = 0, curSegment = 0, segmentSize = 2, remainder = 0;
    for(int i = 0; i < arr.size(); i++) {
        remainder = segmentSize % n == 0;
        if(i % segmentSize == 0)
            if(i == 0)
                curSegment = 1;
            curSegment = i;
        if(counter <= segmentSize) {
            arr[i] += curSegment;
            counter++;
        }
        else if(counter > segmentSize)
            counter = 0;
    }
}

void DoubleBlip(std::vector<int> & a1, std::vector<int> & a2) { // Fix!
    for(unsigned int i = 0; i < a2.size(); i++) {
        int leftBlip = a2[i] - a2[i] - 1;
        int rightBlip = a2[i] + a2[i] - 1;
        if(leftBlip < 0 || rightBlip > a1.size())
            continue;
        a1[leftBlip] += a2[i];
        a1[rightBlip] += a2[i];
    }
}

int Kadanes(std::vector<int> &arr) {
    int ans = INT_MIN, a = 0;
    for(int x : arr) {
        a += x;
        ans = std::max(ans, a);
        a = std::max(a, 0);
    }
    return ans;
}

bool isRepeatingCycle(std::vector<int> && arr, const int length) {
	int counter = 0;
	for(uint8_t i = length; i < arr.size(); i++) {
		if(arr[i] != arr[counter]) {
		    if(counter == length) 
		        return true;
			return false;
		}
		counter++;
	}
	return true;
}

std::string toSnakeCase(std::string str) {
	for(uint8_t i = 0; i < str.length(); i++) {
		if(isupper(str[i])) {
			str.insert(i, "_");
			str[i+1] = std::tolower(str[i+1]);
		}
	}
	return str;
}

std::string toCamelCase(std::string str) {
    for(uint8_t i = 0; i < str.length(); i++) {
		if(str[i] == '_') {
            str.erase(i,1);
            str[i] = std::toupper(str[i]);
		}
	}
    return str;
}

bool overTwentyOne(const std::vector<char> && cards) {
	int score = 0;
	bool hasA = false;
	for(int i = 0; i < cards.size(); i++) {
		if(cards[i] == 'A') {
		    hasA = true;
		    continue;
		}
		else if(cards[i] == 'K' || cards[i] == 'J') {
			score += 10;
			continue;
		}
		score += (int)cards[i];
	}
	if(hasA) {
    	if(score + 11 > 21)
    		score++;
    	else
    		score += 11;
        score = score + 11 > 21 ? score++ : score += 11;
	}
	if(score > 21)
	    return true;
	return false;
}

bool MiniSuduko(const std::vector<std::vector<int>> & grid) { // Re-do!
    int w = grid[0].size();
    int h = grid.size();
    std::vector<std::pair<int,int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    auto bounds=[&](const int x, const int y) { return x > 0 && x < w && y > 0 && y < h; };
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] < 1 || grid[i][j] > 9)
                return false;
            // DFS
            std::stack<std::pair<int,int>> s;
            s.push({i,j});
            while(!s.empty()) {
                std::pair<int,int> newPos = s.top();
                s.pop();
                std::pair<int,int> lastPos = newPos;
                for(std::pair<int,int> dir : directions) {
                    int newX = lastPos.first + dir.first;
                    int newY = lastPos.second + dir.second;
                    if(grid[newX][newY] == grid[i][j])
                        return false;
                    s.push({newX,newY});
                    lastPos.first = newX;
                    lastPos.second = newY;
                }
            }
        }
    }
    return true;
}

bool MiniSuduko2(const std::vector<std::vector<int>> & grid) { // Fix, correct positions!
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] < 1 || grid[i][j] > 9)
                return false;
            int k = i, l = j; // Position
            bool doneVert = false;
            while(k <= grid.size() && j <= grid[0].size()) {
                std::cout << grid[k][l] << '-';
                if(grid[k][l] == grid[i][j] && k != i && l != j)
                    return false;
                if(!doneVert) {
                    k++;
                    if(k == grid.size()) {
                        doneVert = true;
                        k = i;
                    }
                }
                else {
                    l++;
                    if(l == grid[0].size())
                        break;
                }
            }
        }
    }
    return true;
}

// Non-zeroed input
void RemoveElement(std::vector<int> & a, int index) {
    if(index <= 0 || index > a.size())
        return;
    a[index-1] = a[index];
    for(int i = index; i < a.size()-1; i++)
        a[i] = a[i+1];
    a.pop_back();
}

// Terrain generator
void Propogate(std::vector<std::vector<int>> & arr, std::pair<int,int> & pos) {
    uint8_t distance = 1; // Scale factor
    uint8_t fillDist{};
    // Axis
    auto boundsCheck = [&](const int x, const int y) {
        return x >= 0 && x < arr[0].size() && y >= 0 && y < arr.size();
    };
    for(unsigned int i = 0; i < 3; i++) {
        if(boundsCheck(pos.first+i, pos.second))
            arr[pos.first+distance+i][pos.second] = 1+i;
        if(boundsCheck(pos.first, pos.second-distance-i))
            arr[pos.first][pos.second-distance-i] = 1+i;
        if(boundsCheck(pos.first-distance-i, pos.second))
            arr[pos.first-distance-i][pos.second] = 1+i;
        if(boundsCheck(pos.first, pos.second+distance+i))
            arr[pos.first][pos.second+distance+i] = 1+i;
        // Diagonals
        if(boundsCheck(pos.first+distance+i, pos.second+distance+i))
            arr[pos.first+distance+i][pos.second+distance+i] = 1+i;
        if(boundsCheck(pos.first+distance+i, pos.second-distance-i))
            arr[pos.first+distance+i][pos.second-distance-i] = 1+i;
        if(boundsCheck(pos.first-distance-i, pos.second+distance+i))
            arr[pos.first-distance-i][pos.second+distance+i] = 1+i;
        if(boundsCheck(pos.first-distance-i, pos.second-distance-i))
            arr[pos.first-distance-i][pos.second-distance-i] = 1+i;
        // distance++;
        fillDist++;
    }
}

void NoisePass(std::vector<std::vector<int>> & arr) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            if(arr[i][j] > 0) {
                int chance = rand() % 2;
                if(chance >= 1)
                    arr[i][j]++;
            }
            else if(arr[i][j] == 0) {
                int chance = rand() % 10;
                if(chance > 6)
                    arr[i][j]++;
            }
        }
    }
}

void Terrain(std::vector<std::vector<int>> & arr) { // Convert to 1D
    // Generate indexes
    std::vector<std::pair<int,int>> anchorPoints(4, {0,0});
    for(std::pair<int,int> &p : anchorPoints) {
        p.first = rand() % arr.size();
        p.second = rand() % arr.size();
    }
    // Branch out from locations
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            for(std::pair<int,int> p : anchorPoints) {
                if(p.first == i && p.second == j) {
                    arr[p.first][p.second] = 1;
                    Propogate(arr, p);
                }
            }
        }
    }
    NoisePass(arr);
}

// Reverse for smallest
    // None sorting method
std::vector<int> N_Largest(std::vector<int> & arr, const int n) {
    std::vector<int> marked{};
    std::vector<int> nValues{};
    int storedPos = -1;
    while(nValues.size() != n) {
        int max = INT_MIN;
        bool found = false;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > max) {
                for(int j = 0; j < marked.size(); j++) {
                    if(i == j) {
                        found = true;
                        break;
                    }
                }
                if(found)
                    continue;
                max = arr[i];
                storedPos = i;
            }
        }
        nValues.push_back(max);
        marked.push_back(storedPos);
    }
    return nValues;
}

void AlternateConcanate(std::vector<int> & a1, std::vector<int> & a2) {
    std::vector<int> newArray{};
    int counterF = 0, counterS = 0;
    bool hasSwapped = false;
    for(int i = 0; i < a1.size()+a2.size(); i++) {
        if(!hasSwapped) {
            newArray.push_back(a1[counterF]);
            counterF++;
            hasSwapped = true;
        }
        else {
            newArray.push_back(a2[counterS]);
            counterS++;
            hasSwapped = false;
        }
    }
}

std::vector<int> SlidingWindow(std::vector<int> & arr, const int k) {
    int left = 0, right = k;
    int result = 0;
    std::vector<int> sums{};
    for(int i = 0; i < k; i++)
        result += arr[i];
    sums.push_back(result);
    for(int i = 0; i < arr.size(); i++) {
        if(left == arr.size() || right == arr.size())
            break;
        result = result - arr[left++] + arr[right++];
        sums.push_back(result);
    }
    return sums;
}

std::vector<int> ObtainLargest(std::vector<int> & a1, std::vector<int> & a2) {
    std::vector<int> a3;
    if(a1.size() != a2.size())
        return a3;
    for(unsigned int i = 0; i < a1.size(); i++)
        a3.push_back(std::max(a1[i],a2[i]));
    return a3;
}

void Scramble(std::vector<int> & a1) {
    int x, y;
    for(int i = 0; i < a1.size(); i++)
        Swap(&a1[x = rand() % a1.size()],&a1[y = rand() % a1.size()]);
}

void CountingSort(std::vector<int> & a1) {
    int max = INT_MIN;
    for(int i = 0; i < a1.size(); i++) {
        if(a1[i] > max)
            max = a1[i];
    }
    std::vector<int> countArray(max);
    for(int i = 0; i < a1.size(); i++) {
        
    }
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
	// std::vector<int> sArray = SortedSquaredArray(data2);
	// for(auto i : sArray)
		// std::cout << i << ", ";

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
    // std::cout << StaircaseTraversal(4);

    // Cycle count
    std::cout << isRepeatingCycle({1, 2, 3, 1, 2, 3, 1},3);

    // Snake and Camel
    std::cout << toSnakeCase("helloWorldVariable");
    std::cout << toCamelCase("hello_world_test_sentence");

    putchar('\n');

    // Suduko
    std::vector<std::vector<int>> grid{
        {1,2,3},
        {5,5,6},
        {7,8,9}
    };
    std::cout << MiniSuduko2(grid);

	return 0;
}
