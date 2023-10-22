#define _CRT_SECURE_NO_WARNINGS  1

#include"stack.h"

Stack* Init()
{
	Stack* head = new Stack;
	head->data = 0;
	head->next = nullptr;
	return head;
}

bool Empty(Stack* s)
{
	if (s)
	{
		return s->data == 0;
	}
}

void Push(Stack* s, type data)
{
	if (s)
	{
		Stack* node = new Stack;
		node->data = data;
		node->next = s->next;
		s->next = node;
		s->data++;
	}

}

void Pop(Stack* s)
{
	if (s && s->data)
	{
		Stack* node = s->next;
		s->next = node->next;
		delete(node);
		s->data--;
	}
}

type Top(Stack* s)
{
	if (s)
		return s->next->data;
	return NULL;
}

void Destroy(Stack* s)
{
	Stack* node = s;
	while (node)
	{
		s = s->next;
		delete(node);
		node = s;
	}
}