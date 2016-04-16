#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype {
    int key;
    struct nodetype *next;
} NodeT;

NodeT *first,*last;

void push(int val) {
    NodeT *p=(NodeT *)malloc(sizeof(NodeT));
    p->key = val;
    p->next = NULL;
    if (first == NULL) {
        first=p;
        last=p;
    }
    else {
        last->next = p;
        last = p;
    }
}

void pop() {
    NodeT *q,*q1;
    q1=NULL;
    q=first;
    while(q != last) {
        q1=q;
        q = q->next;
    }
    if (q == first) {
        first = last = NULL;
    }
    else {
        q1->next = NULL;
        last = q1;
    }
    free(q);
}

void printStack()
{
    NodeT *p=first;
    while(p!=NULL)
    {
        printf("%d ",p->key);
        p=p->next;
    }
        printf("\n");
}

int main()
{
    push(7);push(8);push(4);push(7);push(5);
    pop();pop();
    printStack();
    return 0;
}
