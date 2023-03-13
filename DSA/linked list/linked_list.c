#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *link;
}Node;

Node* make_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->val = data;
    new_node->link = NULL;
    return new_node;
}

void append(Node **head, int data) {
    Node *new_node = make_node(data);

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        Node *tail = *head;
        while (tail->link != NULL) {
            tail = tail->link;
        }
        tail->link = new_node;
    }
}

Node* append_without_traversal(Node *tail, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->val = data;
    new_node->link = NULL;

    tail->link = new_node;
    return new_node;
}

void push(Node **head, int data) {
    Node *new_node = make_node(data);
    new_node->link = *head;
    *head = new_node;
}

void insert(Node **head, int data, int pos) {
    if (pos == 1) {
        push(head, data); // don't add & before head
        return;
    }

    Node *ptr = *head;
    Node *new_node = make_node(data);

    // find the node which points to the pos node
    pos--; //index start from 0, we need to point to the pos-2 node
    while (pos != 1) {
        ptr = ptr->link;
        pos--;
    }

    new_node->link = ptr->link;
    ptr->link = new_node;
}

void pop(Node *head) {
    if (head == NULL) {
        printf("The list is empty!");
        return;
    }
    Node *ptr = head;
    while (ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;
}

void delete(Node **head, int pos) {
    Node *prev = *head;
    if (*head == NULL) {
        printf("List is empty!");
    }
    else if (pos == 1) {
        *head = prev->link;
        free(prev);
        prev = NULL;
    }
    else {
        Node *del_node = *head;
        while (pos != 1) {
            prev = del_node;
            del_node = del_node->link; 
            pos--;
        }
        prev->link = del_node->link;
        free(del_node);
        del_node = NULL;
    }
}

void del_list(Node **head) {
    Node *tmp = *head;
    while (tmp != NULL) {
        *head = tmp->link;
        free(tmp);
        tmp = *head;
    }
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
    Node *head = make_node(1);
    append(&head, 2); 
    append(&head, 3); 
    append(&head, 4);
    insert(&head, 5, 1);
    // delete(&head, 3);
    print_list(head);
}
