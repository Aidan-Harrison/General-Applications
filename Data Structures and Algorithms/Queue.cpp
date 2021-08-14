#include <iostream>
// ================ Linear Queue ================
struct Queue { // Bounded
    int items[10];
    int front = 0;
    int rear = -1;

    bool IsFull() {
        if(rear == 10)
            return true;
        return false;
    }

    bool IsEmpty() {
        if(front > rear)
            return true;
        return false;
    }

    void Enqueue(int data) {
        if(IsFull()) {
            std::cerr << "Queue is full!" << std::endl;
            exit(1);
        }
        else {
            rear++;
            items[rear] = data; 
        }
    }

    int Dequeue() {
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

    int Peek() {
        return items[front];
    }

    void Print() const {
        for(unsigned int i = front; i <= rear; i++)
            std::cout << items[i] << "|";
    }
};

// ================ List Queue ================
struct ListQueue { // Queue implemented via a linked list

};

// ================ Circular Queue ================
struct RingBuffer {
    int SIZE = 5;
    int items[5];
    int front = 0; // Check!
    int rear = -1;

    bool IsFull() {
        if(rear == SIZE-1 && front == 0 || rear == front-1) // Check!
            return true;
        return false; 
    }

    bool IsEmpty() {
        if(front == -1) // front == rear
            return true;
        return false;
    }

    void Enqueue(const int data) { // Implement front
        rear++;
        if(rear == SIZE)
            rear = 0;
        items[rear] = data;
    }

    int Dequeue() { // Fix!
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

    void Print() const { 
        for(int i = 0; i < SIZE; i++)
            std::cout << items[i] << "|";       
    }
};

int main() {
    std::cout << "Queue:\n";
    Queue q;

    q.Enqueue(5);
    q.Enqueue(14);
    q.Enqueue(1);
    q.Enqueue(4);
    q.Enqueue(9);

    q.Print();

    putchar('\n');

    std::cout << q.Dequeue() << '\n';
    std::cout << q.Dequeue() << '\n';
    std::cout << q.Dequeue() << '\n';

    q.Print();
    putchar('\n');

    std::cout << "Ring Buffer:\n";
    RingBuffer r;

    r.Enqueue(5);
    r.Enqueue(7);
    r.Enqueue(4);
    r.Enqueue(1);
    r.Enqueue(8);

    r.Print();

    r.Enqueue(2);
    r.Enqueue(9);
    putchar('\n');

    r.Print();

    return 0;
}