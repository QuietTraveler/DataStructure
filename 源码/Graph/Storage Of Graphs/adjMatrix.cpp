#include<iostream>
#include<cstdlib>
#include<limits.h>

using namespace std;
typedef char type;


typedef struct adjMatrix{
    type* vertex;
    int** edge;
    int vSize;
    int eSize;
}adjMatrix;

int Find(type* arr,int size,type k)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==k)
        return i;
    }
    return -1;
}

//带权有向图   邻接矩阵
adjMatrix* CreateGraph()
{
    adjMatrix* G=new adjMatrix;
    cout<<"请输入图的顶点数和边数："<<endl;
    cin>>G->vSize>>G->eSize;

    G->vertex=new type[G->vSize];
    G->edge=new int*[G->vSize];
    for(int i=0;i<G->vSize;i++)
    {
        G->edge[i]=new int [G->vSize];
    }

    for(int i=0;i<G->vSize;i++)
    {
        cout<<"请输入顶点值："<<endl;
            cin>>G->vertex[i];
    }
    for(int i=0;i<G->vSize;i++)
    {
        for(int j=0;j<G->vSize;j++)
        {
            G->edge[i][j]=INT_MAX;
        }
    }

    type u=0,v=0;
    int weight=0;
    for(int i=0;i<G->eSize;i++)
    {
        cout<<"请输入对应边的邻接点和权值："<<endl;
        cin>>u>>v>>weight;
        G->edge[Find(G->vertex,G->vSize,u)][Find(G->vertex,G->vSize,v)]=weight;
    }
    
    return G;
}

void Print(adjMatrix* G)
{
    cout<<"顶点："<<endl;
    for(int i=0;i<G->vSize;i++)
    {
        cout<<G->vertex[i]<<endl;
    }

    cout<<"图:"<<endl;
    for(int i=0;i<G->vSize;i++)
    {
        for(int j=0;j<G->vSize;j++)
        {
            if(G->edge[i][j]==INT_MAX)
            {
                cout<<"*"<<" ";
            }
            else
                cout<<G->edge[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    adjMatrix*G = CreateGraph();
    Print(G);
    return 0;
}