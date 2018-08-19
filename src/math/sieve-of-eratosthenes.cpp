/*
  koder : melkor
  TASK  : Sieve of Eratosthenes
*/

#include <cstdio>
#include <cstdlib>

#define MAXN 1000000

int i, j;
bool mark[MAXN];

int main() {

  /* Prime Sieve */

  for ( i = 2; i <= 100; i++ )
    if ( !mark[i] )
      for ( j = 2 * i; j <= MAXN; j += i )
        mark[j] = 1;
  
  for ( i = 2; i <= MAXN; i++ )
    if ( !mark[i] ) printf( "%d ", i );
  
  system( "pause" );

  return 0;
}//melkor
