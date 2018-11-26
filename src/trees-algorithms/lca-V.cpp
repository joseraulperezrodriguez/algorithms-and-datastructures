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

using namespace std;

#define MAXV 1001

/*typedef void (*function) (char_node*, int);

function functions[2] = {&increment_last, &add_new};*/

int graph[MAXV][MAXV];
int ady[MAXV];
int lca[MAXV];

int cities = 0;
int pipes = 0;
int result = 0;


int calc_lca(int node){
	if(lca[node] != 0)return lca[node];

	int prev = 1;
	bool equal = true;
	for(int I = 0; I < ady[node]; I++){
		int current_lca = calc_lca(graph[node][I]);
		if(prev == 1)prev = current_lca;
		if(prev != current_lca)equal = false;
	}

	if(equal)lca[node] = prev;
	else lca[node] = node;

	return lca[node];

}

int main(){

	memset(graph,0, sizeof(graph));
	memset(ady,0, sizeof(ady));
	memset(lca,0, sizeof(lca));

	lca[1] = 1;

	scanf("%d %d", &cities, &pipes);

	for(int I = 0; I < pipes; I++){
		int a = 0;
		int b = 0;

		scanf("%d %d", &a, &b);
		if(a == 1)lca[b] = b;
		graph[b][ady[b]++] = a;
	}

	for(int I = cities; I > 0; I--)calc_lca(I);

	result = cities - 1;

	for(int I = 2; I <= cities; I++)
		for(int J = I + 1; J <= cities; J++)
            if(lca[I] != lca[J])result++;


    printf("%d", result);

	return 0;
}
