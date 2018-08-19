/*
  koder : melkor
  TASK  : BubbleSort
  
  Running time: O(N^2)
*/

#include <cstdio>

#define MAXN 2000

int N, tmp;

int a[MAXN];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ )
    scanf( "%d", &a[i] );
  
  /* BubbleSort */
  
  for ( int i = 0; i < N - 1; i++ )
    for ( int j = N - 1; j > i; j-- )
      if ( a[j] < a[ j - 1 ] ) {
        int tmp = a[j];
        a[j] = a[ j - 1 ];
        a[ j - 1 ] = tmp;
      }
  
  for ( int i = 0; i < N; i++ )
    printf( "%d\n", a[i] );

  return 0;
}//melkor
