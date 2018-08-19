/*
  koder : melkor
  TASK  : Given two strings find their longest common subsequence
  
  Running time: Theta(nm)
    n: length of s1
    m: length of s2
*/

#include <cstdio>
#include <cstring>

#define MAXLEN 5001
#define oo 1000000000

int n, m;

int dp[MAXLEN][MAXLEN],
    from[MAXLEN][MAXLEN]; /* -1: up, 0: left-up, 1: left */
char s1[MAXLEN],
     s2[MAXLEN];

void build( int x, int y ) {

  if ( !x || !y ) return ;
  
  if ( s1[ x - 1 ] != s2[ y - 1 ] ) {
    if ( from[x][y] == -1 )
         build( x - 1, y );
    else build( x, y - 1 );
  } else {
    build( x - 1, y - 1 );
    printf( "%c", s1[ x - 1 ] );
  }
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%s", s1 );
  scanf( "%s", s2 );
  
  n = strlen( s1 );
  m = strlen( s2 );
  
  /* DP */
  
  for ( int i = 1; i <= n; i++ )
    for ( int j = 0; j <= m; j++ ) {
    
      dp[i][j] = oo;
      
      if ( s1[ i - 1 ] == s2[ j - 1 ] ) {
        dp[i][j] = dp[ i - 1 ][ j - 1 ] + 1;
        from[i][j] = 0;
      } else {
        //dp[i][j] = dp[ i - 1 ][j] >? dp[i][ j - 1 ];
    	dp[i][j] = dp[ i - 1 ][j] > dp[i][ j - 1 ] ? dp[ i - 1 ][j] : dp[i][ j - 1 ];

        from[i][j] = ( dp[ i - 1 ][j] > dp[i][ j - 1 ] ) ? -1 : 1;
      }
    }
  
  printf( "LCS: %d\n", dp[n][m] );
  build( n, m );

  return 0;
}//melkor
