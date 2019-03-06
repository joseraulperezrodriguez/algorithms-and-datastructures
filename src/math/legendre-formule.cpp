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

//Finds the max power W of a prime P, such that P^W divides N!, example 5!
void solve(int n, int p) {

	int ans = 0;
	int pow = 1;
	while(pow <= n / p) {
		pow *= p;
		ans += n/pow;
	}
	printf("%d", ans);

}

int main() {
	//freopen("input","r",stdin);
	solve(6, 2);
}
