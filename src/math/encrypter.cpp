/*
  koder : melkor
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef long long int64;

const int prime[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

int64 p, q, e;
int64 n, phi, d;
int64 x, y;
char c;

char file[100];

int64 power( int64 a, int64 b, const int64 m ) {

  if ( !b ) return 1;
  
  if ( b & 1 ) return ( a * power( a, b - 1, m ) ) % m;
  int64 tmp = power( a, b / 2, m );
  return ( tmp * tmp ) % m;
}

bool rabin_miller( int64 n ) {

  if ( p < 2 || ( p > 2 && !( p % 2 ) ) )
    return false;
  
  for ( int i = 0; i < 10 && prime[i] < n; i++ )
    if ( power( prime[i], n - 1, n ) != 1 )
      return false; /* surely */
  
  return true; /* we hope! */
}

void extended_euclid( int64 a, int64 b ) {

  int64 x1, y1;
  
  if ( !b ) {
    x = 1;
    y = 0;
  } else {
    extended_euclid( b, a % b );
    x1 = x; y1 = y;
    x = y1;
    y = x1 - ( a / b ) * y1;
  }
}

int main() {

  /* Select constants */
  
  srand( time( 0 ) );
  
  do { p = ( rand() % 100 ) + 2; } while ( !rabin_miller( p ) );
  do { q = ( rand() % 100 ) + 2; } while ( !rabin_miller( q ) );
  do { e = ( rand() % 100 ) + 2; } while ( !rabin_miller( e ) );
  
  n = p * q;
  phi = ( p - 1 ) * ( q - 1 );
  
  /* Compute the multiplicative inverse of e modulo phi */
  
  extended_euclid( e, phi );
  d = ( x > 0 ) ? x : x + phi;
  
  /* Encrypt file */
  
  printf( "Enter the name of the file to be encrypted: " );
  scanf( "%s", file );
  
  freopen( file, "r", stdin );
  freopen( "cipher.txt", "w", stdout );
  
  printf( "%lld ", d );
  printf( "%lld ", n );
  
  while ( ( c = getchar() ) != EOF )
    printf( "%lld ", power( c, e, n ) );

  return 0;
}//melkor
