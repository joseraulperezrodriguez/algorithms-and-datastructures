/*
  koder : melkor
  TASK  : Range Minimum Query Problem: Given a sequence S of real numbers,
          RMQ(i,j) returns the index of the element in S[i...j] with
          smallest value.
  
  Performance:
    Initialize STree --> O(N)
    Answer query     --> O(log N)
*/

#include <cstdio>

#define LGN 15
#define MAXN 1 << LGN

int N, Q;
int u, v;

int A[MAXN];
int sTree[ ( 1 << ( LGN + 2 ) ) - 1 ];

void init( int node, int lo, int hi ) {

  if ( lo == hi ) sTree[node] = lo;
  else {
  
    int mid = ( lo + hi ) >> 1;
    init( 2 * node + 1, lo, mid );
    init( 2 * node + 2, mid + 1, hi );
    
    sTree[node] = A[ sTree[ 2 * node + 1 ] ] <= A[ sTree[ 2 * node + 2 ] ] ?
                  sTree[ 2 * node + 1 ] : sTree[ 2 * node + 2 ];
  }
}

int queryRMQ( int node, int lo, int hi, int& u, int& v ) {

  if ( lo > v || hi < u ) return -1;
  
  if ( u <= lo && hi <= v ) return sTree[node];
  
  int mid = ( lo + hi ) >> 1;
  int q1 = queryRMQ( 2 * node + 1, lo, mid, u, v );
  int q2 = queryRMQ( 2 * node + 2, mid + 1, hi, u, v );
  
  if ( q1 == -1 ) return q2;
  if ( q2 == -1 ) return q1;
  return A[q1] <= A[q2] ? q1 : q2;
}

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ ) scanf( "%d", A + i );
  
  // Initialize data structure
  
  init( 0, 0, N - 1 );
  
  // Answer queries (0-based!!!)
  
  scanf( "%d", &Q );
  for ( int i = 0; i < Q; i++ ) {
    scanf( "%d %d", &u, &v );
    printf( "RMQ( %d, %d ) = %d\n", u, v, queryRMQ( 0, 0, N - 1, u, v ) );
  }

  return 0;
}//melkor
