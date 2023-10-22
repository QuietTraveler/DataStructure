#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<cstdlib>
 
using namespace std;


//¹þ·òÂüÊ÷
typedef struct HuffmanTree {
	int right;
	int left;
	int parent;
	int weight;
}HuffmanNode,HuffmanTree;

void FindMin(HuffmanTree* Tree, int size,int* u,int*v)
{
	
	int min = 0;
	for (int i = 1; i <= size; i++)
	{
		if (!Tree[i].parent)
		{
			min = Tree[i].weight;
			*u = i;
			break;
		}
	}


	for (int i = 1; i <= size; i++)
	{
		if (!Tree[i].parent)
		{
			if (min > Tree[i].weight)
			{
				min = Tree[i].weight;
				*u = i;
			}
		}
	}
	Tree[*u].parent = -1;

	for (int i = 1; i <= size; i++)
	{
		if (!Tree[i].parent)
		{
			min = Tree[i].weight;
			*v = i;
			break;
		}
	}

	for (int i = 1; i <= size; i++)
	{
		if (!Tree[i].parent)
		{
			if (min > Tree[i].weight)
			{
				min = Tree[i].weight;
				*v = i;
			}
		}
	}

}

HuffmanTree* CreateHuffmanTree(int* weighted,int size)
{
	int TreeSize = size * 2;
	HuffmanTree* Tree = new HuffmanNode [TreeSize];
	for (int i = 0; i < TreeSize; i++)
	{
		Tree[i].left = Tree[i].right = Tree[i].parent = 0;
		if (i <= size && i>0)
			Tree[i].weight = weighted[i-1];
	}
	Tree[0].parent = TreeSize;
	
	int u=0, v=0;
	for (int i = size+1; i < TreeSize; i++)
	{
		FindMin(Tree, i-1, &u, &v);
		Tree[i].left = u;
		Tree[i].right = v;
		Tree[i].weight = Tree[u].weight + Tree[v].weight;
		Tree[u].parent = Tree[v].parent = i;
	}

	return Tree;
}

char** HuffmanCode(HuffmanTree* Tree,int TreeSize)
{
	int n = TreeSize / 2;
	char** code = new char* [n];
	for(int i=0;i<n;i++)
	{
		char* temp = new char[n];
		code[i] = temp;
	}
	
	char* ch = new char[n];
	int prev = 0, k = 0,start=n-1;
	for (int i = 0; i < n; i++)
	{
		k = i+1;
		start = n - 1;
		ch[start] = '\0';
		while (Tree[k].parent)
		{
			prev = k;
			k = Tree[k].parent;
			if (Tree[k].left == prev)
			{
				ch[start - 1] = '1';
			}
			else
			{
				ch[start - 1] = '0';
			}
			start--;
		}

		strcpy(code[i], &(ch[start]));
	}

	return code;
}


int main()
{
	char letter[] = { 'B','I','T','E','S','T' };
	int weighted[] = { 2,4,6,7,1,9 };
	int size = sizeof(weighted) / sizeof(weighted[0]);
	HuffmanTree* root = CreateHuffmanTree(weighted,size);
	char** code = HuffmanCode(root, root[0].parent);

	cout << "×óº¢×Ó" << " " << "ÓÒº¢×Ó" << " " << "È¨ÖØ" << " " << "¸¸Ç×" << endl;
	for (int i = 1; i < size * 2; i++)
	{
		
		cout << root[i].left << "	" << root[i].right << "	" << root[i].weight << "	" << root[i].parent << endl;
	}


	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << letter[i] << ":" << code[i] << endl;
	}
	return 0;
}