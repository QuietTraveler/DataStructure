#define _CRT_SECURE_NO_WARNINGS  1
#include"Queue.h"

void InitQueue(Q* q)
{
    assert(q);
    q->head = q->tail = NULL;
}

void QueuePush(Q* q, QueueType p)
{
    assert(q);
    Queue* t = (Queue*)malloc(sizeof(Queue));
    if (t == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    t->data = p;
    t->next = NULL;
    if (q->head == NULL)
    {
        q->head = q->tail = t;
    }
    else
    {
        q->tail->next = t;
        q->tail = q->tail->next;
    }
}

bool QueueEmpty(Q* q)
{
    assert(q);
    return q->head==NULL;
}

int QueuePop(Q* q, QueueType& tree)
{
    assert(q);
    if (QueueEmpty(q))
    {
        return -1;
    }
    tree = q->head->data;
    Queue* cur = q->head->next;
    free(q->head);
    q->head = cur;
    return 1;
}

void QueueDestroy(Q* q)
{
    assert(q);
    while (q->head != NULL)
    {
        Queue* cur = q->head->next;
        free(q->head);
        q->head = cur;
    }
    q->tail = q->head;
}