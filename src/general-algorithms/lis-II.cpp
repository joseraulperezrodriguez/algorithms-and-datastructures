/*
  koder : melkor
  TASK  : Given a sequence A of n integers find its longest
          increasing subsequence (i.e. a subsequence A(p),
          A(p+1), ..., A(q-1), A(q) such that A(i) <= A(i+1)
          for i = 1..(q-p+1))
  
  Running time: O(n log n)
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 50000
#define oo 1000000000

int N;

int a[MAXN];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ )
    scanf( "%d", &a[i] );
  
  /* LIS */
  
  vector< int > seq( N, oo ), id( N );
  for ( int i = 0; i < N; i++ ) {
    id[i] = distance( seq.begin(), lower_bound( seq.begin(), seq.end(), a[i] ) );
    seq[ id[i] ] = a[i];
  }
  
  int len = *max_element( id.begin(), id.end() ) + 1;
  printf( "%d\n", len );
  
  vector< int > lis( len );
  for ( int i = N - 1; i >= 0; i-- )
    if ( id[i] == len - 1 ) lis[ --len ] = a[i];
  
  for ( typeof( lis.begin() ) it = lis.begin(); it != lis.end(); it++ )
    printf( "%d ", *it );

  return 0;
}//melkor
