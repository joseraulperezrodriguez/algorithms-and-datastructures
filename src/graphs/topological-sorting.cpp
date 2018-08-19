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

#define MAX_N 1001

int nodes = 0, edges = 0;

vector<vector<int> > adj(MAX_N);

bool explored[MAX_N];

bool exploring[MAX_N];

int sorted[MAX_N];



void topological_sort_using_DFS(int I, int& t){
   explored[I] = true;

   for (int J = 0; J < (int)adj[I].size(); J++) {
      if (explored[adj[I][J]] == false) {
         topological_sort_using_DFS(adj[I][J], t);
      }
   }

   t--;
   sorted[t] = I;

   return;
}

void topological_sort_using_DFS_loop() {

   int t = nodes;

   for (int I = 0; I < nodes; I++) {
      if (explored[I] == false) {
         topological_sort_using_DFS(I + 1, t);
      }
   }

   return;
}

int traverseDAG(int parent) {
	if(exploring[parent])return 0;

	exploring[parent] = true;
	for(int I = 0; I < (int)adj[parent].size(); I++) {
		int son = adj[parent][I];

		if(exploring[son])return 0;
		if(explored[son])continue;

		if(!traverseDAG(son))return 0;
	}

	explored[parent] = true;
	exploring[parent] = false;

	return 1;

}

int main() {

	freopen("input","r",stdin);

	scanf("%d %d", &nodes, &edges);

	memset(explored,0, sizeof(explored));
	memset(exploring,0, sizeof(exploring));

	for(int I = 0; I < edges; I++) {
		int v = 0, u = 0;

		scanf("%d %d", &v, &u);
		adj[v].push_back(u);
	}

	bool isDAG = traverseDAG(1);
	if(isDAG)printf("Is a DAG");
	else printf("Not a DAG");

	//topological_sort_using_DFS_loop();

	/*for(int I = 0; I < nodes; I++){
		printf("%d ", sorted[I]);
	}*/

	return 0;
}
