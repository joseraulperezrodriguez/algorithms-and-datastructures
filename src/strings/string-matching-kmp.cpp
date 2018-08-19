/*
  koder : melkor
  TASK  : Given a pattern P[1...m] and a text T[1...n], find all
          occurrences of P in T (assuming n >= m)
  Remarks: 0-based
  
  Running time:
          Preprocessing: Theta(m)
          Matching: Theta(n)
*/

#include <cstdio>
#include <cstring>

#define MAXL 50005

int N, k, cnt;
char c;

int Q[MAXL];
char pattern[MAXL];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%s", pattern );
  N = strlen( pattern );
  
  // Compute KMP automaton
  // (the so-called failure function)
  
  k = Q[0] = -1;
  for ( int i = 1; i < N; i++ ) {
    while ( k >= 0 && pattern[ k + 1 ] != pattern[i] ) k = Q[k];
    if ( pattern[ k + 1 ] == pattern[i] ) k++;
    Q[i] = k;
  }
  
  // Find occurrences
  
  scanf( "\n" );
  
  k = -1;
  while ( ( c = getchar() ) != EOF ) {
    while ( k >= 0 && pattern[ k + 1 ] != c ) k = Q[k];
    if ( pattern[ k + 1 ] == c ) k++;
    cnt++;
    if ( k + 1 == N ) {
      printf( "%d\n", cnt - N );
      k = Q[k];
    }
  }

  return 0;
}//melkor
