#include <iostream>
// ================ Linear Queue ================
struct Queue {
    int items[10];
    int front = 0;
    int rear = -1;

    bool IsFull();
    bool IsEmpty();
    void Enqueue(int data);
    int Dequeue();

    void Print() const;
};

bool Queue::IsFull() {
    if(rear == 10)
        return true;
    return false;
}

bool Queue::IsEmpty() {
    if(front > rear)
        return true;
    return false;
}

void Queue::Enqueue(int data) {
    if(IsFull()) {
        std::cerr << "Queue is full!" << std::endl;
        exit(1);
    }
    else {
        rear++;
        items[rear] = data; 
    }
}

int Queue::Dequeue() {
    if(IsEmpty()) {
        std::cerr << "Queue is empty!" << std::endl;
        exit(1);
    }
    else {
        int item = items[front];
        front++;
        return item;
    }
}

void Queue::Print() const {
    for(int i = 0; i < rear; i++)
        std::cout << items[i] << ",";
}

// ================ List Queue ================
struct ListQueue { // Queue implemented via a linked list

};

// ================ Circular Queue ================
struct RingBuffer { // Check everything!
    int SIZE = 0;
    int items[10];
    int front = -1;
    int rear = -1;

    bool IsFull() {
        if(rear == SIZE-1 && front == 0 || rear == front-1) // Check!
            return true;
        return false; 
    }

    bool IsEmpty() {
        if(front == -1)
            return true;
        return false;
    }

    void Enqueue(const int data) {
        if(IsFull())
            std::cerr << "Circular Queue is full!\n";
        else {
            if(front != 0) {
                rear = 0;
                items[rear] = data;   
            }
        }
    }

    int Dequeue() {
        if(IsEmpty())
            std::cerr << "Queue is empty!\n";
        else {
            if(front == rear) {
                front = - 1;
                rear = -1;
            } 
            else if(front == SIZE - 1) {
                front = 0;
                return items[front]; // Check!
            }
        }
        return -1;
    }

    void Print() {
        for(int i = 0; i < rear; i++)
            std::cout << items[i];       
    }
};

int main() {
    Queue q;
    RingBuffer r;

    r.Enqueue(5);
    r.Enqueue(7);
    r.Enqueue(4);
    r.Enqueue(1);

    r.Print();

    return 0;
}