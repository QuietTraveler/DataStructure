#pragma once
#include"BiTree.h"

#ifndef TWO
#define TWO 2
typedef BiTree* QueueType;

typedef struct Queue {
    QueueType data;
    Queue* next;
}Queue;

typedef struct Q {
    Queue* head;
    Queue* tail;
}Q;

#endif

void InitQueue(Q* q);

void QueuePush(Q* q, QueueType p);

bool QueueEmpty(Q* q);

int QueuePop(Q* q, QueueType& tree);

void QueueDestroy(Q* q);