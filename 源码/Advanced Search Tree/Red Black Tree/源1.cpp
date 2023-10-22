//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#include<stdlib.h>
//#define RED 0//��ɫ���
//#define BLACK 1//��ɫ���
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
////�� ������� x���Ϊ��������
//void left_rotate(RBTree* root, Node* x)
//{
//	//yָ��x���Һ��� 
//	Node* y = x->r;
//	//��y�����ӱ��x���Һ���,
//	x->r = y->l;
//	//���y->l�ǿգ�x���y->l�ĸ��� 
//	if ( y->l != NULL )
//	{
//		y->l->parent = x;
//	}
//
//	//����y��x-��parent�Ĺ�ϵ	
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
////�� ������� x���Ϊ��������
//void right_rotate(RBTree* root, Node* x)
//{
//	//yָ��x������ 
//	Node* y = x->l;
//	//��y���Һ��ӱ��x������,
//	x->l = y->r;
//	//���y->r�ǿգ�x���y->r�ĸ��� 
//	if ( y->r != NULL )
//	{
//		y->r->parent = x;
//	}
//
//	//����y��x-��parent�Ĺ�ϵ	
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
//	Node* gparent;//үү
//	Node* uncle;
//	parent = node->parent;
//	while ( parent != NULL && parent->color == RED )
//	{//���׺죬үү��ɫ
//
//		gparent = parent->parent;
//		//���׽����үү�����Һ��ӣ�RR/RL��
//		if ( parent == gparent->r )
//		{
//			uncle = gparent->l;
//			//1.�����Ǻ�ɫ
//			if ( uncle != NULL && uncle->color == RED )
//			{
//				uncle->color = BLACK;
//				parent->color = BLACK;
//				gparent->color = RED;
//				node = gparent;
//				parent = node->parent;
//				continue;
//			}
//			//�����Ǻ�ɫ��->RR,RL
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
//	   //���׽����үү�������ӣ�LL/LR��
//		if ( parent == gparent->l )
//		{
//			uncle = gparent->r;
//			//1.�����Ǻ�ɫ
//			if ( uncle != NULL && uncle->color == RED )
//			{
//				uncle->color = BLACK;
//				parent->color = BLACK;
//				gparent->color = RED;
//				node = gparent;
//				parent = node->parent;
//				continue;
//			}
//			//�����Ǻ�ɫ��->LR,LL
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
//	//���¸����ڵ���ɫ 
//	( *root )->color = BLACK;
//
//}
//
//
//void insert(RBTree* root, int key)
//{
//	//�ж����Ƿ�Ϊ��
//	if ( ( *root ) == NULL )
//	{
//		( *root ) = creatRoot(key);
//
//		return;
//	}
//
//	Node* x = ( *root );//������key�����λ�� 
//	Node* xp = NULL;//x�ĸ��� 
//	//����BST�Ҳ����λ��
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
////���������� 
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
//		cout << "��ɫ" << endl;
//	else
//		cout << "��ɫ" << endl;
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
//	///BUG1: root������ֵ���ݡ�main��rootû�и��ź����е�root�仯---��Ϊ��ַ������ 
//
//	/// 107�У������ж�parent��=NULL����Ȼ�Ҳ���parent->color 	
//
//
//	return 0;
//}
//
