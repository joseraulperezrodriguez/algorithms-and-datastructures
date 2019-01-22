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

#define MAX_N 200001

int id[MAX_N], sz[MAX_N], nextt[MAX_N];

int count_sets = 0;


int find(int p)	{
	int root = p;
	while (root != id[root])
		root = id[root];
	while (p != root) {
		int newp = id[p];
		id[p] = root;
		p = newp;
	}
	return root;
}

void merge(int x, int y)	{
	int i = find(x);
	int j = find(y);
	if (i == j) return;

	// make smaller root point to larger one
	if   (sz[i] < sz[j])	{
		id[i] = j;
		sz[j] += sz[i];
	} else	{
		id[j] = i;
		sz[i] += sz[j];
	}
	count_sets--;
}


int main() {

	//freopen("input","r",stdin);

	int n = 0, q = 0;
	scanf("%d %d", &n, &q);

	count_sets = n;

	for(int I = 0; I < n; I++) {
		id[I + 1] = I + 1;
		sz[I + 1] = 1;
		nextt[I + 1] = I + 2;
	}

	nextt[n] = 0;

	string result;

	for(int I = 0; I < q; I++) {
		int type, x, y = 0;

		scanf("%d %d %d", &type, &x, &y);
		if(type == 1) merge(x, y);
		else if(type == 2) {
			if(x == y)continue;

			int index = x;
			while(nextt[index] <= y) {
				merge(index, nextt[index]);
				int temp = index;
				index = nextt[index];
				nextt[temp] = y + 1;

			}
		} else result += (find(x) == find(y) ? "YES\n" : "NO\n");


	}

	cout << result;

	return 0;
}
