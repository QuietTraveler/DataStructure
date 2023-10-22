#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#ifndef ONE
#define ONE 10

typedef int BiTreeType;

typedef enum {
	Link,
	Tread
}status;

typedef struct BiTreeNode {
	BiTreeType val;
	status ltag;
	status rtag;
	BiTreeNode* lchild;
	BiTreeNode* rchild;
}BiTreeNode;

#endif

void CreateBiTree(BiTreeNode* &Tp);

void TraverTreBiTree(BiTreeNode*Tp);

BiTreeNode* HeadTreBiTree(BiTreeNode* Tp);

void TraverBiTree(BiTreeNode* Tp);

void TraverTread(BiTreeNode* head);