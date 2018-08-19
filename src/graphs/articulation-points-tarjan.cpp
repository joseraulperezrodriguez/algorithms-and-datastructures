/*
  koder : melkor
  TASK  : Given a graph G = (V,E) find its articulation points (i.e. those
          vertices whose removal would cause the graph to become disconnected).
  
  Running time: O(V + E)
*/

#include <cstdio>
#include <cstring>

#define MAXV 50005
#define MAXE 100005

struct node {
  int v, next;
} L[MAXE];

int V, E, cnt, top, subtrees;
int x, y;

int ptr[MAXV];
int dfsnum[MAXV], low[MAXV];
bool mk[MAXV], ap[MAXV];

void DFS( int u ) {

  mk[u] = true;
  dfsnum[u] = low[u] = ++cnt;
  
  for ( int i = ptr[u]; i >= 0; i = L[i].next ) {
    int v = L[i].v;
    if ( !mk[v] ) {
      if ( !u ) subtrees++;
      DFS( v );
      if ( low[v] >= dfsnum[u] ) ap[u] = true;
      //low[u] <?= low[v];
      low[u] = (low[u] <= low[v] ? low[u] : low[v]);

    } //else low[u] <?= dfsnum[v];
    else (low[u] <= dfsnum[v] ? low[u] : dfsnum[v] );
  }
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( ptr, -1, sizeof( ptr ) );
  
  scanf( "%d %d", &V, &E );
  for ( int i = 0; i < E; i++ ) {
  
    scanf( "%d %d", &x, &y );
    x--; y--;
    
    L[i] = ( node ) { y, ptr[x] };
    ptr[x] = i;
    L[ i + E ] = ( node ) { x, ptr[y] };
    ptr[y] = i + E;
  }
  
  // Find Articulation Points
  
  DFS( 0 );
  
  if ( subtrees < 2 ) ap[0] = false;
  for ( int i = 0; i < V; i++ )
    if ( ap[i] ) printf( "%d\n", i + 1 );

  return 0;
}//melkor
