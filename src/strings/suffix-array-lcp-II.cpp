#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXLEN 100001

using namespace std;

int N, offset;

char st[MAXLEN];
int SA[MAXLEN], Bckt[MAXLEN], T[MAXLEN];
int LCP[MAXLEN];
char aux[MAXLEN];

bool Cmp( const int &i, const int &j ) {
  if ( Bckt[i] != Bckt[j] ) return Bckt[i] < Bckt[j];
  if ( i + offset >= N || j + offset >= N ) return i > j;
  return Bckt[ i + offset ] < Bckt[ j + offset ];
}

int main() {  
  scanf( "%s", st );
  N = strlen( st );
  for ( int i = 0; i < N; i++ ) {
    SA[i] = i;
    Bckt[i] = st[i] - 'A' + 1;
  }
  for ( ; T[ N - 1 ] != N - 1; offset ? offset *= 2 : offset++ ) {
    sort( SA, SA + N, Cmp );
    for ( int i = 0; i < N - 1; i++ )
      T[ i + 1 ] = T[i] + Cmp( SA[i], SA[ i + 1 ] );
    for ( int i = 0; i < N; i++ ) Bckt[ SA[i] ] = T[i];
  }
  printf( "%d\n", SA[N-1] );
  system("pause");
  return 0;
}
