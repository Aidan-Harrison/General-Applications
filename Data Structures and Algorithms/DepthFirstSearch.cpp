#include <iostream>
#include <list>
#include <stack>
#include <vector>

struct gNode {
    bool isVisited = false;
    char key = 'a';
    std::vector<gNode*> connectedNodes{};
    gNode() {}
    gNode(char c, const int children) 
        :key(c) 
    {
        connectedNodes.resize(children);
    }
    ~gNode() {}
};

void DepthFirstSearchIterative(gNode *n) { // CHANGE!
    std::stack<gNode*> stack;
    stack.push(n);

    while(!stack.empty()) {
        gNode* vertex = stack.top();
        vertex->isVisited = true;
        std::cout << vertex->key << " ";
        stack.pop();
        for(unsigned int i = 0; i < vertex->connectedNodes.size(); i++)
            if(!vertex->connectedNodes[i]->isVisited)
                stack.push(vertex->connectedNodes[i]);
    }
}

void DepthFirstSearchRecursive(gNode *n) {
    n->isVisited = true; 
    std::cout << n->key << " ";
    for(unsigned int i = 0; i < n->connectedNodes.size(); i++)
        if(!n->connectedNodes[i]->isVisited)
            DepthFirstSearchRecursive(n->connectedNodes[i]);
}

int main() {
    gNode root('s', 3);
    gNode n1('a', 2);
    gNode n2('d', 3);
    gNode n3('b', 2);
    gNode n4('c', 2);

    root.connectedNodes[0] = &n1;
    root.connectedNodes[1] = &n3;
    root.connectedNodes[2] = &n4;

    n1.connectedNodes[0] = &root; 
    n1.connectedNodes[1] = &n2;

    n2.connectedNodes[0] = &n1; 
    n2.connectedNodes[1] = &n3; 
    n2.connectedNodes[2] = &n4;

    n3.connectedNodes[0] = &root; 
    n3.connectedNodes[1] = &n2; 
    
    n4.connectedNodes[0] = &root;
    n4.connectedNodes[1] = &n2;

    /*=== Comment one out ===*/
    std::cout << "Iterative: ";
    DepthFirstSearchIterative(&root);
    std::cout << "\nRecrusive: ";
    // DepthFirstSearchRecursive(&root);

    return 0;
}