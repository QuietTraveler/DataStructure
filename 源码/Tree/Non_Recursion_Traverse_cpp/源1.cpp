#define _CRT_SECURE_NO_WARNINGS  1
#include"stack.h"

typedef struct BTree {
	int count = 0;
	BTNode* root = NULL;
}BTree;

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

void Visited(BTNode* node)
{
	if (node)
		cout << node->data << endl;
}

//非递归先序
void F_OrderBTree(BTNode* root)
{
	if (!root)
		return;
	Stack* s = Init();
	Push(s, root);
	BTNode* node = NULL;
	while (!Empty(s))
	{
		node = Top(s);
		Visited(node);
		Pop(s);
		if (node->right)
			Push(s, node->right);
		if (node->left)
			Push(s, node->left);
	}
	Destroy(s);
}

//非递归后序
void E_OrderBTree1(BTNode* root)
{
	if (!root)
		return;
	Stack* s1 = Init();
	Stack* s2 = Init();
	BTNode* node = NULL;
	Push(s1, root);
	while (!Empty(s1))
	{
		node=Top(s1);
		Pop(s1);
		Push(s2, node);
		if (node->left)
			Push(s1, node->left);
		if (node->right)
			Push(s1, node->right);
	}
	Stack* k = s2->next;
	while (k)
	{
		cout << k->data->data << endl;
		k = k->next;
	}
}

//非递归后序
void E_OrderBTree2(BTNode* root)
{
	if (!root)
		return;
	Stack* s = Init();
	BTNode* node = root;
	BTNode* prev = NULL;
	while (!Empty(s) || node)
	{
		if (node != NULL)
		{
			Push(s, node);
			node = node->left;
		}
		else
		{
			node = Top(s);
			if (node->right && prev == node->left)
			{
				node = node->right;
			}
			else
			{
				Pop(s);
				Visited(node);
				prev = node;
				node = NULL;
			}
		}
	}
}

//非递归中序
void M_OrderBTree(BTNode* root)
{
	if (!root)
		return;
	Stack* s = Init();
	BTNode* node = root;
	while (!Empty(s) || node)
	{
		if (node != NULL)
		{
			Push(s, node);
			node = node->left;
		}
		else
		{
			node=Top(s);
			Pop(s);
			Visited(node);
			node = node->right;
		}
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
	//F_OrderBTree(tree->root);
	//M_OrderBTree(tree->root);
	//E_OrderBTree1(tree->root);
	E_OrderBTree2(tree->root);
	//L_OrderBTree(tree->root);

	return 0;
}