/*
  koder : melkor
  TASK  : Manacher's Algorithm
  
  This version computes both even and odd palindromes.
  Vector rad[] is really the length of the palindromes,
  that is, rad[i] is the length of the palindrome centered
  at i (odd palindromes are in rad[ 2 * i ] and even ones
  in rad[ 2 * i + 1 ])
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXLEN 100000

int n, i, j, k;

int rad[ 2 * MAXLEN ];
char s[MAXLEN];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );

  scanf( "%s", s );
  n = strlen( s );

  for ( i = 0, j = 0; i < 2 * n - 1; i += k ) {

    while ( i - j >= 0 && i + j + 1 < 2 * n &&
            s[ ( i - j ) / 2 ] == s[ ( i + j + 1 ) / 2 ] )
              j++;

	rad[i] = j;
    for ( k = 1; k <= rad[i] && rad[ i - k ] != rad[i] - k; k++ )
      rad[ i + k ] = min( rad[ i - k ], rad[i] - k );

	j = max( j - k, 0 );
  }

  printf( "%s\n\n", s );
  for ( i = 0; i < n; i++ ) {
    printf( "pos: %3d, odd length:  %3d\n", i + 1, rad[ 2 * i ] );
    printf( "pos: %3d, even length: %3d\n", i + 1, rad[ 2 * i + 1 ] );
  }

  return 0;
}//melkor
