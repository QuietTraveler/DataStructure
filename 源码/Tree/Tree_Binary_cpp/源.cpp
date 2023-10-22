#include"Queue.h"

typedef struct BTree {
	int count=0; 
	BTNode* root=NULL;
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

BTNode* Find(BTNode* root,TYPE parent)
{
	if (!root || root->data == parent)
		return root;
	BTNode* node = NULL;
		node=Find(root->left, parent);
		if (node)
			return node;
		node = Find(root->right, parent);
		return node;
}

void Insert(BTree* tree, bool flag,int parent_key,int key)
{
	BTNode* node = CreateNode(key);
	BTNode* parent = Find(tree->root,parent_key);
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
	if(node)
	cout << node->data << endl;
}

void F_OrderBTree(BTNode* root)
{
	if (!root)
		return;
	Visited(root);
	F_OrderBTree(root->left);
	F_OrderBTree(root->right);
	return;
}

void E_OrderBTree(BTNode* root)
{
		if (!root)
		return;
	E_OrderBTree(root->left);
	E_OrderBTree(root->right);
	Visited(root);
	return;
}

void M_OrderBTree(BTNode* root)
{
if (!root)
		return;
	M_OrderBTree(root->left);
	Visited(root);
	M_OrderBTree(root->right);
	return;
}

void L_OrderBTree(BTNode* root)
{
	Queue* q = InitQueue();
	PushQueue(q, root);
	while (!EmptyQueue(q))
	{
		Qtype data = PopQueue(q);
		Visited(data);
		if(data->left)
		PushQueue(q,data->left);
		if(data->right)
		PushQueue(q,data->right);
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
	//E_OrderBTree(tree->root);
	L_OrderBTree(tree->root);
	return 0;
}