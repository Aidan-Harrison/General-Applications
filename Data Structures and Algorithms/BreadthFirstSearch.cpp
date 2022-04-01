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

inline void Add(Node * base, Node * _new) {
    base->children.push_back(_new);
}

void BFS(Node * root) {
    std::queue<Node*> q;
    q.push(root);
    root->isVisited = true;
    while(!q.empty()) {
        Node * vertex = q.front();
        q.pop();
        std::cout << vertex->data << '-';
        for(auto i : vertex->children) {
            if(!i->isVisited) {
                q.push(i);
                i->isVisited = true;
            }
        }
    }
}

// Iterative
Node* BreadthFirstSearchIterative(Node * root, int target) {
    Node *nullNode = new Node(0);
    root->isVisited = true;
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

int main() {
    Node *root = new Node(5);
    Node *n1 = new Node(2);
    Node *n2 = new Node(6);
    Node *n3 = new Node(4);
    Node *n4 = new Node(9);

    Add(root,n1);
    Add(root,n2);
    Add(root,n3);

    Add(n3,n4);

    //Node *resultNode = BreadthFirstSearchIterative(root, 4);
    //std::cout << resultNode->data;
    BFS(root);

    return 0;
}