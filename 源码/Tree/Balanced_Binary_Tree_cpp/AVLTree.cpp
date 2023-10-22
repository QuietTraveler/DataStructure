#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef int keytype;
typedef struct AVL {
	int height;
	struct AVL* right;
	struct AVL* left;
	keytype data;
}Node,*Root;

int GetHeight(Node* node)
{
	return node ? node->height : 0;
}

Node* CreateNode(keytype data)
{
	Node* node = new Node;
	node->height = 0;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node* Left_Left(Node* node)
{
	Node* k = node->left;
	node->left = k->right;
	k->right = node;
	node->height = MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
	k->height = MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
	return k;
}

Node* Right_Right(Node* node)
{
	Node* k = node->right;
	node->right = k->left;
	k->left = node;
	node->height = MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
	k->height = MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
	return k;
}

Node* Left_Right(Node* node)
{
	node->left = Right_Right(node->left);
	node = Left_Left(node);
	return node;
}

Node* Right_Left(Node* node)
{
	node->right = Left_Left(node->right);
	node = Right_Right(node);
	return node;
}

Node* AVLInsert(Root node,keytype data)
{
	if (!node)
	{
		node = CreateNode(data);
	}
	else if (node->data > data)
	{
		node->left = AVLInsert(node->left, data);
		if (GetHeight(node->left) - GetHeight(node->right) == 2)
		{
			if (node->left->data > data)
				node = Left_Left(node);
			else
				node = Left_Right(node);
		}
	}
	else if (node->data < data)
	{
		node->right = AVLInsert(node->right, data);
		if (GetHeight(node->right) - GetHeight(node->left) == 2)
		{
			if (node->right->data < data)
				node = Right_Right(node);
			else
				node = Right_Left(node);
		}
	}
	else
		cout << "该元素已存在" << endl;
	node->height = MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
	return node;
}

bool Search(Node* node,keytype data)
{
	if (node == NULL)
		return false;
	if (node->data > data)
		return Search(node->left, data);
	else if (node->data < data)
		return Search(node->right, data);
	else
		return true;
}

Node* MinNum(Node* node)
{
	if (!node)
		return NULL;
	while (node->right)
		node = node->right;
	return node;
}

void in_order(Node* node)
{
	if (!node)
		return;
	in_order(node->left);
	cout << node->data << " ";
	in_order(node->right);
}

Node* AVLDelete(Node* node,keytype data)
{
	if (!Search(node, data))
		return NULL;
	if (node->data > data)
	{
		node->left = AVLDelete(node->left, data);
		if (GetHeight(node->right) - GetHeight(node->left) == 2)
		{
			Node* temp = node->right;
			if (GetHeight(temp->right) - GetHeight(temp->left)>0)
				node = Right_Right(node);
			else
				node = Right_Left(node);
		}
	}
	else if (node->data < data)
	{
		node->right = AVLDelete(node->right, data);
		if (GetHeight(node->left) - GetHeight(node->right) == 2)
		{
			Node* temp = node->left;
			if (GetHeight(temp->left) - GetHeight(temp->right)>0)
				node = Left_Left(node);
			else
				node = Left_Right(node);
		}
	}
	else
	{
		if (node->right && node->left)
		{
			Node* min = MinNum(node->left);
			node->data = min->data;
			node->left = AVLDelete(node->left, min->data);
		}
		else
		{
			Node* temp = node;
			node = node->left ? node->left : node->right;
			delete(temp);
		}
	}
	if(node)
		node->height= MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
	return node;
}

int main()
{
	Node* tree1 = NULL;
	int a1[] = { 13, 8, 15, 3, 10 };
	int l1 = sizeof(a1) / sizeof(int);
	for (int i = 0; i < l1; i++)
	{
		tree1 = AVLInsert(tree1, a1[i]);
	}
	printf("第一种情况-左孩子的左子树\n");
	printf("中序遍历:");
	in_order(tree1);
	printf("\n");
	printf("根结点为%d,深度为:%d\n\n", tree1->data, tree1->height);

	printf("插入1\n");
	tree1 = AVLInsert(tree1, 1);
	printf("中序遍历:");
	in_order(tree1);
	printf("\n");
	printf("根结点为%d,深度为:%d\n\n", tree1->data, tree1->height);

	printf("删除结点8\n");
	tree1 = AVLDelete(tree1, 8);
	printf("中序遍历:");
	in_order(tree1);
	printf("\n");
	printf("根结点为%d,深度为:%d\n\n", tree1->data, tree1->height);

	printf("删除结点13\n");
	tree1 = AVLDelete(tree1, 13);
	printf("中序遍历:");
	in_order(tree1);
	printf("\n");
	printf("根结点为%d,深度为:%d\n\n", tree1->data,tree1->height);

	printf("删除结点1\n");
	tree1 = AVLDelete(tree1, 1);
	printf("中序遍历:");
	in_order(tree1);
	printf("\n");
	printf("根结点为%d,深度为:%d\n\n",tree1->data, tree1->height);
	//第二种情况-右孩子的右子树
	Node* tree2 = NULL;
	int a2[] = { 13, 8, 15, 14, 16 };
	int l2 = sizeof(a2) / sizeof(int);
	for (int i = 0; i < l2; i++)
	{
		tree2 = AVLInsert(tree2, a2[i]);
	}
	printf("第二种情况-右孩子的右子树\n");
	printf("中序遍历:");
	in_order(tree2);
	printf("\n");
	printf("根结点的深度为:%d\n\n", tree2->height);

	tree2 = AVLInsert(tree2, 20);
	printf("插入20\n");
	printf("中序遍历:");
	in_order(tree2);
	printf("\n");
	printf("根结点的深度为:%d\n\n", tree2->height);

	//第三种情况-左孩子的右子树
	Node* tree3 = NULL;
	int a3[] = { 13, 8, 15, 3, 10 };
	int l3 = sizeof(a3) / sizeof(int);
	for (int i = 0; i < l3; i++)
	{
		tree3 = AVLInsert(tree3, a3[i]);
	}
	printf("第三种情况-左孩子的右子树\n");
	printf("中序遍历:");
	in_order(tree3);
	printf("\n");
	printf("根结点的深度为:%d\n\n", tree3->height);

	tree3 = AVLInsert(tree3, 9);
	printf("插入9\n");
	printf("中序遍历:");
	in_order(tree3);
	printf("\n");
	printf("根结点的深度为:%d\n\n", tree3->height);


	//第四种情况 - 右孩子的左子树
	Node* tree4 = NULL;
	int a4[] = { 13, 8, 18, 15, 20 };
	int l4 = sizeof(a4) / sizeof(int);
	for (int i = 0; i < l4; i++)
	{
		tree4 = AVLInsert(tree4, a4[i]);
	}
	printf("第四种情况-右孩子的左子树\n");
	printf("中序遍历:");
	in_order(tree4);
	printf("\n");
	printf("根结点的深度为:%d\n\n", tree4->height);

	tree4 = AVLInsert(tree4, 14);
	printf("插入14\n");
	printf("中序遍历:");
	in_order(tree4);
	printf("\n");
	printf("根结点的深度为:%d\n\n", tree4->height);
	return 0;
}