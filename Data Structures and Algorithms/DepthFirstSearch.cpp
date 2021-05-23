#include <iostream>
#include <list>

class Graph {
private:
    int numOfVerts;
    std::list<int> *adjVerts;
    bool *isVisited;
public:
    Graph(int verts);
    void AddEdge(int start, int end);
    void DFS(int vertex);
};

Graph::Graph(int verts)
    :numOfVerts(verts) 
{
    adjVerts = new std::list<int>[verts]; // Dynamically allocate a 'stack' of integers
    isVisited = new bool[verts]; // Dynamically allocate a 'stack' of bools
}

void Graph::AddEdge(int start, int end) {
    adjVerts[start].push_front(end);
}

void Graph::DFS(int vertex) {
    isVisited[vertex] = true;
    std::list<int> adjVert = adjVerts[vertex];

    std::cout << vertex << " ";

    std::list<int>::iterator i;
    for(i = adjVert.begin(); i != adjVert.end(); i++)
        if(!isVisited[*i])
            DFS(*i);
}

int main() {
    Graph g(4);

    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);

    g.DFS(2);
    
    return 0;
}