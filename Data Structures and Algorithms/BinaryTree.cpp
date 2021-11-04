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
    void Insert(int data, node *n);
    node* Search(int data, node *n);
public:
    node *root;

    bTree() {};

    void Insert(int data);    
    node* Search(int data);
    void DeleteTree(node *n);

    void Print(node *n, node *other) const;

    ~bTree() {};
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
        if(data == n->data)
            return n;
        if(data < n->data)
            return Search(data, n->lChild); // Check left child instead
        else
            return Search(data, n->rChild);
    }
    return NULL;
}

void bTree::Insert(int data) {
    if(root != nullptr)
        Insert(data, root);
    else
        node *root = new node(data);
}

node* bTree::Search(int data) { // nullptr check?
    return Search(data, root);
}
 
void bTree::DeleteTree(node *n) {
    if(n != nullptr) {
        n->lChild = nullptr;
        n->rChild = nullptr;
        delete n;
    }
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

// Another implementation | Purely node based ==============================================
struct bstNode {
    int data;
    bstNode *left;
    bstNode *right;
    bstNode(int d) :data(d), left(nullptr), right(nullptr) {}

    bool Search(int value);
    void Insert(int value);
    void Print() const;

    void InOrder();
    void PreOrder();
    void PostOrder();
};

void bstNode::Insert(int value) {
    if(value <= data) {
        if(left == nullptr) {
            bstNode *newNode = new bstNode(value);
            left = newNode;
        }
        else
            left->Insert(value);
    }
    else {
        if(right == nullptr) {
            bstNode *newNode = new bstNode(value);
            right = newNode;
        }
        else
            right->Insert(value);
    }
}

bool bstNode::Search(int value) {
    if(value == data)
        return true;
    else if(value < data) {
        if(left == nullptr)
            return false;
        else
            return left->Search(value);
    }
    else {
        if(right == nullptr)
            return false;
        else
            return right->Search(value);
    }
    return false;
}

void bstNode::Print() const { // In-Order printing/traversal
    if(left != nullptr)
        left->Print();
    std::cout << data << ", ";
    if(right != nullptr)
        right->Print();
}

void bstNode::InOrder() {

}

void bstNode::PreOrder() { 

    /*  // DFS?
    std::cout << data << ", ";
    if(left != nullptr)
        left->PreOrder();
    if(right != nullptr)
        right->PreOrder();
    */
}

void bstNode::PostOrder() {
}

int main() {    
    bstNode *root = new bstNode(10);
    bstNode *n2 = new bstNode(9);
    bstNode *n3 = new bstNode(12);
    bstNode *n4 = new bstNode(8);
    bstNode *n5 = new bstNode(14);
    bstNode *n6 = new bstNode(13);
    bstNode *n7 = new bstNode(22);

    root->left = n2;
    root->right= n3;

    n2->left = n4;
    n2->right = n5;

    n5->left = n6;
    n5->right = n7;

    root->Print();
    putchar('\n');
    std::cout << root->Search(8) << '\n';
    root->Insert(34);
    std::cout << root->Search(34) << '\n';
    root->Print();

    std::cout << "Traversal:\n";
    root->InOrder();
    putchar('\n');
    root->PreOrder();
    putchar('\n');
    root->PostOrder();
    putchar('\n');

    return 0;
}