/*
  koder : melkor
  TASK  : Given a set of N elements find the k-th smallest element
  
  Performance: O(N) [expected]
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXN 10000

int N, k;

int a[MAXN];

inline int swap( int& a, int& b ) { int t = a; a = b; b = t; }

int selection( int *a, int lo, int hi, const int& k ) {

  if ( lo == hi ) return a[lo];
  
  /* Partitioning */
  
  int rand_pos = lo + ( rand() % ( hi - lo + 1 ) );
  swap( a[hi], a[ rand_pos ] );
  
  int x = a[hi],
      i = lo - 1;
  
  for ( int j = lo; j < hi; j++ )
    if ( a[j] <= x ) swap( a[ ++i ], a[j] );
  
  swap( a[ ++i ], a[hi] );
  
  /* Recurse */
  
  if ( i == k - 1 ) return a[i];
  
  if ( k - 1 < i )
       return selection( a, lo, i - 1, k );
  else return selection( a, i + 1, hi, k );
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  srand( time( 0 ) );
  
  scanf( "%d %d", &N, &k );
  for ( int i = 0; i < N; i++ )
    scanf( "%d", &a[i] );
  
  printf( "%d\n", selection( a, 0, N - 1, k ) );

  return 0;
}//melkor
