//
// Created by xcite on 4/27/2024.
//

#include "Queue.h"

/**
 @param size: The size of the queue to be created.
 @brief Creates a new queue of the specified size.
 @return A pointer to the newly created queue if successful, otherwise NULL.
 */
Queue_t *Create_Queue(unsigned int size) {
    Queue_t *queue = (Queue_t *) malloc(sizeof(Queue_t));
    if (!queue) {
        printf("Allocation Failed Successfully\n");
        free(queue);
        return NULL;
    } else {
        queue->pointer = (int *) malloc(sizeof(int) * size);
        queue->rear = 0;
        queue->front = 0;
        queue->size = size;
        return queue;
    }
}

/**@param q: Pointer to the queue.
 @param val: The value to be enqueued.
 @brief Enqueues a value into the queue.
 @return void
 */
void Enqueue(Queue_t *q, int val) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
    } else {
        q->pointer[(q->rear + 1) % q->size] = val;
        q->rear = (q->rear + 1) % q->size;
    }
}

/**
 @param q: Pointer to the queue.
 @brief Dequeues a value from the queue.
 @return The dequeued value if successful, otherwise -1.
 */
int Dequeue(Queue_t *q) {
    int return_val = -1;
    if (q->rear == q->front) {
        printf("Queue is Empty\n");
        return return_val;
    } else {
        return_val = q->pointer[q->front];
        q->front = (q->front + 1) % q->size;
        return return_val;
    }
}

/**
 @param q: Pointer to the queue.
 @brief Displays the elements of the queue.
 @return void
 */
void Display(Queue_t *q) {
    if (q->front == q->rear) {
        printf("Queue is Empty\n");
    } else {
        int i = q->front;
        printf("Queue Elements: ");
        while (i != q->rear) {
            printf("%d ", q->pointer[i]);
            i = (i + 1) % q->size;
        }
        printf("\n");
    }
}


/**
 * @brief Creates a new queue implemented using two stacks.
 *
 * This function creates a new Queue_2Stack_t structure with two stacks, s1 and s2.
 *
 * @param size The size of the queue.
 * @return A pointer to the newly created queue if successful, otherwise NULL.
 */
Queue_2Stack_t *Create_Q2S(int size) {
    Queue_2Stack_t qs;
    qs->s1 = Create_Stack(size);
    qs->s2 = Create_Stack(size);
    if (qs.s1 == NULL || qs.s2 == NULL) {
        printf("Allocation Failed Successfully XD\n");
        return NULL;
    }
    qs->size = size;
    return qs;
}

/**
 * @brief Enqueues an element into the queue.
 *
 * If the first stack (s1) is not full, the element is pushed onto it.
 *
 * @param qs Pointer to the queue.
 * @param val The value to be enqueued.
 * @return void
 */
void QS_Enqueue(Queue_2Stack_t *qs, int val) {
    if (!isFull(qs->s1))
        push(qs->s1, val);
    else {
        printf("Queue is Full\n");
    }
}

/**
 * @brief Dequeues an element from the queue.
 *
 * If both stacks (s1 and s2) are empty, the queue is empty.
 * If the second stack (s2) is not empty, the element is popped from it.
 * Otherwise, elements are moved from s1 to s2, then the front element is popped from s2.
 *
 * @param qs Pointer to the queue.
 * @return The dequeued element if successful, otherwise -1.
 */
int QS_Dequeue(Queue_2Stack_t *qs) {
    if (isEmpty(qs->s1) && isEmpty(qs->s2)) {
        printf("Queue is Empty\n");
        return -1;
    } else if (!isEmpty(qs->s2)) {
        return pop(qs->s2);
    } else {
        while (!isEmpty(qs->s1)) {
            push(qs->s2, peek(qs->s1));
            pop(qs->s1);
        }
        int x = peek(qs->s2);
        pop(qs->s2);
        return x;
    }
}



