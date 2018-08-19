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
} edge[MAXE], MST[MAXV];

int V, E, cost;
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
  
  scanf( "%d %d", &V, &E );
  for ( int i = 0; i < E; i++ ) {
    scanf( "%d %d %d", &u, &v, &w );
    u--; v--;
    edge[i] = ( Edge ) { u, v, w };
  }
  
  /* Kruskal's Algorithm */
  
  sort( edge, edge + E );
  
  cost = u = 0;
  for ( int i = 0; i < E; i++ )
    if ( find( edge[i].u ) != find( edge[i].v ) ) {
      cost += edge[i].w;
      MST[ u++ ] = edge[i];
      join( edge[i].u, edge[i].v );
    }
  
  printf( "MST's cost: %d\n", cost );
  for ( int i = 0; i < u; i++ )
    printf( "(%d, %d, %d)\n", MST[i].u + 1, MST[i].v + 1, MST[i].w );

  return 0;
}//melkor
