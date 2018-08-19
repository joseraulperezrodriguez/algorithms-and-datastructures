/*
  koder : melkor
  Iterate over all subsets using bitwise operators
*/

#include <cstdio>
#include <string>

using namespace std;

string str = "abcdefghijk";

int main() {

  freopen( "d.out", "w", stdout );
  
  int len = str.length();
  int cant = 0;
  
  for ( int i = 1; i <= 1 << len; i++ ) {
  
    string s = "";
  
    for ( int j = 0; j < len; j++ )
      if ( i  & ( 1 << j ) )
        s += str[j];
    
    printf( "%s\n", s.c_str() );
    cant++;
  }
  
  printf( "%d\n", cant );

  return 0;
}//melkor
