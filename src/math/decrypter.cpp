/*
  koder : melkor
*/

#include <cstdio>
#include <cstdlib>

typedef long long int64;

int64 d, n;
int64 r;

char cipher[100],
     plain[100];

inline int64 next_int() {

  register char c;
  register int64 ret = 0;
  register int sign = 1;

  while ( ( c = getchar() ) < '0' && c != '-' )
    if ( c == EOF ) exit( 0 );

  if ( c == '-' ) { sign = -1; c = getchar(); }
  
  do {
    ret *= 10;
    ret += c - '0';
  } while ( ( c = getchar() ) >= '0' );

  return ret * sign;
}

int64 power( int64 a, int64 b, const int64 m ) {

  if ( !b ) return 1;
  
  if ( b & 1 ) return ( a * power( a, b - 1, m ) ) % m;
  int64 tmp = power( a, b / 2, m );
  return ( tmp * tmp ) % m;
}

int main() {

  printf( "Enter the name of the encrypted file: " );
  scanf( "%s", cipher );
  
  printf( "Enter the name of the decrypted file: " );
  scanf( "%s", plain );
  
  freopen( cipher, "r", stdin );
  freopen( plain, "w", stdout );
  
  d = next_int();
  n = next_int();
  
  for ( ;; ) {
    r = next_int();
    printf( "%c", power( r, d, n ) );
  }

  return 0;
}//melkor
