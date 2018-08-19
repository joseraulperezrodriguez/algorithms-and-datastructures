/*
  koder : melkor
  TASK  : Given a graph G = (V,E) find and report its strongly
          connected components.
  
  Complexity: O(V + E)
*/

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

#define MAXV 50005
#define MAXE 100005

struct node {
  int v, next;
} L[MAXE];

int V, E, SCC, cnt;
int x, y;

int ptr[MAXV];
int dfsnum[MAXV], low[MAXV];
bool mk[MAXV], erased[MAXV];

stack< int > s;

void DFS( int u ) {

  s.push( u );
  low[u] = dfsnum[u] = cnt++;
  mk[u] = true;
  
  for ( int i = ptr[u]; i >= 0; i = L[i].next ) {
    int v = L[i].v;
    if ( !erased[v] )
      if ( !mk[v] ) {
        DFS( v );
        //low[u] <?= low[v];
        low[u] = (low[u] <= low[v] ? low[u] : low[v]);
      } //else low[u] <?= dfsnum[v];
    else low[u] = (low[u] <= dfsnum[v] ? low[u] : dfsnum[v]);

  }
  
  if ( u && dfsnum[u] == low[u] ) {
    printf( "SCC %d:", ++SCC );
    while ( s.top() != u ) {
      printf( " %d", s.top() );
      erased[ s.top() ] = true;
      s.pop();
    }
    printf( " %d\n", u );
    erased[u] = true;
    s.pop();
  }
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( ptr, -1, sizeof( ptr ) );
  
  scanf( "%d %d", &V, &E );
  for ( int i = 0; i < E; i++ ) {
    scanf( "%d %d", &x, &y );
    L[i] = ( node ) { y, ptr[x] };
    ptr[x] = i;
  }
  
  // Create a 'dummy' vertex with edges to all other vertices
  
  for ( int i = 1; i <= V; i++ ) {
    L[ E + i - 1 ] = ( node ) { i, ptr[0] };
    ptr[0] = E + i - 1;
  }
  
  // Find SCCs
  
  DFS( 0 );

  return 0;
}//melkor
