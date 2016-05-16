#include <stdio.h>
#define MAXN 10
#define INFTY 0x7fff

void Prim2(int n, int c[MAXN][MAXN], int e[MAXN][2], int *cost)

{
int v[MAXN];
int i, j, k, min;
*cost = 0;
v[1]=0;
for ( i = 2; i <= n; i++ ) v[i] = 1;
for ( i = 1; i <= n - 1; i++ ) {
    min = INFTY;
    for ( k = 1; k <= n; k++ )
        if ( v[k] != 0 )
            if (c[k][v[k]] < min ) {
                j = k;
                min = c[k][v[k]];
            }
    e[i][0] = v[j];
    e[i][1] = j;
    *cost += c[j][v[j]];
    v[j]= 0;
    for ( k = 1; k <= n; k++ )
        if (v[k] != 0 &&
    c[k][v[k]] > c[k][j])
    v[k] = j;
 }
}
int main() {
int n;
int c[MAXN][MAXN];
int e[MAXN][2];
int i, j, k, cost;
printf( "\nNumber of nodes in graph G: " );
scanf( "%d", &n );
while ( '\n' != getchar() );
for ( i = 1; i <= n; i++ )
    for ( j = 1; j <= n; j++ )
        c[ i ][ j ] = INFTY;
for ( i = 1; i < n; i++ ){
    do {
        printf("\nNode adjacent to %2d [0=finish]:",i );
        scanf( "%d", &j );
    while ( '\n' != getchar() );
    if (j > 0 ) {
        printf("\nCost c[%d][%d]:", i, j);
        scanf( "%d", &c[ i ][ j ] );
        while ( '\n' != getchar() );
        c[j][i] = c[i][j];
  }
 }
while ( j > 0 );
}
Prim2( n, c, e, &cost );
printf("\nThe cost of MST is %d", cost );
printf("\nTree edges\tEdge cost\n" );
for ( i = 1; i <= n-1; i++ )
printf("%2.2d - %2.2d\t%10d\n",
        e[i][0], e[i][1],
        c[e[i][0]][e[i][1]] );
return 0;
}
