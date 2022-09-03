// Stack implemeniation using linked list (std and custom)
#include <iostream>
#include <list>

struct stdStack { // std::list implementation | Pointless??? The same as a vector
    int MAXSIZE = 10;
    std::list<int> items;
    int top = -1;

    bool IsFull() {
        if(top == MAXSIZE)
            return true;
        return false;
    }
    bool IsEmpty() {
        if(top == -1)
            return true;
        return false;
    }
    void Push(int data) {
        if(IsFull())
            std::cerr << "Stack is full!\n";
        else {
            items.push_back(data);
            top++;
        }
    }
    int Pop() {
        if(IsEmpty())
            std::cerr << "Stack is empty!\n";
        else {
            int item = items.front();
            items.pop_back();
            top--;
            return item;
        }
    }

    void Print() const {
        for(auto i : items)
            std::cout << i << "|";
    }

    stdStack() {}
    ~stdStack() {}
};

// Custom List - Stack
struct LinkedList { // Doubly-linked list 
    struct node {
        int data;
        node * next;
        node * prev;
        node() :data(0), next(nullptr), prev(nullptr) {}
        node(int d) :data(d), next(nullptr), prev(nullptr) {}
    };

    int size{};
    node * head = nullptr;
    node * tail = nullptr;

    int Peek() { 
        return tail->data;
    }

    int GetSize() {
        return size;
    }

    void Print() const {
        node * tempNode = head;
        while(tempNode != nullptr) {
            std::cout << tempNode->data;
            tempNode = head->next;
        }
    }

    void add(const int pos, const int val) { // Add a node at a given position
        int counter{};
        node * tNode;
        while(tNode != nullptr) {
            if(counter == pos) {
                node * newNode;
                newNode->data = val;
                newNode->next = tNode->next;
                newNode->prev = tNode;
                tNode->next = newNode;
            }
            counter++;
        }
    }

    void append(node * n) { // Adds node to end
        size++; 
        if(head == nullptr) {
            head= n;
            return;
        }
        if(tail == nullptr) {
            tail = n;
            head->next = tail;
            return;
        }
        tail->next = n;
        tail = n;
        n->next = nullptr; // Ensure valid tail
    }

    node * pop() { // Returns end node
        node poppedNode = node(tail->data);
        tail = tail->prev;
        tail->next = nullptr;
        size--;
        return &poppedNode;
    }

    LinkedList() {}
    ~LinkedList() {}
};

struct CusStack { // Custom list implementation
    int MAXSIZE = 0;
    LinkedList *l;

    bool IsFull() {
        if(l->GetSize() == MAXSIZE)
            return true;
        return false;
    }

    bool IsEmpty() {
        if(l->GetSize() == 0)
            return true;
        return false;
    }

    void Push(int data) { // Fix!
        if(IsFull())
            std::cerr << "Stack is full!\n";
        else {
            LinkedList *copyList = l;
            LinkedList::node* newNode = new LinkedList::node(data);
            while(copyList->head != nullptr) {
                copyList->head = copyList->head->next;
            }
            copyList->head->next = newNode;
            l = copyList;
            delete copyList;
        }
    }

    void Pop() {
        if(IsEmpty())
            std::cerr << "Stack is empty!\n";
        else {
            // Get prev from tail and set its next to nullptr
            // Return it's data
            
        }
    }

    void Print() {
        while(l->head != nullptr) {
            std::cout << l->head->data;
            l->head = l->head->next;
        }
    }

    CusStack() {}
    ~CusStack() {}
};

int main() {
    stdStack s;
    s.Push(5);
    s.Push(17);
    s.Push(3);
    s.Push(24);

    s.Print();

    CusStack sList;

    sList.Push(5);
    sList.Push(17);
    sList.Push(3);
    sList.Push(17);

    sList.Print();

    return 0;
}