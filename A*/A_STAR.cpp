#include <iostream>
#include <vector>

// A*
struct Node {
    bool visited = false;
    float global = 0.0f, local = 0.0f;
    int x, y;
    std::vector<Node*> neighbours{};
    node* parent = nullptr;
};

void A_Star(Node * start, Node * end) {
    // Search
    for(auto i : start->neighbours) {
        // Compare local
        if(!i->visited) {
            // Pythag to end
            // Set parent
            // Set local and global
        }
    }
    // Backtrack

}

void Print() {
    
}

int main() {
    Node * startNode;
    node * endNode;
    A_Star(startNode, endNode);

    return 0;
}