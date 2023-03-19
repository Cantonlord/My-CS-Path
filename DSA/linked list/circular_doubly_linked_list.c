#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

void print_list(Node *tail) {
    if (tail == NULL) {
        printf("WARNING: List is empty!\n");
        return;
    }
    // Traversal the list
    Node *ptr = tail->next;
    int i = 0;
    printf("\nIndex");
    do {
        printf("%5d%s", i++, (ptr != tail) ? "" : "\n");
        ptr = ptr->next;
    } while (ptr != tail->next);

    ptr = tail->next;
    printf("Value");
    do {
        printf("%5d%s", ptr->val, (ptr != tail) ? "" : "\n\n");
        ptr = ptr->next;
    } while (ptr != tail->next);
}

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
    Node *head = (*tail)->next;
    new->next = head;
    new->prev = *tail;
    head->prev = new;
    (*tail)->next = new;
}

void append(Node **tail, int data) {
    Node *new = make_node(data);
    if (!*tail) {
        *tail = new;
        return;
    }
    Node *head = (*tail)->next;
    new->next = head;
    new->prev = *tail;
    head->prev = new;
    (*tail)->next = new;
    *tail = new;
}

void insert_after(Node **tail, int data, int pos) {
    Node *ptr = (*tail)->next;
    while (pos > 1) {
        ptr = ptr->next;
        pos--;
    }
    Node *new = make_node(data);
    new->next = ptr->next;
    new->prev = ptr;
    ptr->next->prev = new;
    ptr->next = new;
    if (ptr == *tail)
        *tail = (*tail)->next;
}

void insert_before(Node **tail, int data, int pos) {
    if (pos == 1) {
        push(tail, data);
        return;
    }

    Node *new = make_node(data);
    Node *ptr = (*tail)->next;

    while (pos > 2) {
        ptr = ptr->next;
        pos--;
    }
    new->next = ptr->next;
    new->prev = ptr;
    ptr->next->prev = new;
    ptr->next = new;
}

// delete the first node
int del_check(Node **tail) {
    if (*tail == NULL) {
        printf("WARNING: List is already empty!\n");
        return 0;
    }
    // if there is one node only
    else if ((*tail)->next == *tail) {
        printf("List has one node only\n");
        free(*tail);
        *tail = NULL;
        return 0;
    }
    return 1;
}

void cut(Node **tail) {
    if (del_check(tail) == 0)
        return;

    Node *head = (*tail)->next;
    (*tail)->next = head->next;
    head->next->prev = *tail;
    free(head);
}

void pop(Node **tail) {
    if (del_check(tail) == 0)
        return;

    Node *ptr =(*tail)->prev;
    ptr->next = (*tail)->next;
    (*tail)->next->prev = ptr; 
    free(*tail);
    *tail = ptr;
}

void del_node(Node **tail, int pos) {
    if (del_check(tail) == 0)
        return;
    if (pos == 1) {
        cut(tail);
        return;
    }

    Node *ptr = (*tail)->next;
    while (pos > 1) { //之所以这里是1，因为ptr要直接指向del_node而不是前一个
        ptr = ptr->next;
        if (ptr == (*tail)->next) {
            printf("WARNING: Position is out of range!\n");
            return;
        }
        pos--;
    }
    Node *prev_node = ptr->prev;
    prev_node->next = ptr->next;
    ptr->next->prev = prev_node;
    // if deleting the tail node, tail pointer move backward
    if (ptr == *tail)
        *tail = prev_node;
    free(ptr);
}

