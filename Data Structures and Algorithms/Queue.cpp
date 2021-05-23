#include <iostream>
struct Queue {
    int items[10];
    int front = -1;
    int rear = -1;
};

bool IsFull(Queue *q) {
    if(q->rear == 10)
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
        std::cerr << "Queue is full!" << std::endl;
        exit(1);
    }
    else {
        q->items[q->rear++] = item; 
        // Front?
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

int Peek(Queue *q) {
    return q->items[q->front];
}

void Insert(Queue *q, int item) {
    if(IsFull(q)) {
        if(q->rear == q->front-1)
            q->rear = -1;
    }
    q->items[q->rear++] = item;
}

void PrintQueue(Queue &q) {
    for(int i = 0; i < q.rear; i++)
        std::cout << q.items[i] << ', ';
}

int main() {
    Queue q;
    
    return 0;
}