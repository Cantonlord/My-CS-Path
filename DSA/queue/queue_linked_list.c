#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Node *head = NULL;
Node *tail = NULL;

Node* make_node(int data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void enqueue(int data) {
    Node *new = make_node(data);
    if (!head) {
        head = tail = new;
        return;
    }
    tail->next = new;
    tail = new;
}

void dequeue() {
    if (!head) {
        printf("ERROR: The queue is empty");
        return;
    }
    Node *temp = head;
    if (head == tail)
        head = tail = NULL;
    else
        head = head->next;
    free(temp);
}

int isFull() {
    if (tail->next == head)
        return 1;
    return 0;
}

int isEmpty() {
    if (head == NULL)
        return 1;
    return 0;
}

Node* front() {
    if (head)
        return head;
    exit(1);
}

Node* rear() {
    if (tail) 
        return tail;
    exit(1);
}