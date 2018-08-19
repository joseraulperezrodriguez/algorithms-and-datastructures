/*
  koder : melkor
  TASK  : We define a graph's edge to be a "bridge" if its removal causes
          the graph to become disconnected. Given a connected, undirected
          graph G = (V,E) find its "bridges".
  
  Running time: O(V + E)
*/

#include <cstdio>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

#define MAXV 10000
#define MAXE 30000

#define BACK( x ) ( ( x < E ) ? x + E : x - E )

struct edge {
  int v, next;
} edges[ 2 * MAXE ];

int V, E;
int u, v;
int _time;

int p[MAXV];
int dfsn[MAXV], low[MAXV];
bool cut[ 2 * MAXE ];
vector< pair< int, int > > bridges;

void dfs( int u ) {

  dfsn[u] = low[u] = ++_time;
  
  for ( int i = p[u]; i != -1; i = edges[i].next ) {
    int v = edges[i].v;
    if ( !dfsn[v] ) {
      cut[ BACK( i ) ] = 1;
      dfs( v );
      //low[u] <?= low[v];
      low[u] = (low[u] <= low[v] ? low[u] : low[v]);

      if ( low[v] > dfsn[u] )
        bridges.push_back( make_pair( u, v ) );
    } else if ( !cut[i] ) {
    	//low[u] <?= dfsn[v];
    	low[u] = (low[u] <= dfsn[v] ? low[u] : dfsn[v]);

    }
  }
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( p, -1, sizeof( p ) );
  
  scanf( "%d %d", &V, &E );
  for ( int i = 0; i < E; i++ ) {
  
    scanf( "%d %d", &u, &v );
    u--; v--;
    
    edges[i] = ( edge ) { v, p[u] };
    p[u] = i;
    edges[ i + E ] = ( edge ) { u, p[v] };
    p[v] = i + E;
  }
  
  dfs( 0 );
  
  int size = bridges.size();
  printf( "%d\n", size );
  for ( int i = 0; i < size; i++ )
    printf( "(%d,%d)\n", bridges[i].first + 1, bridges[i].second + 1 );

  return 0;
}//melkor
