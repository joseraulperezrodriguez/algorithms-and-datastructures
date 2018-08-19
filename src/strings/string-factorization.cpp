/*
  koder : melkor
  TASK  : 'Factorize' a string!!!
*/

#include <cstdio>
#include <cstring>

#define MAXLEN 1005

int len, size, cost;
int i, j, k;

char s[MAXLEN];
int log[MAXLEN], fail[MAXLEN];
int fact[MAXLEN][MAXLEN];
int dp[MAXLEN][MAXLEN],
    from[MAXLEN][MAXLEN];

void print( int lo, int hi ) {

  if ( lo == hi ) {
    printf( "%c", s[lo] );
    return;
  }
  
  if ( from[lo][hi] >= 0 ) {
    print( lo, from[lo][hi] );
    print( from[lo][hi] + 1, hi );
  }
  else {
    printf( "(" );
    print( lo, lo - from[lo][hi] - 1 );
    printf( ")%d", ( hi - lo + 1 ) / -from[lo][hi] );
  }
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%s", s );
  len = strlen( s );
  
  /* Calculate logarithms */
  
  for ( i = 0; i < len; i++ ) {
    log[i] = ( i > 9 ) + ( i > 99 ) + ( i > 999 );
    if ( i < len ) dp[i][i] = 1;
  }
  
  /* String Factorization */
  
  for ( k = 0; k < len; k++ ) {
  
    fact[k][k] = 1;
    
    /* KMP's automaton */
    for ( j = 0, i = k + 1; i < len; i++ ) {

      while ( j && s[ k + j ] != s[i] ) j = fail[j];
      
      if ( s[ k + j ] == s[i] ) j++;
      
      int ln = i - k + 1;
      fail[ln] = j;
      
      if ( j && ln % ( ln - j ) == 0 )
           fact[k][i] = ln - j;
      else fact[k][i] = -1;
    }
  }
  
  /* DP */
  
  for ( size = 1; size < len; size++ )
    for ( i = 0; i < len - size; i++ ) {
    
      j = i + size;
      
      /* Factorize */
      if ( ( k = fact[i][j] ) != -1 ) {
        dp[i][j] = dp[i][ i + k - 1 ] + log[ ( size + 1 ) / k ] + 3;
        from[i][j] = -k;
      }
      else dp[i][j] = 1000000000;
      
      /* Concatenate */
      for ( k = i; k < j; k++ ) {
        cost = dp[i][k] + dp[ k + 1 ][j];
          if ( cost < dp[i][j] ) {
            dp[i][j] = cost;
            from[i][j] = k;
          }
      }
    }
  
  print( 0, len - 1 );
  printf( "\n" );

  return 0;
}//melkor
