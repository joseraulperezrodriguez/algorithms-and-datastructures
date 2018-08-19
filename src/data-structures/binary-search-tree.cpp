/*
  koder : melkor
  TASK  : Binary Search Tree Operations
*/

#include <cassert>

struct BST {

  struct node {
    int key; /* assuming keys are integers */
    node *ch[2];
    node( int key ) : key( key ) { ch[0] = ch[1] = 0; }
  } *root;
  
  node* insert( node *t, const int& key ) {
    
    if ( !t ) return new node( key );
    if ( key == t->key ) return t;
    
    int b = !( key < t->key );
    t->ch[b] = insert( t->ch[b], key );
    
    return t;
  }
  
  node* erase( node *t, const int& key ) {
  }
  
  node* find( node *t, const int& key ) {
    while ( t && key != t->key )
      t = t->ch[ !( key < t->key ) ];
    return t;
  }
  
  int get_extreme( int b ) {
    assert( root );
    node *t = root;
    for ( ; t->ch[b]; t = t->ch[b] );
    return t->key;
  }
  
  /* "Public" methods */
  
  void insert( const int& key ) { root = insert( root, key ); }
  void erase( const int& key ) { root = erase( root, key ); }
  bool find( const int& key ) { return find( root, key ); }
  int get_min() { return get_extreme( 0 ); }
  int get_max() { return get_extreme( 1 ); }

  BST() : root( 0 ) { }
};

int main() {
  return 0;
}//melkor
