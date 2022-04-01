#include <iostream>

class Queue {
private:
    int front = -1;
    int rear = -1;
    int queue[10];
public:
    Queue() {}

    bool IsFull() {
        if(front == 0 && rear == 10)
            return true;
        return false;
    }
    bool IsEmpty() {
        return(front == -1) ? true : false;
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
    int reader = 0; // Increments by 1 when element is consumed
    int writer = -1; // Increments by 1 when element is inserted

    int buffer[10];

    RingBuffer() {}

    bool IsFull() {
        // Full if the write sequence is equal to the size of the buffer and the read is equal to zero
        // In this case no elements have been read and thus there is N amount of elements to be read, with N being the capacity
        // If the writers value = N, and readers = 0, then the following will produce a result
        int size = (writer - reader) + 1; // If N - 0 + 1 (Array indexing)
        return(size == 10) ? true : false;
    }
    bool IsEmpty();
    void Insert(const int data) {
        // Mod operation wraps sequence around at the boundaries to derive a slot in the buffer
        buffer[++writer % 10] = data; // Note pre-increment
    }
    int Consume() {
        // Consuming an element does not remove it from the buffer, it stays until overwritten
        int element = buffer[reader++ % 10]; // Note post-increment
        return element;
    }

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