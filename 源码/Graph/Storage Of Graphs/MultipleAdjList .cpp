#include<iostream>
#include<cstdlib>

using namespace std;

typedef char type;     

//边结点
typedef struct Enode{
    int weight=0;    //权值
    int uvex=0;       //边的邻接点
    int vvex=0;       //边的邻接点
    struct Enode* uLink=NULL;    //与该边有相连的顶点u
    struct Enode* vLink=NULL;    //与该边有相连的顶点v
}Enode;

//顶点
typedef struct VNode{    
    type data=0;    //顶点值
    Enode* first=NULL;    //连接跟该顶点有相连的顶点链表的指针
    int ESize=0;
}VNode;

//图
typedef struct MulAdjList{
    int vertex;   //顶点
    int edge;      //边
    VNode* vList;   //多重邻接表
}MulAdjList;

//寻找值对应下标
int Find(MulAdjList* const G,type k)
{
    for(int i=0;i<G->vertex;i++)
    {
        if(k==G->vList[i].data)
        return i;
    }
    return -1;
}

//添加对应边
void addEdge(MulAdjList* const G,int uPos,int vPos,int weight)
{
    Enode* node=new Enode;   //为边结点开辟空间
    node->uvex=uPos;          //为边结点的邻接点u赋值
    node->vvex=vPos;           //为边结点的邻接点v赋值
    node->weight=weight;      //给边结点的权值赋值
    
    //头插法
    node->uLink = G->vList[uPos].first;
    G->vList[uPos].first = node;

    //增加顶点对应度的值
    G->vList[uPos].ESize++;
    
    //头插法
    node->vLink=G->vList[vPos].first;
    G->vList[vPos].first = node;

    //增加顶点对应度的值
    G->vList[vPos].ESize++;
}

//多重邻接表  带权无向图
MulAdjList* CreateGraph()
{
    //为图开辟空间
    MulAdjList* G=new MulAdjList;
    cout<<"请输入图的顶点数和边数："<<endl;
    cin>>G->vertex>>G->edge;
    //为存储图顶点和边的多重邻接表开辟空间
    G->vList=new VNode [G->vertex];
    //为多重邻接表里面顶点的边指针开辟空间
    for(int i=0;i<G->vertex;i++)
    {
        G->vList[i].first=new Enode;
    }

    //存储顶点值
    for(int i=0;i<G->vertex;i++)
    {
        cout<<"请输入顶点值："<<endl;
        cin>>G->vList[i].data;
    }
 
    type u,v;
    int weight=0;
    //循环存储边结点和对应关系
    for(int i=0;i<G->edge;i++)
    {
        cout<<"请输入边对应的邻接点和权值："<<endl;
        cin>>u>>v>>weight;    //输入起点和终点的值
        int uPos=Find(G,u);   //查找对应邻接点的下标
        int vPos=Find(G,v);   //查找对应邻接点的下标

        addEdge(G,uPos,vPos,weight);   //将边结点添加进多重邻接表
    }
    return G;
}

//打印图
void Print(MulAdjList *G)
{
    for(int i=0;i<G->vertex;i++)
    {
        cout<<"顶点："<<G->vList[i].data<<" ";
        cout<<"度数："<<G->vList[i].ESize<<" ";
        cout<<endl;
        Enode* node=G->vList[i].first;
        int k=Find(G,G->vList[i].data);
        int size=G->vList[i].ESize;
        while(size--)
        {
            if(node && node->uvex == k)
            {
            cout<<node->vvex<<" "<<node->weight<<"/  ";
            node=node->uLink;
            }
            else if(node && node->vvex == k)
            {
            cout<<node->uvex<<" "<<node->weight<<"/  ";
            node=node->vLink;
            }
        }
        cout<<endl;
    }
}

int main()
{
    MulAdjList* G= CreateGraph();
    Print(G);
    return 0;
}