#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    // Node *tail = make_node(1);
    // push(&tail, 2);
    // push(&tail, 3);
    // push(&tail, 4);
    // print_list(tail);
    // pop(&tail);
    // print_list(tail);

    Node *head;
    head = make_node(0);
    append(&head, 1);
    append(&head, 12);
    append(&head, 323);
    append(&head, 44);
    print_list(head);
}