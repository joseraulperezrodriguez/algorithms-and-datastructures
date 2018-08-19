/*
  koder : melkor
  Task  : Lowest Common Ancestor Problem: reduction to RMQ
  
  Preprocessing --> O(N log N)
  Answer query  --> O(1)
*/

#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 50005
#define LOGMAXN 16

typedef vector < int > List;

int N, Q, N2, top;
int x, y;

int L[ 2 * MAXN - 1 ],
    Level[ 2 * MAXN - 1 ],
    H[ 2 * MAXN - 1 ];

int RMQ[MAXN][LOGMAXN];
int Log2[MAXN];
bool Mk[MAXN];

vector < List > Ady( MAXN );

void DFS( int v ) {

  Mk[v] = true;
  H[v] = top;
  L[ top++ ] = v;
  
  int size = Ady[v].size();
  for ( int i = 0; i < size; i++ ) {
    int w = Ady[v][i];
    if ( !Mk[w] ) {
      Level[top] = Level[ top - 1 ] + 1;
      DFS( w );
      Level[top] = Level[ H[v] ];
      L[ top++ ] = v;
    }
  }
}

int main() {
  
  freopen( "input.txt", "r", stdin );
  freopen( "output.txt", "w", stdout );
  
  scanf( "%d %d", &N, &Q );
  N2 = 2 * N - 1;
  
  for ( int i = 0; i < N - 1; i++ ) {

    scanf( "%d %d", &x, &y );
    x--; y--;
    
    // Create edge
    
    Ady[x].push_back( y );
    Ady[y].push_back( x );
  }
  
  // Euler Tour
  
  DFS( 0 );
  
  // Preprocess logarithms
  
  int log = -1;
  for ( int i = 1; i < MAXN; i++ ) {
    if ( !( i & ( i - 1 ) ) ) log++;
    Log2[i] = log;
  }
  
  // Preprocess RMQ using Sparse Tables
  
  // Base Cases
  
  for ( int i = 0; i < N2; i++ ) RMQ[i][0] = i;
  
  for ( int j = 1; j <= Log2[N2]; j++ )
    for ( int i = 0; i + ( 1 << j ) - 1 < N2; i++ )
      if ( Level[ RMQ[i][ j - 1 ] ] <= 
           Level[ RMQ[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ] ] )
        RMQ[i][j] = RMQ[i][ j - 1 ];
      else
        RMQ[i][j] = RMQ[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ];
  
  // Process queries
  
  for ( int i = 0; i < Q; i++ ) {

    scanf( "%d %d", &x, &y );
    x--; y--;
    
    if ( H[x] > H[y] ) swap( x, y );
    
    int k = Log2[ H[y] - H[x] + 1 ];
    //int idLCA = RMQ[ H[x] ][k] <? RMQ[ H[y] - ( 1 << k ) + 1 ][k];
    int idLCA = (RMQ[ H[x] ][k] < RMQ[ H[y] - ( 1 << k ) + 1 ][k] ? RMQ[ H[x] ][k]
    		: RMQ[ H[y] - ( 1 << k ) + 1 ][k]);
    
    printf( "%d\n", L[idLCA] + 1 );
  }

  return 0;
}//melkor
