/*
  koder : melkor
  TASK  : Given three integers a, b and n we want to find the solutions
          to the equation ax mod n = b mod n (if there is some)
  
  Running time: O(log n + gcd(a,n))
*/

#include <cstdio>
//#include <conio.h>

typedef long long int64;

int64 a, b, n;
int64 d, x, y, x0;

int64 extended_euclid( int64 a, int64 b, int64& x, int64& y ) {

  int64 g = a;
  x = 1; y = 0;
  
  if ( b != 0 ) {
    g = extended_euclid( b, a % b, y, x );
    y -= ( a / b ) * x;
  }
  
  return g;
}

inline int64 my_mod( int64 a, int64 b ) {
  return ( ( a % b ) + b ) % b;
}

int main() {

  scanf( "%lld %lld %lld", &a, &b, &n );
  
  d = extended_euclid( a, n, x, y );
  if ( b % d == 0 ) {
    x0 = my_mod( x * b / d, n );
    printf( "Solution(s):\n" );
    for ( int i = 0; i < d; i++ )
      printf( "%lld\n", my_mod( x0 + i * n / d, n ) );
  } else printf( "No solution!\n" );
  
  //getch();

  return 0;
}//melkor
