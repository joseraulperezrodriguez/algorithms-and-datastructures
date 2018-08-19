/*
  koder : melkor
  TASK  : Andrew's Algorithm for finding Convex Hulls
  
  O(N log N) --> Sorting
  O(N)       --> Find 'lower' and 'upper' hulls
*/

#include <cstdio>
#include <complex>
#include <algorithm>

using namespace std;

#define MAXN 50005

typedef complex< double > point;

int N, H, limit;
double max_dist;

point p[MAXN], hull[ 2 * MAXN ];

bool cmp( const point &a, const point &b ) {
  return real( a ) != real( b ) ? real( a ) < real( b ) : imag( a ) < imag( b );
}

double cross( const point &a, const point &b ) {
  return imag( conj( a ) * b );
}

double area2( const point &a, const point &b, const point &c ) {
  return cross( b - a, c - a );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ ) 
    scanf( "%lf %lf", &real( p[i] ), &imag( p[i] ) );
  
  sort( p, p + N, cmp );
  
  limit = 1;
  for ( int i = 0; i < N; hull[ H++ ] = p[ i++ ] )
    while ( H > limit && area2( hull[ H - 2 ], hull[ H - 1 ], p[i] ) < 0 )
      H--;
  
  limit = H - 1;
  for ( int i = N - 2; i >= 0; hull[ H++ ] = p[ i-- ] )
    while ( H > limit && area2( hull[ H - 2 ], hull[ H - 1 ], p[i] ) < 0 )
      H--;
  
  H--;
  
  printf( "%d\n", H );
  for ( int i = 0; i < H; i++ )
    printf( "%lf %lf\n", real( hull[i] ), imag( hull[i] ) );

  return 0;
}//melkor
