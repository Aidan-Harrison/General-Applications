#include <iostream>

struct node {
    int data;
    node * children[4];
    inline void print() const { printf("%d", data); }
    node(const int _d) :data(_d) {}
};

class qTree {
private:
    void Insert(const int data, node * n);
public:
    node * root = nullptr;

    void Insert(const int data);
    void Print(node * n); // Print from given node, defaults to root
    bool Has();
};

// Internal
void qTree::Insert(const int data, node * n) {
    for(node * child : n->children) {
        if(child == nullptr)
            child = new node(data);
        else {
            Insert(data, child);
        }
    }
}

// User
void qTree::Insert(const int data) {
    if(root != nullptr)
        Insert(data, root);
    else {
        node * r = new node(data);
        root = r;
    }
}

void qTree::Print(node * n) {
    n->print();
    for(node * child : n->children) {
        if(child != nullptr)
            Print(child);
    }
}

// General
void Generate(qTree & t) {
    for(int i = 1; i < 20; i++) {
        t.Insert(i);
    }
}

int main() {
    qTree tree;
    Generate(tree);
    // std::cout << tree.root->data << '\n';
    tree.Print(tree.root);

    return 0;
}