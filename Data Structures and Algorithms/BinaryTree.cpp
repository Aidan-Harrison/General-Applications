#include <iostream>
#include <vector>
#include <cmath>

struct node {
    int data;
    node *lChild;
    node *rChild;
    node(const int d) :data(d), lChild(nullptr), rChild(nullptr) {}
    node(const int d, node *left) :data(d), lChild(left), rChild(nullptr) {}
    node(const int d, node *left, node *right) :data(d), lChild(left), rChild(right) {}
};

class bTree {
private:
    void Insert(const int data, node *n);
    node * Search(int data, node *n);
public:
    node *root;

    void Insert(const int data);    
    node * Search(int data);
    void DeleteTree(node *n);

    void Print(node *n) const;

    bTree() {};
    ~bTree() {};
};

void bTree::Insert(const int data, node *n) {
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

node * bTree::Search(int data, node *n) {
    if(n != nullptr) {
        if(data == n->data)
            return n;
        if(data < n->data)
            return Search(data, n->lChild); // Check left child instead
        else
            return Search(data, n->rChild);
    }
    return nullptr;
}

void bTree::Insert(const int data) {
    if(root != nullptr)
        Insert(data, root);
    else {
        node *r = new node(data);
        root = r;
    }
}

node* bTree::Search(int data) { // nullptr check?
    if(root != nullptr)
        return Search(data, root);
}

void bTree::DeleteTree(node *n) { // Check!
    if(n != nullptr) {
        n->lChild = nullptr;
        n->rChild = nullptr;
        delete n;
    }
}

void bTree::Print(node *n) const { // Handle both children!!!!! | Fix
    std::cout << n->data;
    if(n->lChild != nullptr)
        std::cout << n->lChild->data;
    if(n->rChild != nullptr)
        std::cout << n->rChild->data;
}

// Another implementation | Purely node based ============================================== || ???
struct bstNode {
    int data;
    bstNode *left;
    bstNode *right;
    bstNode(const int d) :data(d), left(nullptr), right(nullptr) {}

    bool const Search(int value); // Check const return!
    void Insert(int value);
    void Print() const;

    void InOrder() const;
    void PreOrder() const;
    void PostOrder() const;
};

void bstNode::Insert(const int value) {
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

bool const bstNode::Search(int value) { // Do return search
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

void bstNode::InOrder() const {
    if(left != nullptr)
        left->InOrder();
    if(right != nullptr)
        right->InOrder();
    std::cout << data << ", ";
}

void bstNode::PreOrder() const { 
    /*  // DFS?
    std::cout << data << ", ";
    if(left != nullptr)
        left->PreOrder();
    if(right != nullptr)
        right->PreOrder();
    */
}

void bstNode::PostOrder() const {

}

// Array
std::vector<int> binaryTree{11,12,-3,4,5,-11,7,8,2};

inline int GetLeft(const int index) { return (2*index)+1; }
inline int GetRight(const int index) { return (2*index)+2; }
inline int GetParent(const int index) { return (index-1)/2; }

void PrintArrayTree() {
    std::cout << "Root\n" << binaryTree[0] << '\n';
    auto check=[&](const int val) {
        return val > binaryTree.size();
    };
    for(int i = 0; i < binaryTree.size(); i++) {
        if(!check(GetLeft(i))) {
            std::cout << "/\n";
            std::cout << binaryTree[GetLeft(i)] << '\n';
            putchar('\t');
        }
        if(!check(GetRight(i)))
            std::cout << binaryTree[GetRight(i)] << '\n';
    }
}


int main() {    
    // Regular:
    /*
    std::cout << "===Regular Binary Tree===\n";
    bTree tree;
    tree.Insert(5);
    tree.Insert(14);
    tree.Insert(16);
    tree.Insert(8);
    tree.Insert(12);
    tree.Insert(2);
    tree.Insert(3);

    tree.Print(tree.root);
    */

    std::cout << "====================\n";

    // Purely Node based:
    std::cout << "===Node Based===\n";
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

    // Array
    std::cout << "\n==Array based Binary Tree==\n";
    PrintArrayTree();

    return 0;
}