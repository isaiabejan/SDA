#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype {
    int val;
    struct nodetype *next;
    } NodeT;

NodeT *head = NULL,*tail = NULL;

void insert(int val){
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->val=val;
    p->next=NULL;
    if (head == NULL) {
        head=p;
        tail=p;
    }
    else {
        tail->next=p;
        tail=p;
    }
}

int extract(){
    if (head == NULL) return -1;
    NodeT *p = head;
    int aux=p->val;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else head = p->next;
    free(p);
    return aux;
}

enum { NEVIZITAT, VIZITAT };

void bfs( int nr, int x, int **a ) {
        int viz[nr];
        int i,v;
        for (i=0; i<nr; i++)
            viz[i]=NEVIZITAT;
        viz[x]=VIZITAT;
        insert(x);
        printf("%d ",x);
        while(head != NULL) {
                v=extract();
                for (i=0; i<nr; i++)
                    if (a[v][i] == 1 && viz[i] == NEVIZITAT) {
                        viz[i] = VIZITAT;
                        printf("%d ",i);
                        insert(i);
                }
        }
        printf("\n");
}


int main()
{
    int n,i,j;
    FILE *f=fopen("data.txt","r");
    fscanf(f,"%d",&n);
    int **a=(int **)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        a[i]=(int*)malloc(n*sizeof(int));

    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            a[i][j]=0;
    while(!feof(f)){
        fscanf(f,"%d",&i);
        fscanf(f,"%d",&j);
        a[i][j]=1;
        a[j][i]=1;
    }

    printf("Introduceti nodul de la care plecam ");
    scanf("%d",&i);
    printf("\n");
    bfs(n,i,a);
    return 0;
}
