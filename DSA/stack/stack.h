#ifndef STACK_H
#define STACK_H

typedef struct stack {
    char *arr;
    int capacity;
    int top;
} Stack;

Stack* CreateStack(int capacity);
bool isFull(Stack *obj);
bool isEmpty(Stack *obj);
void push(Stack *obj, char data);
char pop(Stack *obj);
char top(Stack *obj);
void print(Stack *obj);


#endif