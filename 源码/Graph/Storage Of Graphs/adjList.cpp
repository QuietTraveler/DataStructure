#include<iostream>
#include<cstdlib>
#include<limits.h>

using namespace std;
typedef char type;

typedef struct eNode{
    type data=0;
    int weight=0;
    struct eNode*next=NULL;
}eNode;

typedef struct vNode{
    type data=0;
    struct eNode* first=NULL;
}vNode;

typedef struct adjList{
    vNode* vertex;
    int vSize;
    int eSize;
}adjList;

int Find(vNode* arr,int size,type k)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i].data==k)
        return i;
    }
    return -1;
}

//邻接表 带权有向图
adjList* CreateGraph()
{
    adjList* G=new adjList;
    cout<<"请输入顶点数和边数："<<endl;
    cin>>G->vSize>>G->eSize;

    G->vertex=new vNode[G->vSize];
    for(int i=0;i<G->vSize;i++)
    {
        cout<<"请输入顶点值；"<<endl;
        cin>>G->vertex[i].data;
        G->vertex[i].first=new eNode;
    }

    type u,v;
    int weight=0;
    for(int i=0;i<G->eSize;i++)
    {
        cout<<"请输入对应边的邻接点和权值："<<endl;
        cin>>u>>v>>weight;
        int x=Find(G->vertex,G->vSize,u);
     //   int y=Find(G->vetrix,G->vSize,v);
        
        eNode*node=new eNode;
        node->data=v;
        node->weight=weight;
        node->next=NULL;

        G->vertex[x].first->weight++;
        node->next=G->vertex[x].first->next;
        G->vertex[x].first->next=node;
    }

    return G;
}

void Print(adjList* G)
{
    cout<<"顶点："<<endl;
    for(int i=0;i<G->vSize;i++)
    {
        cout<<G->vertex[i].data<<endl;
    }

    cout<<"图:"<<endl;
    for(int i=0;i<G->vSize;i++)
    {
        eNode* node=G->vertex[i].first;
        cout<<"与该边关联的边数："<<node->weight<<endl;
        node=node->next;
        while(node)
        {
            cout<<node->data<<" "<<node->weight<<endl;
            node=node->next;
        }
        cout<<endl;
    }
}

int main()
{
    adjList* G=CreateGraph();
    Print(G);
    return 0;
}
