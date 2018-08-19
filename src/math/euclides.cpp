/*
  koder : melkor
  TASK  : Given two nonnegative integers a and b find their gcd,
          lcm and the integer coefficients x and y such that
          ax + by = gcd(a,b)
  
  Runing time: O(log b)
*/

#include <cstdio>
//#include <conio.h>

typedef long long int64;

int64 a, b, d, x, y;
int64 a2, b2, r;

int64 extended_euclid( int64 a, int64 b, int64& x, int64& y ) {

  int64 g = a;
  x = 1; y = 0;
  
  if ( b != 0 ) {
    g = extended_euclid( b, a % b, y, x );
    y -= ( a / b ) * x;
  }
  
  return g;
}

int main() {

  scanf( "%lld %lld", &a, &b );
  
  /* Euclid's algorithm for finding the gcd */
  
  a2 = a; b2 = b;
  r = a2 % b2;
  while ( r != 0 ) {
    a2 = b2; b2 = r;
    r = a2 % b2;
  }
  
  printf( "gcd: %lld\n", b2 );
  printf( "lcm: %lld\n", a / b2 * b ); /* lcm(a,b) = a * b / gcd(a,b) */
  
  /* Find x and y such that ax + by = d = gcd(a,b) */
  
  d = extended_euclid( a, b, x, y );
  
  printf( "x = %lld\n", x );
  printf( "y = %lld\n", y );
  
  //getch();

  return 0;
}//melkor
