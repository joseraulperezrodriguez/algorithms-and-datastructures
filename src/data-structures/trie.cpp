#include <iostream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <string.h>

#define NONINITIALIZED 0

using namespace std;



struct node {
	node* sons[26];
	int sonsN;
	int sonsArray[26];
	bool isLeaf;

	node(){
		sonsN = 0;
		isLeaf = false;
		for(int I = 0; I < 26; I++){
			sons[I] = NONINITIALIZED;
		}
	}
};

node* treeRoot = new node();

int startIndex = (int)'a';

node* currentInsert;

int types = 0;

void insert(int ch){
	int index = ch - startIndex;
	if(currentInsert->sons[index] != NONINITIALIZED){
		currentInsert = currentInsert->sons[index];
	}
	else {
		node* next = new node();
		currentInsert->sonsArray[currentInsert->sonsN++] = index;
		currentInsert->sons[index] = next;
		currentInsert = next;
	}
}

void traverse(node* current, int cumul){
	if(current->sonsN == 0){
		types += cumul;
		return;
	}

	int carrier = 0;
	if(current->isLeaf){
		types += cumul;
		if(current->sonsN == 1){
			carrier++;
		}
	}

	if(current->sonsN == 1){
		node* current1 = current->sons[current->sonsArray[0]];
		traverse(current1,cumul + carrier);
		return;
	}

	for(int I = 0; I < current->sonsN; I++){
		node* current1 = current->sons[current->sonsArray[I]];
		carrier = 1;
		traverse(current1, cumul + carrier);
	}

}

int main() {

	//freopen("Input","r",stdin);

	treeRoot = new node();
	char word[80];

	int words = 0;
	while(scanf("%d",&words) != EOF){
		treeRoot = new node();
		types = 0;

		for(int I = 0; I < words; I++){
			currentInsert = treeRoot;

			scanf("%s",word);
			int lenght = strlen(word);
			for(int I = 0; I < lenght; I++){
				insert(word[I]);
			}

			currentInsert->isLeaf = true;
		}

		currentInsert = treeRoot;

		types += words;

		for(int I = 0; I < treeRoot->sonsN; I++){
			currentInsert = treeRoot->sons[treeRoot->sonsArray[I]];
			traverse(currentInsert,0);
		}

		float f = (float)types / (float)words;

		printf("%.2f\n",f);
	}

	return 0;
}
