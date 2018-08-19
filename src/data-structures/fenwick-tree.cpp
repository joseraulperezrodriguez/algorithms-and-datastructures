/*
  koder : melkor
  TASK  : Fenwick Tree Implementation
  0-based
  To start the index on 1, just add and subtract lobit( x )
  
  Performance:
    lobit  --> O(1)
    query  --> O(log N)
    update --> O(log N)
*/

#include <cstdio>
#include <vector>

using namespace std;

struct FenwickTree {
  vector< int > data;
  
  #define lobit( x ) ( ( x ) & -( x ) )

  FenwickTree( int N ) : data( N, 0 ) {}
  int query( int x ) {
    int sum = 0;
    for ( ; x >= 0; x -= lobit( x + 1 ) ) sum += data[x];
    return sum;
  }
  void update( int x, int val ) {
    for ( ; x < data.size(); x += lobit( x + 1 ) ) data[x] += val;
  }
};
