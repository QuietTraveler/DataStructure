#define _CRT_SECURE_NO_WARNINGS  1
#include"Queue.h"

Queue* InitQueue()
{
	Queue* q = new Queue;
	QNode* node = new QNode;
	q->head = q->tail = node;
	return q;
}

bool EmptyQueue(Queue* q)
{
	return q->head == q->tail;
}

void PushQueue(Queue* q, Qtype data)
{
	QNode* node = new QNode;
	node->data = data;
	node->next = q->tail->next;
	q->tail->next = node;
	q->tail = node;
}

Qtype PopQueue(Queue* q)
{
	Qtype val = NULL;
	if (!EmptyQueue(q))
	{
		QNode* node = q->head->next;
		q->head->next = node->next;
		if (!(q->head->next))
			q->tail = q->head;
		val = node->data;
		delete(node);
	}
	return val;
}

void DestroyQueue(Queue* q)
{
	QNode* prev = q->head;
	while (prev)
	{
		QNode* cur = prev->next;
		delete(prev);
		prev = cur;
	}
	delete(q);
}
