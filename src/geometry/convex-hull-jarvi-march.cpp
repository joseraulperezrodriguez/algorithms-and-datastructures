/*
  koder : melkor
  TASK  : Finding a polygon's convex hull

  Remarks: Using Jarvis' March (gift wrapping)
           Not dealing with colinear points
  Running time: O(nh)
          n: number of vertices of the polygon
          h: number of vertices of the polygon's convex hull
*/

#include <cstdio>
#include <complex>

using namespace std;

#define MAXN 10000

#define X( p ) real( p )
#define Y( p ) imag( p )

typedef complex< int > point;

int N, H, cp;
int start, curr, next;

int hull[MAXN];
point p[MAXN];

bool operator < ( const point& a, const point& b ) {
  return X( a ) != X( b ) ? X( a ) < X( b ) : Y( a ) < Y( b );
}
int cross( point a, point b ) {
  return imag( conj( a ) * b );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ ) {
    scanf( "%d %d", &X( p[i] ), &Y( p[i] ) );
    if ( p[i] < p[0] ) swap( p[i], p[0] );
  }
  
  /* Jarvis' March */
  
  curr = H = 0;
  do {
    hull[ H++ ] = curr;
    next = -1;
    for ( int i = 0; i < N; i++ ) {
      if ( i == curr ) continue;
      if ( next == -1 ) next = i;
      cp = cross( p[i] - p[curr], p[next] - p[curr] );
      if ( cp < 0 ) next = i;
    }
    curr = next;
  } while ( curr != 0 );
  
  for ( int i = 0; i < H; i++ )
    printf( "(%d,%d)\n", X( p[ hull[i] ] ), Y( p[ hull[i] ] ) );

  return 0;
}//melkor
