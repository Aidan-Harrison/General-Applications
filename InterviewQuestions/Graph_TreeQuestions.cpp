#include <iostream>
#include <vector>
#include <tuple>

template<typename T>
struct stack {
    std::vector<T*> items{};
    int top = -1;

    bool IsFull() {
        if(top == items.size())
            return true;
        return false;
    }

    bool IsEmpty() {
        if(top == -1)
            return true;
        return false;
    }

    void Push(T *n) {
        if(IsFull())
            std::cerr << "Stack if full!\n";
        else {
            top++;
            items[top] = n;
        }
    }

    T* Pop() {
        if(IsEmpty())
            std::cerr << "Stack is empty!\n";
        else {
            T *rNode = items[top];
            items[top] = NULL; // Check!
            top--;
            return rNode;
        }
        return nullptr;
    }

    int GetSize() const { return items.size();}
};

// Binary Tree
struct bNode {
    int data;
    bool isVisited = false;
    bNode *lChild;
    bNode *rChild;
    std::tuple<bNode*, bNode*> children; // First always = left
    bNode() : data(0), lChild(nullptr), rChild(nullptr) {}
    bNode(int d) : data(d), lChild(nullptr), rChild(nullptr) {}
};

// Branch Sum
// Continue!
int CalculateBranch(bNode *n, int sum) {
    if(n->lChild != nullptr) 
        sum += n->lChild->data;
    if(n->rChild != nullptr)
        sum += n->rChild->data;
    if(n->lChild != nullptr) 
        CalculateBranch(n->lChild, sum);
    if(n->rChild != nullptr)
        CalculateBranch(n->rChild, sum);
    return sum;
}

int BranchSums(bNode *root) {
    int sum = 0;
    if(root != nullptr) {
        CalculateBranch(root, sum);
    }
    return sum;
}

// Binary Tree Depth First Search
void BinaryDepthFirstSearchIterative(bNode *n) {
    stack<bNode> s;
    if(n != nullptr) {
        if(!n->isVisited) {
            n->isVisited = true;
            s.Push(n);
        }
        while(!s.IsEmpty()) {

        }
        if(n->lChild != nullptr) {
            n->lChild->isVisited = true;
            s.Push(n->lChild);
        }
        if(n->rChild != nullptr) {
            n->rChild->isVisited = true;
            s.Push(n->rChild);
        }
    }
}

void BinaryDepthFirstSearchRecursive(bNode *n) {
    if(!n->isVisited) {
        n->isVisited = true;
        std::cout << n->data << ", ";
    }
    if(n->lChild != nullptr) 
        BinaryDepthFirstSearchRecursive(n->lChild);
    if(n->rChild != nullptr) 
        BinaryDepthFirstSearchRecursive(n->rChild);
}

// Graph
struct gNode {
    int data = 0;
    bool isVisited = false;
    std::vector<gNode> children{};

    gNode() {}
    gNode(int d) 
    {
        children.resize(d);
    }

    ~gNode() {}
};

// Depth-First Search
std::vector<bool> markedVertices{};

void DFSRecursive(gNode *n, int vertex) {
    n->isVisited = true;
    markedVertices[vertex] = true;
    for(unsigned int i = 0; i < n->children.size(); i++) {
        if(!markedVertices[i])
            DFSRecursive(&n->children[i], i);
    }
}

std::vector<bool> markedVerticesIter{};

void DFSIterative(gNode *n, int vertex) { // Fix!
    stack<gNode> s;
    s.Push(n);
    while(!s.IsEmpty()) {
        if(!markedVerticesIter[vertex]) {
            n->isVisited = true;
            markedVerticesIter[vertex] = true;
            for(unsigned int i = 0; i < n->children.size(); i++) {
                if(!markedVerticesIter[i])
                    s.Push(&n->children[i]);
            }
        }
        s.Pop();
    }
}

std::vector<int> distances{};

// Returns the longest distance between two nodes (Longest Possible Path)
int TreeDiameterIterative(bNode *root, int vertex) { // Branch == left or right | RE-DO, Invalid
    int distance = 0;
    stack<bNode> s;
    std::vector<bNode*> visitedVertices{};
    std::vector<bool> markedVerts{}; // Allocate memory equal to tree size!
    // Do depth-first search
    // Count max distance based on how far each search went, example-
        // - If one branch pushed 4 vertices to the stack and one brach pushed 5, the latter branch is larger
    s.Push(root);
    while(!s.IsEmpty() && visitedVertices.size() > 0) { // Check!
        visitedVertices.push_back(s.Pop());
        if(!markedVerts[vertex]) {
            root->isVisited = true;
            markedVerts[vertex] = true;
            if(!markedVerts[0])
                s.Push(std::get<0>(root->children));
            if(!markedVerts[1])
                s.Push(std::get<1>(root->children));
        }
    }
    return distance;
}

std::vector<int> branchLengths{};

int TreeDiameter(bNode *n, int sum) {
    n->isVisited = true;
    sum++;
    if(n->lChild == nullptr && n->rChild == nullptr) {
        branchLengths.push_back(sum);
        sum = 0;
    }
    else if(n->lChild != nullptr && !n->lChild->isVisited)
        TreeDiameter(n, sum);
    else if(n->rChild != nullptr && !n->rChild->isVisited)
        TreeDiameter(n, sum); 
}

int main() {
    gNode *a;
    gNode *b;
    gNode *c;
    gNode *d;
    gNode *e;
    gNode *f;

    // DFSRecursive(a, 0);

    bNode root(15);
    bNode n1(12);
    bNode n2(14);
    bNode n3(8);
    bNode n4(7);
    bNode n5(4);

    root.lChild = &n1;
    root.rChild = &n2;

    n1.lChild = &n3;

    n2.lChild = &n4;
    n2.rChild = &n5;

    BinaryDepthFirstSearchRecursive(&root);
    TreeDiameter(&root, 0);

    return 0;
}