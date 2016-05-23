#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    int val;
    struct nodetype *next;
}NodeT;
NodeT *head=NULL;

void push(int a)
{
    NodeT *p=(NodeT *) malloc(sizeof(NodeT));
    p->val=a;
    if(head==NULL) {
    p->next=NULL;
    head=p;
    }
    else {
    p->next=head;
    head=p;
    }
}
int IsEmpty()
{
    if(head==NULL)
        return 1;
    else
        return 0;
}
int top()
{
    if(head==NULL) return -1;
    else return head->val;
}
void pop()
{
    NodeT *p=head;
    head=p->next;
    free(p);
}
void dfs(int **a,int n,int x)
{
    int vizitat[n];
    int i,k,p;
    for(i=0;i<n;i++)
        vizitat[i]=0;
    vizitat[x]=1;
    push(x);
    printf("DFS= %d ",x);
    while(!IsEmpty())
    {
        p=-1;
        k=top();
        for(i=0;i<n;i++)
        if(vizitat[i]==0 && a[k][i]==1)
        {
            p = i;
            break;
        }
        if(p!=-1)
        {
            vizitat[p]=1;
            printf("%d ",p);
            push(p);
        }
        else pop(k);
    }
}

int main()
{
    int n,i,j;
    FILE *f=fopen("data.txt","r");
    fscanf(f,"%d",&n);
    int **a=(int **) calloc(n,4);
    for(i=0;i<n;i++)
        a[i]=(int *) calloc(n,4);
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
    dfs(a,n,i);
    return 0;
}
