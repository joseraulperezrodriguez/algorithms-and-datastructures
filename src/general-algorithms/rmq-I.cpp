/*
  koder : melkor
  TASK  : Range Minimum Query Problem: Given a sequence S of real numbers,
          RMQ(i,j) returns the index of the element in S[i...j] with
          smallest value.
  
  Preprocess Sparse Table --> O(N log N)
  Answer query            --> O(1)
*/

#include <cstdio>

#define MAXN 50005
#define LOGN 16

int N, Q;
int x, y;
int k;

int Log2[MAXN];
int RMQ[MAXN][LOGN];

inline int swap( int &a, int &b ) {
  int t = a; a = b; b = t;
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d %d", &N, &Q );
  for ( int i = 0; i < N; i++ ) scanf( "%d", &RMQ[i][0] );
  
  // Preprocess logarithms
  
  x = -1;
  for ( int i = 1; i <= N; i++ ) {
    if ( !( i & ( i - 1 ) ) ) x++;
    Log2[i] = x;
  }
  
  // Preprocess RMQ
  
  for ( int j = 1; j <= Log2[N]; j++ )
    for ( int i = 0; i + ( 1 << j ) - 1 < N; i++ )
      //RMQ[i][j] = RMQ[i][ j - 1 ] <? RMQ[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ];
    	RMQ[i][j] = RMQ[i][ j - 1 ] < RMQ[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ] ? RMQ[i][ j - 1 ]
    			: RMQ[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ];
  
  // Process queries
  
  for ( int i = 0; i < Q; i++ ) {

    scanf( "%d %d", &x, &y );
    x--; y--;
    
    if ( x > y ) swap( x, y );
    k = Log2[ y - x + 1 ];
    
    int ans = (RMQ[x][k] < RMQ[ y - ( 1 << k ) + 1 ][k] ? RMQ[x][k] : RMQ[ y - ( 1 << k ) + 1 ][k] );
    printf( "%d\n", ans);
  }

  return 0;
}//melkor
