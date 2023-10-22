#include<iostream>
#include<cstdlib>

using namespace std;

typedef char type;     

//边结点
typedef struct Enode{
    int weight=0;    //权值
    int head=0;       //边的起点
    int tail=0;       //边的终点
    struct Enode* tailLink=NULL;    //下一个以该顶点为起点的指针
    struct Enode* headLink=NULL;    //下一个以该顶点为终点的指针
}Enode;

//顶点
typedef struct VNode{    
    type data=0;    //顶点值
    Enode* firstIn=NULL;    //连接以该顶点为入度点链表的指针
    Enode* firstOut=NULL;   //连接以该顶点为出度点链表的指针
    int eSize=0;            //该顶点的度
}VNode;

//图
typedef struct TenList{
    int vertex;   //顶点
    int edge;      //边
    VNode* vList;   //十字链表
}TenList;

//寻找值对应下标
int Find(TenList* const G,type k)
{
    for(int i=0;i<G->vertex;i++)
    {
        if(k==G->vList[i].data)
        return i;
    }
    return -1;
}

//添加对应边
void addEdge(TenList* const G,int uPos,int vPos,int weight)
{
    Enode* node=new Enode;   //为边结点开辟空间
    node->head=uPos;          //为边结点的起点赋值
    node->tail=vPos;           //为边结点的终点赋值
    node->weight=weight;      //给边结点的权值赋值
    
    //头插法
    node->headLink = G->vList[uPos].firstOut->headLink;
    G->vList[uPos].firstOut->headLink = node;

    //增加顶点对应度的值
    G->vList[uPos].firstOut->weight++;
    G->vList[uPos].eSize++;
    
    //头插法
    node->tailLink = G->vList[vPos].firstIn->tailLink;
    G->vList[vPos].firstIn->tailLink = node;

    //增加顶点对应度的值
    G->vList[vPos].firstIn->weight++;
    G->vList[vPos].eSize++;
}

//十字链表  带权有向图
TenList* CreateGraph()
{
    //为图开辟空间
    TenList* G=new TenList;
    cout<<"请输入图的顶点数和边数："<<endl;
    cin>>G->vertex>>G->edge;
    //为存储图顶点和边的十字链表开辟空间
    G->vList=new VNode [G->vertex];
    //为十字链表里面顶点的边指针开辟空间
    for(int i=0;i<G->vertex;i++)
    {
        G->vList[i].firstIn=new Enode;
        G->vList[i].firstOut=new Enode;
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
        int uPos=Find(G,u);   //查找对应邻接点（起始点）的下标
        int vPos=Find(G,v);   //查找对应邻接点（终点）的下标

        addEdge(G,uPos,vPos,weight);   //将边结点添加进十字链表
    }
    return G;
}

//打印图
void Print(TenList *G)
{
    for(int i=0;i<G->vertex;i++)
    {
        cout<<"顶点："<<G->vList[i].data<<" ";
        cout<<"入度数："<<G->vList[i].firstIn->weight<<" ";
        cout<<"出度数  "<<G->vList[i].firstOut->weight<<" ";
        cout<<endl;
        Enode* node=G->vList[i].firstIn->tailLink;
        while(node)
        {
            cout<<node->head<<" "<<node->weight<<"| ";
            node=node->tailLink;
        }
        cout<<endl;
        node=G->vList[i].firstOut->headLink;
        while(node)
        {
            cout<<node->tail<<" "<<node->weight<<"| ";
            node=node->headLink;
        }
        cout<<endl;
        cout<<endl;
    }
}

int main()
{
    TenList* G= CreateGraph();
    Print(G);
    return 0;
}