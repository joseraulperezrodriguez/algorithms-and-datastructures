/*
  koder : melkor
  TASK  : Given a set of N points in 2D, find the furthest pair
  
  Running time: O(N log N)
*/

#include <cstdio>
#include <complex>

#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000

#define X( p ) real( p )
#define Y( p ) imag( p )

#define NEXT( x ) ( ( ( x ) + 1 ) % H )

typedef complex< double > point;

int N, H, limit;
double max_dist;

point p[MAXN],
      hull[ 2 * MAXN ];

bool cmp( const point& a, const point& b ) {
  return X( a ) != X( b ) ? X( a ) < X( b ) : Y( a ) < Y( b );
}

double cross( const point& a, const point& b ) {
  return imag( conj( a ) * b );
}

double area2( const point& a, const point& b, const point& c ) {
  return cross( b - a, c - a );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ )
    scanf( "%lf %lf", &X( p[i] ), &Y( p[i] ) );
  
  sort( p, p + N, cmp );
  
  // Andrew's Algorithm for finding Convex Hull
  
  limit = 1;
  for ( int i = 0; i < N; hull[ H++ ] = p[ i++ ] )
    while ( H > limit && area2( hull[ H - 2 ], hull[ H - 1 ], p[i] ) < 0 )
      H--;
  
  limit = H - 1;
  for ( int i = N - 2; i >= 0; hull[ H++ ] = p[ i-- ] )
    while ( H > limit && area2( hull[ H - 2 ], hull[ H - 1 ], p[i] ) < 0 )
      H--;
  H--;
  
  // Find furthest pair
  
  for ( int i = 0, j = 0; i < H; i++ ) {
    //max_dist >?= norm( hull[i] - hull[j] );
	  max_dist = (max_dist >= norm( hull[i] - hull[j] ) ? max_dist :  norm( hull[i] - hull[j] ));
    while ( cross( hull[ NEXT( i ) ] - hull[i],
                   hull[ NEXT( j ) ] - hull[j] ) > 0 ) {
                     j = NEXT( j );
                     //max_dist >?= norm( hull[i] - hull[j] );
                     max_dist = (max_dist >= norm( hull[i] - hull[j] ) ? max_dist :  norm( hull[i] - hull[j] ));
    }
  }
  
  printf( "%lf\n", max_dist );

  return 0;
}//melkor
