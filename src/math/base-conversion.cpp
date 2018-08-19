/*
  koder : melkor
  TASK  : Given a radix-10 integer n, output its radix-b representation
  
  Remarks: 2 <= b <= 16
  Running time: O(log n)
*/

#include <cstdio>

const char *digit = "0123456789ABCDEF";

int n, b;

void convert( int n, const int& b ) {
  if ( n < b ) printf( "%c", digit[n] );
  else {
    convert( n / b, b );
    printf( "%c", digit[ n % b ] );
  }
}

int main() {

  scanf( "%d %d", &n, &b );
  
  if ( n < 0 ) {
    printf( "-" );
	n = -n;
  }
  
  convert( n, b );

  return 0;
}//melkor
