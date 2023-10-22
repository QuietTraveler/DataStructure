#define _CRT_SECURE_NO_WARNINGS  1

#include <iostream>
#include<cstdlib>
#include<cstring>
#include<assert.h>
using namespace std;

typedef struct DCirList {
	int val;
	struct DCirList* prev;
	struct DCirList* next;
}DLinkNode,*DLinkList;

DLinkList Init_DLinkList()
{
	DLinkList node = new DLinkNode;
	node->val = 0;
	node->next = node;
	node->prev = node;
	return node;
}

DLinkNode* Search(DLinkList phead, int fdata)
{
	assert(phead);
	DLinkNode* cur = phead->next;
	while (cur != phead && cur->val != fdata)
		cur = cur->next;
	if (cur!=phead)
		return cur;
	else
		return NULL;
}

bool Insert_DLinkList(DLinkList phead, int fdata, int idata)
{
	DLinkNode* cur = Search(phead, fdata);
	if (!cur)
		return false;
	DLinkNode* node = new DLinkNode;
	node->val = idata;
	DLinkNode* next = cur->next;
	node->next = next;
	node->prev = cur;
	cur->next = node;
	next->prev = node;
	return true;
}

bool Delete_DLinkList(DLinkList phead, int data)
{
	assert(phead);
	DLinkNode* cur = Search(phead, data);
	if (!cur)
		return false;
	DLinkNode* prev = cur->prev;
	DLinkNode* next = cur->next;
	prev->next = next;
	next->prev = prev;
	delete(cur);
	return false;
}

bool Head_Insert(DLinkList phead, int data)
{
	assert(phead);
	DLinkNode* node = new DLinkNode;
	node->val = data;
	node->next = phead->next;
	phead->next->prev = node;
	node->prev = phead;
	phead->next = node;
	return true;
}

void Print(DLinkList phead)
{
	assert(phead);
	DLinkNode* node = phead->next;
	while (node != phead)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

bool Modify(DLinkList phead, int fdata, int mdata)
{
	DLinkNode* node = Search(phead, fdata);
	if (!node)
		return false;
	node->val = mdata;
	return true;
}

int main() {

	DLinkList phead = Init_DLinkList();
	Head_Insert(phead, 5);
	Head_Insert(phead, 6);
	Insert_DLinkList(phead, 5, 9);
	Delete_DLinkList(phead, 5);
	Delete_DLinkList(phead, 6);
	Delete_DLinkList(phead, 9);
	Print(phead);
//	Modify(phead, 9, 4);
	Print(phead);
	return 0;
}



