/*
  koder : melkor
  TASK  : Given N rectangles on the plane, compute their union area
          (line sweep approach)
  
  Performance:
    Sorting events --> O(N log N)
    Sweep line and
    update event's
    queue          --> O(N log MAXC)
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXC 1 << 15

#define LEFT( v ) 2 * ( v ) + 1
#define RIGHT( v ) 2 * ( v ) + 2

struct event {
  int start, lo, hi, flag;
  bool operator < ( const event& e ) const { return start < e.start; }
};

int N, last;
long long area;

vector< event > ls;

int amount[ 3 * MAXC ], times[ 3 * MAXC ];

void update( int node, int lo, int hi, int& start, int& end, int& value ) {

  if ( hi < start || lo > end ) return;
  
  if ( start <= lo && hi <= end )
       times[node] += value;
  else {
    int mid = ( lo + hi ) >> 1;
    update( LEFT( node ), lo, mid, start, end, value );
    update( RIGHT( node ), mid + 1, hi, start, end, value );
  }
  
  if ( !times[node] )
       amount[node] = ( lo == hi ) ? 0 :
                      amount[ LEFT( node ) ] + amount[ RIGHT( node ) ];
  else amount[node] = hi - lo + 1;
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ ) {
  
    int x1, x2, y1, y2;
    scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
    
    if ( x1 > x2 ) swap( x1, x2 );
    if ( y1 > y2 ) swap( y1, y2 );
    
    ls.push_back( ( event ) { x1, y1, y2 - 1, +1 } );
    ls.push_back( ( event ) { x2, y1, y2 - 1, -1 } );
  }
  
  sort( ls.begin(), ls.end() );
  
  // Line Sweep
  
  last = ls[0].start;
  for ( int i = 0; i < 2 * N; i++ ) {
    area += amount[0] * ( ls[i].start - last );
    last = ls[i].start;
    update( 0, 0, MAXC, ls[i].lo, ls[i].hi, ls[i].flag );
  }
  
  printf( "%lld\n", area );

  return 0;
}//melkor
