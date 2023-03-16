#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

Node* make_node(int data) {
    Node *new = malloc(sizeof(Node));
    new->val = data;
    new->next = new;
    new->prev = new;
    return new;
}

void push(Node **tail, int data) {
    Node *new = make_node(data);

    if (!*tail) {
        *tail = new;
        return;
    }

    Node *ptr = (*tail)->next;
    new->next = ptr;
    new->prev = *tail;
    (*tail)->next = new;
    ptr->prev = new;    
}

int main() {
    Node *tail = make_node(1);
    push(&tail, 2);
    push(&tail, 3);
    print_list(tail);
}