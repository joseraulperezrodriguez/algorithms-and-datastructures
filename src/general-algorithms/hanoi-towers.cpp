/*
  koder : melkor
  TASK  : Simple solution to the problem "The Tower of Hanoi"
  
  Running time: Omega(2^n)
*/

#include <cstdio>
//#include <conio.h>

int n;

void move( int n, char from, char to, char aux ) {

  if ( n == 1 )
       printf( "Move disk from %c to %c\n", from, to );
  else {
    move( n - 1, from, aux, to );
    printf( "Move disk from %c to %c\n", from, to );
    move( n - 1, aux, to, from );
  }
}

int main() {

  scanf( "%d", &n );
  move( n, 'A', 'C', 'B' );
  
  //getch();


  return 0;
}//melkor
