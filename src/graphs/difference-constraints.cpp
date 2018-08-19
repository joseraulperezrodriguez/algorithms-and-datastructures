/*
  koder : melkor
  TASK  : Given an m x n matrix A (where each row contains one 1 and one -1,
          and all other entries are 0) and an m-vector b, we wish to find an
          n-vector x that satisfies Ax <= b.
          Given the singularity of A, this problem can be reformulated as
          finding n unknowns xi (for i = 1..n) that satisfy xj - xi <= bk,
          where 1 <= i, j <= n and 1 <= k <= m.
*/

#include <cstdio>

#include <bits/stdc++.h>

#define MAXN 1000
#define MAXM 2000

struct edge {
  int u, v, w;
} edges[MAXM];

int N, M;
int xi, xj, bk;
bool solvable;

int d[MAXN];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d %d", &N, &M );
  for ( int i = 0; i < M; i++ ) {
    scanf( "%d %d %d", &xj, &xi, &bk );
    edges[i] = ( edge ) { xi - 1, xj - 1, bk };
  }
  
  /* Bellman-Ford Algorithm */
  
  solvable = true;
  for ( int i = 0; i < N; i++ ) d[i] = 0;
  
  for ( int i = 0; i < N - 1; i++ )
    for ( int j = 0; j < M; j++ )
      //d[ edges[j].v ] <?= d[ edges[j].u ] + edges[j].w;
    	d[ edges[j].v ] = (d[ edges[j].v ] <= d[ edges[j].u ] + edges[j].w ? d[ edges[j].v ] : d[ edges[j].u ] + edges[j].w );
  
  for ( int i = 0; i < M; i++ )
    if ( d[ edges[i].u ] + edges[i].w < d[ edges[i].v ] ) {
      solvable = false;
      break;
    }
  
  if ( !solvable ) printf( "There is no feasible solution for the problem!\n" );
  else {
    printf( "Feasible solution for the problem:\n" );
    for ( int i = 0; i < N; i++ )
      printf( "x%d = %d\n", i + 1, d[i] );
  }

  return 0;
}//melkor
