#include <iostream>
#include <vector>
#include <stack>

std::vector<int> generatedNames{};
std::vector<std::string> names{
    "Austin, Texas", "New York City, New York", "Denver, Colorado", "Los Angeles, California" 
};

std::string assignName() {
    return names[rand() % names.size()];
}

struct graph {
    struct node {
        std::string name = "Default Location";
        std::vector<node*> children{};
        int weight = 0;
        bool hasSuperCharger = false, visited = false;
        node() {}
    };
    
    std::vector<node*> g{};

    // Recursive
    void SubGen(node * curNode, int counter) {
        if(counter == 0)
            return;
        node * newChild;
        curNode->children.push_back(newChild);
        SubGen(newChild, counter--);
    }

    void Generate() { // Randomly generate a propogating graph
        for(int i = 0; i < 50; i++) {
            node * newNode;
            /*
            for(int i = 0; i < 3; i++) {
                node childNode;
                childNode.name = assignName();
                newNode.children.push_back(childNode);
            }
            */
            SubGen(newNode, 3);
            newNode->name = assignName();
            g.push_back(newNode);
        } 
    }

    void DFS() {
        std::stack<node*> s;
        s.push(g[0]);
        while(!s.empty()) {
            node * curNode = s.top();
            s.pop();
            std::cout << curNode->children.size();
            for(int i = 0; i < curNode->children.size(); i++) {
                if(!curNode->children[i]->visited) {
                    s.push(curNode->children[i]);
                    std::cout << s.top()->name << '\n';
                    s.top()->visited = true;
                }
            }
        }
    }

    graph() 
    {
        Generate();
    }
};

void Path(graph & g) {
    g.DFS();
}

int main() {
    graph g;
    Path(g);

    return 0;
}