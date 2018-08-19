/*
  koder : melkor
  TASK  : Coding a binary heap
  
  Performance:
              Insertion: O(log N)
              Get minimum/maximum: Theta(1)
              Delete minimum/maximum: O(log N)
*/

#include <vector>

#include <bits/stdc++.h>

using namespace std;

/* Min-heap */
struct Binary_Heap {

  vector< int > data;
  
  #define LEFT( x ) ( 2 * x + 1 )
  #define RIGHT( x ) ( 2 * x + 2 )
  #define PARENT( x ) ( ( ( x + 1 ) >> 1 ) - 1 )
  
  Binary_Heap() { }

  inline bool empty() { return data.empty(); }
  int min() {
    assert( !data.empty() );
    return data[0];
  }
  void insert( int x ) {

    data.push_back( x );
    int node = data.size() - 1;
    
    while ( node && data[node] < data[ PARENT( node ) ] ) {
      swap( data[node], data[ PARENT( node ) ] );
      node = PARENT( node );
    }
  }
  void erase_minimum() {
  
    assert( !data.empty() );
    
    swap( data[0], data[ data.size() - 1 ] );
    data.pop_back();
    
    for ( int node = 1, size = data.size(); node < size; node = LEFT( node ) ) {
      if ( node + 1 < size && data[ node + 1 ] < data[node] ) node++;
      if ( data[ PARENT( node ) ] < data[node] ) break;
      swap( data[node], data[ PARENT( node ) ] );
    }
  }
};

int main() {
  return 0;
}//melkor
