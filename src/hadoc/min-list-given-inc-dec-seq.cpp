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
typedef pair<int,int> pii;
typedef pair<char,int> pci;

#define MAXN 10

char data[MAXN];
int ans[MAXN];
int ci = 1;

int consc(int start, int length) {
	int end = start;
	while(end < length && data[end+1] == data[start])
		end++;
	return (end-start)+1;
}

void fill(int index, int dir, int size) {
	for(int i = index + dir; size--; i += dir)
		ans[ci++] = i;
}

void solve() {
	scanf("%s", data);

	int length = strlen(data);

	vector<pci> compacted;
	int inc = 0;
	for(int i = 0; i < length; i += inc)
		compacted.push_back(make_pair(data[i], inc = consc(i, length)));


	ans[0] = (compacted[0].first == 'D' ? compacted[0].second + 1 : 1);
	int maxv = ans[0];
	for(int i = 0; i < (int)compacted.size(); i++) {
		pci cur = compacted[i];

		if(cur.first == 'D') fill(ans[ci-1], -1, cur.second);
		else {//I I D D D
			fill(maxv, +1, cur.second - 1);
			maxv = max(maxv, ans[ci-1]);//this is necessary because maybe ans[ci-1] is not the max, when cur.second == 1
			if(i+1 != (int)compacted.size())
				ans[ci++] = maxv + compacted[i+1].second + 1;
			else
				ans[ci++] = maxv+1;
			maxv = ans[ci-1];
		}
	}

	for(int i = 0; i <= length; i++)
		printf("%d ", ans[i]);

}

int main() {
	freopen("input","r",stdin);
	solve();
}
