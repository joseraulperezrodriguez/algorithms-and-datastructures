/*
  koder : melkor
  TASK  : GCD & LCM
*/

#include <cstdio>

typedef long long int64;

int64 n, m, r, tmpM, tmpN;

/* ax + by = gcd(a,b) */
int64 extendedGCD( int64 a, int64 b, int64& x, int64& y ) {
  int64 g = a; x = 1; y = 0;
  if ( b != 0 ) {
    g = extendedGCD( b, a % b, y, x );
    y -= ( a / b ) * x;
  }
  return g;
}

int main() {

  scanf( "%lld %lld", &n, &m );
  tmpM = m; tmpN = n;
  
  if ( m < n ) { r = m; m = n; n = r; }
  
  r = m % n;
  while ( r ) {
    m = n; n = r;
    r = m % n;
  }
  
  /* At this point, n is the gcd of m and n's original values   */
  /* Their lcm is tmpM * tmpN / n (a better way of doint his is */
  /* setting tmpM / n * tmpN)                                   */

  return 0;
}//melkor
