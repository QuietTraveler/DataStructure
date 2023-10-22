//#define _CRT_SECURE_NO_WARNINGS  1
//
//#include <iostream>
//#include<cstdlib>
//#include<cstring>
//#include<assert.h>
//#define MAX 10
////Ë³ÐòÕ»
//using namespace std;
//typedef int  stacktype;
//
//typedef struct Stack {
//	int top;
//	int capacity;
//	stacktype* data;
//
//}Stack;
//
//Stack* InitStack()
//{
//	Stack* node = new Stack;
//	node->data = new stacktype[MAX];
//	node->capacity = MAX;
//	node->top = 0;
//	return node;
//}
//
//bool EmptyStack(Stack* S)
//{
//	assert(S);
//	return S->top==0;
//}
//
//bool FullStack(Stack* S)
//{
//	assert(S);
//	return S->top == S->capacity;
//}
//
//bool StackPush(Stack* S,stacktype data)
//{
//	assert(S);
//	if (FullStack(S))
//		return false;
//	S->data[S->top++] = data;
//	return true;
//}
//
//bool StackPop(Stack* S,stacktype& data)
//{
//	assert(S);
//	if (EmptyStack(S))
//	return false;
//	data = S->data[S->top-1];
//	S->top--;
//	return true;
//}
//
//stacktype StackGetTop(Stack* S)
//{
//	assert(S);
//	return S->data[S->top - 1];
//}
//
//void Print(Stack* S)
//{
//	for (int i = 0; i < S->top; i++)
//	{
//		cout << S->data[i] << " ";
//	}
//	cout << endl;
//}
//
//bool StackDestroy(Stack* S)
//{
//	assert(S);
//	free(S->data);
//	free(S);
//	return true;
//}
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
//	Print(S);
//	StackDestroy(S);
//	return 0;
//}
//
