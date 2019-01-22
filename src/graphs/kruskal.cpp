/*
  koder : melkor
  TASK  : Kruskal's Algorithm for finding the MST of a connected
          undirected graph
  
  Running time: O(E log V)
*/

#include <cstdio>
#include <algorithm>

#include <bits/stdc++.h>

using namespace std;

#define MAXV 10000
#define MAXE 50000

#define size( u ) ( -parent[u] )

struct Edge {
  int u, v, w;
  bool operator < ( const Edge& b ) const { return w < b.w; }
} graph[MAXE], MST[MAXV];

int V, edge_count, cost;
int u, v, w;

int parent[MAXV];

int find( int u ) {
  return ( parent[u] < 0 ) ? u : parent[u] = find( parent[u] );
}

void join( int u, int v ) {
  u = find( u ); v = find( v );
  if ( size( u ) < size( v ) )
    swap( u, v );
  parent[u] += parent[v];
  parent[v] = u;
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( parent, -1, sizeof( parent ) );
  
  scanf( "%d %d", &V, &edge_count );
  for ( int i = 0; i < edge_count; i++ ) {
    scanf( "%d %d %d", &u, &v, &w );
    u--; v--;
    graph[i] = ( Edge ) { u, v, w };
  }
  
  /* Kruskal's Algorithm */
  
  sort( graph, graph + edge_count );
  
  cost = u = 0;
  for ( int i = 0; i < edge_count; i++ )
    if ( find( graph[i].u ) != find( graph[i].v ) ) {
      cost += graph[i].w;
      MST[ u++ ] = graph[i];
      join( graph[i].u, graph[i].v );
    }
  
  printf( "MST's cost: %d\n", cost );
  for ( int i = 0; i < u; i++ )
    printf( "(%d, %d, %d)\n", MST[i].u + 1, MST[i].v + 1, MST[i].w );

  return 0;
}//melkor
