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
        std::cout << q.items[i] << ', ';
}

// ================ Circular Queue ================
struct CQueue {
    int items[10];
    int front = -1;
    int rear = -1;
};

bool IsFull(CQueue *q, int rear) {
    if((rear + 1) % 10 == q->front) {
        std::cout << "Queue is full!\n";
        return true;
    }
    else
        return false;
}

void CEnqueue(CQueue *q, int front, int rear, int data) {
    if(IsFull(q, rear)) {
        return; // Check!
    }
    else {
        q->rear = (q->rear + 1) % 10;
        q->items[q->rear] = data;
        if(q->front = -1)
            q->front = 0;
    }
}

int main() {
    Queue q;
    
    return 0;
}