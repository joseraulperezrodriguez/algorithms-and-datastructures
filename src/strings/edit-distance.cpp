/*
  koder : melkor
  TASK  : Edit distance problem: we define the "edit" distance of two
          strings to be the minimum number of edit operations (insertion,
          deltetion and change) to transform one string into another. Given
          two strings find their edit distance.
  
  Running time: Theta(nm)
    n: length of string S1
    m: length of string S2
*/

#include <cstdio>
#include <cstring>

#define MAXLEN 5001
#define oo 1000000000

enum operations { INSERT, DELETE, CHANGE, NO_CHANGE };

int n, m;

int dp[MAXLEN][MAXLEN];
operations op[MAXLEN][MAXLEN];
char s1[MAXLEN],
     s2[MAXLEN];

void build( int x, int y ) {

  if ( !x && !y ) return ;
  
  if ( op[x][y] == INSERT ) {
    build( x, y - 1 );
    printf( "insert(%c)\n", s2[ y - 1 ] );
  } else if ( op[x][y] == DELETE ) {
    build( x - 1, y );
    printf( "delete(%c)\n", s1[ x - 1 ] );
  } else {
    build( x - 1, y - 1 );
    if ( op[x][y] == CHANGE )
      printf( "change(%c,%c)\n", s1[ x - 1 ], s2[ y - 1 ] );
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
  
  for ( int i = 0; i <= n; i++ )
    dp[i][0] = i, op[i][0] = DELETE;
  for ( int j = 0; j <= m; j++ )
    dp[0][j] = j, op[0][j] = INSERT;
  
  for ( int i = 1; i <= n; i++ )
    for ( int j = 1; j <= m; j++ ) {
    
      dp[i][j] = oo;
      int delta = !( s1[ i - 1 ] == s2[ j - 1 ] );
      
      if ( dp[ i - 1 ][j] + 1 < dp[i][j] ) {
        dp[i][j] = dp[ i - 1 ][j] + 1;
        op[i][j] = DELETE;
      }
      if ( dp[i][ j - 1 ] + 1 < dp[i][j] ) {
        dp[i][j] = dp[i][ j - 1 ] + 1;
        op[i][j] = INSERT;
      }
      if ( dp[ i - 1 ][ j - 1 ] + delta < dp[i][j] ) {
        dp[i][j] = dp[ i - 1 ][ j - 1 ] + delta;
        op[i][j] = ( delta ) ? CHANGE : NO_CHANGE;
      }
    }
  
  printf( "%s\n%s\n", s1, s2 );
  printf( "Edit distance = %d\n", dp[n][m] );
  build( n, m );

  return 0;
}//melkor
