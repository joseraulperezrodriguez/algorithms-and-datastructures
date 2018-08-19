/*
  koder : melkor
  TASK  : Closest Pair of Points Problem (a line sweep approach)
  
  Time Complexity: O(N log N)
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

struct point {
  double x, y;
};

struct cmpX {
  bool operator () ( const point &a, const point &b ) const {
    return a.x < b.x;
  }
};
struct cmpY {
  bool operator () ( const point &a, const point &b ) const {
    return a.y < b.y;
  }
};

int N, last;
int x, y;
double minDist = 1e12; // infinity

vector< point > ls;
multiset< point, cmpY > Q;
multiset< point, cmpY >::iterator lo, hi;

template< typename T >
T sqr( const T x ) { return x * x ; }

double dist( const point &a, const point &b ) {
  return sqrt( sqr( b.x - a.x ) + sqr( b.y - a.y ) );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ ) {
    scanf( "%d %d", &x, &y );
    ls.push_back( ( point ) { x, y } );
  }
  
  sort( ls.begin(), ls.end(), cmpX() );
  
  for ( int i = 0; i < N; i++ ) {

    for ( ; last < i && ls[i].x - ls[last].x >= minDist; last++ )
      Q.erase( Q.find( ls[last] ) );
    
    lo = Q.lower_bound( ( point ) { ls[i].x, ls[i].y - minDist } );
    hi = Q.upper_bound( ( point ) { ls[i].x, ls[i].y + minDist } );
    
    for ( ; lo != hi; lo++ )
    	//minDist <?= dist( *lo, ls[i] );
    	minDist = (minDist <= dist( *lo, ls[i] ) ? minDist : dist( *lo, ls[i] ));
    
    Q.insert( ls[i] );
  }
  
  printf( "%lf\n", minDist );

  return 0;
}//melkor
