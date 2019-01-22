/*
  koder : melkor
  TASK  : Breadth-first search of graph G = (V,E)
  Note  : Assuming G is directed (nonetheless, the algorithm is also
          correct if E consists of undirected edges)
  Running time: O(V + E)
*/

#include <cstdio>
#include <queue>

#include <bits/stdc++.h>

using namespace std;

#define MAXV 10000
#define MAXE 50000
#define oo 1000000000

enum colors { WHITE, GRAY, BLACK };

struct edge {
  int v, next;
} edges[MAXE];

int V, edge_count, src;
int u, v;

int p[MAXV];
int d[MAXV], parent[MAXV];
colors color[MAXV];

int main() {

  memset( p, -1, sizeof( p ) );
  
  scanf( "%d %d %d", &V, &edge_count, &src );
  for ( int i = 0; i < edge_count; i++ ) {
    scanf( "%d %d", &u, &v );
    edges[i] = ( edge ) { v, p[u] };
    p[u] = i;
  }
  
  /* BFS */
  
  queue< int > Q;
  for ( int i = 0; i < V; i++ ) {
    d[i] = oo;
    parent[i] = -1;
    color[i] = WHITE;
  }
  
  d[src] = 0;
  parent[src] = -1;
  color[src] = GRAY;
  Q.push( src );
  
  while ( !Q.empty() ) {
  
    u = Q.front();
    Q.pop();
    
    for ( int i = p[u]; i != -1; i = edges[i].next ) {
      v = edges[i].v;
      if ( color[v] == WHITE ) {
        color[v] = GRAY;
        d[v] = d[u] + 1;
        parent[v] = u;
        Q.push( v );
      }
    }
    
    color[u] = BLACK;
  }

  return 0;
}//melkor
