/*
  koder : melkor
  TASK  : Manacher's Algorithm
  
  Original version of the problem, where only palindromes
  of even length are computed.
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXLEN 100000

int n, i, j, k;

int rad[MAXLEN];
char s[MAXLEN];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%s", s );
  n = strlen( s );
  
  for ( i = j = 0; i < n; i += k ) {
  
    while ( i - j >= 0 && i + j + 1 < n &&
            s[ i - j ] == s[ i + j + 1 ] )
              j++;
    
    rad[i] = j;
    for ( k = 1; k <= rad[i] && rad[ i - k ] != rad[i] - k; k++ )
      rad[ i + k ] = min( rad[ i - k ], rad[i] - k );
    
    j = max( j - k, 0 );
  }
  
  printf( "%s\n\n", s );
  for ( i = 0; i < n; i++ )
    printf( "pos: %3d, rad[pos]: %3d\n", i + 1, rad[i] );

  return 0;
}//melkor
