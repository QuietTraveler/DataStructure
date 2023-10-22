//#define _CRT_SECURE_NO_WARNINGS  1
//#include<stdio.h>
//#include<stdlib.h>
//
//#define HEIGHT(node) ((node == NULL)? 0 : (((avlnode*)(node))->height ))
//#define MAX(a,b) ((a > b) ? (a) : (b))
//typedef struct node {
//	int data;//存储结点的值
//	struct node* left;
//	struct node* right;
//	int height;//当前结点的深度
//}avlnode, * avltree;
//
//avlnode* creata_node(int key, avlnode* left, avlnode* right)
//{
//	avlnode* node = (avlnode*)malloc(sizeof(avlnode));
//	//判断一下是否创建成功
//	node->data = key;
//	node->left = left;
//	node->right = right;
//	node->height = 0;
//	return node;
//}
//
////获取长度
//int get_height(avlnode* node)
//{
//	return HEIGHT(node);
//}
///*左孩子的左子树*/
//avltree left_left_rotation(avltree tree)
//{//传入的tree为子树根节点，同时也是失衡结点 
//	//k就是我最终需
//	avlnode* k = tree->left;
//	tree->left = k->right;
//	k->right = tree;
//	//切记一点 所有旋转操作以后 需要调整树的高度 
//	//这里是深度 一颗子树的深度 从这个结点的左右子树来判断他的深度
//	tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	k->height = MAX(get_height(k->left), get_height(k->right)) + 1;
//	return k;//此时k为根节点 
//}
///*右孩子的右子树*/
//avltree right_right_rotation(avltree tree)
//{//传入的tree为子树根节点，同时也是失衡结点 
//	avlnode* k = tree->right;
//	tree->right = k->left;
//	k->left = tree;
//	//切记一点 所有旋转操作以后 需要调整树的高度
//	//这里是深度 一颗子树的深度 从这个结点的左右子树来判断他的深度
//	tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	k->height = MAX(get_height(k->left), get_height(k->right)) + 1;
//	return k;//此时k为根节点 
//
//}
///*左孩子得右子树的调整*/
//avltree left_right_rotation(avltree tree)
//{
//	tree->left = right_right_rotation(tree->left);
//	tree = left_left_rotation(tree);
//	return tree;
//}
//
///*右孩子的左子树的情况*/
//avltree right_left_rotation(avltree tree)
//{
//	tree->right = left_left_rotation(tree->right);
//	tree = right_right_rotation(tree);
//	return tree;
//}
//
//
//avltree avltree_insertNode(avltree tree, int key)
//{
//	if (tree == NULL)
//	{
//		avlnode* node = creata_node(key, NULL, NULL);
//		tree = node;
//	}
//	else if (key < tree->data)//往tree的左子树插入 
//	{
//		//递归寻找插入结点的位置
//		tree->left = avltree_insertNode(tree->left, key);
//		if (get_height(tree->left) - get_height(tree->right) == 2)
//		{
//			//在这里判断是LL还是LR
//			if (key < tree->left->data)
//			{
//				tree = left_left_rotation(tree);
//			}
//			else
//			{
//				//LR旋转
//				tree = left_right_rotation(tree);
//			}
//		}
//	}
//	else if (key > tree->data) //往tree的右子树插入 
//	{
//		tree->right = avltree_insertNode(tree->right, key);
//		if (get_height(tree->right) - get_height(tree->left) == 2)
//		{
//			//RR
//			if (key > tree->right->data)
//			{
//				tree = right_right_rotation(tree);
//			}
//			else
//			{
//				//RL
//				tree = right_left_rotation(tree);
//			}
//		}
//	}
//	else
//	{
//		//报错，不允许插入相同的值
//	}
//
//	//重新调整二叉树的深度
//	tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//
//	return tree;
//
//}
//
//avlnode* mininum_node(avltree tree)
//{
//	if (tree == NULL)
//	{
//		return NULL;
//	}
//	while (tree->left)
//	{
//		tree = tree->left;
//	}
//
//	return tree;
//}
//avltree avltree_deleteNode(avltree tree, int key)
//{
//
//	if (tree == NULL)
//	{
//		return tree;
//	}
//	if (key < tree->data)//要删除的是在左子树
//	{
//		//先递归找要删除的结点
//		tree->left = avltree_deleteNode(tree->left, key);
//		//删完以后 要检查平衡性
//		if (get_height(tree->right) - get_height(tree->left) == 2)
//		{
//			//要如何判断RL,RR;
//			avlnode* tmp = tree->right;
//			if (get_height(tmp->left) - get_height(tmp->right) > 0)
//			{//RL
//				tree = right_left_rotation(tree);
//
//			}
//			else
//			{//RR
//				tree = right_right_rotation(tree);
//			}
//		}
//
//	}
//	else if (key > tree->data)//要删除的在右子树
//	{
//		tree->right = avltree_deleteNode(tree->right, key);
//		//删完以后 要检查平衡性
//		if (get_height(tree->left) - get_height(tree->right) == 2)
//		{
//			//要如何判断LL,LR
//			avlnode* tmp = tree->left;
//			if (get_height(tmp->left) - get_height(tmp->right) > 0)
//			{//LL
//				tree = left_left_rotation(tree);
//			}
//			else
//			{//LR
//				tree = left_right_rotation(tree);
//			}
//		}
//	}
//	else //找到要删除的结点 先按照二叉排序树的方式进行删除
//	{
//		if (tree->left && tree->right)
//		{
//			avlnode* min_node = mininum_node(tree->right);
//			tree->data = min_node->data;
//			//删除 最小值结点
//			tree->right = avltree_deleteNode(tree->right, min_node->data);
//		}
//		else
//		{
//			//独子或者无子的情况结点
//			avlnode* node = tree;
//			tree = tree->left ? tree->left : tree->right;
//			if (tree == NULL)
//			{
//				free(tree);
//				return NULL;
//			}
//			else {
//				free(node);
//			}
//
//		}
//
//	}
//
//	//调整高度
//	if (tree)
//	{
//		tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	}
//
//
//	return tree;
//}
//
//
//void pre_order(avltree tree)
//{//中序遍历输出 
//	if (tree)
//	{
//
//		pre_order(tree->left);
//		printf("%d   ", tree->data);
//		pre_order(tree->right);
//	}
//}
//
//
//int main()
//{
//	avltree tree = NULL;
//	int a[] = { 3,2,15,1 };
//	//int length = sizeof(a) / sizeof(a[0]);
//	for (int i = 0; i < 4; i++)
//	{
//		tree = avltree_insertNode(tree, a[i]);
//	}
//
//	pre_order(tree);
//	printf("\n");
//	//	in_order(tree);
//	printf("\n");
//	tree = avltree_deleteNode(tree, 15);
//	pre_order(tree);
//	printf("\n");
//	//in_order(tree);
//
//}
