#include <iostream>
#include <vector>

class Queue {
private:
    int front = -1;
    int rear = -1;
    int queue[10];
public:
    Queue() {}

    bool IsFull() const {
        if(front == 0 && rear == 10)
            return true;
        return false;
    }
    bool IsEmpty() const {
        return(front == -1) ? true : false;
    }
    void Enqueue(int item) {
        if(IsFull()) 
            return;
        if(front == -1)
            front++;
        rear++;
        queue[rear] = item;
    }
    int Dequeue() {
        if(IsEmpty())
            return;
        int element = queue[front];
        if(front >= rear) {
            front = -1;
            rear = -1;
        }
        else
            front++;
        return element;
    }

    void Print() const {
        for(unsigned int i = front; i <= rear; i++)
            std::cout << queue[i] << ", ";
        putchar('\n');
    }

    ~Queue() {}
};

// Circular Queue
struct RingBuffer {
    int front = 0;
    int rear = 0;
    int size = 5;
    int array[5];
    int elementCount = 0;

    bool full() { return elementCount == size ? true : false; }
    bool empty() { return elementCount == 0 ? true : false; }

    void push(const int data) {
        if(!full())
            elementCount++;
        array[rear] = data;
        rear = (rear + 1) % size;
    }
    int pop() {
        if(empty())
            return INT_MIN;
        int result = array[front];
        front = (front + 1) % size;
        elementCount--;
        return result;
    }
};

void PrintBuffer(RingBuffer & b) {
    for(int i = 0; i < 5; i++)
        std::cout << b.array[i] << ',';
    putchar('\n');
}

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

    // Ring Buffer
    putchar('\n');
    RingBuffer rb;
    int input;
    while(1) {
        std::cin >> input;
        if(input == -1)
            break;
        rb.push(input);
        PrintBuffer(rb);
    }

    return 0;
}