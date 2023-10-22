#define _CRT_SECURE_NO_WARNINGS  1
#include"HuffmanTree.h"

int main()
{
	HuffmanTree tree[NUM];
	HuffmanTree* T = tree;
	CreateHMTree(T,NODE);
	HMTreePirnt(T);
	char** arr=AcquireCode(T, NODE);
	CodesPrint(arr, NODE);
	char arr1[] = { '0','1','1','0','1','0','1','1','1','0','1','1','1','1','1','1','0','\0'};
	size_t len = strlen(arr1);
	int returnSize = 0;
	char*arr0= Decode(T, arr1, NODE,len,&returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf(" %c ", arr0[i]);
	}
	return 0;
}
