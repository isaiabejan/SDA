#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int val;
    struct cell *next;
} NodeT;

NodeT *hTable[100];

int hFunction(int value) {
    return value % 11;
}

int findElement(int key) {
    NodeT *p;
    int h=hFunction(key);
    p=hTable[h];
    while (p != NULL){
        if (p->val == key) return 1;
        p = p->next;
    }
    return 0;
}

void insertElement(int key) {
    int h = hFunction(key);
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p->val = key;
    if(hTable[h] == NULL) {
        hTable[h] = p;
        p->next = NULL;
    }
    else {
        int nr = findElement(key);
        if (nr == 1) printf("Elementul %d exista deja ...",key);
        else {
            p->next = hTable[h];
            hTable[h] = p;
        }
    }
}

void showAll(int n) {
    int i;
    for(i=0; i<n; i++) {
        if(hTable[i] != NULL) {
            printf("%d :",i);
            NodeT *p = hTable[i];
            while(p != NULL) {
                printf("%d ",p->val);
                p = p->next;
            }
            printf("\n");
        }
        else printf("%d :\n",i);

    }
}

int main() {
    int i,n,x;
    for(i=0; i<100; i++)
        hTable[i] = NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d",&x);
        insertElement(x);
    }
    showAll(n);
    return 0;
}
