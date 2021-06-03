#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <list>

// Main
struct graph {
    int top = -1;
    struct edge {
        int source, destination;
    };

    struct node {
        char alias = 'A';
        int data = 0;
        node(const char ali = 'A', const int d = 0) : alias(ali), data(d) {}
        std::vector<node> connectedNodes{};
        std::vector<node> GetConnectedNodes() const {return connectedNodes;}
        void PrintConnectedNodes();
    };

    graph(std::vector<edge> &edges, int n) 
    {
        adjacencyList.resize(n);
        for(auto &edge : edges) {
            adjacencyList[edge.source].push_back(edge.destination);
        }
    }
    // Add constructor
    std::vector<std::vector<int>> adjacencyList{};
    std::array<node, 10> vertices;

    void AddVertex(const char alias, const int data);
    void DelVertex(char alias);
    void DisplayVertex(char alias);

    void DepthFirstSearch();
    void BreadthFirstSearch();
};

void graph::AddVertex(const char alias, const int data) { // Do!
    graph::node newNode(alias, data);
}

void graph::DelVertex(char alias) { // Do properly, use 'delete'?
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

void graph::DepthFirstSearch() {
    return;
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

// Adjacency List:
struct node {
    int data = 0;
    node* next;
};

class listGraph {
private:
    int numOfVerts;
    std::list<int> *adjLists;
public:
    listGraph(const int v)
        :numOfVerts(v) 
    {
    }
    void AddEdge(int src, int dest);
    void Display() const;
};

void listGraph::AddEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void listGraph::Display() const {
    
}

// Depth First Search | Pure stack?
struct stack {
    std::array<int, 10> adjList;
    bool visited[10];
    int top = -1;
};
stack *st;

void DepthFirstSearch(int s) { // Starting node | Continue!  
    st->visited[s] = true;
    for(unsigned int i = 0; i < st->adjList.size(); i++) {
        if(st->visited[st->adjList[i]] == false) {
            DepthFirstSearch(st->adjList[s]);
        }
    }
}

// Breadth First Search


int main() {
    // Adjacency Matrix-
    int vertexCount = 5; 
    AddEdge(0,3);
    AddEdge(0,4);
    AddEdge(1,2);
    AddEdge(1,5);
    AddEdge(2,4);
    AddEdge(2,3);
    DisplayGraph(vertexCount);

    // Adjacency List-
    listGraph g(5);
    g.AddEdge(0,3);
    g.AddEdge(0,3);
    g.AddEdge(1,2);
    g.AddEdge(1,5);
    g.AddEdge(2,4);

    return 0;
}