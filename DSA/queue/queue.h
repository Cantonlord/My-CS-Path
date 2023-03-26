#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct node Node;

typedef struct queue Queue;

Queue* createQueue();
void enQueue(Queue *obj, int data);
void deQueue(Queue *obj);
bool isFull(Queue *obj);
bool isEmpty(Queue *obj);
int front(Queue *obj);
int rear(Queue *obj);


#endif