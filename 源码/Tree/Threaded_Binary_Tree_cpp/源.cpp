#define _CRT_SECURE_NO_WARNINGS  1
#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef int TYPE;

typedef struct BTNode {
	TYPE data;
	struct BTNode* left = NULL;
	struct BTNode* right = NULL;
	bool lflag = 0;
	bool rflag = 0;
}BTNode;

typedef struct BTree {
	int count = 0;
	BTNode* root = NULL;
}BTree;

BTNode* tprev = NULL;  //保存前结点

BTree* CreateBTree(BTNode* root)
{
	BTree* tree = new BTree;
	if (root)
	{
		tree->count = 1;
		tree->root = root;
	}
	return tree;
}

BTNode* CreateNode(TYPE key)
{
	BTNode* node = new BTNode;
	node->data = key;
	return node;
}

BTNode* Find(BTNode* root, TYPE parent)
{
	if (!root || root->data == parent)
		return root;
	BTNode* node = NULL;
	node = Find(root->left, parent);
	if (node)
		return node;
	node = Find(root->right, parent);
	return node;
}

void Insert(BTree* tree, bool flag, int parent_key, int key)
{
	BTNode* node = CreateNode(key);
	BTNode* parent = Find(tree->root, parent_key);
	if (!parent)
		return;
	if (flag)
		parent->left = node;
	else
		parent->right = node;
	tree->count++;
}

//记录线索
void Visited(BTNode* node)
{
		if (node->left == NULL)
		{
			node->left = tprev;
			node->lflag = 1;
		}

		if (tprev && tprev->right == NULL)
		{
			tprev->right = node;
			tprev->rflag = 1;
		}
		tprev = node;
		cout << node->data << endl;
}

void F_OrderBTree(BTNode* root)
{
	if (!root)
		return;
	Visited(root);
	if(root->lflag == 0)
	F_OrderBTree(root->left);
	if (root->rflag == 0)
	F_OrderBTree(root->right);
	return;
}


void E_OrderBTree(BTNode* root)
{
	if (!root)
		return;
	if(root->lflag==0)
	E_OrderBTree(root->left);
	if (root->rflag == 0)
	E_OrderBTree(root->right);
	Visited(root);
	return;
}

void M_OrderBTree(BTNode* root)
{
	if (!root)
		return;
	if(root->lflag == 0)
	M_OrderBTree(root->left);
	Visited(root);
	if (root->rflag == 0)
	M_OrderBTree(root->right);
	return;
}

void TreadBTree(BTNode* root)
{
	if (!root)
		return;
	M_OrderBTree(root);
	tprev->rflag = 1;
}

//找前驱和后继
void FindThread(BTNode* node)
{
	if (node)
	{
		BTNode* prev = node->left;
		BTNode* next = node->right;
		if (prev && !(node->lflag))
		{
			while (!(prev->rflag))
				prev = prev->right;
		}
		if(prev)
		cout << "前驱 " << prev->data << endl;

		if (next && !(node->rflag))
		{
			while (!(next->lflag))
				next = next->left;
		}
		if(next)
		cout << "后继 " << next->data << endl;
	}
}

int main()
{
	BTNode* root = CreateNode(2);
	BTree* tree = CreateBTree(root);
	Insert(tree, 1, 2, 4);
	Insert(tree, 0, 2, 5);
	Insert(tree, 1, 4, 11);
	Insert(tree, 0, 4, 12);
	Insert(tree, 1, 5, 15);
	Insert(tree, 0, 5, 66);
	Insert(tree, 1, 11, 7);
	Insert(tree, 0, 11, 16);
	Insert(tree, 1, 12, 77);
	TreadBTree(tree->root);
	FindThread(tree->root);
	return 0;
}