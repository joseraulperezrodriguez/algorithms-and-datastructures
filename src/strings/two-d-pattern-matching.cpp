/*
  koder : melkor
  TASK  : 2-dimensional pattern matching (find a 2D pattern into
          a 2D text [image]).
  
  Remarks: Using English alphabet (|S|=26). This approach is
           dependent on the alphabet's size (but for practical
           purposes that's a constant)
  Running time:
          Build Aho-Corasick automaton: O(M|S|)
          Transform text T into a 'numeric' matrix: Theta(N)
          Find occurrences: Theta(N)
          M = |pattern's rows| * |pattern's columns|
          N = |text's rows| * |text's columns|
  
*/

/*#include <cstdio>
#include <queue>
#include <cassert>*/
#include<bits/stdc++.h>

using namespace std;

#define MAXP 1000
#define MAXT 5000
#define ALPHA 26

struct state {

  int state_id;
  state *fail;
  state *next[ALPHA];
  
  state( int id ) : state_id( id ) {
    fail = 0;
    memset( next, 0, sizeof( next ) );
  }
} *root, *t, *v;

int pR, pC, tR, tC;
int states, k;
char c;

int np[MAXP], nt[MAXT][MAXT];
int fail[MAXP];
char P[MAXP][MAXP],
     T[MAXT][MAXT];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d %d", &pR, &pC );
  for ( int i = 0; i < pR; i++ )
    scanf( "%s", P[i] );
  
  scanf( "%d %d", &tR, &tC );
  for ( int i = 0; i < tR; i++ )
    scanf( "%s", T[i] );
  
  assert(pR <= tR && pC <= tC);
  
  /* Build Aho-Corasick automaton for the pattern's columns */
  
  root = new state( states = 0 );
  
  for ( int col = 0; col < pC; col++ ) {
    t = root;
    for ( int row = 0; row < pR; row++ ) {
      c = P[row][col] - 'a';
      if ( !t->next[c] ) t->next[c] = new state( ++states );
      t = t->next[c];
    }
    np[col] = t->state_id;
  }
  
  queue< state* > Q;
  for ( c = 0; c < ALPHA; c++ )
    if ( root->next[c] ) {
      root->next[c]->fail = root;
      Q.push( root->next[c] );
    } else root->next[c] = root;
  
  while ( !Q.empty() ) {
    t = Q.front(); Q.pop();
    for ( c = 0; c < ALPHA; c++ )
      if ( t->next[c] ) {
        Q.push( t->next[c] );
        v = t->fail;
        while ( !v->next[c] ) v = v->fail;
        t->next[c]->fail = v->next[c];
      }
  }
  
  /*
    Transform text T into a 'numeric' matrix
    whose entries are states of the automaton
  */
  
  for ( int col = 0; col < tC; col++ ) {
    t = root;
    for ( int row = 0; row < tR; row++ ) {
      c = T[row][col] - 'a';
      while ( !t->next[c] ) t = t->fail;
      t = t->next[c];
      nt[row][col] = t->state_id;
    }
  }
  
  /*
    Search for occurrences of the 'numeric' pattern
    into the 'numeric' matrix using KMP automaton
  */
  
  fail[0] = k = -1;
  for ( int i = 1; i < pC; i++ ) {
    while ( k >= 0 && np[ k + 1 ] != np[i] ) k = fail[k];
    if ( np[ k + 1 ] == np[i] ) k++;
    fail[i] = k;
  }
  
  for ( int i = pR - 1; i < tR; i++ ) {
    k = -1;
    for ( int j = 0; j < tC; j++ ) {
      while ( k >= 0 && np[ k + 1 ] != nt[i][j] ) k = fail[k];
      if ( np[ k + 1 ] == nt[i][j] ) k++;
      if ( k == pC - 1 ) {
        printf( "(%d,%d)\n", i - pR + 2, j - pC + 2 );
        k = fail[k];
      }
    }
  }

  return 0;
}//melkor
