/*
  koder : melkor
  TASK  : 1-dimensional Range Searching: Given a set S of n points in
          1-dimensional space (i.e. a set of real numbers), preprocess
          it to handle queries of the type "report all points inside a
          1-dimensional rectangle (i.e. an interval [x,y])"
  
  Remarks: Instead of dealing with real numbers, let's assume they
           are integers. The same effect can be obtained using binary
           search, but it does not generalize to higher dimensions.
  Running time:
          Sorting: O(n log n)
          Build Tree: O(n)
          Query: O(k + log n)
          k: number of points in interval [x,y]
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100000

struct node {
  int val;
  node *ch[2];
  node( int val, node *l, node *r ) : val( val ) { ch[0] = l; ch[1] = r; }
} *root;

int N, Q;
int lo, hi;

int p[MAXN];

inline bool leaf( node *x ) { return !x->ch[0] && !x->ch[1]; }
inline bool included( node *t, const int& x, const int &y  ) { 
  return x <= t->val && t->val <= y;
}

node* build( int lo, int hi ) {

  if ( lo == hi )
    return new node( p[lo], 0, 0 );

  int mid = ( lo + hi ) >> 1;
  return new node( p[mid], build( lo, mid ), build( mid + 1, hi ) );
}

node* find_split( const int& x, const int& y ) {
  node *t = root;
  while ( !leaf( t ) && ( y <= t->val || x > t->val ) )
    t = t->ch[ !( y <= t->val ) ];
  return t;
}

void report( node *t ) {
  if ( !t ) return;
  if ( leaf( t ) )
       printf( "%d ", t->val );
  else {
    report( t->ch[0] );
	report( t->ch[1] );
  }
}

void query( const int& x, const int& y ) {

  node *split = find_split( x, y );
  
  if ( leaf( split ) ) {
    if ( included( split, x, y ) )
	  printf( "%d ", split->val );
  } else {
	for ( int dir = 0; dir < 2; dir++ ) {
	  node *v = split->ch[dir];
	  while ( !leaf( v ) ) {
	    if ( ( dir == 0 && x <= v->val ) || ( dir == 1 && v->val < y ) ) {
		  report( v->ch[ !dir ] );
		  v = v->ch[dir];
		} else v = v->ch[ !dir ];
	  }
	  if ( included( v, x, y ) )
	    printf( "%d ", v->val );
	}
  }
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ )
    scanf( "%d", &p[i] );

  sort( p, p + N );
  root = build( 0, N - 1 );
  
  for ( scanf( "%d", &Q ); Q--; ) {
    scanf( "%d %d", &lo, &hi );
	query( lo, hi );
	printf( "\n" );
  }

  return 0;
}//melkor
