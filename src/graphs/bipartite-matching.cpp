/*
  koder : melkor
  TASK  : Given a bipartite graph G = ( S U V, E ), find a matching between
          vertices from V to S such that its cardinality is maximum.

  Running time: O(V(V+E))
*/

#include <cstdio>
#include <cstring>

#define MAXV 1000
#define MAXE 5000

struct edge {
  int v, next;
} edges[ 2 * MAXE ];

int S, V, edge_count;
int u, v;
int cardinality;

int p[MAXV], match_to[MAXV];
bool mark[MAXV];

bool augment( int u, int *match_to, bool *mark ) {

  if ( u < 0 ) return true;
  
  for ( int i = p[u]; i != -1; i = edges[i].next ) {
    int v = edges[i].v;
	if ( mark[v] ) continue;
	mark[v] = true;
	if ( augment( match_to[v], match_to, mark ) ) {
	  match_to[u] = v;
	  match_to[v] = u;
	  return true;
	}
  }
  
  return false;
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( p, -1, sizeof( p ) );
  memset( match_to, -1, sizeof( match_to ) );
  
  scanf( "%d %d %d", &S, &V, &edge_count );
  for ( int i = 0; i < edge_count; i++ ) {
    
	scanf( "%d %d", &u, &v );
	u--; v--;
	
	edges[i] = ( edge ) { v, p[u] };
	p[u] = i;
	edges[ i + edge_count ] = ( edge ) { u, p[v] };
	p[v] = i + edge_count;
  }
  
  /* Ford-Fulkerson method */
  
  for ( int i = 0; i < S; i++ ) {
    memset( mark, 0, sizeof( mark ) );
	if ( augment( i, match_to, mark ) ) cardinality++;
  }
  
  printf( "%d\n", cardinality );
  for ( int i = 0; i < S; i++ )
    if ( match_to[i] >= 0 )
	  printf( "(%d,%d)\n", i + 1, match_to[i] + 1 );
  
  return 0;
}//melkor
