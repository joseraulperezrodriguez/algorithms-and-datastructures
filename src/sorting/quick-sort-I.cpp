/*
  koder : melkor
  TASK  : QuickSort
  
  Performance: O(N log N) ~ O(N^2)
*/

#include <cstdio>

#define MAXN 50005

int N;

int a[MAXN];

inline void swap( int& a, int& b ) {
  int t = a; a = b; b = t;
}

void QuickSort( int lo, int hi ) {

  int mid = a[ ( lo + hi ) >> 1 ],
      l = lo, r = hi;
  
  do {
    while ( a[l] < mid ) l++;
    while ( a[r] > mid ) r--;
    if ( l <= r ) swap( a[ l++ ], a[ r-- ] );
  } while ( l <= r );
  
  if ( l < hi ) QuickSort( l, hi );
  if ( lo < r ) QuickSort( lo, r );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ ) scanf( "%d", a + i );
  
  QuickSort( 0, N - 1 );
  
  for ( int i = 0; i < N; i++ ) printf( "%d\n", a[i] );

  return 0;
}//melkor
