/*
  koder : melkor
  TASK  : Counting Sort
  
  Time Complexity: O(MAXN)
*/

#include <cstdio>

#define MAXN 50005

int N;

int a[MAXN], sorted[MAXN];
int cnt[MAXN];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ ) {
    scanf( "%d", &a[i] );
    cnt[ a[i] ]++;
  }
  
  // Counting Sort --> O(MAXN)
  // I assume that the numbers are in [0,50000]
  
  for ( int i = 1; i < MAXN - 1; i++ ) cnt[i] += cnt[ i - 1 ];
  
  for ( int i = N - 1; i >= 0; i-- )
    sorted[ --cnt[ a[i] ] ] = a[i];
  
  for ( int i = 0; i < N; i++ ) printf( "%d\n", sorted[i] );

  return 0;
}//melkor
