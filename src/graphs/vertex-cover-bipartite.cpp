/*
  koder : melkor
  Task  : Given a bipartite graph, find its minimum vertex cover

  Running time: O(VE)
*/

#include <cstdio>
#include <vector>
#include <queue>

#include <bits/stdc++.h>

using namespace std;

#define MAXV 5000

struct node
{
	int u;
	bool L;
	node( int u, bool L ) : u(u), L(L) { }
};

int X, Y, edge_count;
int u, v;
int sentinel;
int cardinality;

int matched[MAXV];
bool mark[MAXV];
bool T[MAXV];

bool augment( int u, const vector< vector< int > >& ady )
{
	if ( u == -1 ) return true;

	int size = ady[u].size();
	for ( int i = 0; i < size; i++ )
	{
		int v = ady[u][i];
		
		if ( mark[v] ) continue ;
		mark[v] = true;

		if ( augment( matched[v], ady ) )
		{
			matched[u] = v;
			matched[v] = u;
			return true;
		}
	}

	return false;
}

int main()
{
	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );

	scanf( "%d %d %d", &X, &Y, &edge_count );
	vector< vector< int > > ady( X + Y );
	for ( int i = 0; i < edge_count; i++ )
	{
		scanf( "%d %d", &u, &v );
		u--; v--;
		ady[u].push_back( v );
		ady[v].push_back( u );
	}

	/* Find maximum matching */

	memset( matched, -1, sizeof( matched ) );
	
	cardinality = 0;
	for ( int i = 0; i < X; i++ )
	{
		memset( mark, 0, sizeof( mark ) );
		if ( augment( i, ady ) ) cardinality++;
	}

	/* Find minimum vertex cover */

	queue< node > Q;
	for ( int i = 0; i < X; i++ )
		if ( matched[i] == -1 )
		{
			T[i] = true;
			Q.push( node( i, 1 ) );
		}

	while ( !Q.empty() )
	{
		node front = Q.front();
		Q.pop();

		int size = ady[ front.u ].size();
		for ( int i = 0; i < size; i++ )
		{
			v = ady[ front.u ][i];
			if ( T[v] ) continue ;
			if ( ( front.L && v != matched[ front.u ] ) ||
				( !front.L && v == matched[ front.u ] ))
			{
				T[v] = true;
				Q.push( node( v, !front.L ) );
			}
		}
	}

	printf( "Cardinality: %d\n", cardinality );
	printf( "Minimum Vertex Cover:\n" );

	for ( int i = 0; i < X; i++ )
		if ( !T[i] ) printf( "%d\n", i + 1 );
	for ( int i = X; i < X + Y; i++ )
		if ( T[i] ) printf( "%d\n", i + 1 );

    return 0;
}//melkor
