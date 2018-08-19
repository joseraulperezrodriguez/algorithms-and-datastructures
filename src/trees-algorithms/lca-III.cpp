/*
  koder : melkor
  TASK  : Lowest Common Ancestor Problem
  
  Running time: <O(N), O(sqrt(N))>
*/

#include <cstdio>
#include <cmath>
#include <queue>

#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000

struct edge {
  int v, next;
} edges[ 2 * ( MAXN - 1 ) ];

int N, queries;
int u, v;
int height, sqrt_height;

int p[MAXN], level[MAXN];
int parent[MAXN], ancestor[MAXN];
bool mark[MAXN];

void dfs( int u ) {

  if ( level[u] < sqrt_height ) ancestor[u] = 0;
  else if ( level[u] % sqrt_height == 0 )
       ancestor[u] = parent[u];
  else ancestor[u] = ancestor[ parent[u] ];
  
  mark[u] = true;
  for ( int i = p[u]; i != -1; i = edges[i].next )
    if ( !mark[ edges[i].v ] ) dfs( edges[i].v );
}

int LCA( int u, int v ) {

  while ( ancestor[u] != ancestor[v] )
    if ( level[u] > level[v] )
         u = ancestor[u];
    else v = ancestor[v];
  
  while ( u != v )
    if ( level[u] > level[v] )
         u = parent[u];
    else v = parent[u];
  
  return u;
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( p, -1, sizeof( p ) );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N - 1; i++ ) {
  
    scanf( "%d %d", &u, &v );
    u--; v--;
    
    edges[i] = ( edge ) { v, p[u] };
    p[u] = i;
    edges[ i + N - 1 ] = ( edge ) { u, p[v] };
    p[v] = i + N - 1;
  }
  
  /*
    BFS to assign levels. This can also be done in the later DFS,
    but I need to compute the square root of the tree's height
  */
  
  queue< int > Q;

  level[0] = height = 0;
  mark[0] = true;
  Q.push( 0 );
  
  while ( !Q.empty() ) {
  
    u = Q.front();
    Q.pop();
    
    for ( int i = p[u]; i != -1; i = edges[i].next ) {
      v = edges[i].v;
      if ( mark[v] ) continue;
      mark[v] = true;
      parent[v] = u;
      level[v] = level[u] + 1;
      //height >?= level[v];
      height = (height >= level[v] ? height : level[v] );
      Q.push( v );
    }
  }
  
  sqrt_height = ( int ) sqrt( height );
  memset( mark, 0, sizeof( mark ) );
  dfs( 0 );
  
  for ( scanf( "%d", &queries ); queries--; ) {
    scanf( "%d %d", &u, &v );
    printf( "LCA(%d,%d) = %d\n", u, v, LCA( u - 1, v - 1 ) + 1 );
  }

  return 0;
}//melkor
