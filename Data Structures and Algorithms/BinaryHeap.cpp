#include <iostream>
#include <array>

struct node {
    int data;
    int position;
    node *lChild;
    node *rChild;
    node *parent; // Remove?
    node() : data(0), lChild(nullptr), rChild(nullptr) {}
};

struct BinaryHeap {
    BinaryHeap() {}
    ~BinaryHeap() {}

    int heapSize = 0;
    static const int MAXSIZE = 10;

    std::array<node*, MAXSIZE> tree{};

    node *root;

    void Swap(node *n, node *n2);

    void Insert(int data);
    void Extract();
    void Search();
    void Delete();
};

void BinaryHeap::Swap(node *n, node *n2) {
    node *temp = n;
    n = n2;
    n2 = temp;
}

void BinaryHeap::Insert(int data) { // CHECK!
    // Insert new element at left most empty space
    // Compare against parent
    // If larger/smaller, swap with parent
    // Repeat step 2 and 3
    node newNode;

    if(heapSize == MAXSIZE) {
        std::cerr << "Heap is full!\n";
        return;
    }
    heapSize++;
    newNode.position = tree.size() - 1;
    tree[newNode.position]->data = data;
    while(newNode.data != 0  && tree[newNode.data] > tree[newNode.parent->data]) { // Get parent and compare
        Swap(tree[newNode.position], tree[newNode.parent->position]);
        newNode.position = newNode.parent->position;
    }
}

int main() {
    BinaryHeap b;

    return 0;
}