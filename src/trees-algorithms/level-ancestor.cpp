/*
  koder : melkor
  TASK  : Level Ancestor Problem: Given a tree T with N nodes, a Level
          Ancestor Query LA(u,d) requests the depth d ancestor of node u.
  
  
  Remarks: Using Jump-Pointers Algorithm
  Running time: <O(N log N), O(log N)>
*/

#include <cstdio>
#include <queue>

#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000
#define LOG 17

struct edge {
  int v, next;
} edges[ MAXN - 1 ];

int N, edge_count, queries;
int u, v, d;

int p[MAXN], lg[MAXN];
int depth[MAXN];
bool mark[MAXN];

int LA[MAXN][LOG]; /* LA[i][j] stores the (2^j)-th ancestor of node i */

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  lg[0] = -1;
  for ( int i = 1; i < MAXN; i++ )
    lg[i] = lg[ i - 1 ] + !( i & ( i - 1 ) );
  
  memset( p, -1, sizeof( p ) );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N - 1; i++ ) {

    scanf( "%d %d", &u, &v );
    u--; v--;
    
    edges[edge_count] = ( edge ) { v, p[u] };
    p[u] = edge_count++;
    edges[edge_count] = ( edge ) { u, p[v] };
    p[v] = edge_count++;
  }
  
  /* Assign depths and compute table LA[][] */
  
  queue< int > Q;
  
  depth[0] = LA[0][0] = 0;
  mark[0] = 1;
  Q.push( 0 );
  
  while ( !Q.empty() ) {
  
    u = Q.front();
    Q.pop();
    
    for ( int i = p[u]; i != -1; i = edges[i].next ) {
      
      v = edges[i].v;
      if ( mark[v] ) continue;
      
      depth[v] = depth[u] + 1;
      mark[v] = 1;
      Q.push( v );
      
      LA[v][0] = u;
      for ( int j = 1; j <= lg[ depth[v] ]; j++ )
        LA[v][j] = LA[ LA[v][ j - 1 ] ][ j - 1 ];
    }
  }
  
  /* Process queries */
  
  for ( scanf( "%d", &queries ); queries--; ) {
  
    scanf( "%d %d", &u, &d );
    v = u--;
    
    if ( d > depth[u] )
         printf( "LA(%d,%d) is undefined!\n", v, d );
    else {
      for ( int i = lg[ depth[u] ]; i >= 0; i-- )
        if ( depth[u] - ( 1 << i ) >= d )
          u = LA[u][i];
      
      printf( "LA(%d,%d) = %d\n", v, d, u + 1 );
    }
  }

  return 0;
}//melkor
