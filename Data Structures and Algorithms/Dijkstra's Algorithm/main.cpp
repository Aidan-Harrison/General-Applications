// Custom graph implementation > Dijkstra's Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct Vertex {
    bool visited = false;
    int data = 0;
    int dist = INT_MAX;
    std::vector<Vertex*> neighbours{};
    std::vector<const int> weights{};
    Vertex * prev = nullptr;
};

struct Graph {
    std::vector<Vertex*> graph;
};

// Dijstrka's Algorithm:
void DijstrkaAlgorithm(Graph * g, Vertex * n) {
    std::set<Vertex*> visited;
    std::queue<Vertex*> q;
    for(Vertex* i : g->graph) {
        if(i != n)
            i->dist = INT_MAX;
        q.push(i);
    }
    while(!q.empty()) {
        int cur = INT_MAX;
        Vertex * vert = q.front(); // Get minimum distance from Q, initally ALWAYS source
        q.pop();
        for(int i = 0; i < vert->neighbours.size(); i++) {
            int val = vert->dist + vert->weights[i]; // For now weight = neighbours, probably better to combine weights and neighbours into single vector
            if(val < vert->neighbours[i]->dist && !visited.contains(vert->neighbours[i])) { // Valid path
                q.push(vert->neighbours[i]);
                vert->neighbours[i]->dist = val; // Update distance
                visited.insert(vert->neighbours[i]);
            }
        }
    }
}

int main() {
    Vertex a;
    a.dist = 6;
    Vertex b;
    Vertex c;
    Vertex d;
    Vertex e;
    Vertex f;
    Graph g;
    g.graph.push_back(&a);
    g.graph.push_back(&b);
    g.graph.push_back(&c);
    g.graph.push_back(&d);
    g.graph.push_back(&e);
    g.graph.push_back(&f);

    DijstrkaAlgorithm(&g, &a);

    return 0;
}
