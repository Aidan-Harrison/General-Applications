#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>

template<typename T>
struct stack {
    std::vector<T*> items{};
    int top = -1;

    bool IsFull() {
        if(top == items.size())
            return true;
        return false;
    }

    bool IsEmpty() {
        if(top == -1)
            return true;
        return false;
    }

    void Push(T *n) {
        if(IsFull())
            std::cerr << "Stack if full!\n";
        else {
            top++;
            items[top] = n;
        }
    }

    T* Pop() {
        if(IsEmpty())
            std::cerr << "Stack is empty!\n";
        else {
            T *rNode = items[top];
            items[top] = NULL; // Check!
            top--;
            return rNode;
        }
        return nullptr;
    }

    int GetSize() const { return items.size();}
};

// Binary Tree
struct bNode {
    int data;
    bool isVisited = false;
    bNode *lChild;
    bNode *rChild;
    bNode() : data(0), lChild(nullptr), rChild(nullptr) {}
    bNode(int d) : data(d), lChild(nullptr), rChild(nullptr) {}
};

// Branch Sums
int CalculateBranch(bNode *n, int runningSum, std::vector<int> sums) { // Wrong! Assumes every node has two children
    if(n == nullptr)
        return 0;
    else {
        int newRunningSum = runningSum + n->data;
        if(n->lChild == nullptr && n->rChild == nullptr)
            sums.push_back(newRunningSum);
        else {
            CalculateBranch(n->lChild, newRunningSum, sums);
            CalculateBranch(n->rChild, newRunningSum, sums);
        }
    }
    return -1;
}

std::vector<int> BranchSums(bNode *root) {
    std::vector<int> sums{};
    CalculateBranch(root, 0, sums);
    return sums;
}

// Binary Tree Depth First Search
void BinaryDepthFirstSearchIterative(bNode *n) { // Re-do | Looks completely wrong
    stack<bNode> s;
    if(n != nullptr) {
        if(!n->isVisited) {
            n->isVisited = true;
            s.Push(n);
        }
        while(!s.IsEmpty()) {

        }
        if(n->lChild != nullptr) {
            n->lChild->isVisited = true;
            s.Push(n->lChild);
        }
        if(n->rChild != nullptr) {
            n->rChild->isVisited = true;
            s.Push(n->rChild);
        }
    }
}

void BinaryDepthFirstSearchRecursive(bNode *n) {
    if(!n->isVisited) {
        n->isVisited = true;
        std::cout << n->data << ", ";
    }
    if(n->lChild != nullptr) 
        BinaryDepthFirstSearchRecursive(n->lChild);
    if(n->rChild != nullptr) 
        BinaryDepthFirstSearchRecursive(n->rChild);
}

void BinaryBreadthFirstIterative(bNode *n) {

}

void BinaryBreadthFirstRecursive(bNode *n) {

}

// Graph
struct gNode {
    int data = 0;
    bool isVisited = false;
    std::vector<gNode*> children{};

    gNode() {}
    gNode(const int d = 1) 
        :data(d)
    {
    }

    // Copy Constructor
    gNode(gNode &other)
    {
        children = other.children;
    }

    ~gNode() {}
};

// Depth-First Search
std::vector<bool> markedVertices{};

void DFSRecursive(gNode *n, int vertex) {
    n->isVisited = true;
    markedVertices[vertex] = true;
    for(unsigned int i = 0; i < n->children.size(); i++) {
        if(!markedVertices[i])
            DFSRecursive(n->children[i], i);
    }
}

std::vector<bool> markedVerticesIter{};

void DFSIterative(gNode *n, int vertex) { // Fix!
    stack<gNode> s;
    s.Push(n);
    while(!s.IsEmpty()) {
        if(!markedVerticesIter[vertex]) {
            n->isVisited = true;
            markedVerticesIter[vertex] = true;
            for(unsigned int i = 0; i < n->children.size(); i++) {
                if(!markedVerticesIter[i])
                    s.Push(n->children[i]);
            }
        }
        s.Pop();
    }
}

std::vector<int> distances{};

// Returns the longest distance between two nodes (Longest Possible Path)
int TreeDiameterIterative(bNode *root, int vertex) { // Branch == left or right | RE-DO, Invalid
    int distance = 0;
    stack<bNode> s;
    std::vector<bNode*> visitedVertices{};
    std::vector<bool> markedVerts{}; // Allocate memory equal to tree size!
    // Do depth-first search
    // Count max distance based on how far each search went, example-
        // - If one branch pushed 4 vertices to the stack and one branch pushed 5, the latter branch is larger
    s.Push(root);
    while(!s.IsEmpty() && visitedVertices.size() > 0) { // Check!
        visitedVertices.push_back(s.Pop());
        if(!markedVerts[vertex]) {
            root->isVisited = true;
            markedVerts[vertex] = true;
            if(!markedVerts[0])
                s.Push(root->lChild);
            if(!markedVerts[1])
                s.Push(root->rChild);
        }
    }
    return distance;
}

std::vector<int> branchLengths{};

int TreeDiameter(bNode *n, int sum) { // ?
    n->isVisited = true;
    sum++;
    if(n->lChild == nullptr && n->rChild == nullptr) {
        branchLengths.push_back(sum);
        sum = 0;
    }
    else if(n->lChild != nullptr && !n->lChild->isVisited)
        TreeDiameter(n, sum);
    else if(n->rChild != nullptr && !n->rChild->isVisited)
        TreeDiameter(n, sum); 
    return -1;
}

int TreeDiameterNew(bNode *n, int sum) {
    int distance = 0;
    return distance;
}

// Graph blip
    // Almost done, just get values of children from return!
gNode* FindVertex(gNode *n, const int value) {
    if(n->data == value)
        return n;
    n->isVisited = true;
    for(unsigned int i = 0; i < n->children.size(); i++) {
        if(!n->children[i]->isVisited) 
            FindVertex(n->children[i], value);
    }
    return n;
}

void Blip(gNode *root, const int value) {
    // Find any connected vertices
        // Blip any connected verties
    gNode *blipVert = FindVertex(root, value); // Move semantics instead of copy!!
    if(blipVert == nullptr) {
        std::cout << "No suitable vertex found!\n";
        return;
    }
    for(unsigned int i = 0; i < blipVert->children.size(); i++) {
        // blipVert->children[i]->data++;
        std::cout << "\nB: " << blipVert->children[i]->data++<< ',';
    }
}

void UnvisitGraph(gNode *n) {
    n->isVisited = false;
    for(unsigned int i = 0; i < n->children.size(); i++) {
        if(n->children[i]->isVisited)
            UnvisitGraph(n->children[i]);
    }
}

void PrintGraph(gNode *n) {
    std::cout << n->data << ", ";
    n->isVisited = true;
    for(unsigned int i = 0; i < n->children.size(); i++) {
        if(!n->children[i]->isVisited)
            PrintGraph(n->children[i]);
    }
}

// Swap Vertices
void Swap(gNode *n1, gNode *n2) {
    int temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

int Islands(std::vector<std::vector<int>> &islands) {
    int w = islands[0].size();
    int h = islands.size();
    int answer = 0;
    std::vector<std::pair<int,int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    std::vector<std::vector<bool>> visited{};
    visited.resize(islands.size());
    for(int i = 0; i < islands.size(); i++)
        visited[i].resize(islands[0].size());
    auto inside = [&](int x, int y) { // Bounds check
        return 0 <= x && x <= w && 0 <= y && y <= h;
    };
    for(int row = 0; row < islands.size(); row++) {
        for(int col = 0; col < islands[0].size(); col++) {
            if(!visited[row][col] && islands[row][col] == 1) {
                answer++;
                std::queue<std::pair<int,int>> q;
                q.push(std::pair<int,int>{row,col}); // Check if std::pair is needed!
                visited[row][col] = true;
                while(!q.empty()) {
                    std::pair<int,int> pos = q.front();
                    q.pop();
                    for(std::pair<int,int> dir : directions) {
                        int new_row = pos.first + dir.first;
                        int new_col = pos.second + dir.second;
                        if(inside(new_row, new_col) && !visited[new_row][new_col] && islands[new_row][new_col] == 1) {
                            q.push({new_row,new_col});
                            visited[new_row][new_col] = true;
                        }
                    }
                }
            }
        }
    }
    return answer;
}

// Paint bucket tool
void FloodFill(std::vector<std::vector<char>> &canvas, const int x, const int y, const char colour) {
    int w = canvas[0].size();
    int h = canvas.size();
    std::vector<std::pair<int,int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    std::vector<std::vector<bool>> visited{};
    visited.resize(canvas.size());
    for(int i = 0; i < canvas.size(); i++)
        visited[i].resize(canvas[0].size());
    auto inside =[&](int x, int y) {
        return 0 <= x && x <= w && 0 <= y && y <= h;
    };
    for(int row = 0; row < canvas.size(); row++) {
        for(int col = 0; col < canvas[0].size(); col++) {
            if(row == x && col == y && !visited[row][col]) {
                char selectedCol = canvas[row][col];
                std::queue<std::pair<int,int>> q;
                q.push({row,col});
                visited[row][col] = true;
                canvas[row][col] = colour;
                while(!q.empty()) {
                    std::pair<int,int> pos = q.front();
                    q.pop();
                    for(std::pair<int,int> dir : directions) {
                        int new_row = pos.first + dir.first;
                        int new_col = pos.second + dir.second;
                        if(inside(new_row,new_col) && !visited[new_row][new_col] && canvas[new_row][new_col] == selectedCol) {
                            q.push({new_row, new_col});
                            visited[new_row][new_col] = true;
                            canvas[new_row][new_col] = colour;
                        }
                    }
                }
            }
        }
    }
}

// Standard flood fill, excepts fills then swaps colours with nearest other color from source
void SwapNearest(std::vector<std::vector<char>> &canvas, char colToSwap, char col) {
    int h = canvas.size();
    int w = canvas[0].size();
    char charToStore = 'a', storedCol = 'a'; // Used for swapping
    std::pair<int,int> storedPos;
    std::vector<std::vector<bool>> visited{};
    visited.resize(canvas.size());
    for(int i = 0; i < canvas.size(); i++)
        visited[i].resize(canvas[0].size());
    std::vector<std::pair<int,int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    auto boundsCheck =[&](int x, int y) {
        return 0 <= x && x <= w && 0 <= y && y <= h;
    };
    // DFS
    for(int row = 0; row < canvas.size(); row++) {
        for(int col = 0; col < canvas[0].size(); col++) {
            std::stack<std::pair<int,int>> s;
            s.push({row,col});
            visited[row][col] = true;
            while(!s.empty()) {
                std::pair<int,int> pos = s.top();
                s.pop();
                for(std::pair<int,int> dir : directions) {
                    int newRow = pos.first + dir.first;
                    int newCol = pos.second + dir.second;
                    if(boundsCheck(newRow, newCol) && !visited[newRow][newCol] && canvas[newRow][newCol] == colToSwap) {
                        s.push({newRow,newCol});
                        visited[newRow][newCol] = true;
                        canvas[newRow][newCol] = col;
                    }
                    else if(boundsCheck(newRow, newCol) && !visited[newRow][newCol] && canvas[newRow][newCol] != colToSwap) {
                        // Swap
                        char temp = col;
                        col = colToSwap;
                        colToSwap = temp;
                        storedPos = {newRow, newCol};
                        s.push({newRow,newCol});
                        visited[newRow][newCol] = true;
                        canvas[newRow][newCol] = col;
                    }
                }
            }
        }
    }
}

void PrintMatrix(std::vector<std::vector<char>> &matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++)
            std::cout << matrix[i][j] << ' ';
        putchar('\n');
    }
}

int main() {
    /*
    gNode a(4);
    gNode b(6);
    gNode c(4);
    gNode d(14);
    gNode e(24);
    gNode f(5);

    a.children.push_back(&b);
    a.children.push_back(&c);
    a.children.push_back(&d);

    b.children.push_back(&e);
    e.children.push_back(&f);

    // DFSRecursive(a, 0);

    bNode root(15);
    bNode n1(12);
    bNode n2(14);
    bNode n3(8);
    bNode n4(7);
    bNode n5(4);

    root.lChild = &n1;
    root.rChild = &n2;

    n1.lChild = &n3;

    n2.lChild = &n4;
    n2.rChild = &n5;

    // BinaryDepthFirstSearchRecursive(&root);

    //std::vector<int> branchResult(BranchSums(&root));
    //for(auto i : branchResult)
       // std::cout << i << ',';

    TreeDiameter(&root, 0);


    // Matrix Blip

    PrintGraph(&a);
    UnvisitGraph(&a);
    Blip(&a, 14);
    UnvisitGraph(&a);
    putchar('\n');
    PrintGraph(&a);
    */

    // Flood Fill
    std::vector<std::vector<char>> canvas { 
        {'G','G','G','G','G','G','G','G','B'},
        {'G','Y','Y','Y','Y','Y','Y','Y','B'},
        {'G','G','G','G','G','G','Y','Y','B'},
        {'G','G','G','G','Y','Y','Y','Y','B'},
        {'G','G','G','G','Y','Y','Y','Y','B'},
        {'G','G','G','G','Y','Y','Y','Y','B'},
        {'G','G','G','G','Y','Y','Y','Y','B'},
        {'G','G','G','G','G','G','B','B','B'},
        {'O','O','G','G','G','G','B','B','B'},
        {'O','O','O','O','O','O','B','B','B'}
    };
    PrintMatrix(canvas);
    FloodFill(canvas,1,1,'L');
    PrintMatrix(canvas);

    return 0;
}
