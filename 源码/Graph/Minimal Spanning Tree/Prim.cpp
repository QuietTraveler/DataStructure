#include<iostream>
#include<cstdlib>
#include<limits.h>

using namespace std;
typedef char type;


typedef struct adjMatrix {
	type* vertex;
	int** edge;
	int vSize;
	int eSize;
}adjMatrix;

typedef struct disNode {
	int gap;
	int end;
	bool visited;
}disNode;

int Find(type* arr, int size, type k)
{
	for ( int i = 0; i < size; i++ )
	{
		if ( arr[i] == k )
			return i;
	}
	return -1;
}

//带权有向图   邻接矩阵
adjMatrix* CreateGraph()
{
	adjMatrix* G = new adjMatrix;
 //   cout << "请输入图的顶点数和边数：" << endl;
	cin >> G->vSize >> G->eSize;

	G->vertex = new type[G->vSize];
	G->edge = new int* [G->vSize];
	for ( int i = 0; i < G->vSize; i++ )
	{
		G->edge[i] = new int[G->vSize];
	}

	for ( int i = 0; i < G->vSize; i++ )
	{
   //     cout << "请输入顶点值：" << endl;
		cin >> G->vertex[i];
	}
	for ( int i = 0; i < G->vSize; i++ )
	{
		for ( int j = 0; j < G->vSize; j++ )
		{
			G->edge[i][j] = INT_MAX;
		}
	}

	type u = 0, v = 0;
	int weight = 0;
	for ( int i = 0; i < G->eSize; i++ )
	{
	//    cout << "请输入对应边的邻接点和权值：" << endl;
		cin >> u >> v >> weight;
		G->edge[Find(G->vertex, G->vSize, u)][Find(G->vertex, G->vSize, v)] = weight;
		G->edge[Find(G->vertex, G->vSize, v)][Find(G->vertex, G->vSize, u)] = weight;
	}

	return G;
}


void updateNode(adjMatrix* G, disNode* Node, int pos)
{
	for ( int i = 0; i < G->vSize; i++ )
	{
		if ( !Node[i].visited && G->edge[pos][i] < Node[i].gap )
		{
			Node[i].gap = G->edge[pos][i];
			Node[i].end = pos;
		}
	}
}

int findMin(int size,disNode* Node)
{
	int min = INT_MAX, pos = 0;
	for ( int j = 0; j < size; j++ )
	{
		if ( !Node[j].visited && Node[j].gap < min )
		{
			min = Node[j].gap;
			pos = j;
		}
	}
	return pos;
}


void Print(adjMatrix* G, disNode* Node)
{
	for ( int i = 0; i < G->vSize; i++ )
	{
		if ( Node[i].gap )
		{  
			cout << i << " " << Node[i].end << "  权值为：" << Node[i].gap << " " << endl;
		}                  
	}
}

void prim(adjMatrix* G)
{
	disNode* Node = new disNode[G->vSize];
	  
	for ( int i = 0; i < G->vSize; i++ )
	{ 
		Node[i].gap = INT_MAX;
		Node[i].end = -1;
		Node[i].visited = 0;
	}

	Node[0].end = 0;
	Node[0].gap = 0;
	Node[0].visited = 1;
	updateNode(G,Node,0);

	for ( int i = 1; i < G->vSize; i++ )
	{
		int pos=findMin(G->vSize, Node);

		Node[pos].visited = 1;

		updateNode(G, Node, pos);

	}

	Print(G, Node);
}


//5 7
//A
//B
//C
//D
//E
//A B 3
//A C 7
//A D 2
//A E 4
//B C 1
//D E 6
//B D 5

int main()
{
	adjMatrix* G = CreateGraph();
	cout << endl;
	prim(G);

	return 0;
}


