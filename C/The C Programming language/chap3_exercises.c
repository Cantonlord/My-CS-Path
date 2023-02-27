#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 100

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

int mgetline(char s[], int lim) {
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
}

// Exercise 3.1 - Binsearch function, writing minimum tests inside a loop
int bin_search(int key, int arr[], int size) {
    int left, right, mid;
    left = 0;
    right = size - 1;
    mid = left + (right - left) / 2;
    while (left <= right || key != arr[mid]) {
        if (key > arr[mid])
            right = mid - 1;
        else if (key < arr[mid])
            left = mid + 1;
        mid = left + (right - left) / 2;
    }
    if (key == arr[mid])
        return key;
    else
        return -1;
}

// Exercise 3.3 - expand short hand notation in s1 into string s2
void expand(char s1[], char s2[]) {
    int i, j, c;
    i = j = 0;

    while((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] > c) {
            i++;
            while (c < s1[i])
                s2[j++] = c++;
        }
        else 
            s2[j++] = c;
    }
    s2[j] = '\0';
}

// Exercise 3.4 - itoa to handle largest negative integer
void itostr(int n, char s[]) {
    int i, sign;
    sign = n;
    i = 0;
    do {
       s[i++] = abs(n % 10) + '0'; 
    } while ((n /= 10) != 0); // The result of divison between two integers will only take the integer part.
    if (sign < 0) 
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


int main() {
    // char s1[MAXLINE], s2[MAXLINE];
    // mgetline(s1, MAXLINE);
    // expand(s1, s2);
    // printf("%s", s2);
    char s[1000];
    int number = -21474838;
    itostr(number, s);
    printf("%s", s);
    return 0;
}