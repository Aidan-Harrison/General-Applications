#include <iostream>
#include <vector>
#include <queue>
struct Node {
    int data;
    bool isVisited = false;
    std::vector<Node*> children{};
    Node() {}
    ~Node() {}

    std::vector<Node*> GetChildren() { return children; }
};

std::queue<Node*> Q;

Node* BreadthFirstSearch(Node *root, int target) {
    root->isVisited = true;
    Q.push(root);
    while(!Q.empty()) {
        Node *vertex = Q.front();
        Q.pop();
        if(vertex->data == target)
            return vertex;
        for(unsigned int i = 0; i < vertex->children.size(); i++) { // Edges not vertices!
            if(!vertex->children[i]->isVisited)
                Q.push(vertex->children[i]);
        }
    }
}

int main() {


    return 0;
}