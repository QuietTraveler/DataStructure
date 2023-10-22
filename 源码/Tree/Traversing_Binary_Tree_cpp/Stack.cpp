#define _CRT_SECURE_NO_WARNINGS  1
#include"Stack.h"

void InitStack(Stack* K)
{
    K->capacity = ALL;
    StackType* D = (StackType*)malloc(sizeof(StackType) * K->capacity);
    if (D == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    K->data = D;
    K->num = 0;
}

bool FullStack(Stack* K)
{
    assert(K);
    if (K->num == K->capacity)
    {
        return true;
    }
    return false;
}

int EnterStack(Stack* K, StackType p)
{
    assert(K);
    if (FullStack(K))
        return -1;
    K->data[K->num] = p;
    K->num++;
    return 1;
}

bool EmptyStack(Stack* K)
{
    assert(K);
    if (K->num==0) {
        return true;
    }
    return false;
}

int PopStack(Stack* K, StackType* q)
{
    assert(K);
    if (EmptyStack(K))
        return -1;
    K->num--;
    *q = K->data[K->num];
    return 1;
}

void DestroyStack(Stack* K)
{
    assert(K);
    free(K->data);
}
