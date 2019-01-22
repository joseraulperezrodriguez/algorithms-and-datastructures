/*
  koder : melkor
  TASK  : Floyd-Warshall Algorithm
  
  Running time: O(V^3)
*/

#include <cstdio>
#include <cstring>

#define MAXV 200
#define oo 1000000000

int V, edge_count;
int u, v, w;

int c[MAXV][MAXV],
    p[MAXV][MAXV];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( c, 63, sizeof( c ) );
  
  scanf( "%d %d", &V, &edge_count );
  for ( int i = 0; i < edge_count; i++ ) {
    scanf( "%d %d %d", &u, &v, &w );
    c[ u - 1 ][ v - 1 ] = w;
    p[ u - 1 ][ v - 1 ] = -1;
  }
  
  /* Floyd-Warshall */
  
  for ( int k = 0; k < V; k++ )
    for ( int i = 0; i < V; i++ )
      if ( c[i][k] < oo )
        for ( int j = 0; j < V; j++ ) {
          w = c[i][k] + c[k][j];
          if ( w < c[i][j] ) {
            c[i][j] = w;
            p[i][j] = k;
          }
        }
  
  /* You know the rest ;) */

  return 0;
}//melkor
