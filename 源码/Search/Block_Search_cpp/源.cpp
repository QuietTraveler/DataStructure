#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<cstdlib>
#include<cstring>
#define MAX 5
#define NUM 3
#define E 5
#define N 101 
using namespace std;
typedef  int indexType;
typedef int elementType;

typedef struct Enode {
	elementType data;
	Enode* next;
}Enode;

typedef struct Index {
	indexType key;
	Enode* start;
}Index;

typedef struct IndexList {
	Index* list;
	Enode* head;
}IndexList;

//�ֿ����
IndexList* InitIndexList()
{
	IndexList* L = new IndexList;
	L->list = new Index[MAX];
	for (int i = 0; i < NUM; i++)
	{
		L->list[i].start = new Enode;
		L->list[i].start->next = NULL;
	}
	L->head = L->list[0].start;
	for (int i = 0; i < NUM-1; i++)
	{
		L->list[i].start->next = L->list[i+1].start;
	}
	return L;
} 

void CreateIndexList(IndexList* L)
{

	for (int i = 0; i < NUM; i++)
	{
		cout << "������ؼ���:" << endl;
		cin >> L->list[i].key;
		L->list[i].start->data = 101;
	}
	for (int i = 0; i < E; i++)
	{
		Enode* node = new Enode;
		cout << "������Ԫ��ֵ(5��):" << endl;
		cin >> node->data;
		node->next = NULL;
		int j = 0;
		while (j<NUM && node->data > L->list[j].key)
			j++;
		node->next = L->list[j].start->next;
		L->list[j].start->next = node;
		L->list[j].start->data++;
	}
}

int  BlockSearch(IndexList* L)
{
	int ret = 0;
	cin >> ret;
	int i = 0;
	for (i = 0; i < NUM; i++)
	{
		if (ret > L->list[i].key)
			continue;
		else
			break;
	}
	Enode* p = L->list[i].start;
	for (int j = 0; j <= (L->list[i].start->data - 101); j++)
	{
		if (ret == p->data)
		{
			cout << "��" << i + 1 << "���ֿ�:(����->" << (L->list[i].start->data - 101) << ")" << endl;
			cout << "���ֵΪ(" << L->list[i].key << ")" << endl;
			cout << "λ�ڸ÷ֿ��" << j << "��" << "Ԫ��" << endl;
			return 1;
		}
		else
		{
			p=p->next;
			continue;
		}
	}
	return -1;
}

int BlockAdd(IndexList* L, elementType data)
{
	Enode* node = new Enode;
	node->data = data;
	node->next = NULL;
	for (int i = 0; i < NUM; i++)
	{
		if (data > L->list[i].key)
			continue;
		else
		{
			node->next = L->list[i].start->next;
			L->list[i].start->next = node;
			L->list[i].start->data++;
			return 1;
		}
	}
	return -1;
}

int BlockDelete(IndexList* L, elementType data)
{
	int i = 0;
	for (i = 0; i < NUM; i++)
	{
		if (data > L->list[i].key)
			continue;
		else
			break;
	}
	Enode* p = L->list[i].start;
	for (int j = 0; j <= (L->list[i].start->data - 101); j++)
	{
		if (data == p->next->data)
		{
			Enode* temp = p->next->next;
			delete(p->next);
			p->next = temp;
			L->list[i].start->data--;
			return 1;
		}
		else
		{
			p = p->next;
			continue;
		}
	}
	return -1;
}

void Print(IndexList* L)
{
	cout << "������" << endl;
	for (int i = 0; i < NUM; i++)
	{
		cout << L->list[i].key << " ";
	}
	cout << endl;
	cout << "��������ָ�ֿ�ĸ���:" << endl;
	for (int i = 0; i < NUM; i++)
	{
		cout << L->list[i].start->data-101 << " ";
	}
	cout << endl;
	cout << "Ԫ�ر�";
	Enode* p = L->head;
	for (int i = 0; i < E+NUM; i++)
	{
		if (p->data > 100)
		{
			cout << endl;
			cout << "�ֿ����:";
			cout << (p->data - 101) << " ";
		}
		else
		{
			cout << p->data << " ";
		}
		p = p->next;
	}
	cout << endl;
}

int main()
{
	IndexList* L = InitIndexList();
	CreateIndexList(L);
	Print(L);
	BlockSearch(L);
	BlockAdd(L, 85);
	BlockDelete(L, 66);
	Print(L);
	return 0;
}