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

    if (!*head) {
        *head = new;
        return;
    }

    new->next = *head;
    (*head)->prev = new;
    *head = new;
}

void append(Node **head, int data) {
    Node *new = make_node(data);

    if (!*head) {
        *head = new;
        return;
    }

    Node *ptr = *head;
    while (ptr->next) ptr = ptr->next;
    ptr->next = new;
    new->prev = ptr;
}

void insert(Node **head, int data, int pos) {
    if (pos == 1) {
        push(head, data);
        return;
    }

    Node *new = make_node(data);
    Node *ptr = *head;

    while (pos > 2) {
        ptr = ptr->next;
        pos--;
    }
    new->next = ptr->next;
    ptr->next = new;
    new->prev = ptr;

    if (new->next != NULL)
        new->next->prev = new;
}

void create_list(Node **head) {
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("WARNING: Number must be a positive integer!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter Node %d: ", i+1);
        scanf("%d", &data);
        if (i  > 0)
            append(head, data);
        else 
            *head = make_node(data);
    }
}

int pop(Node **head) {
    int val;
    Node *ptr = *head;
    if (ptr == NULL) {
        printf("WARNING: List is already empty!\n");
        return INT_MAX;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    val = ptr->val; 
    free(ptr);
    ptr = NULL;
    return val;
}

void del_node(Node **head, int pos) {
    Node *ptr = *head;
    if (ptr == NULL) {
        printf("WARNING: List is already empty!\n");
        return;
    }
    if (pos == 1) {
        *head = ptr->next;
        free(ptr);
        ptr = NULL;
    }
    else {
        while (pos > 1) {
            ptr = ptr->next;
            if (ptr == NULL) {
                printf("WARNING: Position is out of range!\n");
                return;
            }
            pos--;
        }
        if (ptr->next == NULL)
            pop(&ptr);
        else {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
            ptr = NULL;
        }
    }
}

void reverse(Node **head) {
    Node *p1 = *head;
    Node *p2 = p1->next;

    p1->next = NULL;
    p1->prev = p2;

    while (p2 != NULL) {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    *head = p1;
}


void print_list(Node* head) {
    if (head == NULL) {
        printf("WARNING: List is empty!\n");
        return;
    }
    // Traversal the list
    Node *ptr = head;
    int i = 0;
    printf("Index");
    while (ptr) {
        printf("%5d%s", i++, (ptr->next) ? "" : "\n");
        ptr = ptr->next;
    }
    printf("Value");
    while (head != NULL) {
        printf("%5d%s", head->val, (head->next) ? "" : "\n\n");
        head = head->next;
    }
}

int main() {
    Node *head;
    head = make_node(0);
    append(&head, 1);
    append(&head, 12);
    append(&head, 323);
    append(&head, 44);
    print_list(head);
    reverse(&head);
    // printf("Pop: %d\n", pop(&head));
    // create_list(&head);
    print_list(head);

}

