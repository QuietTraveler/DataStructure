#include<iostream>
#include<cstdlib>
#include<limits.h>

using namespace std;
typedef char type;

//权值不能为负数
typedef struct adjMatrix {
	type* vertex;
	int** edge;
	int vSize;
	int eSize;
}adjMatrix;

typedef struct Path {
	int length;
	int prev;
	bool visited;
}Path;


int Find(type* arr, int size, type k)
{
	for ( int i = 0; i < size; i++ )
	{
		if ( arr[i] == k )
			return i;
	}
	return -1;
}

//带权无向图   邻接矩阵
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


void updateList(adjMatrix* G, Path* list, int pos)
{
	for ( int i = 0; i < G->vSize; i++ )
	{
		int length = list[pos].length;
	 if ( G->edge[pos][i]!=INT_MAX && !list[i].visited && ( G->edge[pos][i] + length ) < list[i].length )
		{
			list[i].length = G->edge[pos][i] + length;
			list[i].prev = pos;
		}
	}
}

int findMin(int size,Path* list)
{
	int min = INT_MAX, pos = 0;
	for ( int j = 0; j < size; j++ )
	{
		if ( list[j].length < min  &&  !list[j].visited )
		{
			min = list[j].length;
			pos = j;
		}
	}
	return pos;
}


void Print(adjMatrix* G, Path* list,int start,int end)
{
	for ( int i = 1; i < G->vSize; i++ )
	{
	cout << "起点"<<start<<"到终点"<<i<<"的最小路径长度为："<<list[i].length << endl;
	int j = i;
	cout << j;
	while ( list[j].prev != -1 )
	{
		cout << "->" << list[j].prev;
		j = list[j].prev;
	}
	cout << endl;
	}
}

void Dijkstra(adjMatrix* G,int start,int end)
{
	Path* list = new Path[G->vSize];

	for ( int i = 0; i < G->vSize; i++ )
	{
		list[i].length = INT_MAX;
		list[i].prev = -1;
		list[i].visited = 0;
	}

	list[start].length = 0;
	list[start].visited = 1;
	updateList(G, list, start);

	for(int i=1;i<G->vSize;i++)
	{
		int pos=findMin(G->vSize,list);

		list[pos].visited = 1;

		updateList(G,list, pos);

	}

	Print(G, list,start,end);
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
	Dijkstra(G,0,4);

	return 0;
}


