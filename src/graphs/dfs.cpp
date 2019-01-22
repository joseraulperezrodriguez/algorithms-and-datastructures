/*
  koder : melkor
  TASK  : Depth-first search of graph G = (V,E)
  Note  : Assuming G is directed (nonetheless, the algorithm is also
          correct if E consists of undirected edges)
  Running time: O(V + E)
*/

#include <cstdio>
#include <cstring>

#define MAXV 10000
#define MAXE 50000
#define oo 1000000000

enum colors { WHITE, GRAY, BLACK };
enum types  { TREE, BACK, FORWARD, CROSS };

struct edge {
  int v, next;
  types type;
} edges[MAXE];

int V, edge_count;
int u, v;
int time;

int p[MAXV], parent[MAXV];
int d[MAXV], f[MAXV];
colors color[MAXV];

void dfs( int u ) {

  color[u] = GRAY;
  d[u] = ++time;
  
  for ( int i = p[u]; i != -1; i = edges[i].next ) {
    int v = edges[i].v;
    if ( color[v] == WHITE ) {
      parent[v] = u;
      edges[i].type = TREE;
      dfs( v );
    }
    else if ( color[v] == GRAY ) edges[i].type = BACK;
    else if ( d[u] < d[v] ) edges[i].type = FORWARD;
    else edges[i].type = CROSS;
  }
  
  color[u] = BLACK;
  f[u] = ++time;
}

int main() {

  memset( p, -1, sizeof( p ) );
  
  scanf( "%d %d %d", &V, &edge_count );
  for ( int i = 0; i < edge_count; i++ ) {
    scanf( "%d %d", &u, &v );
    edges[i] = ( edge ) { v, p[u] };
    p[u] = i;
  }
  
  /* DFS */
  
  for ( int i = 0; i < V; i++ ) {
    d[i] = f[i] = oo;
    parent[i] = -1;
    color[i] = WHITE;
  }
  
  time = 0;
  for ( int i = 0; i < V; i++ )
    if ( color[i] == WHITE ) dfs( i );

  return 0;
}//melkor
