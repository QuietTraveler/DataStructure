#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<cstdlib>
#include<cstring>
#define Init 5
using namespace std;
typedef int SListType;
typedef struct SList {
	int size;
	int capacity;
	SListType* val;
}SList;

//初始化顺序表
SList InitSList()
{
	SList list;
	list.capacity = Init;
	list.size = 0;
	list.val = new SListType[Init];
	if (list.val == NULL)
	{
		perror("new");
		exit(-1);
	}
	return list;
}

//扩容
int Dilatation(SList& slist)
{
	slist.capacity *= 2;
	slist.val = (SListType*)realloc(slist.val, sizeof(SListType) * (slist.capacity));
	if (slist.val == NULL)
	{
		perror("realloc");
		return -1;
	}
	return 1;
}

//查
int SListFind(SList slist, SListType data)
{
	for (int i = 0; i < slist.size; i++)
	{
		if (slist.val[i] == data)
			return i;
	}
	return -1;
}

//增
int SListAdd(SList& slist, SListType data)
{
	if (slist.capacity == slist.size)
	{
		if (!Dilatation(slist))
		{
			return -1;
		}
	}
	slist.val[slist.size] = data;
	slist.size++;
	return 1;
}

//销毁
int SListDestroy(SList& slist)
{
	if (slist.size == 0)
	return -1;
	free(slist.val);
	slist.capacity = slist.size = 0;
	return 1;
}

//删
int SListDelete(SList& slist, SListType data)
{
	int index = SListFind(slist, data);
	if (index == -1 || slist.size == 0)
		return -1;
	for (int i = index; i < slist.size - 1; i++)
	{
		slist.val[i] = slist.val[i + 1];
	}
	slist.size--;
	return 1;
}

//改
int SListAmend(SList& slist, SListType original, SListType later)
{
	int index = SListFind(slist, original);
	if (index == -1)
		return -1;
	slist.val[index] = later;
	return 1;
}

//插入
int SListInsert(SList& slist, SListType data, SListType indata)
{
	if (slist.capacity == slist.size)
	{
		if (!Dilatation(slist))
		{
			return -1;
		}
	}
	int index = SListFind(slist, data);
	for (int i = slist.size; i > index; i--)
	{
		slist.val[i] = slist.val[i - 1];
	}
	slist.val[index] = indata;
	slist.size++;
	return 1;
}

//打印顺序表
void SListPrint(SList slist)
{
	for (int i = 0; i < slist.size; i++)
	{
		cout << slist.val[i] << endl;
	}
}

int main()
{
	SList slist = InitSList();
	SListAdd(slist, 1);
	SListAdd(slist, 2);
	SListAdd(slist, 3);
	SListAdd(slist, 4);
	SListAdd(slist, 5);
	SListInsert(slist, 3, 8);
	SListDelete(slist, 4);
	SListAmend(slist, 2, 0);
	SListPrint(slist);
}