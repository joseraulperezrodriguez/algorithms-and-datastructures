/*
  koder : melkor
  TASK  : Given a sequence (chain) <A1, A2, ..., An> of n matrices to be
          multiplied, where for i = 1, 2, ...n, matrix Ai has dimension
          p(i-1) x pi, fully parenthesize the product A1 A2 An in a way
          that minimizes the number of scalar multiplications.
  Note  : 0-based
  
  Running time: O(n^3)
*/

#include <cstdio>

#define MAXN 200
#define oo 1000000000

int N, len, i, j, k;
int scalars;
bool error;

int row[MAXN], col[MAXN];
int dp[MAXN][MAXN],
    from[MAXN][MAXN];

void print( int lo, int hi ) {

  if ( lo == hi ) printf( "A%d", lo + 1 );
  else {
    printf( "(" );
    print( lo, from[lo][hi] );
    print( from[lo][hi] + 1, hi );
    printf( ")" );
  }
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  error = false;

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ ) {
    scanf( "%d %d", &row[i], &col[i] );
    if ( i && row[i] != col[ i - 1 ] ) {
      error = true;
      break;
    }
  }
  
  if ( error ) printf( "The sequence cannot be multiplied! Check dimensions.\n" );
  else {
  
    /* DP */
    /* dp[i][j] = minimum number of scalar multiplications needed to */
    /*            multiply matrices from i through j (inclusive)     */
    
    for ( i = 0; i < N; i++ )
      dp[i][i] = 0;
    
    for ( len = 2; len <= N; len++ )
      for ( i = 0; i + len - 1 < N; i++ ) {
        j = i + len - 1;
        dp[i][j] = oo;
        for ( k = i; k < j; k++ ) {
          scalars = row[i] * col[k] * col[j] + dp[i][k] + dp[ k + 1 ][j];
          if ( scalars < dp[i][j] ) {
            dp[i][j] = scalars;
            from[i][j] = k;
          }
        }
      }
    
    printf( "Minimum number of scalars multiplications: %d\n", dp[0][ N - 1 ] );
    print( 0, N - 1 );
  }

  return 0;
}//melkor
