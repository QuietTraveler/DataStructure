#define _CRT_SECURE_NO_WARNINGS  1
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<assert.h>

using namespace std;
//Á´Õ»
typedef struct SNode {
	int data;
	struct SNode* next;
}SNode;

typedef struct Stack {
	SNode* top;
	int capacity;
}Stack;

Stack* InitStack()
{
	Stack* node = new Stack;
	node->top = new SNode;
	node->top->next = NULL;
	node->top->data = 0;
	return node;
}

bool EmptyStack(Stack* S)
{
	assert(S);
	return S->top->data==0;
}

bool StackPush(Stack* S, int data)
{
	assert(S);
	SNode* node = new SNode;
	node->data = data;
	node->next = S->top->next;
	S->top->next = node;
	S->top->data++;
	return true;
}

bool StackPop(Stack* S, int& data)
{
	assert(S);
	if (EmptyStack(S))
		return false;
	SNode* node = S->top->next;
	data = node->data;
	S->top->next = node->next;
	delete(node);
	S->top->data--;
	return true;
}

int StackGetTop(Stack* S)
{
	assert(S);
	return S->top->next->data;
}

void Print(Stack* S)
{
	assert(S);
	SNode* node = S->top->next;
	while (node)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

bool StackDestroy(Stack* S)
{
	assert(S);
	SNode* node = S->top;
	SNode* node1 = node;
	while (node1)
	{
		node = node1->next;
		free(node1);
		node1 = node;
	}
	free(S);
	return true;
}

int main() {
	Stack* S = InitStack();
	StackPush(S, 3);
	StackPush(S, 4);
	StackPush(S, 5);
	StackPush(S, 1);
	StackPush(S, 1);
	int data = 0;
	StackPop(S, data);
	StackPop(S, data);
	StackPop(S, data);
	Print(S);
	StackDestroy(S);
	return 0;
}
