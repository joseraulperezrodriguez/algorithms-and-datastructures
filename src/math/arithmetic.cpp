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

/*sum from a to b using the interval d */
int sum(int a, int b, int d) {
	int n = (b / a);
	int ans = n*(double)((a + b) / 2.0);
	return ans;
}


int main() {

	int ans = sum(3, 33, 3);
	printf("%d", ans);
	return 0;
}
