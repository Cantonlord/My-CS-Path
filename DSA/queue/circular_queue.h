#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>

typedef struct queue Queue;

Queue* createQueue(int capacity);
void enQueue(Queue *obj, int data);
void deQueue(Queue *obj);
bool isEmpty(Queue *obj);
bool isFull(Queue *obj);
int front(Queue *obj);
int rear(Queue *obj);
void printQueue(Queue *obj);
void freeQueue(Queue *obj);


#endif