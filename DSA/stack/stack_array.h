#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>

typedef struct stack Stack;

Stack* createStack(int capacity);
bool isFull(Stack *obj);
bool isEmpty(Stack *obj);
void push(Stack *obj, char data);
char pop(Stack *obj);
char top(Stack *obj);
void printStack(Stack *obj);


#endif