#include <iostream>
#include <vector>

void Swap(int *a, int *b) {
    int *temp = a;
    *a = *b;
    *b = *temp;
}

struct MinHeap {
    int curSize = 0;
    int MAXSIZE = 0;
    std::vector<int> tree;
    MinHeap(int size) 
    {
        MAXSIZE = size;
    }

    int GetParent(int i) { return (i-1)/2; }
    int GetLeft(int i) { return 2*i + 1; } 
    int GetRight(int i) { return 2*i + 2; } 

    void Insert(int data) {
        if(tree.size() == MAXSIZE)
            return;
        int i = curSize-1;
        tree.push_back(data);
        while(data < GetParent(i)) {
            Swap(&data, &tree[GetParent(i)]);
            i = GetParent(i);
        }
    }

    int Remove();
    int Peek();

    ~MinHeap() {}
};

int main() {


    return 0;
}