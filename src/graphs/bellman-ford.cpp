#include <cstdio>

#define MAXV 1000
#define MAXE 5000
#define oo 1000000000

struct Edge {
  int u, v, w;
} edge[MAXE];

int V, E, source;
int u, v, w;
bool neg_cycle;

int d[MAXV], p[MAXV];

void find( int idx ) {
  if ( idx == source ) return;
  find( p[idx] );
  printf( " -> %d", idx + 1 );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d %d %d", &V, &E, &source );
  for ( int i = 0; i < E; i++ ) {
    scanf( "%d %d %d", &u, &v, &w );
    edge[i] = ( Edge ) { u - 1, v - 1, w };
  }
  
  /* Bellman-Ford Algorithm */
  
  for ( int i = 0; i < V; i++ )
    d[i] = oo;
  d[ --source ] = 0;
  neg_cycle = false;
  
  for ( int i = 0; i < V - 1; i++ )
    for ( int j = 0; j < E; j++ ) {
      u = edge[j].u;
      v = edge[j].v;
      w = edge[j].w;
      if ( d[u] + w < d[v] ) { /* relaxation */
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  
  /* Checking for negative-weight cycles */
  
  for ( int i = 0; i < E; i++ )
    if ( d[ edge[i].u ] + edge[i].w < d[ edge[i].v ] ) {
      neg_cycle = true;
      break;
    }
  
  if ( neg_cycle )
       printf( "Negative-weight cycle encountered!!!\n" );
  else {
    printf( "Shortest paths from source = %d:\n", source + 1 );
    for ( int i = 0; i < V; i++ )
      if ( i != source ) {
        printf( "Vertex %d: %d", i + 1, source + 1 );
        find( i );
        printf( " Cost: %d\n", d[i] );
      }
  }

  return 0;
}
