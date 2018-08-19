/*
  koder : melkor
  TASK  : Convex Hull Problem (Graham's Scan)
  
  O(N log N) --> Sorting
  O(N)       --> Find Convex Hull
*/

#include <cstdio>
#include <complex>
#include <algorithm>

using namespace std;

#define MAXN 50005

typedef complex< double > point;

int N, top;

int hull[MAXN];
point p[MAXN];

double cross( const point &a, const point &b ) {
  return imag( conj( a ) * b );
}

bool cmp_p( const point &a, const point &b ) {
  return imag( a ) != imag( b ) ? imag( a ) < imag( b ) : real( a ) < real( b );
}
bool cmp( const point &a, const point &b ) {

  double cp = cross( a - p[0], b - p[0] );
  
  if ( cp < 0 ) return 0;
  if ( cp > 0 ) return 1;
  
  return norm( a - p[0] ) < norm( b - p[0] );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ ) {
    scanf( "%lf %lf", &real( p[i] ), &imag( p[i] ) );
    if ( cmp_p( p[i], p[0] ) ) swap( p[0], p[i] );
  }
  
  sort( p + 1, p + N, cmp );
  
  hull[0] = 0; hull[1] = 1;
  top = 2;
  
  for ( int i = 2; i < N; hull[ top++ ] = i++ )
    while ( top > 1 &&
            cross( p[ hull[ top - 1 ] ] - p[ hull[ top - 2 ] ],
            p[i] - p[ hull[ top - 1 ] ] ) <= 0 )
              top--;
  
  printf( "%d\n", top );
  for ( int i = 0; i < top; i++ )
    printf( "%lf %lf\n", real( p[ hull[i] ] ), imag( p[ hull[i] ] ) );

  return 0;
}//melkor
