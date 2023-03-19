#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
}Node;

// Functions for Doubly linked list


// Functions for Circular doubly linked list
Node* make_node(int data);
void print_list(Node *tail);

void push(Node **tail, int data);
void append(Node **tail, int data);

void insert_after(Node **tail, int data, int pos);
void insert_before(Node **tail, int data, int pos);

void cut(Node **tail);
void pop(Node **tail);
void del_node(Node **tail, int pos);

#endif