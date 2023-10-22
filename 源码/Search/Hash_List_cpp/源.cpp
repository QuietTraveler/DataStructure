#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
typedef struct HashNode {
	int data;
	struct HashNode* next;
}HashNode;

typedef struct HashList {
	HashNode* List;
	int size;
}HashList;

HashList* Init_HashList(void)
{
	HashList* node = new HashList;
	node->size = 10;
	node->List = new HashNode[node->size+1];
	for (int i = 0; i < node->size+1; i++)
	{
		node->List[i].data = 0;
		node->List[i].next = NULL;
	}
	return node;
}

void Create_HashList(HashList* list, int* data)
{
	int index = 0;
	for (int i = 0; i < list->size; i++)
	{
		index = data[i] % (list->size+1);
		HashNode* node = new HashNode;
		node->data = data[i];
		node->next = list->List[index].next;
		list->List[index].next = node;
		list->List[index].data++;
	}
}

int Search_HashList(HashList* list, int data)
{
	int index = data % (list->size + 1);
	for (int i = 0; i < list->List[index].data; i++)
	{
		HashNode* node = list->List[index].next;
		if (node->data == data)
			return true;
		node = node->next;
	}
	return false;
}

void Delete_HashList(HashList* list, int data)
{
	int index = data % (list->size + 1);
	HashNode* prev = list->List[index].next;
	HashNode* node = prev;
	for (int i = 0; i < list->List[index].data; i++)
	{
		if (node->data == data)
		{
			if(prev == node)
			{
				list->List[index].next = node->next;
				delete(node);
			}
			else
			{
				prev->next = node->next;
				delete(node);
			}
			list->List[index].data--;
			break;
		}
		prev = node;
		node = node->next;
	}
}

void Print_HashList(HashList* list)
{
	for (int i = 0; i < list->size+1; i++)
	{
		if (list->List[i].data)
		{
			cout << "下标为" << i << "的元素有:";
			HashNode* node = list->List[i].next;
			while (node)
			{
			cout << node->data <<" ";
			node = node->next;
			}
			cout << endl;
		}
	}
}

void Destroy_HashList(HashList* list)
{
	for (int i = 0; i < list->size + 1; i++)
	{
		if (list->List[i].data)
		{
			HashNode* cur = list->List[i].next;
			HashNode* temp = cur;
            do
			{
				temp = temp->next;
				delete(cur);
				cur = temp;
			} while (cur);
		}
	}
	delete(list);
}

int main()
{
	int arr[10] = { 45,63,21,57,98,104,765,34,1,7 };
	HashList* list = Init_HashList();
	Create_HashList(list, arr);
	Print_HashList(list);
	cout << endl;
	Delete_HashList(list, 57);
	Print_HashList(list);
	cout << endl;
	Delete_HashList(list, 21);
	Print_HashList(list);
	Destroy_HashList(list);
	return 0;
}