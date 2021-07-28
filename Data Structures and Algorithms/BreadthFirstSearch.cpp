#include <iostream>
#include <vector>
#include <queue>
struct Node {
    int data;
    bool isVisited = false;
    std::vector<Node*> children{};
    Node() {}
    Node(int d) :data(d) {}

    std::vector<Node*> GetChildren() { return children; }

    ~Node() {}
};

std::queue<Node*> Q;

// Iterative
Node* BreadthFirstSearch(Node *root, int target) {
    Node *nullNode = new Node(0);
    root->isVisited = true;
    Q.push(root);
    Q.push(root);
    Q.push(root);
    Q.push(root);
    while(!Q.empty()) {
        std::cout << " | " << Q.size() << '\n';
        Node *vertex = Q.front();
        std::cout << vertex->data << '\n';
        Q.pop();
        if(vertex->data == target)
            return vertex;
        for(unsigned int i = 0; i < vertex->children.size(); i++) { // Edges not vertices!?
            if(!vertex->children[i]->isVisited)
                Q.push(vertex->children[i]);
        }
    }
    std::cout << "NOT FOUND!\n";
    return nullptr;
}

// Recursive
Node *BreadthFirstSearchRecursive(Node *curNode, int target) {

}

int main() {
    Node *root = new Node(5);
    Node *n1 = new Node(2);
    Node *n2 = new Node(6);
    Node *n3 = new Node(4);
    Node *n4 = new Node(9);

    Node *resultNode = BreadthFirstSearch(root, 4);
    std::cout << resultNode->data;

    return 0;
}