/*
  koder : melkor
  TASK  : Range Minimum-Sum Segment Query Problem
  
  Compute arrays C, P and M --> O(N)
  Preprocess logarithms     --> O(N) 
  Preprocess RMQ            --> O(N log N)
  Answer RMSQ queries       --> O(1)
*/

#include <cstdio>

#define MAXN 50005
#define LGN 16

int N, Q, i, j, x, y, z;

int A[MAXN], lg[MAXN];
int C[MAXN], P[MAXN], M[MAXN], L[MAXN];
int RMQ[MAXN][LGN][2];

int queryRMQ( int i, int j, int b ) {

  int k = lg[ j - i + 1 ];
  if ( !b ) return C[ RMQ[i][k][b] ] <= C[ RMQ[ j - ( 1 << k ) + 1 ][k][b] ] ?
                   RMQ[i][k][b] : RMQ[ j - ( 1 << k ) + 1 ][k][b];
  else return M[ RMQ[i][k][b] ] >= M[ RMQ[ j - ( 1 << k ) + 1 ][k][b] ] ?
              RMQ[i][k][b] : RMQ[ j - ( 1 << k ) + 1 ][k][b];
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d %d", &N, &Q );
  for ( i = 1; i <= N; i++ ) scanf( "%d", &A[i] );
  
  // Compute arrays C, P and M
  
  for ( i = 1; i <= N; i++ ) {
    C[i] = C[ i - 1 ] + A[i];
    L[i] = i - 1; P[i] = i;
    while ( C[ L[i] ] < C[i] && L[i] ) {
      if ( C[ P[ L[i] ] - 1 ] < C[ P[i] - 1 ] ) P[i] = P[ L[i] ];
      L[i] = L[ L[i] ];
    }
    M[i] = C[i] - C[ P[i] - 1 ];
  }
  
  // Preprocess logarithms
  
  lg[0] = -1;
  for ( i = 1; i <= N + 1; i++ )
    lg[i] = lg[ i - 1 ] + !( i & ( i - 1 ) );
  
  // Preprocess array C for RMQmin and array M for RMQmax
  // RMQ[i][j][0] holds the minimum, while RMQ[i][j][1] holds
  // the maximum
  
  for ( i = 0; i <= N; i++ )
    RMQ[i][0][0] = RMQ[i][0][1] = i;
  
  for ( j = 1; j <= lg[ N + 1 ]; j++ )
    for ( i = 0; i + ( 1 << j ) - 1 <= N + 1; i++ ) {
      if ( C[ RMQ[i][ j - 1 ][0] ] <= C[ RMQ[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ][0] ] )
           RMQ[i][j][0] = RMQ[i][ j - 1 ][0];
      else RMQ[i][j][0] = RMQ[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ][0];
      if ( M[ RMQ[i][ j - 1 ][1] ] >= M[ RMQ[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ][1] ] )
           RMQ[i][j][1] = RMQ[i][ j - 1 ][1];
      else RMQ[i][j][1] = RMQ[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ][1];
    }
  
  // Answer queries
  
  for ( int q = 0; q < Q; q++ ) {
  
    scanf( "%d %d", &i, &j );
    
    x = queryRMQ( i, j, 1 );
    if ( P[x] < i ) {
      y = queryRMQ( x + 1, j, 1 );
      z = queryRMQ( i - 1, x - 1, 0 ) + 1;
      if ( C[x] - C[ z - 1 ] < M[y] )
           printf( "%d %d\n", P[y], y );
      else printf( "%d %d\n", z, x );
    }
    else printf( "%d %d\n", P[x], x );
  }

  return 0;
}//melkor
