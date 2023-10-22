#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef int keytype;
typedef int etype;
typedef struct Element {
	keytype key;
	etype info;
}Element;

typedef struct SearchTree {
	Element data;
	struct SearchTree* rchild;
	struct SearchTree* lchild;
}STree, * root;

void InitSTree(root& ST)
{
	ST = new STree;
	ST->data.key = ST->data.info = 6;
	ST->lchild = ST->rchild = NULL;
}

//¶þ²æËÑË÷Ê÷µÝ¹é²éÕÒ
STree* STreeSearch1(root ST, keytype data)
{
	if (!ST || ST->data.key == data)
	{
		return ST;
	}
	else if (ST->data.key < data)
	{
		return STreeSearch1(ST->rchild, data);
	}
	else
	{
		return STreeSearch1(ST->lchild, data);
	}
}

//¶þ²æËÑË÷Ê÷µÄ·ÇµÝ¹é²éÕÒ
STree* STreeSearch(root ST, keytype data)
{
	STree* cur = ST;
	while (cur)
	{
		if (cur->data.key > data)
		{
			cur = cur->lchild;
		}
		else if (cur->data.key < data)
		{
			cur = cur->rchild;
		}
		else
			return cur;
	}
	return NULL;
}

//ËÑË÷¶þ²æÊ÷µÄ²åÈë
bool STreeInsert(root& ST, keytype data)
{
	STree* cur = ST, * prev = ST;
	while (cur)
	{
		prev = cur;
		if (cur->data.key > data)
		{
			cur = cur->lchild;
		}
		else if (cur->data.key < data)
		{
			cur = cur->rchild;
		}
		else
			return true;
	}
	STree* node = new STree;
	node->data.key = data;
	node->lchild = node->rchild = NULL;
	if (!cur)
	{
		ST = node;
		return true;
	}
	if (prev->data.key > data)
		prev->lchild = node;
	else if(prev->data.key<data)
		prev->rchild = node;
	return true;
}

//¶þ²æËÑË÷Ê÷µÄÉ¾³ý
bool STreeDelete(root& ST, keytype data)
{
	STree* cur = ST, * prev = ST;
	while (cur)
	{
		prev = cur;
		if (cur->data.key > data)
		{
			cur = cur->lchild;
		}
		else if (cur->data.key < data)
		{
			cur = cur->rchild;
		}
		if (cur->data.key == data)
			break;
	}
	if (!cur)
	{
		return false;
	}
	else
	{
		if (cur->lchild && cur->rchild)
		{
			STree* pcur = cur->rchild, * pprev = cur;
			while (pcur->lchild)
			{
				pprev = pcur;
				pcur = pcur->lchild;
			}
			cur->data.key = pcur->data.key;
			cur = pcur;
			prev = pprev;
		}
		STree* temp = NULL;
		if (cur->lchild)
			temp = cur->lchild;
		else if (cur->rchild)
			temp = cur->rchild;
		if (cur == prev)
		{
			if (!cur->lchild && !cur->rchild)
			{
				ST = NULL;
			}
			else
			{
				if (cur->lchild)
					ST = cur->lchild;
				else
					ST = cur->rchild;
			}
		}
		else
		{
			if (prev->lchild == cur)
			{
				prev->lchild = temp;
			}
			else if (prev->rchild == cur)
			{
				prev->rchild = temp;
			}
		}
		delete(cur);
		return true;
	}
}

void ReservePrint(root ST)
{
	if (!ST)
		return;
	ReservePrint(ST->lchild);
	cout << ST->data.key << " ";
	ReservePrint(ST->rchild);
}

int main()
{
	root ST;
	InitSTree(ST);
	int key = 0;
	for (int i = 0; i < 9; i++)
	{
		cout << "ÇëÊäÈë¹Ø¼ü×Ö:" << endl;
		cin >> key;
		STreeInsert(ST, key);
	}
	cout << endl;
	ReservePrint(ST);
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "ÇëÊäÈëÒªÉ¾³ýµÄÊýÖµ:" << endl;
		cin >> key;
		STreeDelete(ST, key);
		ReservePrint(ST);
		cout << endl;
	}
	return 0;
}