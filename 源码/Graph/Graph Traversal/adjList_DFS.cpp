#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<stack>

using namespace std;

typedef char type;

typedef struct eNode {
    type data = 0;
    int weight = 0;
    struct eNode* next = NULL;
}eNode;

typedef struct vNode {
    type data = 0;
    struct eNode* first = NULL;
}vNode;

typedef struct adjList {
    vNode* vertex;
    int vSize;
    int eSize;
}adjList;

int Find(vNode* arr, int size, type k)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].data == k)
            return i;
    }
    return -1;
}

//邻接表 带权有向图
adjList* CreateGraph()
{
    adjList* G = new adjList;
    //  cout<<"请输入顶点数和边数："<<endl;
    cin >> G->vSize >> G->eSize;

    G->vertex = new vNode[G->vSize];
    for (int i = 0; i < G->vSize; i++)
    {
        //    cout<<"请输入顶点值；"<<endl;
        cin >> G->vertex[i].data;
        G->vertex[i].first = new eNode;
    }

    type u, v;
    int weight = 0;
    for (int i = 0; i < G->eSize; i++)
    {
        //  cout<<"请输入对应边的邻接点和权值："<<endl;
        cin >> u >> v >> weight;
        int x = Find(G->vertex, G->vSize, u);
        //   int y=Find(G->vetrix,G->vSize,v);

        eNode* node = new eNode;
        node->data = v;
        node->weight = weight;
        node->next = NULL;

        G->vertex[x].first->weight++;
        node->next = G->vertex[x].first->next;
        G->vertex[x].first->next = node;
    }

    return G;
}

void Print(adjList* G, int pos)
{
    cout << G->vertex[pos].data << " ";
}

void Traversal(adjList* G, bool* visited, int pos)
{
    for (auto i = G->vertex[pos].first->next; i; i = i->next)
    {
        int index = Find(G->vertex, G->vSize, i->data);
        if (!visited[index])
        {
            visited[index] = 1;
            Print(G, index);
            Traversal(G, visited, index);
        }
    }
    return;
}

//邻接表的深度优先遍历   递归
void TraversalGraph(adjList* G)
{
    bool* visited = new bool[G->vSize];
    memset(visited, 0, sizeof(bool) * (G->vSize));

    Traversal(G, visited, 0);
    delete[]visited;
}

//邻接表的深度优先遍历   非递归
void OrderGraph(adjList* G)
{
    bool* visited = new bool[G->vSize];
    memset(visited, 0, sizeof(bool) * (G->vSize));
    stack<int>s;
    s.push(0);
    cout << G->vertex[0].data << " ";
    visited[0] = 1;

    while (!s.empty())
    {
        int pos = s.top();

        bool flag = 1;
        for (auto i = G->vertex[pos].first->next; i; i = i->next)
        {
            int index = Find(G->vertex, G->vSize, i->data);
            if (!visited[index])
            {
                flag = 0;
                Print(G, index);
                visited[index] = 1;
                s.push(index);
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
    adjList* G = CreateGraph();
    OrderGraph(G);
    return 0;
}