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

#define MAX_L 1000

char text[MAX_L];

int count_palindromic_slices() {
	int length = strlen(text);

	int count = 0;

	for (int position=0; position < length; position++) {
		int offset = 0;

		// Check the "aa" situation
		while((position-offset>=0) && (position+offset+1) < length && text[position-offset] == text[position+offset+1]) {
			count ++;
			offset ++;
		}

		offset = 1;  // reset it for the odd length checking
		// Check the string for "aba" situation
		while((position-offset>=0) && position+offset < length &&  text[position-offset] == text[position+offset]) {
			count ++;
			offset ++;
		}
	}
	return count;
}

int main() {

	freopen("input","r",stdin);

	scanf("%s", text);

	int result = count_palindromic_slices();

	printf("%d", result);

	return 0;
}
