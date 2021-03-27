// Custom graph implementation / Dijkstra's Algorithm
#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
class graph {
public:
    struct vertex {
        T data{0};
    };
    struct edge {
        vertex* vert1, vert2;
    };
    short counter = 0;
    int m_amountOfVerts = 2;
    bool loops = false, single = false; // Has all vertices connected to one another | Vertices only have 1-2 connections
    std::vector<vertex> totalVertices = {};
    std::vector<edge> totalEdges = {};
    // System Functions:  =================================================================================
    void SysCreateGraph(int amountOfVerts) {
        return;
    }
    void UserCreateGraph(std::vector<T> &data) { // Review
        if(data.size() != totalVertices.size()) {
            std::cerr << "Inputted data does not match size of total amount of vertices\n";
            exit(1);
        }
        else {
            vertex newVert;
            edge newEdge;
            for(unsigned int i = 0; i < totalVertices.size(); i++) {
                newVert.data = data[i]; // Change
            }
            while(counter != m_amountOfVerts) {
                totalVertices.push_back(newVert);
                counter++;
                if(counter % totalVertices.size() == 2) { // Support odd as well
                    newEdge->vert1 = newVert;
                    newEdge->vert2 = newVert; // Fix
                    totalEdges.push_back(newEdge);
                }
                UserCreateGraph(); // Do better recursion
            }
        }
    }
    void AddVert(short data, short location) { // Do defaults?
        vertex newVert;
        newVert.data = data;
        for(int i = 0; i < totalVertices.size(); i++) {
            if(i == location)
                totalVertices[i].insert(newVert);
        }
    } 
    void PrintGraph() {  // Prints edges along with all their connected vertices
        std::cout << "Vertices:\n";
        for(unsigned int i = 0; i < totalVertices.size(); i++) {
            std::cout << i << " : " << totalVertices[i].data << '\n';
        }
        std::cout << "Edges:\n"; // Do
        for(unsigned int i = 0; i < totalEdges.size(); i++) {
            std::cout << "Edge: " << "{ " << totalEdges[i]->vert1 << " , " << totalEdges[i]->vert2 << " }\n";
        }
    }
    void DestroyGraph(graph g) {
        for(unsigned int j = totalEdges.size(); j >= 0; j--) { // Check which method to use!
            delete totalEdges[i]->vert1;
            delete totalEdges[i]->vert2;
            delete totalEdges[i];
        }
        delete g;
    }
    // User Functions: ==============================================================================
    vertex SearchVert(const short data) const {
        for(unsigned int i = 0; i < totalVertices.size(); i++) {
            if(data == totalVertices[i].data)
                return totalVertices[i];
        }
        std::cout << "Could not find specified vertex\n";
        return nullptr;
    }
    graph ReplaceVert(graph &g, vertex &v, T data) {
        for(unsigned int i = 0; i < totalVertices.size(); i++) { // Get working with edges
            if(v.data == totalVertices[i].data)
                totalVertices[i].data = data;
        }
        return g; // Check!
    }
    graph ReplaceEdge(int edgeToReplace, vertex &newVert1, vertex &newVert2) { // Check!
        for(unsigned int i = 0; i <= totalEdges.size(); i++) {
            if(edgeToReplace == i) {
                totalEdges[i]->vert1 = newVert1;
                totalEdges[i]->vert2 = newVert2;
            }
        }
    } // Reorder edges without altering vertices
    graph ReplaceVert(int vertToReplace) {
        return;
    }
    graph(int vertCount = 2, bool isLooped = false, bool isSingle = false)
        :m_amountOfVerts(vertCount), loops(isLooped), single(isSingle)
    {
        assert(m_amountOfVerts != 0);
        SysCreateGraph(m_amountOfVerts);
    }
    ~graph() { // Improve?
        DestroyGraph();
    }
};

int main() {
    return 0;
}

// Dijstrka's Algorithm:
void DijstrkaAlgorithm() {
    return;
}