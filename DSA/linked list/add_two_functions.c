#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
}Node;


Node* make_node(int data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

Node* append(Node *head, int data) {
    Node *new = make_node(data);
    if (!head) {
        head = new;
        return head;
    }
    Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new;
    return head;
}

Node *push(Node *head, int data) {
    Node *new = make_node(data);
    if (!head) {
        head = new;
        return head;
    }
    new->next = head;
    head = new;
    return head;
}

Node* create_list(Node *head) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    Node *ptr;
    while (n != 0) {
        head = append(head, n % 10);
        n /= 10;
    }
    return head;
}

Node* add(Node *head1, Node *head2) {
    Node *result = NULL;
    Node *ptr1 = head1;
    Node *ptr2 = head2;

    int sum, carry = 0;

    while (ptr1 || ptr2) {
        sum = 0;
        if (ptr1)
            sum += ptr1->data;
        if (ptr2)
            sum += ptr2->data;
        sum += carry;
        carry = sum / 10;
        result = push(result, sum % 10);
        if (ptr1)
            ptr1 = ptr1->next;
        if (ptr2)
            ptr2 = ptr2->next;
    }
    if (carry)
        result = push(result, carry);
    return result;
}

Node* reverse(Node *head) {
    if (!head)
        return head;

    Node *curr = NULL;
    Node *next = head->next;
    head->next = NULL;

    while (!next) {
        curr = next;
        next = next->next;
        curr->next = head;
        head = curr;
    }
    return head;
}

void print(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d%s", ptr->data, (ptr->next) ? "->" : "\n");
        ptr = ptr->next;
    }
}



int main() {
    Node *num1 = NULL;
    Node *num2 = NULL;
    num1 = create_list(num1);
    print(num1);
    num2 = create_list(num2);
    print(num2);

    Node *result = NULL;
    result = add(num1, num2);
    print(result);
}