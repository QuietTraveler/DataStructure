#define _CRT_SECURE_NO_WARNINGS  1

#include <iostream>
#include <cstdlib>
#include<assert.h>
using namespace std;
typedef int keytype;

typedef struct LinkList {
	keytype val;
	struct LinkList* next;
}LinkList,Linkhead;

Linkhead* Init_LinkList()
{
	Linkhead* phead = new Linkhead;
	phead->val = 0;
	phead->next = NULL;
	return phead;
}

LinkList* Search(Linkhead* phead,keytype data)
{
	assert(phead);
	LinkList* cur = phead->next;
	while (cur)
	{
		if (cur->val == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void Head_Insert(Linkhead* phead,keytype data)
{
	assert(phead);
	LinkList* node = new LinkList;
	node->val = data;
	node->next = phead->next;
	phead->next = node;
	phead->val++;
}

bool Middle_Insert(Linkhead* phead, keytype idata,keytype fdata)
{
	assert(phead);
	LinkList* prev = phead;
	LinkList* cur = prev->next;
	while (cur)
	{
		if (cur->val == fdata)
		{
			LinkList* node = new LinkList;
			node->val = idata;
			node->next = cur;
			prev->next = node;
			phead->val++;
			return true;
		}
		prev = cur;
		cur = cur->next;
	}
	return false;
}

bool Tail_Insert(Linkhead* phead,keytype data)
{
	assert(phead);
	LinkList* cur = phead;
	LinkList* node = new LinkList;
	node->val = data;
	while (cur->next)
		cur = cur->next;
	node->next = cur->next;
	cur->next = node;
	phead->val++;
	return true;
}

bool Modify(Linkhead* phead,keytype fdata,keytype mdata)
{
	assert(phead);
	LinkList* cur = phead->next;
	LinkList* p = Search(phead, fdata);
	if (p)
	{
		p->val = mdata;
		return true;
	}
	return false;
}

bool Head_Delete(Linkhead* phead)
{
	assert(phead);
	if(phead->next)
	{
		LinkList* cur = phead->next;
		phead->next = cur->next;
		delete(cur);
		phead->val--;
		return true;
	}
	return false;
}

bool Tail_Delete(Linkhead* phead)
{
	assert(phead);
	if (phead->next)
	{
		LinkList* cur = phead;
		LinkList* tail = cur->next;
		while (tail->next)
		{
			cur = tail;
			tail = tail->next;
		}
		phead->val--;
		cur->next = tail->next;
		delete(tail);
		return true;
	}
	return false;
}

bool Middle_Delete(Linkhead* phead,keytype data)
{
	assert(phead);
	LinkList* prev = phead;
	LinkList* cur = prev->next;
	while (cur)
	{
		if (cur->val == data)
		{
			prev->next = cur->next;
			delete(cur);
			phead->val--;
			return true;
		}
		prev = cur;
		cur = cur->next;
	}
	return false;
}

void Print_List(Linkhead* phead)
{
	LinkList* cur = phead->next;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
}

void I_Insert(Linkhead* phead, int i,int data)
{
	LinkList* node = phead;
	LinkList* cur = new LinkList;
	cur->val = data;
	int j = 0;
	while (j < i)
	{
		node = node->next;
		j++;
	}
	cur->next = node->next;
	node->next = cur;
}

int main() {
	LinkList* phead = Init_LinkList();
	Head_Insert(phead,1);
	Head_Insert(phead,2);
	Head_Insert(phead,3);
	Head_Insert(phead,4);
	Head_Insert(phead,2);
	Head_Insert(phead,3);
	Head_Insert(phead,1);
	Print_List(phead);
	return 0;
}

