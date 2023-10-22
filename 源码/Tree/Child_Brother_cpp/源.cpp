#define _CRT_SECURE_NO_WARNINGS  1

#include <iostream>
#include<cstdlib>
#include<cstring>
//孩子兄弟表示法
using namespace std;
typedef struct Tree {
	int data;
	struct Tree* lchild;
	struct Tree* rbrother;
}TreeNode;

TreeNode* InitTree(int data)
{
	TreeNode* root = new TreeNode;
	root->data = data;
	root->lchild = root->rbrother = NULL;
	return root;
}

TreeNode* FindParent(TreeNode* root, int parent_data)
{
	if (root->data == parent_data)
		return root;
	if (root->lchild != NULL)
	{
	TreeNode* node = FindParent(root->lchild, parent_data);
	if (node)
		return node;
	}
	if(root->rbrother!=NULL)
	{
	TreeNode* node = FindParent(root->rbrother, parent_data);
	if (node)
		return node;
	}
	return NULL;
}

void InsertTree(TreeNode* root,int data, int parent_data)
{
	TreeNode* node=FindParent(root, parent_data);
	if (node)
	{
		TreeNode* temp = new TreeNode;
		temp->data = data;
		temp->lchild = NULL;
		temp->rbrother = node->lchild;
		node->lchild = temp;
	}
	else
		cout << "error_no_data" << endl;
}

void Print(TreeNode* root)
{
	if (!root)
		return;
	Print(root->lchild);
	cout << root->data << endl;
	Print(root->rbrother);
	return;
}

int main() {
	TreeNode* root = InitTree(4);
	InsertTree(root, 3,4);
	InsertTree(root, 5,4);
	InsertTree(root, 6,4);
	InsertTree(root, 2,3);
	InsertTree(root, 1,3);
	InsertTree(root, 0,3);
	InsertTree(root, 12,5);
	InsertTree(root, 7,6);
	InsertTree(root, 8,6);
	Print(root);
	return 0;
}

