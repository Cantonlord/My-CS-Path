#include <stdio.h>
#include <stdlib.h>

// Initiate 

// use malloc to initiate memory
int* init_intergers(int n) {
    int i;
    int *ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory is not allocated!");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        // printf("Enter No.%2d integer: ", i+1);
        scanf("%d", ptr + i);
    }
    return ptr;
}

// use realloc to allocate more memory

int* more_intergers(int *p, int old_n, int new_n) {
    if (p == NULL) {
        printf("New memory is lesser than old memory!");
        exit(1);
    }
    p = (int*)realloc(p, new_n*sizeof(int));
    for (int i = old_n; i < new_n; i++) {
        printf("Enter No.%2d integets: ", i + 1);
        scanf("%d", p + i);
    }
    return p;
}

void print_integers(int *p, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

int main() {
    int i, n, m;
    printf("Enter number of integers: ");
    scanf("%d", &n);
    int *p = init_intergers(n);
    print_integers(p, n);
    printf("New number of integers: ");
    scanf("%d", &m);
    p = more_intergers(p, n, m);
    print_integers(p, m);




    return 0;
}