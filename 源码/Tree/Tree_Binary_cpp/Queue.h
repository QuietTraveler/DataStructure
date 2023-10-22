#pragma once
#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef int TYPE;

typedef struct BTNode {
	TYPE data;
	struct BTNode* left = NULL;
	struct BTNode* right = NULL;
}BTNode;

typedef BTNode* Qtype;

typedef struct QNode {
	Qtype data;
	struct QNode* next=NULL;
}QNode;

typedef struct Queue {
	struct QNode* head;
	struct QNode* tail;
}Queue;

Queue* InitQueue();

bool EmptyQueue(Queue* q);

void PushQueue(Queue* q, Qtype data);

Qtype PopQueue(Queue* q);

void DestroyQueue(Queue* q);