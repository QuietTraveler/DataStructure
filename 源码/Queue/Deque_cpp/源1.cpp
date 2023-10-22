#define _CRT_SECURE_NO_WARNINGS  1

#include <iostream>
#include<cstdlib>
#include<cstring>
#include<assert.h>
using namespace std;
typedef struct Node {
	int val;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct deque {
	Node* lport;
	Node* rport;
}deque;

deque* Init_Deque()
{
	deque* Q = new deque;
	Q->rport = new Node;
	Q->rport->next = NULL;
	Q->rport->prev = NULL;
	Q->lport = Q->rport;
	return Q;
}

bool Empty_Deque(deque* Q)
{
	assert(Q);
	return Q->lport == Q->rport || Q->lport == NULL;
}

bool L_Pop_Deque(deque* Q)
{
	assert(Q);
	if (Empty_Deque(Q))
		return false;
	Node* node = Q->lport;
	Q->lport = node->next;
	Q->lport->prev = node->prev;
	delete(node);
	return true;
}

bool R_Pop_Deque(deque* Q)
{
	assert(Q);
	if (Empty_Deque(Q))
		return false;
	Node* node = Q->rport;
	Q->rport = Q->rport->prev;
	Q->rport->next = node->next;
	delete(node);
	return true;
}

bool L_Push_Deque(deque* Q, int data)
{
	assert(Q);
	Node* node = new Node;
	node->val = data;
	node->next = Q->lport;
	node->prev = Q->lport->prev;
	Q->lport->prev = node;
	Q->lport = node;
	return true;
}

bool R_Push_Deque(deque* Q, int data)
{
	assert(Q);
	Q->rport->val = data;
	Node* node = new Node;
	node->prev = Q->rport;
	node->next = Q->rport->next;
	Q->rport->next = node;
	Q->rport = node;
	return true;
}

int Length_Deque(deque* Q)
{
	assert(Q);
	int count = 0;
	Node* node = Q->lport;
	while (node)
	{
		count++;
		node = node->next;
	}
	return count-1;
}

bool Destroy_Deque(deque* Q)
{
	assert(Q);
	if (Empty_Deque(Q))
		return false;
	Node* node = Q->lport;
	Node* next = NULL;
	while (node)
	{
		next = node->next;
		delete(node);
		node = next;
	}
	delete(Q);
	return true;
}

void Print(deque* Q)
{
	Node* node = Q->lport;
	for (int i = 0; i < Length_Deque(Q); i++)
	{
		cout << node->val << " ";
		node=node->next;
	}
	cout << endl;
}
int main() {

	deque* Q = Init_Deque();
	R_Push_Deque(Q, 5);
	R_Push_Deque(Q, 3);
	R_Push_Deque(Q, 2);
	R_Push_Deque(Q, 1);
	R_Push_Deque(Q, 7);
	L_Push_Deque(Q, 6);
	L_Push_Deque(Q, 21);
	Print(Q);
//	L_Pop_Deque(Q);
//	L_Pop_Deque(Q);
//	L_Pop_Deque(Q);
//	L_Pop_Deque(Q);
	L_Pop_Deque(Q);
//	R_Pop_Deque(Q);
	R_Pop_Deque(Q);
//	R_Pop_Deque(Q);
	L_Pop_Deque(Q);
	Print(Q);
	R_Push_Deque(Q, 5);
	R_Push_Deque(Q, 3);
	R_Push_Deque(Q, 2);
	R_Push_Deque(Q, 1);
	R_Push_Deque(Q, 7);
//	L_Push_Deque(Q, 6);
//	L_Push_Deque(Q, 21);
	Print(Q);
	return 0;
}

