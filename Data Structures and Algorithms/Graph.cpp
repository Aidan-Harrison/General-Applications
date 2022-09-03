#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <list>
#include <stack>
#include <queue>

/*
    Implementations of the Graph data structure
*/

// Adjacency Matrix:
struct MatrixGraph {
    std::array<std::array<int, 5>, 5> adjMatrix{};
    std::vector<int> adjMat{};
    int width{}, height{};

    void AddEdge(const int x, const int y, bool isDirect = false) {
        if(x == y) {
            std::cout << "Same vertex!\n";
            return;
        }
        adjMatrix[x][y] = 1;
        if(isDirect)
            adjMatrix[y][x] = 1;
    }

    void AddEdgeO(const int x, const int y, bool isDirect = false) {
        if(x == y)
            return;
        adjMat[x + y * width] = 1;
        if(isDirect)
            adjMat[y + x * width] = 1;
    }

    void DeleteEdge(const int x, const int y, bool isDirect = false) {
        if(adjMatrix[x][y] == 0) {
            std::cout << "No edge exists!\n";
            return;
        } else if(x == y) {
            std::cout << "Same vertex!\n";
            return;
        }
        adjMatrix[x][y] = 0;
        if(isDirect)
            adjMatrix[y][x] = 0;
    }

    void DisplayGraph() const {

    }

    void DFS(int start, std::vector<bool> visited) {
        visited[start] = true;
        std::cout << start << '-';
        for(int i = 0; i < adjMatrix[start].size(); i++) {
            if(adjMatrix[start][i] == 1 && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    void DFS(std::pair<int,int> & pos, std::pair<int,int> & target) { // Iterative conversion

    }

    MatrixGraph(int rows, int cols) 
        :height(rows), width(cols)
    {
        adjMat.resize(height * width);
    }
};

// Weighted Adjacency Matrix
struct wMatrix {
    std::vector<std::vector<int>> w_Mat{};
    void Add(const int x, const int y, const int weight, bool isDirect = false) {
        if(x == y)
            return;
        w_Mat[x][y] = weight;
        if(isDirect)
            w_Mat[y][x] = weight;
    }
    void Delete(const int x, const int y, bool isDirect = false) {
        if(w_Mat[x][y] == 0) {
            std::cout << "Invalid!";
            return;
        }
        w_Mat[x][y] = 0;
        if(isDirect) {
            w_Mat[y][x] = 0;
        }
    }
};

// Adjacency List:
struct listNode {
    int data;
    bool visited = false;
    listNode * next;
    listNode() :next(nullptr), data(0) {}
    listNode(const int d) :data(d), next(nullptr) {}
};

struct listGraph {
    std::vector<listNode*> graph{};
    listGraph() {}
    listGraph(const int size) 
    {
        graph.resize(size); // Should initialise as nullptr
    }

    void Add(int index, listNode * vertex = nullptr) {
        if(index > graph.size())
            return;
        /*
        if(vertex != nullptr) {
            listNode * newList = new listNode;
            graph.push_back(newList);
        }
        */
        // Get vertex in list, add to linked list
        if(graph[index] != nullptr)
            graph[index]->next = vertex;
        else
            graph[index] = vertex;
    }

    void Print() const {
        for(int i = 0; i < graph.size(); i++) {
            listNode * traverseNode = graph[i];
            while(traverseNode != nullptr) {
                std::cout << traverseNode->data << "->";
                traverseNode = traverseNode->next;
            }
            putchar('\n');
        }
    }

    bool has(const int vertex, listNode & c_Vertex) const {
        listNode * traverseNode = graph[vertex];
        while(traverseNode != nullptr) {
            if(traverseNode = &c_Vertex) // Check!
                return true;
            traverseNode = traverseNode->next;
        }
        delete traverseNode;
        return false;
    }

    void DFS() { // Fix and improve!
        std::stack<listNode*> s{};
        s.push(graph[0]);
        graph[0]->visited = true;
        while(!s.empty()) {
            listNode * curVertex = s.top();
            s.pop();
            listNode * traverseNode = curVertex;
            while(traverseNode != nullptr) {
                if(!traverseNode->visited)
                    traverseNode->visited = true;
                    s.push(traverseNode);
                traverseNode = traverseNode->next;
            }
        }
    }

    void AddVertex(const int data, int src, int dest) { // ??  | Re-do
        listNode * newNode = new listNode(data);
        newNode->next = graph[src];
        graph[src] = newNode;

        listNode *otherNode = new listNode(data);
        otherNode->next = graph[dest];
        graph[dest] = otherNode;
    }

    void AddVert(const int data, int loc = 0, int dest = 0, bool isDirected = false) { // Re-write
        listNode * newNode = new listNode(data);
        graph[loc]->next = newNode;
        if(!isDirected) {
            graph[dest]->next = newNode;
        }
    }

    void PrintGraph() const {
        for(unsigned int i = 0; i < graph.size(); i++) {
            listNode * newNode = graph[i];
            while(newNode != nullptr) {
                std::cout << newNode->data << " -> ";
                newNode = newNode->next;
            }
            delete newNode;
        }
    }

    virtual ~listGraph() {}
};

void PrintGraph(std::vector<int> graph[], int v) {
    for(unsigned int i = 0; i < v; i++) {
        for(auto i : graph[v])
            std::cout << " -> " << i;
        putchar('\n');
    }
}

// Adjacency List 2
void AddEdge(std::vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

// Print the graph
void PrintGraph2(std::vector<int> adj[], int verts) {
    for(unsigned int i = 0; i < verts; i++) {
        std::cout << "Vertex " << i << "| ";
        for(auto x : adj[i])
            std::cout << "->" << x;
        putchar('\n');
    }
}

// Node Based
struct gNode {
    bool isVisited = false;
    int data = 0;
    std::vector<gNode*> children{};

    gNode(const int d) :data(d) {}
    ~gNode() {}
};

void Insert(gNode *n, int data) {
    gNode *newNode = new gNode(data);
    n->children.push_back(newNode);
}

// Depth First Search Iterative
void DFSIter(gNode *n) {
    std::stack<gNode*> s;
    s.push(n);
    n->isVisited = true;
    std::cout << n->data << '-';
    while(!s.empty()) {
        gNode *cur = s.top();
        s.pop();
        for(auto i : cur->children) {
            if(!i->isVisited) {
                std::cout << i->data << '-';
                i->isVisited = true;
                s.push(i);
            }
        }
    }
}

// Depth First Search Recursive
void DFS(gNode *n) {
    n->isVisited = true;
    std::cout << n->data << " - ";
    for(auto i : n->children)
        if(!i->isVisited)
            DFS(i);
}

int pathLength = 0;
std::vector<int> pathLengths{};

void FindPathLengths(gNode *n) { // Continue?
    n->isVisited = true;
    if(n->children.size() == 0) { // End of path
        pathLengths.push_back(pathLength);
        pathLength = 0;
    }
    else {
        for(auto i : n->children) {
            if(!i->isVisited) {
                pathLength++;
                FindPathLengths(i);
            }
        }
    }
}

void Unvisit(gNode *n) {
    n->isVisited = false;
    for(unsigned int i = 0; i < n->children.size(); i++) {
        if(n->children[i]->isVisited)
            DFS(n->children[i]);
    } 
}

bool Search(gNode *n, const int data) {
    if(n->data == data)
        return true;
    n->isVisited = true;
    for(auto i : n->children)
        if(!i->isVisited)
            Search(i, data);
    return false;
}

// Breadth First Search
void BFS(gNode *n) {
    std::queue<gNode*> q;
    q.push(n);
    std::cout << n->data << '-';
    n->isVisited = true;
    while(!q.empty()) {
        gNode *vertex = q.front();
        q.pop();
        for(auto i : vertex->children) {
            if(!i->isVisited) {
                std::cout << i->data << '-';
                i->isVisited = true;
                q.push(i);
            }
        }
    }
}

// Weighted Graph
struct wgNode {
    bool isVisited = false;
    int data = 0;
    std::vector<wgNode*> vertices{};
    std::vector<int> weights{};
    wgNode(const int d)
        :data(d)
    {
    }
};

void AddEdgeWeighted(wgNode * a, wgNode * b, const int weight, bool directed = false) {
    a->vertices.push_back(b);
    a->weights.push_back(weight);
    if(!directed) {
        b->vertices.push_back(a);
        b->weights.push_back(weight);
    }
}

template<typename T>
T Search(wgNode * cur, wgNode * target, char type = 'N') {
    cur->isVisited = true;
    for(int i = 0; i < cur->vertices.size(); i++) {
        if(cur->vertices[i] == target) {
            switch(type) {
                case 'N': return target; break;
                case 'P': return i; break;
                case 'F': return true; break;
            }
            if(type == 'N')
                return target;
        }
        else {
            if(!cur->vertices[i]->isVisited) {
                Search(cur->vertices[i], target, type);
            }
        }
    }
    return false; // Needed?
}

int Search(wgNode * cur, wgNode * target) {
    cur->isVisited = true;
    for(int i = 0; i < cur->vertices.size(); i++) {
        if(cur->vertices[i] == target)
            return i;
        else
            if(!cur->vertices[i]->isVisited)
                Search(cur->vertices[i], target);
    } 
    return 0;
}

void RemoveEdge(wgNode * a, wgNode * b) {
    // Find which vertex b is equal to
    // > Run search for B
    // Check if vertex is connected
    bool found = false;
    for(auto i : a->vertices)
        if(i == b)
            found = true;
    if(found)
        a->vertices.erase(a->vertices.begin() + Search(a, b));
    else
        std::cout << "Given nodes are invalid!\n";
}

void PrintGraph(wgNode * n) {
    n->isVisited = true;
    std::cout << n->data << '-';
    for(int i = 0; i < n->vertices.size(); i++) {
        if(!n->vertices[i]->isVisited) {
            n->vertices[i]->isVisited = true;
            PrintGraph(n->vertices[i]);
        }
    }
}

// Given a graph, find the vertex with the smallest value
int Node_FindSmallest(gNode * n) {
    int smallestVal = INT_MAX;
    std::stack<gNode*> s;
    s.push(n);
    n->isVisited = true;
    while(!s.empty()) {
        gNode * vert = s.top();
        s.pop();
        for(gNode * v : vert->children) {
            if(!v->isVisited) {
                s.push(v);
                v->isVisited = true;
                if(v->data < smallestVal)
                    smallestVal = v->data;
            }
        }
    }
    return smallestVal;
}

void Matrix_FindSmallest(std::vector<std::vector<int>> &graph) {

}

void List_FindSmallest(listGraph &g) {
    
}

int main() {
    // Adjacency Matrix-
    /*
    std::cout << "\nAdjacency Matrix:\n";
    int vertexCount = 5; 
    MatrixGraph mGraph;
    mGraph.AddEdge(0,3);
    mGraph.AddEdge(0,4, true);
    mGraph.AddEdge(1,2, true);
    mGraph.AddEdge(1,5, true);
    mGraph.AddEdge(2,4);
    mGraph.AddEdge(2,3);
    mGraph.DisplayGraph(vertexCount);
    std::vector<bool> visited(5, false);
    mGraph.DFS(0, visited);

    // Adj Matrix Other -
    int n = 5, u, v, m;
    // std::cin >> n;
    int A[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            A[i][j] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // std::cin >> u >> v;
            A[u][v] = 1;
            A[v][u] = 1; // Remove if directed
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << A[i][j] << ", ";
        }
        putchar('\n');
    }
    
    // Set-

    // Adjacency List- | Check
    std::cout << "\nAdjacency List:\n";
    listGraph g(5);
    g.AddVertex(5, 0, 3);
    g.AddVertex(7, 0, 4);
    g.AddVertex(2, 1, 2);
    g.AddVertex(1, 1, 5);
    g.PrintGraph();

    // Adjacency List 2 -
    std::cout << "\nAdjacency List 2:\n";
    std::vector<int> adjList[5];

    AddEdge(adjList, 0, 1);
    AddEdge(adjList, 0, 2);
    AddEdge(adjList, 0, 3);
    AddEdge(adjList, 1, 2);
    PrintGraph2(adjList, 5);

    // Adjacency List 3 -
    std::cout << "\nAdjacency List 3:\n";
    int jacenN = 5, jacenU, jacenV;
    std::vector<std::vector<int>> jacenList(jacenN);
    for(int i = 0; i < n; i++) {
        std::cin >> jacenU >> jacenV;
        jacenList[jacenU].push_back(jacenV);
        jacenList[jacenV].push_back(jacenU); // Remove for directed
    }
    for(int i = 0; i < jacenList.size(); i++) {
        std::cout << "---> ";
        for(int j = 0; j < jacenList[i].size(); j++) 
            std::cout << jacenList[i][j] << " --->";
        putchar('\n');
    }

    // Node Based
    std::cout << "\nPurely Node Based:\n";
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

    //std::cout << "\nDepth First Search (Recursive):\n"; // Comment out which one you don't want | Fix unvisit
    //DFS(&root);

    //std::cout << "\nDepth First Search (Iterative):\n";
    //DFSIter(&root);

    std::cout << "Breadth First Search (Iterative):\n";
    BFS(&root); 
    */

    // std::cout << '\n' << Search(&root, 14);

    // Weighted Graph:
    std::cout << "Weighted Graph:\n";
    wgNode root(6);
    wgNode w1(3);
    wgNode w2(9);
    wgNode w3(12);
    wgNode w4(18);
    wgNode w5(24);

    AddEdgeWeighted(&root, &w1, 1, false);
    AddEdgeWeighted(&w1, &w2, 2, true);
    AddEdgeWeighted(&w2, &w3, 1, true);
    AddEdgeWeighted(&w3, &w4, 4, false);

    PrintGraph(&root);

    return 0;
}