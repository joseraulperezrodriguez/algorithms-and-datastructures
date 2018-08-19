/*
  koder : melkor
  Task  : Hopcroft-Karp algorithm
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int
    MAXV = 50005,
    MAXE = 150005;

struct edge
{
	int u, v;
} edges[MAXE];

int V, vv, E;
int head, tail;
int u, v;
int ans;

int Q[MAXV];

int next[MAXE];
int start[MAXV];

int mx[MAXV],
    my[MAXV];

int dx[MAXV],
    dy[MAXV];

bool bfs()
{
	head = 1;
	tail = 0;
	
	for ( int i = 1; i <= V; i++ )
    {
		if ( mx[i] == -1 )
			Q[ ++tail ] = i;
		dx[i] = 0;
		dy[i] = 0;
	}
	
	bool result = false;
	while ( head <= tail )
    {
		u = Q[ head++ ];
		for ( int i = start[u]; i <= start[ u + 1 ] - 1; i++ )
        {
			v = next[i];
			if ( dy[v] == 0 )
            {
				dy[v] = dx[u] + 1;
				if ( my[v] == -1 )
					result = true;
				else
                {
					dx[ my[v] ] = dy[v] + 1;
					Q[ ++tail ] = my[v];
				}
			}
		}
	}
	
	return result;
}

bool dfs( int u )
{
	for ( int i = start[u]; i <= start[ u + 1 ] - 1; i++ )
    {
		int v = next[i];
		if ( dy[v] == dx[u] + 1 )
        {
			dy[v] = 0;
			if ( ( my[v] == -1 ) || dfs( my[v] ) )
            {
				mx[u] = v;
				my[v] = u;
				return true;
			}
		}
	}
	
	return false;
}

int main()
{
	scanf( "%d %d %d", &V, &v, &E );
	V = max( V, v );
	
	for ( int i = 1; i <= E; i++ )
    {
		scanf( "%d %d", &edges[i].u, &edges[i].v );
		start[ edges[i].u ]++;
	}
	
	start[1]++;
	for ( int i = 2; i <= V; i++ )
		start[i] += start[ i - 1 ];
	start[ V + 1 ] = start[V];
	
	for ( int i = 1; i <= E; i++ )
    {
		start[ edges[i].u ]--;
		next[ start[ edges[i].u ] ] = edges[i].v;
	}
	
	memset( mx, 0xff, sizeof( int ) * ( V + 1 ) );
	memset( my, 0xff, sizeof( int ) * ( V + 1 ) );
	
	while ( bfs() )
		for ( int i = 1; i <= V; i++ )
			ans += ( mx[i] == -1 && dfs( i ) );
	
	printf( "%d\n", ans );
	
	return 0;
}
