#ifndef QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#endif

typedef struct Node Node;

typedef struct {
    int x;
    int y;
    int nr_moves;
} Pos;

struct Node{
    Pos *pos;
    Node *next;
};

typedef struct {
    Node *front;
    Node *rear;
} Queue;


void enqueue(Queue *queue, Pos *pos);
Pos *dequeue(Queue *queue);
Queue *initQueue();
int isEmpty(Queue *queue);
Pos *front(Queue *queue);
