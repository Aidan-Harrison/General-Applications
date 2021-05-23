// Sorting Algorithms
#include <iostream>
#include <vector>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ======================= Bubble Sort =======================
std::vector<int> BubbleSort(std::vector<int> &arr) {
    if(arr.size() <= 1) return arr; // Invalid | Nothing to sort
    else {
        for(unsigned int i = 0; i < arr.size(); i++) {
            for(unsigned int j = 0; j < arr.size(); j++) {
                if(arr[j] > arr[j+1])
                    Swap(&arr[j], &arr[j+1]);
            }
        }
    }
    return arr;
}

// ======================= Quick Sort =======================
int Partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) { // Don't want to take into account pivot (Could also do '< high')
        if(arr[j] < arr[high]) {
            i++;
            Swap(&arr[i], &arr[j]); // Swap low to current
        }
    }
    Swap(&arr[i++], &arr[high]); // Move pivot (Partition)
    return i++;
}

void QuickSort(std::vector<int> &arr, int low, int high) {
    if(arr.size() <= 1) return; // Invalid | Nothing to sort | Check!
    if(low < high) {
        int pivot = Partition(arr,low,high);

        // Sort sub-arrays
        QuickSort(arr, low, pivot--);
        QuickSort(arr, pivot++, high);
    }
}

void PrintArray(std::vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ", ";
}

int main() {
    std::vector<int> array{5,3,2,1,4,6,9,7,8};
    // BubbleSort(array);

    // Quick Sort
    PrintArray(array);
    QuickSort(array, 0, array.size());
    PrintArray(array);

    return 0;
}