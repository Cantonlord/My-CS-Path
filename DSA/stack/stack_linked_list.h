#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>

typedef struct stack Stack;

Stack* createStack();
bool isEmpty(Stack *obj);
void push(Stack *obj, int data);
void pop(Stack *obj);
int top(Stack *obj);
void printStack(Stack *obj);


#endif