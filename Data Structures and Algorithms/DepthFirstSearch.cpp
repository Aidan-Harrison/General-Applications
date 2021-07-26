#include <iostream>
#include <list>

class Graph {
private:
    int numOfVerts;
    std::list<int> *adjVerts;
    bool *isVisited;
public:
    Graph(int verts)
        :numOfVerts(verts) 
    {
        adjVerts = new std::list<int>[verts]; // Dynamically allocate a 'stack' of integers
        isVisited = new bool[verts]; // Dynamically allocate a 'stack' of bools
    }
    void AddEdge(int start, int end);
    void DepthFirstSearch(int vertex);
};

void Graph::AddEdge(int start, int end) {
    adjVerts[start].push_front(end);
}

void Graph::DepthFirstSearch(int vertex) {
    isVisited[vertex] = true;
    std::list<int> adjVert = adjVerts[vertex];

    std::cout << vertex << " ";

    for(std::list<int>::iterator it = adjVert.begin(); it != adjVert.end(); it++)
        if(!isVisited[*it]) // If a node has been visited, recursively call and visit it
            DepthFirstSearch(*it);
}

int main() {
    Graph g(4);

    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);

    g.DepthFirstSearch(2);
    
    return 0;
}