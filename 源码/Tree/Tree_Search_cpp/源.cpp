//#define _CRT_SECURE_NO_WARNINGS  1
//#include<iostream>
//#include<cstdlib>
//#include<cstring>
//typedef int keytype;
//typedef int etype;
//typedef struct Element {
//	keytype key;
//	etype info;
//}Element;
//
//typedef struct SearchTree {
//	Element data;
//	STree* rchild;
//	STree* lchild;
//}STree, *root;
//
//void InitSTree(root& ST)
//{
//	ST = new STree;
//	ST->data.key = ST->data.info = 0;
//	ST->lchild = ST->rchild = NULL;
//}
//
////¶þ²æËÑË÷Ê÷µÝ¹é²éÕÒ
//STree* STreeSearch(root ST,keytype data)
//{
//	if ( !ST|| ST->data.key == data)
//	{
//		return ST;
//	}
//	else if (ST->data.key < data)
//	{
//		return STreeSearch(ST->rchild, data);
//	}
//	else
//	{
//		return STreeSearch(ST->lchild, data);
//	}
//}
//
////¶þ²æËÑË÷Ê÷µÄ·ÇµÝ¹é²éÕÒ
//STree* STreeSearch(root ST, keytype data)
//{
//	STree* cur = ST;
//	while (cur)
//	{
//		if (cur->data.key > data)
//		{
//			cur = cur->lchild;
//		}
//		else if (cur->data.key < data)
//		{
//			cur = cur->rchild;
//		}
//		else
//			return cur;
//	}
//	return NULL;
//}
//
////ËÑË÷¶þ²æÊ÷µÄ²åÈë
//bool STreeInsert(root& ST, keytype data)
//{
//	STree* cur = ST, * prev = ST;
//	while (cur)
//	{
//		prev = cur;
//		if (cur->data.key > data)
//		{
//			cur = cur->lchild;
//		}
//		else if (cur->data.key < data)
//		{
//			cur = cur->rchild;
//		}
//		else
//			return true;
//	}
//		STree* node = new STree;
//		node->data.key = data;
//		if (prev->data.key>data)
//			prev->lchild = node;
//		else
//			prev->rchild = node;
//		return true;
//}
//
////¶þ²æËÑË÷Ê÷µÄÉ¾³ý
//bool STreeDelete(root& ST, keytype data)
//{
//	STree* cur = ST, STree* prev = ST;
//	while (cur)
//	{
//		prev = cur;
//		if (cur->data.key > data)
//		{
//			cur = cur->lchild;
//		}
//		else if (cur->data.key < data)
//		{
//			cur = cur->rchild;
//		}
//		else
//			break;
//	}
//	if (!cur)
//	{
//		return false;
//	}
//	else
//	{
//		if (prev->lchild && prev->rchild)
//		{
//			STree* pcur = prev->rchild, * pprev = prev->rchild;
//			while (pcur->lchild)
//			{
//				pprev = pcur;
//				pcur = pcur->lchild;
//			}
//			cur->data.key = pcur->data.key;
//			cur = pcur;
//			prev = pprev;
//		}
//			if (cur->lchild)
//				prev = cur->lchild;
//			else if(cur->rchild)
//				prev = cur->rchild;
//			if (cur == ST)
//				ST = NULL;
//			delete(cur);
//	}
//}
//
//void ReservePrint(root ST)
//{
//	ReservePrint(ST->lchild);
//    cout << ST->data.key << endl;
//	ReservePrint(ST->rchild);
//}
//
//int main()
//{
//	root ST;
//	initSTree(ST);
//	int key = 0;
//	for (int i = 0; i < 8; i++)
//	{
//		cout << "ÇëÊäÈë¹Ø¼ü×Ö:" << endl;
//		cin >> key;
//		STreeInsert(ST, key);
//	}
//	ReservePrint(ST);
//	return 0;
//}