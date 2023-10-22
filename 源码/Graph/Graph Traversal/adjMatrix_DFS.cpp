#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<cstdlib>
#include<limits.h>
#include<queue>
#include<cstring>
#include<stack>

using namespace std;
typedef char type;

typedef struct adjMatrix {
    type* vertex;
    int** edge;
    int vSize;
    int eSize;
}adjMatrix;

int Find(type* arr, int size, type k)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

//带权有向图   邻接矩阵
adjMatrix* CreateGraph()
{
    adjMatrix* G = new adjMatrix;
    //  cout<<"请输入图的顶点数和边数："<<endl;
    cin >> G->vSize >> G->eSize;

    G->vertex = new type[G->vSize];
    G->edge = new int* [G->vSize];
    for (int i = 0; i < G->vSize; i++)
    {
        G->edge[i] = new int[G->vSize];
    }

    for (int i = 0; i < G->vSize; i++)
    {
        //    cout<<"请输入顶点值："<<endl;
        cin >> G->vertex[i];
    }
    for (int i = 0; i < G->vSize; i++)
    {
        for (int j = 0; j < G->vSize; j++)
        {
            G->edge[i][j] = INT_MAX;
        }
    }

    type u = 0, v = 0;
    int weight = 0;
    for (int i = 0; i < G->eSize; i++)
    {
        //   cout<<"请输入对应边的邻接点和权值："<<endl;
        cin >> u >> v >> weight;
        G->edge[Find(G->vertex, G->vSize, u)][Find(G->vertex, G->vSize, v)] = weight;
    }

    return G;
}

void Print(adjMatrix* G, int pos)
{
    cout << G->vertex[pos] << " ";
}

void Traversal(adjMatrix* G, bool* visited, int pos)
{
    for (int i = 0; i < G->vSize; i++)
    {
        if (!visited[i] && G->edge[pos][i] != INT16_MAX)
        {
            visited[i] = 1;
            Print(G, i);
            Traversal(G, visited, i);
        }
    }
    return;
}

//5 7
//A
//D
//G
//H
//Z
//A G 3
//A H 0
//A D 11
//G H 4
//Z D 9
//H Z 6
//G A 3

//邻接矩阵的深度优先遍历
void TraversalGraph(adjMatrix* G)
{
    bool* visited = new bool[G->vSize];
    memset(visited, 0, sizeof(bool) * (G->vSize));

    Traversal(G, visited, 0);
    delete[]visited;
}

//邻接表的深度优先遍历   非递归
void OrderGraph(adjMatrix* G)
{
    bool* visited = new bool[G->vSize];
    memset(visited, 0, sizeof(bool) * (G->vSize));
    stack<int>s;
    s.push(0);
    cout << G->vertex[0] << " ";
    visited[0] = 1;

    while (!s.empty())
    {
        int pos = s.top();

        bool flag = 1;
        for (auto i = 0; i<G->vSize; i++)
        {
            if (!visited[i] && G->edge[pos][i] != INT_MAX)
            {
                flag = 0;
                Print(G, i);
                visited[i] = 1;
                s.push(i);
                break;
            }
        }

        if (flag)
            s.pop();
    }

    delete[]visited;
}

int main()
{
    adjMatrix* G = CreateGraph();
    OrderGraph(G);
    return 0;
}