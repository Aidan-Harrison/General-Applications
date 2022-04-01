// ASCII Sorting visualiser
#include <iostream>
#include <vector>
#include <thread>
#include <unordered_map>

// Add NCurses!
namespace Global {
    std::vector<std::string> visual{};
}

using namespace Global;

void Interface();

void Swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool Check(std::vector<int> &arr) {
    if(arr.size() <= 1) {
        std::cout << "Array is empty!\nReturning.....";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        return 1;
    }
    return 0;
}

void Visualiser(std::vector<int> &arr, const int first, const int second) { // Exapnd to support all sorting algorithms and their respective methods
    system("clear");
    visual.clear();
    for(unsigned int i = 0; i < arr.size(); i++)
        visual.push_back(std::string(arr[i], '#'));
    for(unsigned int i = 0; i < visual.size(); i++) {
        std::cout << visual[i];
        if(i == first) {
            std::cout << "\t<--F--\n";
            continue;
        }
        if(i == second) 
            std::cout << "\t<--S--\n";
        else
            putchar('\n');
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void Finish() {
    std::cout << "DONE!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Interface(); 
}

// ================ BUBBLE SORT ================
void BubbleSort(std::vector<int> &arr) {
    for(unsigned int i = 0; i < arr.size(); i++)
        for(unsigned int j = 0; j < arr.size()-1; j++)
            if(arr[j] > arr[j+1])
                Swap(&arr[j], &arr[j+1]);
    Finish();
}

void FastBubbleSort(std::vector<int> &arr) { // Implement n iterations!
    if(Check(arr))
        Interface();
    bool hasSwapped = true;
    while(hasSwapped) {
        hasSwapped = false;
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] > arr[i+1]) {
                Swap(&arr[i], &arr[i+1]);
                hasSwapped = true;
                Visualiser(arr, i, i+1);
            }
        }
    }
    Finish();
}

// ================ SELECTION SORT ================
void SelectionSort(std::vector<int> &arr) {
    if(Check(arr))
        Interface();
    for(unsigned int i = 0; i < arr.size(); i++) {
        int min = i;
        for(unsigned int j = i+1; j < arr.size(); j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i) {
            Swap(&arr[i], &arr[min]);
            Visualiser(arr, i, min);
        }
    }
    Finish();
}

// ================ INSERTION SORT ================
void InsertionSort(std::vector<int> &arr) {
    if(Check(arr))
        Interface();
    int j;
    for(unsigned int i = 1; i < arr.size(); i++) {
        j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            Swap(&arr[j], &arr[j-1]);
            Visualiser(arr, j, j-1);
            j--;
            // Add
        }
    }
    Finish();
}

void FastInsertionSort(std::vector<int> &arr) {

}

// ================ QUICK SORT ================
int Partition(std::vector<int> &arr, int left, int right) {
    int i = left -1;
    for(unsigned int j = left; j < right; j++) {
        if(arr[j] < arr[right]) {
            i++;
            Swap(&arr[i], &arr[j]);
            Visualiser(arr, i, j);
        }
    }
    Swap(&arr[i+1], &arr[right]);
    Visualiser(arr, i+1, right);
    return i+1;
}

void QuickSort(std::vector<int> &arr, int left, int right) {
    if(Check(arr))
        Interface();
    if(left < right) {
        int pivot = Partition(arr, left, right);

        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
    Finish();
}

// ================ MERGE SORT ================
void Merge() {

}

void MergeSort(std::vector<int> &arr) {
    if(Check(arr))
        Interface();
    
}

// HEAP SORT

// RADIX SORT

// COUNTING SORT | Continue!
void CountingSort(std::vector<int> &arr) {
    // Find largest element
    int max = INT_MIN;
    for(auto i : arr)
        if(i > max)
            max = i;
    std::vector<int> count(max+1,0);
    std::unordered_map<int,int> occurences{};
    for(auto i : arr)
        occurences[i]++;

}

// BUCKET SORT

void Interface() {
    system("clear");
    std::vector<int> test{5,4,8,2,3,6,9,7,1,2,10,11,13,14,12,15};
    int input = 0;
    std::cout << "Choose an algorithm: " <<
                "1) Bubble Sort\t 2) Bubble Sort (Fast)\t 3) Selection Sort\t 4) Insertion Sort\t 5) Insertion Sort (Fast)\t 6) Quick Sort\n";
    std::cin >> input;
    // Visualiser(test, 0, 0);
    switch(input) {
        case 1: BubbleSort(test); break;
        case 2: FastBubbleSort(test); break;
        case 3: SelectionSort(test); break;
        case 4: InsertionSort(test); break;
        case 5: FastInsertionSort(test); break;
        case 6: QuickSort(test, 0, test.size()); break;
        default: {
            system("clear");
            exit(0); break;
        }
    }
}

int main() {
    Interface();

    return 0;
}