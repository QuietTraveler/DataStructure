//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#include<stdlib.h>
//#define RED 0//红色结点
//#define BLACK 1//黑色结点
//
//typedef struct RBTreeNode {
//	int data;
//	int color;
//	struct RBTreeNode* l;
//	struct RBTreeNode* r;
//	struct RBTreeNode* parent;
//}Node, * RBTree;
//
//
//
//Node* creatRoot(int key)
//{
//	Node* root = (Node*) malloc(sizeof(Node));
//	root->data = key;
//	root->color = BLACK;
//	root->parent = root->l = root->r = NULL;
//	return root;
//}
//Node* craetNode(int key, Node* parent, Node* left, Node* right)
//{
//	Node* n = (Node*) malloc(sizeof(Node));
//	n->data = key;
//	n->color = RED;
//	n->parent = parent;
//	n->l = left;
//	n->r = right;
//	return n;
//}
////以 红黑树的 x结点为中心左旋
//void left_rotate(RBTree* root, Node* x)
//{
//	//y指向x的右孩子 
//	Node* y = x->r;
//	//将y的左孩子变成x的右孩子,
//	x->r = y->l;
//	//如果y->l非空，x变成y->l的父亲 
//	if ( y->l != NULL )
//	{
//		y->l->parent = x;
//	}
//
//	//处理y和x-》parent的关系	
//	y->parent = x->parent;
//	if ( x->parent == NULL )
//	{
//		( *root ) = y;
//	}
//	else {
//		if ( x == x->parent->l )
//		{
//			x->parent->l = y;
//		}
//		else {
//			x->parent->r = y;
//		}
//
//	}
//	y->l = x;
//	x->parent = y;
//
//}
////以 红黑树的 x结点为中心右旋
//void right_rotate(RBTree* root, Node* x)
//{
//	//y指向x的左孩子 
//	Node* y = x->l;
//	//将y的右孩子变成x的左孩子,
//	x->l = y->r;
//	//如果y->r非空，x变成y->r的父亲 
//	if ( y->r != NULL )
//	{
//		y->r->parent = x;
//	}
//
//	//处理y和x-》parent的关系	
//	y->parent = x->parent;
//	if ( x->parent == NULL )
//	{
//		( *root ) = y;
//	}
//	else {
//		if ( x == x->parent->l )
//		{
//			x->parent->l = y;
//		}
//		else {
//			x->parent->r = y;
//		}
//
//	}
//	y->r = x;
//	x->parent = y;
//
//}
//
//void fixup(RBTree* root, Node* node)
//{
//	Node* parent;
//	Node* gparent;//爷爷
//	Node* uncle;
//	parent = node->parent;
//	while ( parent != NULL && parent->color == RED )
//	{//父亲红，爷爷黑色
//
//		gparent = parent->parent;
//		//父亲结点是爷爷结点的右孩子（RR/RL）
//		if ( parent == gparent->r )
//		{
//			uncle = gparent->l;
//			//1.叔叔是红色
//			if ( uncle != NULL && uncle->color == RED )
//			{
//				uncle->color = BLACK;
//				parent->color = BLACK;
//				gparent->color = RED;
//				node = gparent;
//				parent = node->parent;
//				continue;
//			}
//			//叔叔是黑色的->RR,RL
//			else {
//				if ( node == parent->l )
//				{
//					//RL
//					right_rotate(root, parent);
//					Node* t;
//					t = node;
//					node = parent;
//					parent = t;
//				}
//				//RR;
//				parent->color = BLACK;
//				gparent->color = RED;
//				left_rotate(root, gparent);
//			}
//		}
//	   //父亲结点是爷爷结点的左孩子（LL/LR）
//		if ( parent == gparent->l )
//		{
//			uncle = gparent->r;
//			//1.叔叔是红色
//			if ( uncle != NULL && uncle->color == RED )
//			{
//				uncle->color = BLACK;
//				parent->color = BLACK;
//				gparent->color = RED;
//				node = gparent;
//				parent = node->parent;
//				continue;
//			}
//			//叔叔是黑色的->LR,LL
//			else {
//				if ( node == parent->r )
//				{
//					//LR
//					left_rotate(root, parent);
//					Node* t;
//					t = node;
//					node = parent;
//					parent = t;
//				}
//				//LL;
//				parent->color = BLACK;
//				gparent->color = RED;
//				right_rotate(root, gparent);
//			}
//		}
//
//	}
//	//重新给根节点变黑色 
//	( *root )->color = BLACK;
//
//}
//
//
//void insert(RBTree* root, int key)
//{
//	//判断树是否为空
//	if ( ( *root ) == NULL )
//	{
//		( *root ) = creatRoot(key);
//
//		return;
//	}
//
//	Node* x = ( *root );//遍历找key插入的位置 
//	Node* xp = NULL;//x的父亲 
//	//根据BST找插入的位置
//	while ( x != NULL )
//	{
//		xp = x;
//		if ( key < x->data )
//		{
//			x = x->l;
//		}
//		else {
//			x = x->r;
//		}
//	}
//	Node* n = craetNode(key, xp, NULL, NULL);
//
//	if ( key < xp->data )
//	{
//		xp->l = n;
//	}
//	else {
//		xp->r = n;
//	}
//	fixup(root, n);
//
//}
//
////中序遍历输出 
//void inorder(Node* tree)
//{
//
//	if ( tree != NULL )
//	{
//		inorder(tree->l);
//
//		printf("%d %d ", tree->data, tree->color);
//		if ( tree->parent != NULL )
//		{
//			printf("%d\n", tree->parent->data);
//		}
//		else {
//			printf("-1\n");
//		}
//		inorder(tree->r);
//	}
//}
//
//void rbTreePrint(RBTree root)
//{
//	if ( !root )
//		return;
//	rbTreePrint(root->l);
//	cout << root->data << " ";
//	if ( root->color == RED )
//		cout << "红色" << endl;
//	else
//		cout << "黑色" << endl;
//
//	rbTreePrint(root->r);
//
//	return;
//}
//
//
//int main()
//{
//	//int a[9] = { 10,40,30,60,90,70,20,50,80 };
//	int a[9] = { 1,2,3,4,5,6,7,8,9 };
//	RBTree root = (Node*) malloc(sizeof(Node));
//	root = NULL;
//	for ( int i = 0; i < 9; i++ )
//	{
//		insert(&root, a[i]);
//
//	}
//
//	rbTreePrint(root);
//
//	//inorder(root);
//	//printf("\n");
//	///BUG1: root：属于值传递。main中root没有跟着函数中的root变化---改为地址传参数 
//
//	/// 107行，得先判断parent！=NULL，不然找不到parent->color 	
//
//
//	return 0;
//}
//
