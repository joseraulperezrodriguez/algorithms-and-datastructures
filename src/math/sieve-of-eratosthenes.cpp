/*
  koder : melkor
  TASK  : Sieve of Eratosthenes
 */

#include <cstdio>
#include <cstdlib>

#define MAXN 1000000

int i, j;
bool mark[MAXN];


void divisor_sieve(int n) {
	int divisors[n + 1];
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			++divisors[j];
}

void prime_sieve(){
	for ( i = 2; i <= MAXN; i++ )
		if ( !mark[i] )
			for ( j = 2 * i; j <= MAXN; j += i )
				mark[j] = 1;

	for ( i = 2; i <= MAXN; i++ )
		if ( !mark[i] ) printf( "%d ", i );

}

int main() {

	/* Prime Sieve */


	system( "pause" );

	return 0;
}//melkor
