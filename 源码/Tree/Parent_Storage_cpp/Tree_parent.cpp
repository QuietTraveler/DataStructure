#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<cstdlib>
//树的双亲表示法
using namespace std;
#define MAX 15
typedef char Type;
typedef struct Node {
	Type val;
	int parent;
}Node;

typedef struct Tree {
	int size=0;
	int capacity=MAX;
	Node* data[MAX];
}Tree;

Tree* InitTree(Type root_val)
{
	Tree* tree = new Tree;
	Node* node = new Node;
	node->val = root_val;
	node->parent = -1;
	tree->data[tree->size++] = node;
	return tree;
}

int FindParent(Tree* root,int parent_val)
{
	for (int i = 0; i < root->size; i++)
	{
		if (root->data[i]->val == parent_val)
		{
			return i;
		}
	}
	return -1;
}

void InsertTree(Tree* root,Type val,int parent_val)
{
	if (root->size == MAX)
	{
		cout << "error_full" << endl;
		return;
	}
	int parent = FindParent(root,parent_val);
	if (parent!=-1)
	{
		Node* node = new Node;
		node->val = val;
		node->parent = parent;
		root->data[root->size++] = node;
	}
	else
	{
		cout << "error_no_val" << endl;
	}
}

void Print(Tree* root)
{
	for (int i = 0; i < root->size; i++)
	{
		cout << root->data[i]->val << "   " << root->data[i]->parent << endl;
	}
}

int main()
{
	Tree* root=InitTree('4');
	InsertTree(root, '3', '4');
	InsertTree(root, '5', '4');
	InsertTree(root, '6', '4');
	InsertTree(root, '1', '3');
	InsertTree(root, '2', '5');
	InsertTree(root, '7', '6');
	InsertTree(root, '9', '1');
	Print(root);
	return 0;
}