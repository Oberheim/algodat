#include "queue.h"

Queue *initQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, Pos *pos) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->pos = pos;
    node->next = NULL;
    if(isEmpty(queue) == 1) {
        queue->front= node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
}

Pos *dequeue(Queue *queue) {
    if(isEmpty(queue) == 1) {
        printf("dequeue aborting: queue is empty\n");
        return NULL;
    }
    Node *node = queue->front;
    queue->front = queue->front->next;
    Pos *pos = node->pos;
    free(node);
    if(isEmpty(queue) == 1) {
        queue->rear = NULL;
    }
    return pos;
}

int isEmpty(Queue *queue) {
    if(queue->front== NULL) {
        return 1;
    }
    return 0;
}

Pos *front(Queue *queue) {
    if(isEmpty(queue) == 0) {
        return queue->front->pos;
    }
    return NULL;
}

