#define _CRT_SECURE_NO_WARNINGS  1
#include"queue.h"
void InitQueue(queue& q)
{
	q.capacity = MaxNum;
	q.head = q.tail = 0;
	int* arr = (int*)malloc(sizeof(int) * q.capacity);
	if(arr==NULL)
	{
		perror("malloc");
		exit(-1);
	}
	q.val = arr;
}

int QueuePush(queue* q, int data)
{
	assert(q);
	if (FullQueue(q))
	{
		return -1;
	}
	q->val[q->tail] = data;
	int k = q->capacity;
	q->tail = (q->tail + 1) % k;
	return 1;
}

bool EmptyQueue(queue* q)
{
	assert(q);
	return q->tail == q->head;
}

bool FullQueue(queue* q)
{
	assert(q);
	int k = q->capacity;
	if ((q->tail + 1) % k == q->head)
	{
		return true;
	}
	else
		return false;
}

int QueuePop(queue* q, int& top)
{
	assert(q);
	if (EmptyQueue(q))
	{
		return -1;
	}
	int k = q->capacity;
	top = q->val[q->head];
	q->head = (q->head + 1) % k;
	return 1;
}

void DestroyQueue(queue* q)
{
	assert(q);
	free(q->val);
	q->capacity = q->head = q->tail = 0;
}

void QueuePrint(queue* q)
{
	int k = q->capacity;
	for (int i = q->head; i != q->tail; i=(i+1)%k)
	{
		printf("%d ", q->val[i]);
	}
}