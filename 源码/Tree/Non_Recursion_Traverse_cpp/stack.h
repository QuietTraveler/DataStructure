#pragma once
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

typedef int TYPE;

typedef struct BTNode {
	TYPE data = 0;
	struct BTNode* left = NULL;
	struct BTNode* right = NULL;
}BTNode;

typedef BTNode* type; 

typedef struct Stack {
	type data;
	struct Stack* next;
}Stack;

Stack* Init();

bool Empty(Stack* s);

void Pop(Stack* s);

void Push(Stack* s, type data);

type Top(Stack* s);

void Destroy(Stack* s);

