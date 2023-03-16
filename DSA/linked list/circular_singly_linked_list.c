#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}Node;

Node* make_node(int data) {
    Node *new = malloc(sizeof(Node));
    new->val = data;
    new->next = new;
    return new;
}

void push(Node **tail, int data) {
    Node *new = make_node(data);
    new->next = (*tail)->next;
    (*tail)->next = new;
}

void append(Node **tail, int data) {
    Node *new = make_node(data);
    new->next = (*tail)->next;
    (*tail)->next = new;
    *tail = new;
}

void insert_after(Node **tail, int data, int pos) {
    Node *ptr = (*tail)->next;
    Node *new = make_node(data);
    while (pos > 1) {
        ptr = ptr->next;
        if (ptr == (*tail)->next) {
            printf("WARNING: Position is out of range!\n");
            return;
        }
        pos--;
    }
    new->next = ptr->next;
    ptr->next = new;
    if (ptr == *tail) {
        *tail = (*tail)->next;
    }
}

// delete the first node
int del_check(Node **tail) {
    if (*tail == NULL)
        return 0;
    // if there is one node only
    else if ((*tail)->next == *tail) {
        printf("List only has one node\n");
        free(*tail);
        *tail = NULL;
        return 0;
    }
    return 1;
}

void cut(Node **tail) {
    if (del_check(tail) == 0)
        return;

    Node *ptr;
    ptr = (*tail)->next;
    (*tail)->next = ptr->next;
    free(ptr);
    ptr = NULL;
}

void pop(Node **tail) {
    if (del_check(tail) == 0)
        return;

    Node *ptr =(*tail)->next;
    while (ptr->next != *tail) {
        ptr = ptr->next;
    }
    ptr->next = (*tail)->next;
    free(*tail);
    *tail = ptr;
}

void del_node(Node **tail, int pos) {
    if (del_check(tail) == 0)
        return;
    if (pos == 1) {
        cut(tail);
        return;
    }

    Node *ptr = (*tail)->next;
    while (pos > 2) {
        ptr = ptr->next;
        pos--;
    }
    Node *del_node = ptr->next;
    ptr->next = del_node->next;
    // if deleting the tail node, tail pointer move backward
    if (del_node == *tail)
        *tail = ptr;
    free(del_node);
    del_node = NULL;
}


void create_list(Node **tail) {
    int n, i, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("WARNING: Enter number must be greater than 0!");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter Node %d: ", i+1);
        scanf("%d", &data);
        if (i  > 0)
            append(tail, data);
        else 
            *tail = make_node(data);
    }
}

void print_list(Node* tail) {
    if (tail == NULL) {
        printf("WARNING: List is empty!\n");
        return;
    }
    // Traversal the list
    Node *ptr = tail->next;
    int i = 0;
    printf("\nIndex");
    do {
        printf("%5d%s", i++, (ptr != tail) ? "" : "\n");
        ptr = ptr->next;
    } while (ptr != tail->next);

    ptr = tail->next;
    printf("Value");
    do {
        printf("%5d%s", ptr->val, (ptr != tail) ? "" : "\n\n");
        ptr = ptr->next;
    } while (ptr != tail->next);
}


int find_prompt() {
    int n;
    printf("Enter the value to search: ");
    scanf("%d", &n);
    return n;
}

int find_node(Node *tail) {
    if (!tail)
        return -2;

    int data = find_prompt();

    int index = 0;
    Node *ptr = tail->next;
    do {
        if (ptr->val == data)
            return index;
        ptr = ptr->next;
        index++;
    } while (ptr != tail->next);
    return -1;
}

void find_result(int index) {
    if (index == -1)
        printf("No result found!\n");
    else if (index == -2)
        printf("The list is empty!\n");
    else
        printf("The index is %d!\n", index);
}

int main() {
    // Node *tail = NULL;
    Node *tail = make_node(1);
    push(&tail, 2);
    push(&tail, 3);
    push(&tail, 4);
    append(&tail, 5);
    insert_after(&tail, 6, 1);
    print_list(tail);
    cut(&tail);
    del_node(&tail, 3);
    print_list(tail);
    find_result(find_node(tail));
    return 0;
}