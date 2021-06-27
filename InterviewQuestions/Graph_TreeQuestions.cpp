#include <iostream>
#include <vector>
#include <tuple>

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

// Stack
std::vector<bNode*> items{};
int top = -1;

bool IsEmpty() {
    if(top == -1)
        return true;
    return false;
}

// Branch Sum
// Continue!
int CalculateBranch(bNode *n, int sum) {
    if(n != nullptr) {
        sum += n->lChild->data;
        sum += n->rChild->data;
        if(n->lChild != nullptr)
            CalculateBranch(n->lChild, sum);
        if(n->rChild != nullptr)
            CalculateBranch(n->rChild, sum);
    }
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
void BinaryDepthFirstSearch(bNode *n) { // Do Backtrack!
    if(n != nullptr) {
        if(!n->isVisited) {
            n->isVisited = true;
            items[top++] = n;
        }
        while(!IsEmpty()) {

        }
        if(n->lChild != nullptr) {
            n->lChild->isVisited = true;
            items[top++] = n->lChild;
            BinaryDepthFirstSearch(n->lChild);
        }
        if(n->rChild != nullptr) {
            n->rChild->isVisited = true;
            items[top++] = n->rChild;
            BinaryDepthFirstSearch(n->rChild);
        }
    }
}

// Graph
struct gNode {
    int data;
    bool isVisited = false;
    std::vector<gNode> children{};
    gNode()
    {
        for(auto i : children)
            i.data = 0;
    }
    gNode(int d) 
    {
        for(auto i : children)
            i.data = 0;
    }
};

// Depth-First Search
std::vector<bool> markedVertices{};

void DFSRecursive(gNode n, int vertex) { // Check!
    // Add base case
    n.isVisited = true;
    markedVertices[vertex] = true;
    for(int i = 0; i < n.children.size(); i++) {
        if(!markedVertices[i])
            DFSRecursive(n.children[i], i);
    }
}

struct stack {
    std::vector<gNode*> items{};
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

    void Push(gNode *n) {
        if(IsFull()) {
            return;
        }
        else {
            items[top++] = n;
        }
    }

    gNode* Pop() {
        if(IsEmpty())
            return;
        else {
            items[top] = NULL; // Check!
            return items[top];
            top--;
        }
    }
};

std::vector<bool> markedVerticesIter{};

void DFSIterative(gNode *n, int vertex) { // Check! Seems wrong regarding loop, should use vertex somewhere
    stack s;
    std::vector<gNode*> visitedVerts{};
    s.Push(n); // Check!
    while(!s.IsEmpty()) {
        visitedVerts.push_back(s.Pop());
        if(!markedVerticesIter[vertex]) {
            n->isVisited = true;
            markedVerticesIter[vertex] = true;
            for(int i = 0; i < n->children.size(); i++) {
                if(!markedVerticesIter[i])
                    s.Push(&n->children[i]);
            }
        }
    }
}

struct bStack {
    std::vector<bNode*> items{};
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

    void Push(bNode *n) {
        items[top++] == n;
    }

    bNode* Pop() {
        items[top] = NULL;
        top--;
    }
};

std::vector<int> distances{};

// Returns the longest distance between two nodes (Longest Possible Path)
int TreeDiameter(bNode *root, int vertex) { // Branch == left or right | RE-DO, Invalid
    int distance = 0;
    bStack s;
    std::vector<bNode*> visitedVertices{};
    std::vector<bool> markedVerts{}; // Allocate memory equal to tree size!
    // Do depth-first search
    // Count max distance based on how far each search went, example-
        // - If one branch pushed 4 vertices to the stack and one brach pushed 5, the latter branch is larger
    s.Push(root);
    while(!s.IsEmpty()) {
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
}

int main() {


    return 0;
}