#define _CRT_SECURE_NO_WARNINGS  1
#include"TreadBiTree.h"
//����������
BiTreeNode* prev = NULL;
void CreateBiTree(BiTreeNode*& Tp)
{
	char data;
	printf("����������:\n");
	scanf("%c", &data);
	getchar();
	if (data=='n')
	{
		Tp = NULL;
		return;
	}
	BiTreeNode* node = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	if (node == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	node->val = data;
	node->ltag = node->rtag = Link;
	node->lchild = node->rchild=NULL;
	Tp = node;
	CreateBiTree(Tp->lchild);
	CreateBiTree(Tp->rchild);
	return;
}

void TraverTreBiTree(BiTreeNode* Tp)
{
	if (Tp)
	{
		TraverTreBiTree(Tp->lchild);
		if (Tp->lchild==NULL)
		{
			Tp->ltag = Tread;
			Tp->lchild = prev;
		}
		if (prev != NULL && prev->rchild == NULL)
		{
			prev->rchild = Tp; 
			prev->rtag = Tread;
		}
		prev = Tp;
		TraverTreBiTree(Tp->rchild);
	}
}

BiTreeNode* HeadTreBiTree(BiTreeNode* Tp)
{
	assert(Tp);
	BiTreeNode* head = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	if (head == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	head->ltag = Link;
	head->rchild = head;
	head->rtag = Tread;
	if (Tp == NULL)
	{
		head->lchild = head;
		head->ltag = Tread;
	}
	else
	{
		head->lchild = Tp;
		prev = head;
		TraverTreBiTree(Tp);
		head->rchild = prev;
		prev->rtag = Tread;
		prev->rchild = head;
	}
	return head;
}

void TraverBiTree(BiTreeNode* Tp)
{
	if (Tp)
	{
		TraverBiTree(Tp->lchild);
		printf("�����:%c\n", Tp->val);
		TraverBiTree(Tp->rchild);
	}
}

void TraverTread(BiTreeNode* head)
{
	BiTreeNode* Tp = head->lchild;
	while (Tp != head)
	{
		while (Tp->ltag == Link)
		{
			Tp = Tp->lchild;
		}
		printf("�������:%c\n", Tp->val);
		while (Tp->rtag==Tread && Tp->rchild !=head)
		{
			Tp = Tp->rchild;
			printf("�������:%c\n", Tp->val);
		}
		Tp = Tp->rchild;
	}
}