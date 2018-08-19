/*
  koder : melkor
  PROG  : 
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <complex>
#include <map>
#include <bitset>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
#define REDP( i, n ) \
    for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;
typedef unsigned long long uint64;

/* Fast IO */

const int MAXBUFF = 5000000;

struct scanner
{
    char buffer[MAXBUFF];
    char* p;
    
    scanner()
    {
        p = buffer + MAXBUFF;
    }
    
    inline char next_char()
    {
        if ( p == buffer + MAXBUFF )
        {
            fread( buffer, 1, MAXBUFF, stdin );
            p = buffer;
        }
        return *p++;
    }

    inline int next_int()
    {
        char c;
        int sign = +1;
        while ( !isdigit( c = next_char() ) )
            if ( c == '-' ) sign = -1;
        int res = c - '0';
        while ( isdigit( c = next_char() ) ) res = res * 10 + c - '0';
        return sign * res;
    }
};

int main()
{
	return 0;
}
