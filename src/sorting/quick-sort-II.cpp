/*
  koder : melkor
  TASK  : Randomized QuickSort
  
  Performance: O(N log N) [expected]
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXN 10000

int N;

int a[MAXN];

inline void swap( int& a, int& b ) { int t = a; a = b; b = t; }

void QuickSort( int *a, int lo, int hi ) {

  if ( lo >= hi ) return ;
  
  /* Partitioning */
  
  int rand_pos = lo + ( rand() % ( hi - lo + 1 ) );
  swap( a[hi], a[ rand_pos ] );
  
  int x = a[hi],
      i = lo - 1;

  for ( int j = lo; j < hi; j++ )
    if ( a[j] <= x ) swap( a[ ++i ], a[j] );
  
  swap( a[ ++i ], a[hi] );
  
  /* Recurse */
  
  QuickSort( a, lo, i - 1 );
  QuickSort( a, i + 1, hi );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  srand( time( 0 ) );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ )
    scanf( "%d", &a[i] );
  
  QuickSort( a, 0, N - 1 );
  
  printf( "%d", a[0] );
  for ( int i = 1; i < N; i++ )
    printf( " %d", a[i] );

  return 0;
}//melkor
