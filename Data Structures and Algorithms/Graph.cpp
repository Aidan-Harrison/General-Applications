#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <list>

// Main
struct graph {
    std::vector<bool> isVisited{};
    int top = -1;
    struct edge {
        int source, destination;
    };

    struct node {
        char alias = 'A';
        int data = 0;
        node(const char ali = 'A', const int d = 0) : alias(ali), data(d) {}
        std::vector<node> connectedNodes{};
        void PrintConnectedNodes(); // ?
    };

    std::vector<std::vector<int>> adjacencyList{};
    std::array<node, 10> vertices;

    graph(std::vector<edge> &edges, int n) 
    {
        adjacencyList.resize(n);
        for(auto &edge : edges)
            adjacencyList[edge.source].push_back(edge.destination);
    }

    void AddVertex(const char alias, const int data);
    void DelVertex(char alias);
    void DisplayVertex(char alias);

    void DepthFirstSearch();
    void BreadthFirstSearch();
};

void graph::AddVertex(const char alias, const int data) { // Do!
    node newNode(alias, data);
}

void graph::DelVertex(char alias) { // RE-DO
    for(unsigned int i = 0; i <= vertices.size(); i++) {
        if(alias == vertices[i].alias)
            vertices[i].data = 0;
    }
}

void graph::DisplayVertex(char alias) {
    for(unsigned int i = 0; i <= vertices.size(); i++)
        std::cout << vertices[i].alias << '|' <<  vertices[i].data;
}

void graph::node::PrintConnectedNodes() {
    for(unsigned int i = 0; i <= connectedNodes.size(); i++)
        std::cout << connectedNodes[i].alias << '|' << connectedNodes[i].data << ", ";
}

void graph::BreadthFirstSearch() {
    return;
}

// Adjacency Matrix:
std::array<std::array<short, 20>, 20> adjMatrix{};

void AddEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void DisplayGraph(const int v) {
    for(unsigned int i = 0; i < v; i++) {
        for(unsigned int j = 0; j < v; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        putchar('\n');
    }
}

// Set
class setGraph {
    setGraph() {}
    // std::set<int> graph;

    /*
    void AddEdge(const int v1, const int v2) {
        graph.insert(v1,v2);
    }
    */

    void PrintGraph(const int v) const {

    }

    ~setGraph() {}
};

// Adjacency List: | Directed (Singly-Linked)
struct listNode {
    int data;
    listNode *next;
    listNode() :next(nullptr) {}
    listNode(int d) :data(d), next(nullptr) {}
    ~listNode() {}
};

struct adjList {
    listNode *head;
};

struct listGraph { // Check!
    adjList *root;
    int SIZE;
    std::vector<adjList*> lists{};

    listGraph(const int size) 
        :SIZE(size)
    {
        lists.resize(size);
    }

    void AddVertex(const int data, int src, int dest) {        
        listNode *newNode = new listNode(data);
        newNode->next = lists[src]->head;
        lists[src]->head = newNode;
    }

    void PrintGraph() const {
        for(unsigned int i = 0; i < lists.size(); i++) {
            listNode *newNode = lists[i]->head;
            while(newNode != nullptr) {
                std::cout << newNode->data << " -> ";
                newNode-newNode->next;
            }
            delete newNode;
        }
    }
};

void PrintGraph(std::vector<int> graph[], int v) {
    for(unsigned int i = 0; i < v; i++) {
        for(auto i : graph[v])
            std::cout << " -> " << i;
        putchar('\n');
    }
}

// Node Based
struct gNode {
    bool isVisited = false;
    int data = 0;
    std::vector<gNode*> children{};

    gNode(int d) :data(d) {}
    ~gNode() {}
};

void Insert(gNode *n, int data) {
    gNode newNode(data);
    n->children.push_back(&newNode);
}

void DFS(gNode *n) {
    n->isVisited = true;
    std::cout << n->data << " - ";
    for(unsigned int i = 0; i < n->children.size(); i++) {
        if(!n->children[i]->isVisited)
            DFS(n->children[i]);
    }
}

bool Search(gNode *n, const int data) {
    std::cout << data;
    if(n->data == data)
        return true;
    else {
        n->isVisited = true;
        for(unsigned int i = 0; i < n->children.size(); i++) {
            if(!n->children[i]->isVisited)
                Search(n->children[i], data);
        }
    }
    return false;
}

int main() {
    // Adjacency Matrix-
    std::cout << "Adjacency Matrix:\n";
    int vertexCount = 5; 
    AddEdge(0,3);
    AddEdge(0,4);
    AddEdge(1,2);
    AddEdge(1,5);
    AddEdge(2,4);
    AddEdge(2,3);
    DisplayGraph(vertexCount);

    // Set-

    // Adjacency List-
    std::cout << "Adjacency List:\n";
    listGraph g(5);
    g.AddVertex(5, 0, 3);
    g.AddVertex(7, 0, 4);
    g.AddVertex(2, 1, 2);
    g.AddVertex(1, 1, 5);
    g.PrintGraph();

    // Node Based
    std::cout << "Purely Node Based:\n";
    putchar('\n');
    gNode root(4);
    gNode n1(7);
    gNode n2(9);
    gNode n3(11);
    gNode n4(14);
    gNode n5(1);

    root.children.push_back(&n1);
    root.children.push_back(&n2);

    n1.children.push_back(&n2);
    n1.children.push_back(&n3);

    n2.children.push_back(&n4);
    n2.children.push_back(&n5);

    DFS(&root);
    putchar('\n');
    std::cout << Search(&root, 14);

    return 0;
}