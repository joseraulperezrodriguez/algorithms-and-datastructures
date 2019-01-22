/*
  koder : melkor
  TASK  : Dijkstra's Single-Source Shortst-Paths Algorithm
  
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
} edges[MAXE];

int V, edge_count, source;
int u, v, w, dist;

int p[MAXV], d[MAXV];

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
  
  set< pii > S;
  for ( int i = 0; i < V; i++ )
    d[i] = oo;
  
  d[ --source ] = 0;
  
  S.insert( make_pair( 0, source ) );
  for ( int i = 0; i < V; i++ ) {
  
    pii top = *S.begin();
    S.erase( S.begin() );
    
    u = top.second;
    dist = top.first;
    
    for ( int i = p[u]; i != -1; i = edges[i].next ) {
      v = edges[i].v; w = edges[i].w;
      if ( d[u] + w < d[v] ) {
        if ( d[v] != oo )
          S.erase( S.find( make_pair( d[v], v ) ) );
        d[v] = d[u] + w;
        S.insert( make_pair( d[v], v ) );
      }
    }
  }

  return 0;
}//melkor
