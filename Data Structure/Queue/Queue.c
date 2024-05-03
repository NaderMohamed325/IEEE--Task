#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *pointer;
    int front;
    int rear;
} Queue;


Queue *Create_Queue(unsigned int size) {
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    if (!Q) {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    Q->pointer = (int *)malloc(sizeof(int) * size);
    Q->rear = -1;
    Q->front = -1;
    Q->size = size;
    return Q;
}

void enqueu(Queue *q, int val) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->pointer[q->rear] = val;
        if (q->front == -1) {
            q->front = q->rear;
        }
    }
}

int dequeue (Queue *q) {
    int x = -1;
    if (q->rear == q->front) {
        printf("Queue is Empty\n");
    } else
    {
        x = q->pointer[q->front];
        q->front = (q->front + 1) % q->size;
    }

    return x;
}