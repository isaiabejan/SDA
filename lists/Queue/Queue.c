#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype {
    int key;
    struct nodetype *next;
} NodeT;

NodeT *first,*last;

void enqueue(int val) {
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->key = val;
    p->next = NULL;
    if (first == NULL){
        first = p;
        last = p;
    }
    else {
        last->next = p;
        last = p;
    }
}

void dequeue() {
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    if (first == NULL) {
        printf("The queue is empty \n");
        exit(1);
    }
    else {
        p = first;
        first = first->next;
        free(p);
    }
}

void deleteQueue() {
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    while(first != NULL) {
        p = first;
        first = first->next;
        free(p);
    }
}

void printQueue() {
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p = first;
    while (p != NULL) {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(6);enqueue(7);enqueue(2);enqueue(1);enqueue(9);
    dequeue();dequeue();
    printQueue();
    return 0;
}


