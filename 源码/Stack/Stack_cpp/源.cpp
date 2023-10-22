//#define _CRT_SECURE_NO_WARNINGS  1
//#include <iostream>
//#include<cstdlib>
//#include<cstring>
//#include<assert.h>
//#define MAX 5
//using namespace std;
////Á´Õ»
//typedef struct SNode {
//	int data;
//	struct SNode* next;
//}SNode;
//
//typedef struct Stack {
//	SNode* top;
//	int size;
//	int capacity;
//}Stack;
//
//Stack* InitStack()
//{
//	Stack* node = new Stack;
//	node->top = NULL;
//	node->capacity = MAX;
//	node->size = 0;
//	return node;
//}
//
//bool EmptyStack(Stack* S)
//{
//	assert(S);
//	return S->top == NULL;
//}
//
//bool FullStack(Stack* S)
//{
//	assert(S);
//	return S->size == S->capacity;
//}
//
//bool StackPush(Stack* S, int data)
//{
//	assert(S);
//	if (FullStack(S))
//		return false;
//		SNode* node = new SNode;
//		node->data = data;
//		node->next = S->top;
//		S->top = node;
//		S->size++;
//	return true;
//}
//
//bool StackPop(Stack* S, int& data)
//{
//	assert(S);
//	if (EmptyStack(S))
//		return false;
//	data = S->top->data;
//	S->top = S->top->next;
//	S->size--;
//	return true;
//}
//
//int StackGetTop(Stack* S)
//{
//	assert(S);
//	return S->top->data;
//}
//
//void Print(Stack* S)
//{
//	assert(S);
//	SNode* node = S->top;
//	while(node)
//	{
//		cout << node->data << " ";
//		node = node->next;
//	}
//	cout << endl;
//}
//
//bool StackDestroy(Stack* S)
//{
//	assert(S);
//	SNode* node = S->top;
//	SNode* node1 = node;
//	while (node1)
//	{
//		node = node1->next;
//		free(node1);
//		node1 = node;
//	}
//	free(S);
//	return true;
//}
//
//int main() {
//	Stack* S = InitStack();
//	StackPush(S, 3);
//	StackPush(S, 4);
//	StackPush(S, 5);
//	StackPush(S, 1);
//	StackPush(S, 1);
//	int data = 0;
//	StackPop(S, data);
//	StackPop(S, data);
//	StackPop(S, data);
//	Print(S);
//	StackDestroy(S);
//	return 0;
//}
