#define _CRT_SECURE_NO_WARNINGS  1
#include"queue.h"
int main()
{
	queue q;
	InitQueue(q);
	QueuePush(&q,2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	int data;
	QueuePop(&q,data);
	int ret=QueuePush(&q, 7);
	printf("%d %d\n",ret,data);
	QueuePrint(&q);
	return 0;
}