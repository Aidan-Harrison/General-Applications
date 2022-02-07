#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <list>
#include <stack>
#include <queue>

// Main
struct graph { // Questionable
    struct node {
        bool isVisited = false;
        char alias = 'A';
        int data = 0;
        node(const char ali = 'A', const int d = 0) : alias(ali), data(d) {}
        std::vector<node> connectedNodes{};

        void PrintChildren() {
            for(auto i : connectedNodes) {
                std::cout << i.data << "-";
            }
        }
    };

    graph() {}

    void AddVertex(node *n, char alias, int data);
    void DelVertex(char alias);
    void DisplayVertex(char alias);

    void DepthFirstSearch();
    void BreadthFirstSearch(node *root);

    ~graph() {}
};

void graph::AddVertex(node *n, char alias, int data) {
    node newNode(alias, data);
    n->connectedNodes.push_back(newNode);
}

void graph::DelVertex(char alias) {
    return;    
}

void graph::DisplayVertex(char alias) {
    return;
}

void graph::DepthFirstSearch() {
    std::stack<node*> stack;
}

void graph::BreadthFirstSearch(node *root) {
    std::queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node *vertex = q.back();
        q.pop();
        for(auto i : vertex->connectedNodes) {
            std::cout << i.data << ',';
            if(!i.isVisited) {
                i.isVisited = true;
                q.push(&i); // Check!
            }      
        }
    }
}

// Adjacency Matrix:
struct MatrixGraph {
    std::array<std::array<int, 5>, 5> adjMatrix{};

    void AddEdge(const int x, const int y, bool isDirect = false) {
        if(x == y)
            std::cerr << "Same vertex!\n";
        adjMatrix[x][y] = 1;
        if(isDirect)
            adjMatrix[y][x] = 1;
    }

    void DeleteEdge(const int x, const int y) {
        if(adjMatrix[x][y] == 0)
            std::cerr << "No edge exists!\n";
        else {
            adjMatrix[x][y] = 0;
            adjMatrix[y][x] = 0;
        }
    }

    void DisplayGraph(const int v) const {
        for(unsigned int i = 0; i < v; i++) {
            for(unsigned int j = 0; j < v; j++)
                std::cout << adjMatrix[i][j] << " ";
            putchar('\n');
        }
    }
};

// Adjacency List:
struct listNode {
    int data;
    listNode *next;
    listNode() :next(nullptr) {}
    listNode(int d) :data(d), next(nullptr) {}
    ~listNode() {}
};
struct listGraph { // Check!
    std::vector<listNode*> lists{};
    listGraph(const int size) 
    {
        lists.resize(size);
    }

    void AddVertex(const int data, int src, int dest) {        
        listNode *newNode = new listNode(data);
        newNode->next = lists[src];
        lists[src] = newNode;

        listNode *otherNode = new listNode(data); // Check!
        otherNode->next = lists[dest];
        lists[dest] = otherNode;
    }

    void PrintGraph() const {
        for(unsigned int i = 0; i < lists.size(); i++) {
            listNode *newNode = lists[i];
            while(newNode != nullptr) {
                std::cout << newNode->data << " -> ";
                newNode = newNode->next;
            }
            // delete newNode;
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

void DFSIter(gNode *n) {
    std::stack<gNode*> s;
    s.push(n);
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

void DFS(gNode *n) {
    n->isVisited = true;
    std::cout << n->data << " - ";
    for(auto i : n->children)
        if(!i->isVisited)
            DFS(i);
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

int main() {
    /*
    // Main
    graph newGraph;
    graph::node newRoot;
    newGraph.AddVertex(&newRoot, 'A', 14);
    newGraph.AddVertex(&newRoot, 'B', 12);
    newGraph.AddVertex(&newRoot, 'C', 10);
    newGraph.AddVertex(&newRoot, 'D', 8);

    newGraph.BreadthFirstSearch(&newRoot);

    // Adjacency Matrix-
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
    */

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
    std::cout << "\nDepth First Search (Iterative):\n";
    DFSIter(&root);
    std::cout << '\n' << Search(&root, 14);

    return 0;
}