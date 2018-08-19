/*
  koder : melkor
  TASK  : Big integers "library"
*/

#include <algorithm>
#include <string>

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int BASE = 100000000; /* power of 10 */
const int LOG_BASE = 8;
const int MAXDIGITS = 10000; /* it can represent LOG_BASE * MAXDIGITS digits (in base 10) */

struct bigInt {
  int size;
  int64 digit[MAXDIGITS];
  bigInt( int size = 1, int64 a = 0 ) : size( size ) {
    memset( digit, 0, sizeof( digit ) );
	digit[0] = a;
  }
};

const bigInt ZERO( 1, 0 ), ONE( 1, 1 );

/* Comparators */
bool operator < ( const bigInt& x, const bigInt& y ) {
  if ( x.size != y.size ) return x.size < y.size;
  for ( int i = x.size - 1; i >= 0; i-- )
    if ( x.digit[i] != y.digit[i] )
	  return x.digit[i] < y.digit[i];
  return 0;
}
bool operator > ( const bigInt& x, const bigInt& y ) { return y < x; }
bool operator <= ( const bigInt& x, const bigInt& y ) { return !( y < x ); }
bool operator >= ( const bigInt& x, const bigInt& y ) { return !( x < y ); }
bool operator != ( const bigInt& x, const bigInt& y ) { return x < y || y < x; }
bool operator == ( const bigInt& x, const bigInt& y ) { return !( x < y ) && !( y < x ); }

/* Utilities */
bigInt normal( bigInt x ) {

  int64 c = 0, a;
  for ( int i = 0; i < x.size; i++ ) {
    while ( x.digit[i] < 0 )
	  x.digit[ i + 1 ] -= 1, x.digit[i] += BASE;
	a = x.digit[i] + c;
	x.digit[i] = a % BASE;
	c = a / BASE;
  }
  
  for ( ; c > 0; c /= BASE ) x.digit[ x.size++ ] = c % BASE;
  while ( x.size > 1 && x.digit[ x.size - 1 ] == 0 ) x.size--;
  
  return x;
}
bigInt convert( int64 a ) { return normal( bigInt( 1, a ) ); }
bigInt convert( const string& s ) {

  bigInt x;
  
  int size = s.size(),
      i = size % LOG_BASE;
  if ( i > 0 ) i -= LOG_BASE;
  for ( ; i < size; i += LOG_BASE ) {
    int64 a = 0;
    for ( int j = 0; j < LOG_BASE; j++ )
      a = 10 * a + ( i + j >= 0 ? s[ i + j ] - '0' : 0 );
    x.digit[ x.size++ ] = a;
  }
  
  reverse( x.digit, x.digit + x.size );
  return normal( x );
}

/* Basic operations */
bigInt operator + ( const bigInt& x, const bigInt& y ) {
  //bigInt z( x.size >? y.size );
	bigInt z( x.size > y.size ? x.size : y.size);
  for ( int i = 0; i < z.size; i++ )
    z.digit[i] = x.digit[i] + y.digit[i];
  return normal( z );
}
bigInt operator + ( bigInt x, int64 a ) {
  x.digit[0] += a;
  return normal( x );
}
bigInt operator - ( const bigInt& x, const bigInt& y ) {
  assert( x >= y );
  bigInt z = x;
  for ( int i = 0; i < y.size; i++ )
    z.digit[i] -= y.digit[i];
  return normal( z );
}
bigInt operator - ( bigInt x, int64 a ) {
  x.digit[0] -= a;
  return normal( x );
}
bigInt operator * ( const bigInt& x, const bigInt& y ) {
  bigInt z( x.size + y.size );
  for ( int i = 0; i < x.size; i++ )
    for ( int j = 0; j < y.size; j++ )
	  z.digit[ i + j ] = x.digit[i] * y.digit[j];
  return normal( z );
}
bigInt operator * ( bigInt x, int64 a ) {
  for ( int i = 0; i < x.size; i++ )
    x.digit[i] *= a;
  return normal( x );
}
pair< bigInt, int64 > divmod( bigInt x, int64 a ) {

  int64 c = 0, t;
  for ( int i = x.size - 1; i >= 0; i-- ) {
    t = BASE * c + x.digit[i];
    x.digit[i] = t / a;
    c = t % a;
  }

  return pair< bigInt, int64 > ( normal( x ), c );
}
bigInt operator / ( const bigInt& x, int64 a ) {
  return divmod( x, a ).first;
}
int64 operator % ( const bigInt& x, int64 a ) {
  return divmod( x, a ).second;
}

void print( const bigInt& x ) {
  printf( "%lld", x.digit[ x.size - 1 ] );
  for ( int i = x.size - 2; i >= 0; i-- )
    printf( "%08lld", x.digit[i] );
}

int main() {
  return 0;
}//melkor
