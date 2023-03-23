#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 100

char stack_arr[MAX];
int Top = -1;

int isFull() {
    if (Top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (Top == -1)
        return 1;
    else
        return 0;
}

void push(char data) {
    if (isFull()) {
        printf("ERROR: Stack overflow");
        return;
    }
    Top++;
    stack_arr[Top] = data;
}

char pop() {
    if (Top == -1) {
        printf("ERROR: Stack is empty");
        exit(1);
    }
    char val = stack_arr[Top];
    Top--;
    return val;
}

char top() {
    if (isEmpty()) {
        printf("ERROR: Stack is empty");
        exit(1);
    }
    return stack_arr[Top];
}