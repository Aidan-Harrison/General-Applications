// Stack implemeniation using linked list (std and custom)
#include <iostream>
#include <list>

struct stdStack {
    int MAXSIZE = 10;
    std::list<int> items;
    int top = 0;

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

    void Print() {
        for(auto i : items)
            std::cout << i << '\n';
    }

    stdStack() {}
    ~stdStack() {}
};

// Custom List - Stack
struct LinkedList { // Implemented as a doubly-linked list 
    struct node {
        int data;
        node *next;
        node *prev;
        node() :next(nullptr) {}
        node(int d) :data(d), next(nullptr), prev(nullptr) {}
        ~node() {}
    };

    int size;
    node *head;
    node *tail;

    int Peek() {
        node *newNode = head;
        while(newNode != nullptr) {
            newNode = newNode->next;
        }
        return newNode->data;
    }

    int GetSize() {
        node *newNode = head;
        while(newNode != nullptr) {
            newNode = newNode->next;
            size++;
        }
        return size;
    }

    LinkedList() {}
    ~LinkedList() {}
};

struct CusStack {
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

    void Push(int data) {
        if(IsFull())
            std::cerr << "Stack is full!\n";
        else {
            LinkedList::node* newNode = new LinkedList::node(data);
            while(l->head != nullptr) {
                 l->head = l->head->next;
            }
            l->head->next = newNode;
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