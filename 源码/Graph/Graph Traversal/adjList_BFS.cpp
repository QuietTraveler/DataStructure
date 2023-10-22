#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>

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

void Print(adjList* G,int pos)
{
    cout<<G->vertex[pos].data<<" ";
}

//邻接表的广度优先遍历   
void TraversalGraph(adjList* G)
{
     bool* visited=new bool [G->vSize];
     memset(visited,0,sizeof(bool)*(G->vSize));
     queue<int>q;
     q.push(0);
     visited[0]=1;
    
     while(!q.empty())
     {
        int pos=q.front();
        Print(G,pos);
        q.pop();

        eNode* node=G->vertex[pos].first->next;
        while(node)
        {
            int key=Find(G->vertex,G->vSize,node->data);
            if(!visited[key])
           { 
            q.push(key);
            visited[key]=1; 
            }
            node=node->next;
        }
     }
     delete []visited;
}


int main()
{
    adjList* G= CreateGraph();
    TraversalGraph(G);
    return 0;
}