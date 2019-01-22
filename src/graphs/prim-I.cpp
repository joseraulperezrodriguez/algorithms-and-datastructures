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
typedef pair<i64, int> pli;
typedef pair<int, int> pii;

#define MAXN 200002
#define oo 9.223372e+18

int n,m;

vector< pair<i64, int > > graph[MAXN];
i64 metric[MAXN];
bool visited[MAXN];

void solve() {

	scanf("%d %d", &n, &m);


	for(int i = 0; i < m; i++) {
		int u,v;
		i64 w;
		scanf("%d %d %lli", &u, &v, &w);
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
	}

	i64 ans;
	priority_queue< pli, vector< pli >, greater< pli > > pq;
	for(int i = 0; i < n; i++) metric[i] = oo;
	metric[0] = ans = 0;
	memset(visited, 0, sizeof(visited));
	pq.push(make_pair(0,0));
	while(!pq.empty()) {
		pair<i64, int> pr = pq.top(); pq.pop();
		if(visited[pr.second]) continue;

		ans += pr.first;
		visited[pr.second] = true;
		for(int i = 0; i < (int)graph[pr.second].size(); i++) {
			pair<i64, int> cur = graph[pr.second][i];
			if(!visited[cur.second] && metric[cur.second] > cur.first) {
				pq.push(cur);
				metric[cur.second] = cur.first;
			}
		}
	}
	printf("%lli", ans);
}

int main(int size, char** args) {
	//freopen("input","r",stdin);
	solve();
	//test();
}
