/*
  koder : melkor
  Task  : Given a set of n points in 2D, find the
          farthest pair on L-metric. The second
		  case (finding the closest pair) is analogous.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 50000,
          MAXX = 100000,
		  oo = (int)1e9;

struct point { int x, y; };

struct Fenwick_Tree
{
	#define lobit( x ) (x) & -(x) 
	
	int data[ MAXX + 1 ];

	void clear() { fill( data, data + MAXX + 1, -oo ); }

	void update( int x, int val )
	{
		for ( ; x <= MAXX; x += lobit( x + 1 ) )
			data[x] = max( data[x], val );
	}

	int get_max( int x )
	{
		int ret = -oo;
		for ( ; x >= 0; x -= lobit( x + 1 ) )
			ret = max( ret, data[x] );
		return ret;
	}
};

int N, ans;

point p[MAXN];
Fenwick_Tree t[2];

bool p_cmp( const point& p0, const point& p1 )
{
	return ( p0.y != p1.y ) ? p0.y > p1.y : p0.x > p1.x;
}

int main()
{
	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );

	scanf( "%d", &N );
	for ( int i = 0; i < N; i++ )
		scanf( "%d %d", &p[i].x, &p[i].y );

	t[0].clear();
	t[1].clear();

	sort( p, p + N, p_cmp );

	ans = -oo;
	for ( int i = 0; i < N; i++ )
	{
		int left_max  = t[0].get_max( p[i].x ),
			right_max = t[1].get_max( MAXX - p[i].x );

		if ( left_max != -oo ) ans = max( ans, left_max + p[i].x - p[i].y );
		if ( right_max != -oo ) ans = max( ans, right_max - p[i].x - p[i].y );

		t[0].update( p[i].x, -p[i].x + p[i].y );
		t[1].update( MAXX - p[i].x, p[i].x + p[i].y );
	}

	printf( "%d\n", ans );

    return 0;
}
