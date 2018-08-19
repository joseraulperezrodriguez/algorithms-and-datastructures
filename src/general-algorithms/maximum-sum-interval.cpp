/*
  koder : melkor
  Task  : Given a sequence of N (1 <= N <= 50000) integers and
          Q (1 <= Q <= 100000) queries of the form (x,y), output
          for each one of them two integers i and j (x <= i <= j <= y)
          such that sum(a_i, ..., a_j) is maximized.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define CL 65536
#define oo 1000000000

struct node
{
	int L, R, C, S;
	node() { }
	node( int L, int R, int C, int S ) : L(L), R(R), C(C), S(S) { }
} sTree[ 2 * CL - 1 ];

int N, Q;
int L, R, C, S;
int x, y;
int offset;

bool query( int node, int lo, int hi, const int& slo, const int& shi )
{

	if ( lo > shi || hi < slo || lo > hi ) return false;
	
	if ( slo <= lo && hi <= shi )
	{
		L = sTree[node].L;
		R = sTree[node].R;
		C = sTree[node].C;
		S = sTree[node].S;
		return true;
	}
	
	int mid = ( lo + hi ) >> 1;
	
	bool lw;
	int lL = 0, lR = 0, lC = 0, lS;
	if ( lw = query( 2 * node + 1, lo, mid, slo, shi ) )
	{
		lL = L; lR = R; lC = C; lS = S;
	}
	
	bool rw;
	int rL = 0, rR = 0, rC = 0, rS;
	if ( rw = query( 2 * node + 2, mid + 1, hi, slo, shi ) )
	{
		rL = L; rR = R; rC = C; rS = S;
	}
	
	S = 0;
	if ( lw ) { L = max( lL, lS + rL ); S += lS; } else L = rL;
	if ( rw ) { R = max( rR, rS + lR ); S += rS; } else R = lR;
	
	C = -oo;
	if ( lw ) C = max( C, lC );
	if ( rw ) C = max( C, rC );
	if ( lw && rw ) C = max( C, lR + rL );
	
	return true;
}

int main()
{


	
	scanf( "%d", &N );
	for ( offset = 1; offset < N; offset <<= 1 ) ;
	
	for ( int i = 0; i < N; i++ )
	{
		scanf( "%d", &x );
		sTree[ i + offset - 1 ] = node( x, x, x, x );
	}
	
	/* Build tree */
	
	for ( int i = offset - 2; i >= 0; i-- )
	{
		int left  = 2 * i + 1,
			right = 2 * i + 2;
		sTree[i].S = sTree[left].S + sTree[right].S;
		sTree[i].L = max( sTree[left].L, sTree[left].S + sTree[right].L );
		sTree[i].R = max( sTree[right].R, sTree[right].S + sTree[left].R );
		sTree[i].C = max( max( sTree[left].C, sTree[right].C ), sTree[left].R + sTree[right].L );
	}
	
	/* Process queries */
	
	for ( scanf( "%d", &Q ); Q--; )
	{
		scanf( "%d %d", &x, &y );
		query( 0, 1, offset, x, y );
		printf( "Interval [%d,%d]: %d\n", x, y, C );
	}
    system("pause");
	return 0;
}
