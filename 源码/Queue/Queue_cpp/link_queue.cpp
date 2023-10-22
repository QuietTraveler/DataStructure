#define _CRT_SECURE_NO_WARNINGS  1

#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
//Á´¶ÓÁÐ
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct Queue {
	struct LinkNode* head;
	struct LinkNode* tail;
}Queue;

Queue* Init_Queue()
{
	Queue* Q = new Queue;
	Q->head = new LinkNode;
	Q->head->next = NULL;
	Q->tail = Q->head;
	Q->head->data = 0;
	return Q;
}

bool Empty_Queue(Queue* Q)
{
	return Q->head->data==0;
}

bool Queue_Push(Queue* Q, int data)
{
	LinkNode* node = new LinkNode;
	node->data = data;
	node->next = Q->tail->next;
	Q->tail->next = node;
	Q->tail = node;
	Q->head->data++;
	return true;
}

bool Queue_Pop(Queue* Q)
{
	if (Empty_Queue(Q))
		return false;
	LinkNode* node = Q->head->next;
	Q->head->next = node->next;
	delete(node);
	Q->head->data--;
	if (Q->head->data == 0)
	Q->tail = Q->head;
	return true;
}

int Queue_Lenth(Queue* Q)
{
	return Q->head->data;
}

void Print(Queue* Q)
{
	LinkNode* cur = Q->head->next;
	while(cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
	cout << Queue_Lenth(Q) << endl;
}

bool Queue_Destroy(Queue* Q)
{
	LinkNode* cur = Q->head;
	LinkNode* next = NULL;
	while (cur)
	{
	next = cur->next;
	delete(cur);
	cur = next;
	}
	delete(Q);
	return true;
}

int main() {
	Queue* Q = Init_Queue();
	Queue_Push(Q, 4);
	Queue_Push(Q, 5);
	Queue_Push(Q, 2);
	Queue_Push(Q, 1);
    Queue_Push(Q, 1);
	Queue_Push(Q, 1);
	Queue_Pop(Q);
	Queue_Pop(Q);
	Queue_Pop(Q);
	Queue_Pop(Q);
	Queue_Pop(Q);
	Queue_Pop(Q);
	Queue_Push(Q, 4);
	Queue_Push(Q, 5);
	Queue_Push(Q, 2);
	Queue_Push(Q, 1);
	Queue_Push(Q, 1);
	Queue_Push(Q, 1);
	Print(Q);
	Queue_Destroy(Q);
	return 0;
}


