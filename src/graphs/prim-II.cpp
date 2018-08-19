/*
  koder : melkor
  TASK  : Prim's Algorithm for finding the MST of a connected,
          undirected graph
  
  Running time: O(E log V)
*/

#include <cstdio>
#include <set>

#include <bits/stdc++.h>

using namespace std;

#define MAXV 50000
#define MAXE 100000
#define oo 1000000000

typedef pair< int, int > pii;

struct edge {
  int v, w, next;
} edges[ 2 * MAXE ];

int V, E, cost;
int u, v, w, dist;

int p[MAXV], d[MAXV];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( p, -1, sizeof( p ) );
  
  scanf( "%d %d", &V, &E );
  for ( int i = 0; i < E; i++ ) {

    scanf( "%d %d %d", &u, &v, &w );
    u--; v--;

    edges[i] = ( edge ) { v, w, p[u] };
    p[u] = i;
    edges[ i + E ] = ( edge ) { u, w, p[v] };
    p[v] = i + E;
  }
  
  /* Prim's Algorithm */
  
  set< pii > S;
  for ( int i = 0; i < V; i++ )
    d[i] = oo;
  
  d[0] = cost = 0;
  
  S.insert( make_pair( 0, 0 ) );
  while ( !S.empty() ) {
  
    pii top = *S.begin();
    S.erase( S.begin() );

    u = top.second;
    dist = top.first;
    
    cost += dist;
    
    for ( int i = p[u]; i != -1; i = edges[i].next ) {
      v = edges[i].v; w = edges[i].w;
      if ( w < d[v] ) {
        if ( d[v] != oo )
          S.erase( S.find( make_pair( d[v], v ) ) );
        d[v] = w;
        S.insert( make_pair( d[v], v ) );
      }
    }
  }
  
  printf( "MST's cost: %d\n", cost );

  return 0;
}//melkor
