/*
  koder : melkor
  TASK  : Given a DAG find the k shortest paths between two vertices.
*/

#include <cstdio>
#include <queue>

#include <bits/stdc++.h>

using namespace std;

#define MAXV 10000
#define MAXE 50000

typedef pair< int, int > pii;

struct edge {
  int v, w, next;
} edges[MAXE];

int V, edge_count, s, t, k;
int u, v, w, cost;

int p[MAXV];
int counter[MAXV];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );

  memset( p, -1, sizeof( p ) );

  scanf( "%d %d %d %d %d", &V, &edge_count, &s, &t, &k );
  for ( int i = 0; i < edge_count; i++ ) {
    
	scanf( "%d %d %d", &u, &v, &w );
	u--; v--;
	
	edges[i] = ( edge ) { v, w, p[u] };
	p[u] = i;
  }
  
  s--; t--;
  priority_queue< pii, vector< pii >, greater< pii > > Q;
  Q.push( make_pair( 0, s ) );
  
  while ( !Q.empty() ) {
  
    u = Q.top().second;
	cost = Q.top().first;
	Q.pop();
	
	if ( counter[u] == k ) continue;
    if ( u == t ) printf( "%d\n", cost );
	counter[u]++;
	
	for ( int i = p[u]; i != -1; i = edges[i].next ) {
	  v = edges[i].v; w = edges[i].w;
	  if ( counter[v] == k ) continue;
	  Q.push( make_pair( cost + w, v ) );
	}
  }
  
  for ( int i = counter[t]; i < k; i++ )
    printf( "-1\n" );

  return 0;
}//melkor
