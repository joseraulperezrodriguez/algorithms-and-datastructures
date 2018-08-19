/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <bitset>

#include <complex>
#include <cmath>

#include <cstdlib>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, lo, hi ) for ( int i = (lo); i <= (hi); i++ )
#define FORD( i, hi, lo ) for ( int i = (hi); i >= (lo); i-- )

#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

template< typename T >
T GCD( T A, T B ) {
	return B ? GCD( B, A % B ) : A;
}

template< typename T >
T extendedGCD( T A, T B, T& X, T& Y ) {
	// if ( A < B ) return extendedGCD( B, A, Y, X );
	if ( B == 0 ) {
		X = 1;
		Y = 0;
		return A;
	}
	
	T ans = extendedGCD( B, A % B, Y, X );
	Y -= (A / B) * X;
	
	return ans;
}

template< typename T >
vector< T > solveModEquation( T A, T B, T N ) { // solves a*x = b (mod n)

	T X, Y, D = extendedGCD( A, N, X, Y );

	vector< T > ans;
	
	if ( B % D == 0 ) {
		T X0 = X * (B / D) % N;
		REP( i, D )
			ans.push_back( (X0 + i * (N / D)) % N );
	}

	return ans;
}

template< typename T >
T inverse( T A, T N ) {
	return solveModEquation( A, 1, N )[0];
}

template< typename T >
T sqr( T X ) {
	return X * X;
}

// avoid overflow
template< typename T >
T mulMod( T A, T B, T P ) { // computes (A * B) % P
	if ( A == 0 || B == 0 ) return 0;
	
	T ans = mulMod( A, B / 2, P ) * 2 % P;
	if ( B % 2 == 1 )
	      ans = (ans + A) % P;

	return ans;
}

template< typename T >
T powerMod( T A, T N, T P ) {
	if ( N == 0 ) return 1;
	
	T ans = powerMod( A, N / 2 );
	
	ans = mulMod( ans, ans, P );

	if ( N % 2 == 1 )
	      ans = mulMod( ans, A, P );
	      
	return ans;
}

// primality test for large numbers
template< typename T >
bool rabinMiller( T P ) {
	if ( P < 2 || ( P > 2 && P % 2 == 0 ) )
		return 0;

	T prime[] = { 2, 3, 5, 7, 11, 13, -1 };

	for ( int i = 0; prime[i] != -1 && prime[i] < P; i++ )
		if ( powerMod( prime[i], P - 1, P ) != 1 )
			return 0; // composite

	return 1; // maybe is a prime
}


namespace Gauss1 {
// solver -> O(n^3) -> n variables
typedef vector< double > equation;
typedef vector< equation > eqsystem;

template< typename T >
int solveRealEqSystem( eqsystem& E, vector< T >& out ) {

	int F = E.size(); // assert( F > 0 );
	int C = E[0].size();

	bool unique = true;
	
	vector< bool > freeVar( C - 1, false );

	int i, j;
	for ( i = 0, j = 0; i < F && j < C - 1; i++, j++ ) {

		for ( int k = i; k < F; k++ )
		      if ( E[k][j] != 0 ) {
				E[i].swap( E[k] );
				break ;
			}
			
		if ( E[i][j] == 0 ) {
			unique = false;
			freeVar[j] = true;
			i--;
			continue ;
		}
		
		for ( int p = i + 1; p < F; p++ )
			for ( int q = C - 1; q >= j; q-- ) {
			      E[p][q] = (E[p][q] * (E[i][j] / E[p][j])) - E[i][q];
			      // or E[p][q] = E[p][q] - (E[i][q] * (E[p][j] / E[i][j]));
			}
	}

	for ( int k = i; k < F; k++ )
	      if ( E[k][j] != 0 )
	            return 0; // no solution

	out.resize( C - 1 );

	for ( i--, j = C - 2; i >= 0 && j >= 0; i--, j-- ) {
		if ( freeVar[j] ) {
			out[j] = 0;
			i++;
			continue ;
		}
		
		double sum = E[i][C - 1];
		for ( int k = j + 1; k < C - 1; k++ )
		      sum -= E[i][k] * out[k];
		      
		out[j] = sum / E[i][j];
	}
	 
	if ( unique )
	      return 1;
	else
	      return 2;
}

} // end namespace Gauss1

namespace Gauss2 {
// solver -> O(n^3) -> n variables
typedef vector< int64 > equation;
typedef vector< equation > eqsystem;

template< typename T >
T toMod( T X, T P ) {
	return ((X % P) + P) % P;
}

template< typename T >
int solveModularEqSystem( eqsystem& E, T modulo, vector< T >& out ) {

	int F = E.size(); // assert( F > 0 );
	int C = E[0].size();

	bool unique = true;

	vector< bool > freeVar( C - 1, false );

	int i, j;
	for ( i = 0, j = 0; i < F && j < C - 1; i++, j++ ) {

		for ( int k = i; k < F; k++ )
		      if ( E[k][j] != 0 ) {
				if ( k != i ) E[i].swap( E[k] );
				break ;
			}

		if ( E[i][j] == 0 ) {
			unique = false;
			freeVar[j] = true;
			i--;
			continue ;
		}

		for ( int p = i + 1; p < F; p++ )
			for ( int q = C - 1; q >= j; q-- )
				E[p][q] = toMod( E[p][q] * E[i][j] - E[i][q] * E[p][j], modulo );
	}

	for ( int k = i; k < F; k++ )
	      if ( E[k][j] != 0 )
	            return 0; // no solution

	out.resize( C - 1 );

	for ( i--, j = C - 2; i >= 0 && j >= 0; i--, j-- ) {
		if ( freeVar[j] ) {
			out[j] = 0;
			i++;
			continue ;
		}

		int64 sum = E[i][C - 1];
		for ( int k = j + 1; k < C - 1; k++ )
		      sum = toMod( sum - E[i][k] * out[k], modulo );

		#warning No solution or multiple solutions, possible?
		out[j] = solveModEquation( E[i][j], sum, modulo )[0];
	}

	if ( unique )
	      return 1;
	else
	      return 2;
}

} // end namespace Gauss2

int main() {

	int64 a, b, n, x, y, d;
	cin >> a >> b >> n;

	solveModEquation( a, b, n );

	return 0;
}
