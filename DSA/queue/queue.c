#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node next;
}Node;

Node *head = NULL;
Node *tail = NULL;

Node make_node(int data) {
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
    else {

    }
}