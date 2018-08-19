/*
  koder : melkor
  TASK  : Given a sequence A of n integers find its longest
          increasing subsequence (i.e. a subsequence A(p),
          A(p+1), ..., A(q-1), A(q) such that A(i) <= A(i+1)
          for i = 1..(q-p+1))
  
  Running time: Theta(n^2)
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 2000

int N, id_max;

int a[MAXN];
int dp[MAXN], y[MAXN];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ )
    scanf( "%d", &a[i] );
  
  /* LIS */
  
  fill( dp, dp + N, 1 );
  fill( y, y + N, -1 );
  
  for ( int i = 1; i < N; i++ )
    for ( int j = 0; j < i; j++ )
      if ( a[j] < a[i] )
        if ( dp[i] < dp[j] + 1 ) {
          dp[i] = dp[j] + 1;
          y[i] = j;
        }
  
  id_max = 0;
  for ( int i = 1; i < N; i++ )
    if ( dp[ id_max ] < dp[i] ) id_max = i;
  
  vector< int > lis;
  for ( int i = id_max; i >= 0; i = y[i] )
    lis.push_back( a[i] );
  
  reverse( lis.begin(), lis.end() );
  
  printf( "%d\n", lis.size() );
  for ( typeof( lis.begin() ) it = lis.begin(); it != lis.end(); it++ )
    printf( "%d ", *it );

  return 0;
}//melkor
