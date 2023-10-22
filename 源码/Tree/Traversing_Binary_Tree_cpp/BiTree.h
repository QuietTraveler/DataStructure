#define _CRT_SECURE_NO_WARNINGS  1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#ifndef ONE
#define ONE 1
typedef  int TreeType;

typedef struct BiTree
{
    TreeType data;
    BiTree* lchild;
    BiTree* rchild;
}BiTree;
#endif

void InitBiTree(BiTree* T);

void Visit(BiTree* T);

void TraverBiTree(BiTree* T);

void CreateBiTree(BiTree*& T);

void CopyBiTree(BiTree* T, BiTree*& newT);

int DepthBiTree(BiTree* T);

int LeafBiTree(BiTree* T);

int NodeBiTree(BiTree* T);

int* preorderTraversal(BiTree* T, int* returnSize);

int TraversalBiTree(BiTree* T, int* arr);
