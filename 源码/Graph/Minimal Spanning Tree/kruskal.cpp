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

typedef struct eNode {
	int begin;
	int end;
	int weight;
}eNode;

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

int findParent(int pos,int* parent)
{
	while ( parent[pos] != pos )
		pos = parent[pos];

		return pos;
}

void InitEdge(adjMatrix* G, eNode* Node)
{
	int e = 0;
	for ( int i = 0; i < G->vSize; i++ )
	{
		for ( int j = i + 1; j < G->vSize; j++ )
		{
			if(G->edge[i][j] != INT_MAX )
			{
				Node[e].begin = i;
				Node[e].end = j;
				Node[e].weight = G->edge[i][j];
				e++;
			}
		}
	}

	eNode temp;
	for ( int i = 0; i < G->eSize - 1; i++ )
	{
		for ( int j = 0; j < G->eSize - 1 - i; j++ )
		{
			if(Node[j].weight > Node[j+1].weight )
			{
				temp = Node[j];
				Node[j] = Node[j + 1];
				Node[j + 1] = temp;
			}
		}
	}
}


void kruskal(adjMatrix* G)
{
	//为顶点并查集开辟空间
	int* parent = new int [G->vSize];
	
	eNode* Node = new eNode[G->eSize];

	int total = 0;

	for ( int i = 0; i < G->vSize; i++ )
	{
		parent[i] = i;
	}

	InitEdge(G,Node);
	int count = 0;
	
	for ( int i = 0; i < G->eSize; i++ )
	{
		int x = findParent(Node[i].begin, parent);
		int y = findParent(Node[i].end, parent);
		if(x != y)
		{
			parent[y] = x;
			total += Node[i].weight;
			cout << Node[i].begin+1 << "和" << Node[i].end+1 << "  权值为" << 
				Node[i].weight<< endl;
			count++;
		}
		if ( count == G->vSize - 1 )
			break;

	}
	
	cout  << "权值总和为："<< total << endl;


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
	adjMatrix* G=CreateGraph();
	kruskal(G);

	return 0;
}