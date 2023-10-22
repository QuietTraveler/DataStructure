#pragma once
#include"BiTree.h"

#ifndef ALL
#define ALL 50
typedef BiTree* StackType;
typedef struct Stack {
    StackType* data;
    size_t capacity;
    size_t num;
}Stack;
#endif

void InitStack(Stack* K);

bool FullStack(Stack* K);

int EnterStack(Stack* K, StackType p);

bool EmptyStack(Stack* K);

int PopStack(Stack* K, StackType* q);

void DestroyStack(Stack* K);
