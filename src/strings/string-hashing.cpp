//============================================================================
// Name        : Codeforces.cpp
// Author      : Jos Ral Prez Rodrguez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

#define MAXS 100001
#define MAXT 1000001
#define P 31
#define MOD 1000000009

char s[MAXS];
char t[MAXT];

int ls;
int lt;

int count0[MAXS];
int count1[MAXS];

vector<int> index0;
vector<int> index1;

i64 pows[MAXT];
i64 hashes[MAXT];

void init_pows() {
	pows[0] = 1;
	for (int i = 1; i < MAXT; i++) pows[i] = (pows[i-1] * P) % MOD;
}

void init_hashes() {
	hashes[0] = 0;
	for (int i = 0; i < MAXT; i++)
	    hashes[i+1] = (hashes[i] + (t[i] - 'a' + 1) * pows[i]) % MOD;
}

i64 hash_range(int i, int j) {
	i64 hash_value = (hashes[j] + MOD - hashes[i]) % MOD;
	hash_value = (hash_value * pows[MAXT-i-1]) % MOD;
	return hash_value;
}

void solve() {

	scanf("%s", s);

	ls = strlen(s);

	init_pows();
	init_hashes();

	i64 hash1 = hash_range(1,ls/2);
	i64 hash2 = hash_range((ls/2)+1, ls);

	cout << hash1 << " " << hash2;

}

int main(int size, char** args) {
	//freopen("input","r",stdin);
	solve();
}
