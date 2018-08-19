//============================================================================
// Name        : HackerRank.cpp
// Author      : Jos Ral Prez Rodrguez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <string.h>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

typedef long long int int64;

int binom ( int p, int n ) {
    if ( p == 0 ) return 1;
    int num = n;
    int den = p;
    while ( p > 1 ) {
        p--;
        num *= n - p;
        den *= p;
    }
    return num / den;
}


int main() {

	ios_base::sync_with_stdio(false);

	//freopen("input","r",stdin);

	int sum= binom(2,8);

	printf("%d",sum);

	return 0;
}
