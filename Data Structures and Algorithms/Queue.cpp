#include <iostream>
// ================ Linear Queue ================
struct Queue {
    int items[10];
    int front = 0;
    int rear = -1;
};

bool IsFull(Queue *q) {
    if(q->rear == 10)
        return true;
    else
        return false;
}

bool IsEmpty(Queue *q) {
    if(q->front > q->rear)
        return true;
    else
        return false;
}

void Enqueue(Queue *q, int side, int item) {
    if(IsFull(q)) {
        std::cerr << "Queue is full!" << std::endl;
        exit(1);
    }
    else {
        q->items[q->rear++] = item; 
    }
}

int Dequeue(Queue *q) {
    if(IsEmpty(q)) {
        std::cerr << "Queue is empty!" << std::endl;
        exit(1);
    }
    else {
        int item = q->items[q->front];
        q->front++;
        return item;
    }
}

int RPeek(Queue *q) {
    return q->items[q->rear];
}

int FPeek(Queue *q) {
    return q->items[q->front];
}

void PrintQueue(Queue &q) {
    for(int i = 0; i < q.rear; i++)
        std::cout << q.items[i] << ",";
}

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