#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#ifndef MaxNum
#define MaxNum 6;
typedef int* QueueType;

typedef struct queue {
	QueueType val;
	int capacity;  //数组实际容量
	int head;
	int tail;
}queue;

#endif

void InitQueue(queue& q);

bool EmptyQueue(queue* q);

bool FullQueue(queue* q);

int QueuePush(queue* q, int data);

int QueuePop(queue* q, int& top);

void DestroyQueue(queue* q);

void QueuePrint(queue* q);