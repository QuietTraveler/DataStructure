#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#ifndef NODE
#define NODE 8
#define NUM (2*NODE)
typedef char HMTreeType;
typedef struct HuffmanTree {
	HMTreeType val;
	int parent;
	int lchild;
	int rchild;
	int weight;
}HMTree;

#endif
void CreateHMTree(HMTree* T,int node);

void Minimal(HMTree* T, int num, int& min1, int& min2);

void HMTreePirnt(HMTree* T);

char** AcquireCode(HMTree* T, int node);

void CodesPrint(char** codes, int node);

char* Decode(HMTree* T, char* codes, int node, int codesSize,int *returnSize);