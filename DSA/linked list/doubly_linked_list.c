#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;


Node* make_node(int data) {
    Node *new = malloc(sizeof(Node));
    new->val = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void push(Node **head, int data) {
    Node *new = make_node(data);
    new->next = *head;
    (*head)->prev = new;
    *head = new;
}

void append(Node **head, int data) {

}

void insert(Node **head, int data) {

}







void print_list(Node* head) {
    if (head == NULL) {
        printf("The linked list is empty!");
        return;
    }
    // Traversal the list
    while (head != NULL) {
        printf("%d%s", head->val, (head->next) ? ", " : "\n");
        head = head->next;
    }
}

int main() {
    Node *head = make_node(12);
    push(&head, 11);
    print_list(head);

}

