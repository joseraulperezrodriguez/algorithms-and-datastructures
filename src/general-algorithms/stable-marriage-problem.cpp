/*
  koder : melkor
  TASK  : Stable Marriage Problem: Given N men and N women
          and, for each one of them, a list of who do they
          prefer (a ranking), find a "stable" matching
          between men and women (a matching is said to be
          "stable" if every one can be matched with one of
          its 'highest' preferences without violating that
          man (woman)'s preferences).
  
  Running time: O(N^2)
*/

#include <cstdio>

#define MAXN 1001

int N, w, m;
int who;

int wife[MAXN], nextt[MAXN];
int pref[MAXN][MAXN],
    rank[MAXN][MAXN];

int main() {

  freopen( "in.txt", "r", stdin );
  freopen( "out.txt", "w", stdout );
  
  scanf( "%d", &N );
  
  /* Woman's preferences */
  for ( int i = 1; i <= N; i++ ) {
    scanf( "%d", &who );
    for ( int j = 1; j <= N; j++)
      scanf( "%d", &pref[who][j] );
  }
  
  /* Man's preferences */
  for ( int i = 1; i <= N; i++ ) {
    scanf( "%d", &who );
    for ( int j = 1; j <= N; j++ ) {
      scanf( "%d", &w );
      rank[who][w] = j;
    }
  }
  
  for ( int i = 1; i <= N; i++ ) {
    w = i;
    for ( ;; ) {
      m = pref[w][ ++nextt[w] ];
      if ( !wife[m] ) {
        wife[m] = w;
        break;
      }
      if ( rank[m][w] < rank[m][ wife[m] ] ) {
        int tmp = wife[m];
        wife[m] = w;
        w = tmp;
      }
    }
  }
  
  for ( int i = 1; i <= N; i++ )
    printf( "%d %d\n", i, wife[i] );

  return 0;
}//melkor
