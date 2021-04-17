#include <iostream>

struct Queue {
    int items[10];
    int itemCount = 0;
    int front = -1;
    int rear = 0;
    int Size() const { return itemCount; }
};

bool IsFull(Queue *q) {
    if(q->front == 10 -1)
        return true;
    else
        return false;
}

bool IsEmpty(Queue *q) {
    if(q->front == -1)
        return true;
    else
        return false;
}

void Enqueue(Queue *q, int side, int item) {
    if(IsFull(q)) {
        std::cerr << "Queue is full!";
        exit(1);
    }
    else {
        q->items[q->rear++] = item; // Check!
    }
}

void Dequeue(Queue *q) {
    if(IsEmpty(q)) {
        std::cerr << "Queue is empty!";
        exit(1);
    }
    else {

    }
}

int Peek(Queue *q) {
    return q->items[q->front];
}

void Insert(Queue *q, int item) {
    if(IsFull(q)) {
        if(q->rear == q->front-1)
            q->rear = -1;
    }
    q->items[q->rear++] = item;
    q->itemCount++;
}

void PrintQueue(Queue *q, int size) {
    for(int i = 0; i < size; i++)
        std::cout << q->items[i] << ', ';
}

int main() {
    Queue q;
    
    return 0;
}