/*
  koder : melkor
  TASK  : Dijkstra's Single-Source Shortest-Paths Algorithm
  
  Running Time: O(V^2)
*/

#include <cstdio>
#include <cstring>

#define MAXV 1000
#define MAXE 5000
#define oo 1000000000

struct edge {
  int v, w, next;
} edges[MAXE];

int V, edge_count, source;
int u, v, w, min;

int p[MAXV], d[MAXV], path[MAXV];
bool mark[MAXV];

void find( int idx ) {
  if ( idx == source ) return;
  find( path[idx] );
  printf( " -> %d", idx + 1 );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( p, -1, sizeof( p ) );
  
  scanf( "%d %d %d", &V, &edge_count, &source );
  for ( int i = 0; i < edge_count; i++ ) {
    scanf( "%d %d %d", &u, &v, &w );
    u--; v--;
    edges[i] = ( edge ) { v, w, p[u] };
    p[u] = i;
  }
  
  /* Dijkstra's Algorithm */
  /* Simple implementation running in O(V^2) time */
  
  for ( int i = 0; i < V; i++ )
    d[i] = oo;
  d[ --source ] = 0;
  
  for ( int i = p[source]; i != -1; i = edges[i].next )
    d[ edges[i].v ] = edges[i].w;
  mark[source] = true;
  
  for ( int i = 0; i < V - 1; i++ ) {

    min = oo;
    for ( int i = 0; i < V; i++ )
      if ( !mark[i] && d[i] < min ) {
        min = d[i];
        u = i;
      }
    
    mark[u] = true;
    for ( int i = p[u]; i != -1; i = edges[i].next ) {
      v = edges[i].v; w = edges[i].w;
      if ( d[u] + w < d[v] ) { /* relaxation */
        d[v] = d[u] + w;
        path[v] = u;
      }
    }
  }
  
  printf( "Shortest paths from source = %d:\n", source + 1 );
  for ( int i = 0; i < V; i++ )
    if ( i != source ) {
      printf( "Vertex %d: %d", i + 1, source + 1 );
      find( i );
      printf( " Cost = %d\n", d[i] );
    }

  return 0;
}//melkor
