/*
  koder : melkor
  TASK  : Tarjan's offline LCA algorithm
*/

#include <cstdio>
#include <cstring>

#define MAXN 5000
#define MAXQ 5000

struct pair {
  int v, next;
};

int N, Q;
int u, v;

int p[MAXN], q[MAXN];
int ancestor[MAXN];
bool mark[MAXN], visited[MAXN];
pair graph[ 2 * ( MAXN - 1 ) ],
     query[ 2 * MAXQ ];

/* disjoint-sets structure */
int data[MAXN];

#define size( u ) ( -data[u] )

int find( int u ) { return data[u] < 0 ? u : data[u] = find( data[u] ); }
void join( int u, int v ) {
  u = find( u ); v = find( v );
  if ( size( u ) < size( v ) ) {
    int t = u; u = v; v = t;
  }
  data[u] += data[v];
  data[v] = u;
}

void dfs( int u ) {

  visited[u] = true;
  ancestor[ find( u ) ] = u;

  for ( int i = p[u]; i != -1; i = graph[i].next ) {
    int v = graph[i].v;
    if ( visited[v] ) continue;
    dfs( v );
    join( u, v );
    ancestor[ find( u ) ] = u;
  }
  
  mark[u] = true;
  for ( int i = q[u]; i != -1; i = query[i].next ) {
    int v = query[i].v;
    if ( !mark[v] ) continue;
    printf( "LCA(%d,%d) = %d\n", u + 1, v + 1, ancestor[ find( v ) ] + 1 );
  }
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  memset( p, -1, sizeof( p ) );
  memset( q, -1, sizeof( q ) );
  memset( data, -1, sizeof( data ) );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N - 1; i++ ) {
  
    scanf( "%d %d", &u, &v );
    u--; v--;
    
    graph[i] = ( pair ) { v, p[u] };
    p[u] = i;
    graph[ i + N - 1 ] = ( pair ) { u, p[v] };
    p[v] = i + N - 1;
  }
  
  scanf( "%d", &Q );
  for ( int i = 0; i < Q; i++ ) {
  
    scanf( "%d %d", &u, &v );
    u--; v--;
    
    query[i] = ( pair ) { v, q[u] };
    q[u] = i;
    if ( u == v ) continue;
    query[ i + Q ] = ( pair ) { u, q[v] };
    q[v] = i + Q;
  }
  
  dfs( 0 );

  return 0;
}//melkor
