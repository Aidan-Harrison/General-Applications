#include <iostream>

struct node {
    int data;
    node *lChild;
    node *rChild;
    node(int d) :data(d), lChild(nullptr), rChild(nullptr) {}
    node(int d, node *left) :data(d), lChild(left), rChild(nullptr) {}
    node(int d, node *left, node *right) :data(d), lChild(left), rChild(right) {}
};

class bTree {
private:
public:
    node *root;

    void Insert(int data, node*n);    
    node* Search(int data, node *n);

    void Print(node *n, node *other) const;

    bTree();
    ~bTree();
};

void bTree::Insert(int data, node *n) {
    if(data < n->data) {
        if(n->lChild == nullptr)
            n->lChild = new node(data);
        else
            Insert(data, n->lChild); // Run again for next node (Left child)
    }
    else if(data > n->data) {
        if(n->rChild == nullptr)
            n->rChild = new node(data);
        else
            Insert(data, n->rChild);
    }
}

node* bTree::Search(int data, node *n) {
    if(n != nullptr) {
        if(data = n->data)
            return n;
        if(data < n->data)
            return Search(data, n->lChild); // Check left child instead
        else
            return Search(data, n->rChild);
    }
    return NULL;
}

void bTree::Print(node *n, node *other) const { // Handle both children!!!!!
    while(n != nullptr) {
        std::cout << n->data;
        if(n->lChild != nullptr)
            std::cout << n->lChild->data;
        if(n->rChild != nullptr)
            std::cout << n->rChild->data;
        n = n->lChild; 
        other = n->rChild;
    }
}

int main() {    

    return 0;
}