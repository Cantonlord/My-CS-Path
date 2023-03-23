#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    char *arr;
    int capacity;
    int front;
    int rear;
} Queue;

Queue* CreateQueue(int capacity) {
    Queue* obj = malloc(sizeof(Queue));
    obj->arr = calloc(capacity, sizeof(char));
    obj->capacity = capacity;
    obj->front = obj->rear = -1;
    return obj;
}

bool isEmpty(Queue *obj) {
    return obj->front == -1;
}

bool isFull(Queue *obj) {
    return (obj->rear + 1) % obj->capacity == obj->front;
}

int front(Queue *obj) {
    return obj->arr[obj->front];
}

int rear(Queue *obj) {
    return obj->arr[obj->rear];
}

void enQueue(Queue *obj, int data) {
    if (isFull(obj)) {
        printf("ERROR: Queue is full\n");
        return;
    } else if (isEmpty(obj)) {
        obj->front = obj->rear = 0;
    } else {
        obj->rear = (obj->rear + 1) % obj->capacity;
    }
    obj->arr[obj->rear] = data;
}

void deQueue(Queue *obj) {
    if (isEmpty(obj)) {
        printf("ERROR: Queue is empty\n");
        return;
    } else if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
    }
}

void freeQueue(Queue *obj) {
    free(obj);
}

void printQueue(Queue *obj) {
    if (isEmpty(obj)) {
        printf("ERROR: Queue is empty");
        return;
    }
    for (int i = 0; i < obj->rear + 1; i++)
        printf("%c ", obj->arr[i]);
}

int main() {
    Queue *q = CreateQueue(10);
    enQueue(q, 'a');
    enQueue(q, '2');
    enQueue(q, 'A');
    printf("%d, %d\n", front(q), rear(q));
    printQueue(q);
}