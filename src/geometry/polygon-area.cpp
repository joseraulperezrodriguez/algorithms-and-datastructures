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

int sides[6];



int main() {

	//freopen("input","r",stdin);


	for(int I = 0; I < 6; I++) {
		scanf("%d", &sides[I]);
	}


	/*int result = 0;

	int base = sides[0];
	for(int I = 0; I < sides[0 + 1]; I++) {
		result += (((base + I) * 2) + 1);
	}

	base = sides[3];
	for(int I = 0; I < sides[3 + 1]; I++) {
		result += (((base + I) * 2) + 1);
	}*/

	double eps = 0.01;

	double hight = 0.86602540378443864676372317075294;

	double triangle_area = (hight * (double)1) / (double)2;

	double x[6];
	double y[6];

	x[0] = 3.0;
	y[0] = 3.0;

	x[1] = x[0] + (double)sides[0];
	y[1] = y[0];

	x[2] = x[1] + ((double)sides[1] / (double)2);
	y[2] = y[1] - (hight * (double)sides[1]);

	x[3] = x[2] - ((double)sides[2] / (double)2);
	y[3] = y[2] - (hight * (double)sides[2]);

	x[4] = x[3] - (double)sides[3];
	y[4] = y[3];

	x[5] = x[4] - ((double)sides[4] / (double)2);
	y[5] = y[4] + (hight * (double)sides[4]);



	double sum1 = 0;
	double sum2 = 0;

	for(int I = 0; I < 6; I++) {
		sum1 += (x[I] * y[(I + 1) % 6]);
		sum2 += (y[I] * x[(I + 1) % 6]);
	}

	double area = sum1 - sum2;
	if(area < 0.0)area = area * (double)-1.0;

	area = area / (double)2.0;

	double coc = area / triangle_area;
	int result = (int)(area / triangle_area);

	double diff = (double)(result + 1) - coc;

	if(diff <= eps)result++;

	printf("%d", result);

	return 0;
}
