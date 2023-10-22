//#define _CRT_SECURE_NO_WARNINGS  1
//
//#include <iostream>
//#include<cstdlib>
//#include<cstring>
////孩子表示法
//#define MAX 15
//using namespace std;
//typedef char type;
//typedef struct Node {
//	type val;
//	int parent;
//	struct Node* next;
//}Node;
//
//typedef struct Tree {
//	int size=0;
//	int capacity=MAX;
//	Node* data[MAX];
//}Tree;
//
//Tree* InitTree(type root_val)
//{
//	Tree* tree = new Tree;
//	Node* node = new Node;
//	node->val = root_val;
//	node->parent = -1;
//	node->next = NULL;
//	tree->data[tree->size++] = node;
//	return tree;
//}
//
//int FindParent(Tree* root, type parent_val)
//{
//	for (int i = 0; i < root->size; i++)
//	{
//		if (root->data[i]->val == parent_val)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//void InsertTree(Tree* root, type val, type parent_val)
//{
//	if (root->size == MAX)
//	{
//		cout << "error_full" << endl;
//		return;
//	}
//	int parent = FindParent(root, parent_val);
//	if (parent != -1)
//	{
//		Node* node = new Node;
//		node->val = val;
//		node->parent = parent;
//		node->next = root->data[parent]->next;
//		root->data[parent]->next = node;
//		root->data[root->size++] = node;
//	}
//	else
//	{
//		cout << "error_no_val" << endl;
//	}
//}
//
//void Print(Tree* root)
//{
//	for (int i = 0; i < root->size; i++)
//	{
//		cout << root->data[i]->val << "   " << root->data[i]->parent<<endl;
//		Node* node = root->data[i]->next;
//		while (node )
//		{
//			if(node->parent==i)
//			cout << node->val <<" "<<node->parent<<endl;
//			node = node->next;
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	Tree* root = InitTree('4');
//	InsertTree(root, '3', '4');
//	InsertTree(root, '5', '4');
//	InsertTree(root, '6', '4');
//	InsertTree(root, '1', '3');
//	InsertTree(root, '2', '5');
//	InsertTree(root, '7', '6');
//	InsertTree(root, '9', '1');
//	Print(root);
//	return 0;
//}
//
