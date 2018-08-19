

//=============================*/*===============================================
// Name        : Algorithm.cpp
// Author      : Jos Ral Prez Rodrguez
// Version     :
// Copp.secondright   : p.secondour copp.secondright notice
// Description : Hello World in C++, Ansi-stp.secondle
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

#define MAXN 100001

int segment_tree[MAXN * 5];

int segment_values[MAXN * 5];

int segment_lazy[MAXN * 5];


int segment_index[MAXN];


int m,p,t,x;

void initialize(int node, int start, int end){
	segment_tree[node] = 0;
	if(start == end){
		segment_index[start] = node/*or end*/;
	}
	else {
		int v = node*2;
		int u = (end + start) / 2;
		initialize(v, start, u);
		initialize((v) + 1, u + 1, end);
	}
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

	if(segment_lazy[node] != 0) { // This node needs to be updated
		segment_tree[node] += segment_lazy[node]; // Update it

		if(a != b) {
			segment_lazy[node*2] += segment_lazy[node]; // Mark child as lazy
			segment_lazy[node*2+1] += segment_lazy[node]; // Mark child as lazy
		}

		segment_lazy[node] = 0; // Reset it
	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

	if(a >= i && b <= j) { // Segment is fully within range
		segment_tree[node] += value;

		if(a != b) { // Not leaf node
			segment_lazy[node*2] += value;
			segment_lazy[node*2+1] += value;
		}

		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	segment_tree[node] = max(segment_tree[node*2], segment_tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return -MAXN; // Out of range

	if(segment_lazy[node] != 0) { // This node needs to be updated
		segment_tree[node] += segment_lazy[node]; // Update it

		if(a != b) {
			segment_lazy[node*2] += segment_lazy[node]; // Mark child as lazy
			segment_lazy[node*2+1] += segment_lazy[node]; // Mark child as lazy
		}

		segment_lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return segment_tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result

	return res;
}

int query_ans(int node, int a, int b) {

	if(a == b) {
		return (segment_values[node] > 0 ? segment_values[node] : -1);
	}
	//int qv = query_tree(node, 1, m, a, b);

	int ln = query_tree(node*2, a, (a+b)/2,a, (a+b)/2);
	int rn = query_tree(1+node*2, 1+(a+b)/2, b, 1+(a+b)/2, b);

	if(rn > 0) {
		return query_ans(1+node*2, 1+(a+b)/2, b);
	} else if(ln > 0) {
		return query_ans(node*2, a, (a+b)/2);
	} else return -1;

}


int main() {

	//freopen("input","r",stdin);
	scanf("%d", &m);

	initialize(1, 1, m);

	memset(segment_lazy,0,sizeof(segment_lazy));
	memset(segment_tree,0,sizeof(segment_tree));
	memset(segment_values,0,sizeof(segment_values));

	for(int i = 0; i < m; i++) {
		scanf("%d %d", &p, &t);

		if(t) scanf("%d", &x);

		segment_values[segment_index[p]] = x;

		update_tree(1,1,m,1,p,(t ? 1 : -1));

		//int ans = query_tree(1, 1, m, 1, m);
		int ans = query_ans(1,1,m);

		printf("%d\n", ans);

	}


	/*for(int i = 1; i < MAXN - 1; i++) segment_index[i] = 0;
	//build_tree(1, 0, N-1);
	initialize(1, 1, MAXN - 1);

	memset(segment_lazy, 0, sizeof segment_lazy);

	update_tree(1, 1, MAXN-1, 1, 6, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
	update_tree(1, 1, MAXN-1, 7, 10, 12); // Incremenet range [7, 10] by 12. here 0, N-1 represent the current range.
	update_tree(1, 1, MAXN-1, 10, 100, 100); // Increment range [10, N-1] by 100. here 0, N-1 represent the current range.

	cout << query_tree(1, 1, MAXN-1, 100, 100) << endl; // Get max element in range [0, N-1]*/

	return  0;
}

