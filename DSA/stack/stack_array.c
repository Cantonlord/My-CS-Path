#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

// typedef struct stack {
//     char *arr;
//     int capacity;
//     int top;
// } Stack;

Stack* CreateStack(int capacity) {
    Stack *obj = malloc(sizeof(Stack));
    obj->arr = calloc(capacity, sizeof(char));
    obj->capacity = capacity;
    obj->top = -1;
    return obj;
}

bool isFull(Stack *obj) {
    return obj->top == obj->capacity - 1;
}

bool isEmpty(Stack *obj) {
    return obj->top == -1;
}

void push(Stack *obj, char data) {
    if (isFull(obj)) {
        printf("ERROR: Stack overflow");
        return;
    }
    obj->arr[++obj->top] = data;
}

char pop(Stack *obj) {
    if (obj->top == -1) {
        printf("ERROR: Stack is empty");
        exit(1);
    }
    char val = obj->arr[obj->top];
    obj->top--;
    return val;
}

char top(Stack *obj) {
    if (isEmpty(obj)) {
        printf("ERROR: Stack is empty");
        exit(1);
    }
    return obj->arr[obj->top];
}

void print(Stack *obj) {
    if (isEmpty(obj)) {
        printf("ERROR: Stack is empty");
        return;
    }
    for (int i = 0; i < obj->top + 1; i++)
        printf("%c ", obj->arr[i]);
}

bool isValid(char *str){
	Stack* S = CreateStack(strlen(str));
	while (*str) {
		push(S, *(str++));
		while (!isEmpty(S) && ((top(S) == '{' && *str == '}') || (top(S) == '[' && *str == ']') || (top(S) == '(' && *str == ')')))
			pop(S), str++;
	}
	return isEmpty(S);
}

int main() {
    isValid("{[]}") ? printf("true") : printf("false");
}