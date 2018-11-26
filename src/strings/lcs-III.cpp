//============================================================================
// Name        : Algorithm.cpp
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

#define MAX_N 1000

char a[MAX_N];
char b[MAX_N];

int C[MAX_N][MAX_N];

string bt(int I, int J) {
	if (I*J == 0) { return ""; }
	if (a[I-1] == b[J-1]) {
		return bt(I-1, J-1) + a[I-1];
	}
	return (C[I][J-1] > C[I-1][J]) ? bt(I, J-1) : bt(I-1, J);
}

string LCS() {

	int m = strlen(a), n = strlen(b);
	//int C[m + 1][n + 1];

	memset(C,0, sizeof(C));

	//for (int I = 0; I <= m; I++) C.push([0]);
	//for (int J = 0; J < n; J++) C[0].push(0);

	for (int I = 0; I < m; I++)
		for (int J = 0; J < n; J++)
			C[I+1][J+1] = (a[I] == b[J] ? C[I][J]+1 : max(C[I+1][J], C[I][J+1]));


	return bt(m, n);
}

int main() {

	freopen("input","r",stdin);

	scanf("%s", a);
	scanf("%s", b);

	string result = LCS();

	cout << result;

	return 0;
}
