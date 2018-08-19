//============================================================================
// Name        : Algorithm.cpp
// Author      : Jos� Ra�l P�rez Rodr�guez
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

char s[MAX_N];
char t[MAX_N];


int longest_substr() {
		int s_length = strlen(s);
		int t_length = strlen(t);

		if (s_length == 0 || t_length == 0) return 0;


		int m = s_length;
		int n = t_length;
		int cost = 0;
		int maxLen = 0;

		int pt[n];
		int* p = pt;

		int dt[n];
		int* d = dt;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				// calculate cost/score
				if (s[i] != t[j]) {
					cost = 0;
				} else {
					if ((i == 0) || (j == 0)) {
						cost = 1;
					} else {
						cost = p[j - 1] + 1;
					}
				}
				d[j] = cost;

				if (cost > maxLen) {
					maxLen = cost;
				}
			} // for {}

			int* swap = p;
			p = d;
			d = swap;
		}

		return maxLen;
	}

int main() {

	freopen("input","r",stdin);

	scanf("%s", s);
	scanf("%s", t);

	int result = longest_substr();

	printf("%d", result);

	return 0;
}
