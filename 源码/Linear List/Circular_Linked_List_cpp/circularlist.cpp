#define _CRT_SECURE_NO_WARNINGS  1

#include <iostream>
#include <cstdlib>
#include<assert.h>
using namespace std;
typedef int keytype;

typedef struct LinkList {
	keytype val;
	struct LinkList* next;
}LinkList, Linkhead;

Linkhead* Init_LinkList()
{
	Linkhead* ptail = new Linkhead;
	ptail->val = 0;
	ptail->next = ptail;
	return ptail;
}

LinkList* Search(Linkhead* ptail, keytype data)
{
	assert(ptail);
	LinkList* phead = ptail->next;
	LinkList* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->val == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void Head_Insert(Linkhead*& ptail, keytype data)
{
	assert(ptail);
	LinkList* node = new LinkList;
	LinkList* phead = ptail->next;
	node->val = data;
	node->next = phead->next;
	if (phead->next==phead)
		ptail = node;
	phead->next = node;
	phead->val++;
}

bool Middle_Insert(Linkhead* ptail, keytype idata, keytype fdata)
{
	assert(ptail);
	Linkhead* phead = ptail->next;
	LinkList* prev = phead;
	LinkList* cur = prev->next;
	while (cur!=phead)
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

bool Tail_Insert(Linkhead*& ptail, keytype data)
{
	assert(ptail);
	LinkList* phead = ptail->next;
	LinkList* node = new LinkList;
	node->val = data;
	node->next = ptail->next;
	ptail->next = node;
	ptail = node;
	phead->val++;
	return true;
}

bool Modify(Linkhead* ptail, keytype fdata, keytype mdata)
{
	assert(ptail);
	LinkList* p = Search(ptail, fdata);
	if (p)
	{
		p->val = mdata;
		return true;
	}
	return false;
}

bool Head_Delete(Linkhead*& ptail)
{
	assert(ptail);
	Linkhead* phead = ptail->next;
	if (phead->next!=phead)
	{
		LinkList* cur = phead->next;
		phead->next = cur->next;
		delete(cur);
		phead->val--;
		if (phead->next == phead)
			ptail = phead;
		return true;
	}
	return false;
}

bool Tail_Delete(Linkhead*& ptail)
{
	assert(ptail);
	Linkhead* phead = ptail->next;
	if (phead->next!= phead)
	{
		LinkList* cur = phead->next;
		while (cur->next != ptail)
			cur = cur->next;
		phead->val--;
		cur->next = ptail->next;
		delete(ptail);
		ptail = cur;
		return true;
	}
	return false;
}

bool Middle_Delete(Linkhead* ptail, keytype data)
{
	assert(ptail);
	LinkList* prev = ptail->next;
	LinkList* cur = prev->next;
	while (cur!=ptail->next)
	{
		if (cur->val == data)
		{
			prev->next = cur->next;
			delete(cur);
			ptail->next->val--;
			return true;
		}
		prev = cur;
		cur = cur->next;
	}
	return false;
}

void Print_List(Linkhead* ptail)
{
	LinkList* phead = ptail->next;
	LinkList* cur = phead->next;
	while (cur!=phead)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

void I_Insert(Linkhead* ptail, int i, int data)
{
	if (i > ptail->next->val - 1)
		return;
	LinkList* node = ptail->next;
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
	LinkList* ptail = Init_LinkList();
	Head_Insert(ptail, 5);
	Tail_Insert(ptail, 30);
	Middle_Insert(ptail, 45, 30);
	Print_List(ptail);
	//Head_Delete(ptail);
	//Tail_Delete(ptail);
	//Middle_Delete(ptail,45);
	//Search(ptail, 0);
	I_Insert(ptail, 0, 111);
	Print_List(ptail);
	return 0;
}

