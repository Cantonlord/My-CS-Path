#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_linked_list.h"


typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

Stack* createStack() {
    Stack *obj = malloc(sizeof(Stack));
    obj->top = NULL;
    return obj;
}

bool isEmpty(Stack *obj) {
    return obj->top == NULL;
}

void push(Stack *obj, int data) {
    Node *new = malloc(sizeof(Node));
    new->val = data;
    new->next = obj->top;
    obj->top = new;
}

void pop(Stack *obj) {
    if (isEmpty(obj))
        printf("ERROR: Stack is empty\n");
    Node *del_node = obj->top;
    obj->top = obj->top->next;
    free(del_node);
}

int top(Stack *obj) {
    if (isEmpty(obj)) {
        printf("ERROR: Stack is empty\n");
        return INT_MIN;
    }
    return obj->top->val;
}

void printStack(Stack *obj) {
    if (isEmpty(obj))
        printf("ERROR: Stack is empty\n");
        Node *temp = obj->top;
    while (temp) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void freeStack(Stack *obj) {
    if (obj->top == NULL)
        printf("ERROR: Stack hasn't been created\n");
    while (!isEmpty(obj))
        pop(obj);
}
