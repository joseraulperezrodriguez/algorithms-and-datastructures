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

char text[MAX_N];
char token[MAX_N];

vector<int> KMP(int text_length, int token_length) {

	int T[token_length + 1];
	for(int I = 0; I <= token_length; I++)T[I] = -1;
	//vector<int> T(token_length + 1, -1);
	vector<int> matches;

	if(token_length == 0) {
		matches.push_back(0);
		return matches;
	}
	for(int i = 1; i <= token_length; i++) {
		int pos = T[i - 1];
		while(pos != -1 && token[pos] != token[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}

	int sp = 0;
	int kp = 0;
	while(sp < text_length) {
		while(kp != -1 && (kp == token_length || token[kp] != text[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == token_length) matches.push_back(sp - token_length);
	}

	return matches;
}

int main() {

	freopen("input","r",stdin);

	scanf("%s", text);
	scanf("%s", token);

	int text_length = strlen(text);
	int token_length = strlen(token);

	vector<int> result = KMP(text_length, token_length);

	for(int I = 0; I < (int)result.size(); I++) {
		printf("%d\n", result.at(I));
	}

	return 0;
}
