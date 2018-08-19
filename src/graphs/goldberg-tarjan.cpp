/*
  koder : melkor
  TASK  : Goldberg's generic algorithm for finding a maximum flow
          in a graph.

  Remarks: Assuming the graph is directed.
  Running time: O(EV^2)
*/

#include <cstdio>
#include <queue>

#include <bits/stdc++.h>

using namespace std;

#define MAXV 100
#define MAXE 300

struct edge {
  int u, v, next;
} edges[ 2 * MAXE ];

int V, E, s, t;
int u, v, cap;

int p[MAXV];
int h[MAXV], e[MAXV];
bool in_queue[MAXV];
int c[MAXV][MAXV],
	f[MAXV][MAXV];

void push( int u, int v ) {
  int temp = min( e[u], c[u][v] - f[u][v] );
  f[u][v] += temp;
  f[v][u] = -f[u][v];
  e[u] -= temp;
  e[v] += temp;
}

void relabel( int u ) {
  int temp = -1;
  for ( int i = p[u]; i != -1; i = edges[i].next ) {
    int v = edges[i].v;
    if ( c[u][v] - f[u][v] > 0 && h[u] <= h[v] )
      if ( temp == -1 || h[v] < temp )
        temp = h[v];
  }
  h[u] = 1 + temp;
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( p, -1, sizeof( p ) );
  
  scanf( "%d %d %d %d", &V, &E, &s, &t );
  for ( int i = 0; i < E; i++ ) {
  
    scanf( "%d %d %d", &u, &v, &cap );
    u--; v--;
    
    c[u][v] = cap;
    edges[i] = ( edge ) { u, v, p[u] };
    p[u] = i;
    edges[ i + E ] = ( edge ) { v, u, p[v] };
    p[v] = i + E;
  }
  
  /* Initialize preflow */
  
  queue< int > Q;
  s--; t--;
  
  h[s] = V;
  for ( int i = p[s]; i != -1; i = edges[i].next ) {
    v = edges[i].v;
    f[s][v] = c[s][v];
    f[v][s] = -f[s][v];
    e[v] = f[s][v];
    e[s] -= f[s][v];
    if ( v != t ) {
      Q.push( v );
      in_queue[v] = true;
    }
  }
  
  /* Goldberg's generic maximum-flow algorithm */
  
  while ( !Q.empty() ) {

    u = Q.front();

    for ( int i = p[u]; i != -1; i = edges[i].next ) {
      v = edges[i].v;
      if ( c[u][v] - f[u][v] > 0 && h[u] == h[v] + 1 ) {
        push( u, v );
        if ( v != s && v != t && !in_queue[v] ) {
          Q.push( v );
          in_queue[v] = true;
        }
        if ( e[u] == 0 ) break;
      }
    }
    
    if ( e[u] > 0 ) relabel( u );
    if ( e[u] == 0 ) {
      Q.pop();
      in_queue[u] = false;
    }
  }
  
  printf( "Maximum network flow: %d\n", e[t] );
  for ( int i = 0; i < E; i++ ) {
    u = edges[i].u;
    v = edges[i].v;
    if ( f[u][v] > 0 )
      printf( "f(%d,%d) = %d\n", u + 1, v + 1, f[u][v] );
  }
  
  return 0;
}//melkor
