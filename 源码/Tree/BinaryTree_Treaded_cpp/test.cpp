#define _CRT_SECURE_NO_WARNINGS  1
#include"TreadBiTree.h"

int main()
{
	BiTreeNode T;
	BiTreeNode* Tp = &T;
	CreateBiTree(Tp);
	TraverBiTree(Tp);
	BiTreeNode*H=HeadTreBiTree(Tp);
	TraverTread(H);
	return 0;
}