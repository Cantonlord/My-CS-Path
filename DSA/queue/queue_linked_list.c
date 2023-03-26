#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *head, *tail;
} Queue;

bool isFull(Queue *obj) {
    return obj->tail->next == obj->head;
}

bool isEmpty(Queue *obj) {
    return obj->head == NULL;
}

Queue* createQueue() {
    Queue *obj = malloc(sizeof(Queue));
    obj->head = obj->tail = NULL;
    return obj;
}

void enQueue(Queue *obj, int data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    if (isEmpty(obj)) {
        obj->head = obj->tail = new;
        return;
    }
    obj->tail->next = new;
    obj->tail = new;
}

void deQueue(Queue *obj) {
    if (isEmpty(obj)) {
        printf("ERROR: The queue is empty\n");
        exit(1);
    }
    Node *temp = obj->head;
    if (obj->head == obj->tail)
        obj->head = obj->tail = NULL;
    else
        obj->head = obj->head->next;
    free(temp);
}

int front(Queue *obj) {
    if (obj->head)
        return obj->head->data;
    else if (isEmpty(obj)) {
        printf("ERROR: Queue is empty\n");
        exit(1);
    }
}

int rear(Queue *obj) {
    if (obj->tail) 
        return obj->tail->data;
    else if (isEmpty(obj)) {
        printf("ERROR: Queue is empty\n");
        exit(1);
    }
}