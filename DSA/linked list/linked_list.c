#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *link;
}Node;

Node* append(Node *head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->val = data;
    new_node->link = NULL;

    Node *tail = head;
    while (tail->link != NULL) {
        tail = tail->link;
    }

    tail->link = new_node;
    return head;
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("The linked list is empty!");
        return;
    }
    // Traversal the list
    while (head != NULL) {
        printf("%d%s", head->val, (head->link) ? ", " : "\n");
        head = head->link;
    }
}

int main() {
    Node *head = malloc(sizeof(Node));
    head->val = 1;
    head->link = NULL;

    append(head, 1); 
    append(head, 2); 
    append(head, 3); 
    append(head, 4);
    print_list(head);
}
