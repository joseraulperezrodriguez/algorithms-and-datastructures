/*
  koder : melkor
  TASK  : Given two strings find their longest common subsequence
  
  Running time: O((n + r) log n)
    n: |s1|
    r: |{(i,j): s1[i] = s2[j]}|
*/

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <string.h>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <limits.h>

using namespace std;

#define MAXLEN 50001
#define oo 1000000000

#define all( c ) c.begin(), c.end()
#define index_of( c, x ) \
  distance( c.begin(), lower_bound( all( c ), x ) )

struct node {
  char c;
  node *next;
  node( char c, node *next ) : c( c ), next( next ) { }
};



char a[MAXLEN];
char b[MAXLEN];

int n;
int m;

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%s", a );
  scanf( "%s", b );
  
  n = strlen(a);
  m = strlen(b);
  
  map< char, vector<int> > M;

  for ( int j = m - 1; j >= 0; j-- )
    M[ b[j] ].push_back( j );
  
  vector< int > xs( n + 1, oo ); xs[0] = -oo;
  vector< node* > link( n + 1 );
  
  for ( int i = 0; i < n; i++ )
    if ( M.count( a[i] ) ) {
      vector< int > ys = M[ a[i] ];
      for ( int j = 0; j < ys.size(); j++ ) {
        int k = index_of( xs, ys[j] );
        xs[k] = ys[j];
        link[k] = new node( b[ ys[j] ], link[ k - 1 ] );
      }
    }
  
  int len = index_of( xs, oo - 1 ) - 1;
  printf( "%d\n", len );
  
  vector< char > lcs;
  for ( node *p = link[len]; p; p = p->next )
    lcs.push_back( p->c );
  reverse( all( lcs ) );
  
  for ( int i = 0; i < len; i++ )
    printf( "%c", lcs[i] );
  
  return 0;
}//melkor
