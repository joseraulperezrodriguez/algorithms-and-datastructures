//============================================================================
// Name        : Codeforces.cpp
// Author      : Jos Ral Prez Rodrguez
// Version     :
// Copyright   : Your copyright notice
// Description : Codeforces problem https://codeforces.com/contest/1117/problem/D,
//               using recurrence f(n) = f(n-m) + f(n-1)
//============================================================================
#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;
#define MAXM 101
#define MOD 1000000007

i64 n;
int m;
i64 matrix[1 << 7][MAXM][MAXM];

void multiply(int a, int b, int c) {
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < m; k++)
				matrix[c][i][j] = (matrix[c][i][j] + ((matrix[a][i][k] * matrix[b][k][j]) % MOD)) % MOD;
}

int mpow(i64 pow) {
	if(pow == 1) return 1;
	i64 half = pow / 2;
	int pi = mpow(half);
	multiply(pi, pi, pi + 1);
	if(pow % 2) multiply(pi + 1, 1, pi + 2);
	return pi + 1 + (pow % 2);
}


void solve() {
	scanf("%lli %d", &n, &m);

	if(n < m ) printf("1");
	else if(n == m ) printf("2");
	else {
		memset(matrix,0, sizeof(matrix));
		matrix[1][0][0] = matrix[1][0][m-1] = 1;
		matrix[0][0][0] = 2;
		for(int i = 1; i < m; i++) matrix[1][i][i-1] = 1;
		for(int i = 1; i < m; i++) matrix[0][i][0] = 1;

		int pi = mpow(n-m);
		multiply(pi, 0, pi + 1);
		printf("%lli", matrix[pi + 1][0][0]);
	}
}

int main() {
	//freopen("input","r",stdin);
	solve();
}
