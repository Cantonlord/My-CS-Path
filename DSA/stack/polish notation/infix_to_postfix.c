#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../stack.h"

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int isOpenParenthesis(char par) {
    if (par == '(' || par == '[' || par == '{')
        return 1;
    else
        return 0;
}

int  isCloseParenthesis(char par) {
    if (par == ')' || par == ']' || par == '}')
        return 1;
    else
        return 0;
}

int isOperand(char operand) {
    if (operand >= '0' && operand <= '9') 
        return 1;
    else if (operand >= 'a' && operand <= 'z')
        return 1;
    else if (operand >= 'A' && operand <= 'Z')
        return 1;
    return 0;
}

char OppositeParenthesis(char par) {
    if (par == ']')
        return '[';
    else if (par == '}')
        return '{';
    else
        return '(';
}

char* infixToPostfix(char* s) {
    char *result = malloc(sizeof(strlen(s)));
    int j = 0;
    for (int i = 0; i < strlen(s); ++i) {
        char c = s[i];
        if (isOperand(c))
            result[j++] = c;

        else if (isOpenParenthesis(c))
            push(c);
        
        else if (isCloseParenthesis(c)) {
            while (top() != OppositeParenthesis(c)) {
                result[j++] = top();
                pop();
            }
            pop();
        }
        else {
            while (!isEmpty() && (prec(c) <= prec(top()))) {
                result[j++] = top();
                pop();
            }
            push(c);
        }
    }
    while (!isEmpty()) {
        result[j++] = top();
        pop();
    }
    return result;
}

void print(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        printf("%c", s[i]);
    }
}

int main() {
    char *s = "{D-[A*(B+C)]}/E";
    char *postfix = infixToPostfix(s);
    print(postfix);
}