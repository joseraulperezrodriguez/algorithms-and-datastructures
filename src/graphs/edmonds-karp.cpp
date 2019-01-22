/*
  koder : melkor
  TASK  : Edmonds-Karp algorithm for finding a maximum flow in a graph
  Note  : 0-based
          This code covers the general version, where multiple edges
          between vertices are allowed. In a more restricted case
          (i.e. when there is only one edge between every pair of
          vertices), vector edges[] is not necessary: we can use a
          matrix cap[][] where cap[i][j] holds the current capacity
          of edge (i,j). When updating the residual network, if we have
          pushed x units of flow across edge (i,j), we set
            cap[i][j] = cap[i][j] - x
            cap[j][i] = cap[j][i] + x
*/

#include <cstdio>
#include <queue>

#include <bits/stdc++.h>

using namespace std;

#define MAXV 100
#define MAXE 200

struct edge {
  int u, v, cap, flow, next;
  bool original;
} edges[ 2 * MAXE ];

int V, edge_count, src, snk;
int u, v, c;
int counter, flow, res_cap;

int p[MAXV], from[MAXV];
bool mark[MAXV];

void create_edge( int u, int v, int c ) {
  edges[counter] = ( edge ) { u, v, c, 0, p[u], 1 };
  p[u] = counter++;
  edges[counter] = ( edge ) { v, u, c, c, p[v], 0 };
  p[v] = counter++;
}

bool augment( int src, int snk ) {

  memset( mark, 0, sizeof( mark ) );
  queue< int > Q;
  
  /* BFS */
  
  mark[src] = true;
  Q.push( src );
  
  while ( !mark[snk] && !Q.empty() ) {
  
    u = Q.front();
    Q.pop();
    
    for ( int i = p[u]; i != -1; i = edges[i].next ) {
      v = edges[i].v;
      if ( !mark[v] && edges[i].flow < edges[i].cap ) {
        mark[v] = true;
        from[v] = i;
        Q.push( v );
      }
    }
  }
  
  if ( !mark[snk] ) return false;
  
  res_cap = INT_MAX;
  for ( int i = snk; i != src; i = edges[ from[i] ].u )
    //res_cap <?= edges[ from[i] ].cap - edges[ from[i] ].flow;
	  res_cap = (res_cap <= edges[ from[i] ].cap - edges[ from[i] ].flow ? res_cap :
			  edges[ from[i] ].cap - edges[ from[i] ].flow);
    
  for ( int i = snk; i != src; i = edges[ from[i] ].u ) {
    edges[ from[i] ].flow += res_cap;
    edges[ from[i] ^ 1 ].flow -= res_cap;
  }
  return true;
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( p, -1, sizeof( p ) );
  counter = 0;
  
  scanf( "%d %d %d %d", &V, &edge_count, &src, &snk );
  for ( int i = 0; i < edge_count; i++ ) {
    scanf( "%d %d %d", &u, &v, &c );
    create_edge( u, v, c );
  }
  
  /* Edmonds-Karp */
  
  flow = 0;
  while ( augment( src, snk ) )
    flow += res_cap;
  
  printf( "Total network flow: %d\n", flow );
  for ( int i = 0; i < counter; i++ )
    if ( edges[i].original && edges[i].flow > 0 )
      printf( "f(%d,%d)=%d\n", edges[i].u, edges[i].v, edges[i].flow );

  return 0;
}//melkor
