/*
  koder : melkor
  TASK  : Given a pattern P[1...m] and a text T[1...n], find all
          occurrences of P in T (assuming n >= m)
  
  Remarks: Using English alphabet (|S|=26). This approach is dependent
           on the size of the alphabet (but for practical purposes
           that's a constant).
  Running time:
          Build automaton: Theta(M|S|)
          Find occurrences: Theta(N)
*/

#include <cstdio>
#include <cstring>

#define MAXM 10000
#define ALPHA 26

struct state {
  state *next[ALPHA];
  state() { memset( next, 0, sizeof( next ) ); }
} *init, *terminal, *temp;

int M, cont;
char c;

char pat[MAXM];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d\n", &M );
  gets( pat );
  
  /* Build finite automaton */
  
  init = new state;
  terminal = init;
  
  for ( c = 0; c < ALPHA; c++ )
    init->next[c] = init;
  
  for ( int i = 0; i < M; i++ ) {
    c = pat[i] - 'a';
    temp = terminal->next[c];
    state *x = new state;
    terminal->next[c] = x;
    for ( c = 0; c < ALPHA; c++ )
      x->next[c] = temp->next[c];
    terminal = x;
  }
  
  /* Find occurrences */
  
  temp = init;
  cont = 0;
  while ( ( c = getchar() ) != EOF ) {
    c -= 'a';
    temp = temp->next[c];
    cont++;
    if ( temp == terminal )
      printf( "%d\n", cont - M + 1 );
  }

  return 0;
}//melkor
