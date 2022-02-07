// Sorting Algorithms
#include <iostream>
#include <vector>
#include <algorithm>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ======================= Bubble Sort =======================
void BubbleSort(std::vector<int> &arr) {
    for(unsigned int i = 0; i < arr.size(); i++) {
        for(unsigned int j = 0; j < arr.size()-1; j++) {
            if(arr[j] > arr[j+1])
                Swap(&arr[j], &arr[j+1]);
        }
    }
}

void BubbleSortBetter(std::vector<int> &arr) {
    bool hasSwapped = true;
    while(hasSwapped) {
        hasSwapped = false;
        for(unsigned int i = 0; i < arr.size()-1; i++) {
            if(arr[i] > arr[i+1]) {
                Swap(&arr[i], &arr[i+1]);
                hasSwapped = true;
            }
        }
    }
}

void BubbleSortBest(std::vector<int> &arr) { // nIterations isn't changing, update!
    bool hasSwapped = true;
    int nIterations = 0;
    while(hasSwapped) {
        hasSwapped = false;
        for(unsigned int i = 0; i < arr.size() - nIterations - 1; i++) {
            if(arr[i] > arr[i+1]) {
                nIterations++; // Check!
                Swap(&arr[i], &arr[i+1]);
                hasSwapped = true;
            }
        }
    }
}

// ======================= Selection Sort ========================
std::vector<int> SelectionSort(std::vector<int> &arr) {
    if(arr.size() == 0)
        return arr;
    for(unsigned int i = 0; i < arr.size(); i++) {
        int min = i;
        for(unsigned int j = i+1; j < arr.size(); j++) 
            if(arr[j] < arr[min])
                min = j;
        if(min != i)
            Swap(&arr[i], &arr[min]);
    }
    return arr;
}

// ======================= Insertion Sort =====================
std::vector<int> InsertionSortSwap(std::vector<int> &arr) {
    if(arr.size() <= 1)
        return arr;
    else {
        int j;
        for(unsigned int i = 1; i < arr.size(); i++) {
            j = i;
            while (j > 0 && arr[j-1] > arr[j]) {
                Swap(&arr[j], &arr[j-1]);
                j--;
            }
        }
    }
    return arr;
}

std::vector<int> InsertionSortFast(std::vector<int> &arr) { // Not using 'Swap'
    if(arr.size() == 0)
        return arr;
    else {
        int j;
        int x;
        for(unsigned int i = 1; i < arr.size(); i++) {
            x = arr[i];
            j = i - 1;
            while(j > 0 && arr[j] > arr[j-1]) {
                arr[j+1] = arr[j];
                j = j - 1;
            }
            arr[j+1] = x;
            i = i + 1;
        }
    }
    return arr;
}

// ======================= Quick Sort =======================
int Partition(std::vector<int> &arr, int left, int right) {
    int i = left - 1;
    for(unsigned int j = left; j < right; j++) {
        if(arr[j] < arr[right]) {
            i++;
            Swap(&arr[i], &arr[j]); // Swap left to current
        }
    }
    Swap(&arr[i+1], &arr[right]); // Move pivot (Partition)
    return i+1;
}

void QuickSort(std::vector<int> &arr, int left, int right) {
    if(arr.size() <= 1) return;
    if(left < right) {
        int pivot = Partition(arr,left,right);

        // Sort sub-arrays
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}

// ======================= Merge Sort =======================
void Merge(std::vector<int> &arr, int l, int m, int r) {
    int n1 = m - l + 1; // First sub array
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> M(n2);

    // Set (Copy) elements of sub arrays
    for(unsigned int i = 0; i < n1; i++)
        L[i] = arr[l+i];
    for(unsigned int j = 0; j < n2; j++)
        M[j] = arr[m + 1 + j];

    int i, j = 0;
    int k = l;

    while(i < n1 && j < n2) {
        if(L[i] < M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // Push remaining elements
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m-1);
        MergeSort(arr, m+1, r);

        Merge(arr, l, m, r);
    }
}

// ======================= Heap Sort (MAX HEAP) =======================
void siftDown(std::vector<int> &arr, int start, int end) {
    int root = start;
    while(root+1 <= end) {
        int child = root+=1;
        int swap = root;
        if(arr[swap] < arr[child])
            swap = child; // Left
        if(child+1 <= end && arr[swap] < arr[child+1])
            swap = child+1; // Right
        else {
            Swap(&arr[root], &arr[swap]);
            root = swap;
        }
    }
}

void Heapify(std::vector<int> &arr) {
    int start = arr.size()-1;
    while(start >= 0) {
        siftDown(arr, start, arr.size()-1);
        start--;
    }
}

void HeapSort(std::vector<int> &arr) {
    std::make_heap(arr.begin(), arr.end());
    int end = arr.size() - 1;
    while(end > 0) {
        Swap(&arr[end], &arr[0]);
        end--;
        siftDown(arr, 0, end);
    }
    Heapify(arr);
}

// PRINT FUNCTION
void PrintArray(std::vector<int> &arr) {
    for(int i : arr)
        std::cout << i << ", ";
    putchar('\n');
}

int main() {
    std::vector<int> array{5,3,2,1,4,6,9,7,8};
    PrintArray(array);

    // BubbleSort(array);
    // BubbleSortBetter(array);
    // SelectionSort(array);
    // InsertionSortSwap(array);
    // QuickSort(array, 0, array.size());
    MergeSort(array, 0, array.size()-1); // Fix! Minor issue
    // HeapSort(array);
    PrintArray(array);


    return 0;
}