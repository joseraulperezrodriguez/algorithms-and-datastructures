/*
  koder : melkor
  TASK  : HeapSort
  
  Time Complexity: O(N log N)
*/

#include <cstdio>

#define MAXN 50005

int N, copyN, child;

int heap[MAXN];

inline void swap( int& a, int& b ) { int t = a; a = b; b = t; }

void heapProperty( int v, int& heapSize ) {

  while ( 2 * v + 1 < heapSize ) {
    child = 2 * v + 1;
    if ( child < heapSize - 1 && heap[ child + 1 ] > heap[child] ) child++;
    if ( heap[child] > heap[v] ) swap( heap[v], heap[child] );
    v = child;
  }
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  copyN = N;
  for ( int i = 0; i < N; i++ ) scanf( "%d", &heap[i] );
  
  // Build Heap --> O(N)
  
  for ( int i = ( N >> 1 ) - 1; i >= 0; i-- )
    heapProperty( i, N );
  
  // HeapSort --> O(N log N)
  
  for ( int i = N - 1; i; i-- ) {
    swap( heap[0], heap[i] );
    heapProperty( 0, --N );
  }
  
  for ( int i = 0; i < copyN; i++ ) printf( "%d\n", heap[i] );

  return 0;
}//melkor
