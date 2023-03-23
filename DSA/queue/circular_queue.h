#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct node {
    int data;
    struct node *next;
}Node;

void enqueue(int data);
void dequeue();
int isFull();
int isEmpty();
Node* front();
Node* rear();


#endif