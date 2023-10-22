//#define _CRT_SECURE_NO_WARNINGS  1
//#include<iostream>
//#include<cstdlib>
//#include<cstring>
//#include<stdio.h>
//#define MAX(a,b) ((a>b)?(a):(b))
//
////平衡二叉树
//using namespace std;
//typedef int AVLtype;
//
//typedef struct AVL {
//	int height;
//	AVLtype data;
//	struct AVL* left;
//	struct AVL* right;
//}Node,*Root;
//
//int GetHeight(Root node)
//{
//	return node ? node->height : 0;
//}
//
//Node* CreateNode(AVLtype data)
//{
//	Node* node = new Node;
//	node->data = data;
//	node->height = 0;
//	node->left = node->right = NULL;
//	return node;
//}
//
//Node* Left_Left(Node* node)
//{
//	Node* k = node->left;
//	node->left = k->right;
//	k->right = node;
//	node->height= MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
////	k->height = MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
//	return k;
//}
//
//Node* Right_Right(Node* node)
//{
//	Node* k = node->right;
//	node->right = k->left;
//	k->left = node;
//	node->height= MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
////	k->height = MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
//	return k;
//}
//
//Node* Left_Right(Node* node)
//{
//	node->left = Right_Right(node->left);
//	node = Left_Left(node);
//	return node;
//}
//
//Node* Right_Left(Node* node)
//{
//	node->right = Left_Left(node->right);
//	node = Right_Right(node);
//	return node;
//}
//
//Node* AVLInsert(Root node,AVLtype data)
//{
//	if (node == NULL)
//	{
//		node=CreateNode(data);
//	}
//	else if (node->data > data)
//	{
//		node->left = AVLInsert(node->left, data);
//		if (GetHeight(node->left) - GetHeight(node->right) == 2)
//		{
//			if (node->left->data > data)
//				node = Left_Left(node);
//			else
//				node = Left_Right(node);
//		}
//	}
//	else if (node->data < data)
//	{
//		node->right = AVLInsert(node->right, data);
//		if (GetHeight(node->right) - GetHeight(node->left) == 2)
//		{
//			if (node->right->data < data)
//				node = Right_Right(node);
//			else
//				node = Right_Left(node);
//		}
//	}
//	else
//		cout << "该值已存在" << endl;
//	node->height = MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
//	return node;
//}
//
//bool Search(Node* node,AVLtype data)
//{
//	if (node == NULL || node->data == data)
//	{
//		return node!=NULL;
//	}
//	if (node->data > data)
//	{
//		return Search(node->left, data);
//	}
//	else
//	{
//		return Search(node->right, data);
//	}
//}
//
//Node* MinNum(Node* node)
//{
//	if (node == NULL)
//		return node;
//	while (node->left)
//		node = node->left;
//	return node;
//}
//
//Node* AVLDelete(Node* node, AVLtype data)
//{
//	if (!Search(node, data))
//	{
//		cout << "不存在该元素" << endl;
//		return NULL;
//	}
//	if (data < node->data)
//	{
//		node->left = AVLDelete(node->left, data);
//		if (GetHeight(node->right) - GetHeight(node->left) == 2)
//		{
//			if (node->right->data > data)
//			{
//				node = Right_Left(node);
//			}
//			else
//			{
//				node = Right_Right(node);
//			}
//		}
//	}
//	else if (data > node->data)
//	{
//		node->right = AVLDelete(node->right, data);
//		if(GetHeight(node->left) - GetHeight(node->right) == 2)
//		{
//			if (node->left->data > data)
//			{
//				node = Left_Left(node);
//			}
//			else
//			{
//				node = Left_Right(node);
//			}
//		}
//	}
//	else if (node->left && node->right)
//	{
//		Node* k = MinNum(node->right);
//		node->data = k->data;
//		node->right=AVLDelete(node->right, k->data);
//	}
//	else
//	{
//		Node* temp = node;
//		node = node->right ? node->right : node->left;
//		delete(temp);
//	}
//	if(node)
//	node->height = MAX(GetHeight(node->right), GetHeight(node->left)) + 1;
//	return node;
//}
//
//void in_order(Root node)
//{
//	if (node == NULL)
//		return;
//	in_order(node->left);
//	cout << node->data << " ";
//	in_order(node->right);
//}
//
//int main()
//{
//	Node* tree1 = NULL;
//	int a1[] = {3,2,15,1};
//	int l1 = sizeof(a1) / sizeof(int);
//	for (int i = 0; i < l1; i++)
//	{
//		tree1 = AVLInsert(tree1, a1[i]);
//	}
//	printf("第一种情况-左孩子的左子树\n");
//	printf("中序遍历:");
//	in_order(tree1);
//	printf("\n");
//	printf("根结点为%d,深度为:%d\n\n", tree1->data, tree1->height);
//
//	//printf("插入1\n");
//	//tree1 = AVLInsert(tree1, 1);
//	//printf("中序遍历:");
//	//in_order(tree1);
//	//printf("\n");
//	//printf("根结点为%d,深度为:%d\n\n", tree1->data, tree1->height);
//
//	//printf("删除结点8\n");
//	//tree1 = AVLDelete(tree1, 8);
//	//printf("中序遍历:");
//	//in_order(tree1);
//	//printf("\n");
//	//printf("根结点为%d,深度为:%d\n\n", tree1->data, tree1->height);
//
//	//printf("删除结点13\n");
//	//tree1 = AVLDelete(tree1, 13);
//	//printf("中序遍历:");
//	//in_order(tree1);
//	//printf("\n");
//	//printf("根结点为%d,深度为:%d\n\n", tree1->data, tree1->height);
//
//	printf("删除结点15\n");
//	tree1 = AVLDelete(tree1, 15);
//	printf("中序遍历:");
//	in_order(tree1);
//	printf("\n");
//	printf("根结点为%d,深度为:%d\n\n", tree1->data, tree1->height);
//	//第二种情况-右孩子的右子树
//	Node* tree2 = NULL;
//	int a2[] = { 13, 8, 15, 14, 16 };
//	int l2 = sizeof(a2) / sizeof(int);
//	for (int i = 0; i < l2; i++)
//	{
//		tree2 = AVLInsert(tree2, a2[i]);
//	}
//	printf("第二种情况-右孩子的右子树\n");
//	printf("中序遍历:");
//	in_order(tree2);
//	printf("\n");
//	printf("根结点的深度为:%d\n\n", tree2->height);
//
//	tree2 = AVLInsert(tree2, 20);
//	printf("插入20\n");
//	printf("中序遍历:");
//	in_order(tree2);
//	printf("\n");
//	printf("根结点的深度为:%d\n\n", tree2->height);
//
//	//第三种情况-左孩子的右子树
//	Node* tree3 = NULL;
//	int a3[] = { 13, 8, 15, 3, 10 };
//	int l3 = sizeof(a3) / sizeof(int);
//	for (int i = 0; i < l3; i++)
//	{
//		tree3 = AVLInsert(tree3, a3[i]);
//	}
//	printf("第三种情况-左孩子的右子树\n");
//	printf("中序遍历:");
//	in_order(tree3);
//	printf("\n");
//	printf("根结点的深度为:%d\n\n", tree3->height);
//
//	tree3 = AVLInsert(tree3, 9);
//	printf("插入9\n");
//	printf("中序遍历:");
//	in_order(tree3);
//	printf("\n");
//	printf("根结点的深度为:%d\n\n", tree3->height);
//
//
//	//第四种情况 - 右孩子的左子树
//	Node* tree4 = NULL;
//	int a4[] = { 13, 8, 18, 15, 20 };
//	int l4 = sizeof(a4) / sizeof(int);
//	for (int i = 0; i < l4; i++)
//	{
//		tree4 = AVLInsert(tree4, a4[i]);
//	}
//	printf("第四种情况-右孩子的左子树\n");
//	printf("中序遍历:");
//	in_order(tree4);
//	printf("\n");
//	printf("根结点的深度为:%d\n\n", tree4->height);
//
//	tree4 = AVLInsert(tree4, 14);
//	printf("插入14\n");
//	printf("中序遍历:");
//	in_order(tree4);
//	printf("\n");
//	printf("根结点的深度为:%d\n\n", tree4->height); 
//	return 0;
//}