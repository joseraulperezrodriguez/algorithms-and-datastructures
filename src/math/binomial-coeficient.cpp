//============================================================================
// Name        : HackerRank.cpp
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

typedef long long int int64;

int binom ( int p, int n ) {
    if ( p == 0 ) return 1;
    int num = n;
    int den = p;
    while ( p > 1 ) {
        p--;
        num *= n - p;
        den *= p;
    }
    return num / den;
}

int nCr ( int n, int r ) {

  int ncr = n;
  int k = 1;
  int r1 = n - r;

  /* Handle special cases */
  if ( r1 < 0 ) return 0;    // Invalid value
  if ( r1 < r ) r = r1;      // nCr = nC(n-r)
  if ( r == 0 ) return 1;    // nC0 = 1

  /* To avoid integer overflow, divide as early as possible */
  while ( ++k <= r ) {
    ncr *= --n;
    ncr /= k;
  }

  return ncr;
}


/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD) {
    long long x=1,y=a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long inverse_euler(int n, int MOD) {
    return pow(n,MOD-2,MOD);
}

long long C(int n, int r, int MOD) {
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((inverse_euler(f[r], MOD) * inverse_euler(f[n-r], MOD)) % MOD)) % MOD;
}

int main() {

	ios_base::sync_with_stdio(false);

	//freopen("input","r",stdin);

	int sum= binom(2,8);

	printf("%d",sum);

	return 0;
}
