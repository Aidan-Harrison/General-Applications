#include <iostream>

struct Queue {
    Queue() {}

    int front = -1;
    int rear = -1;

    int queue[10];

    bool IsFull() {
        if(front == 0 && rear == 10)
            return true;
        return false;
    }
    bool IsEmpty() {
        if(front == -1)
            return true;
        return false;
    }
    void Enqueue(int item) {
        if(IsFull())
            std::cout << "Queue is full!\n";   
        else {
            if(front == -1)
                front++;
            rear++;
            queue[rear] = item;
        }
    }
    int Dequeue() {
        if(IsEmpty())
            std::cout << "Queue is empty!\n";
        else {
            int element = queue[front];
            if(front >= rear) {
                front = -1;
                rear = -1;
            }
            else
                front++;
            return element;
        }
        return -1;
    }

    void Print() {
        for(unsigned int i = front; i <= rear; i++)
            std::cout << queue[i] << ", ";
        putchar('\n');
    }

    ~Queue() {}
};

// Circular Queue
struct RingBuffer {
    RingBuffer() {}
    ~RingBuffer() {}
};

int main() {
    Queue q;
    q.Enqueue(2);
    q.Enqueue(4);
    q.Enqueue(6);
    q.Enqueue(8);
    q.Enqueue(10);

    q.Print();

    q.Dequeue();
    q.Dequeue();

    q.Print();

    return 0;
}