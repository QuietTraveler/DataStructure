#include<iostream>
#include<cstring>
#include<stdio.h>
#include<queue>
#include<stack>
#define OK 1
#define ERROR 0
#define MVNum 100
typedef int Status;
typedef char VerTexType;
typedef char OtherInfo;
int indegree[MVNum] = { 0 };//结点的入度个数
using namespace std;

//邻接表创建有向图的实现
//边结点 
typedef struct ArcNode {    //链表结点
	int adjvex;           //邻接表创建无向网的实现
	struct ArcNode* nextarc;    //指向下一条边的指针
	//OtherInfo info;       //和边相关的信息
}ArcNode;

//顶点信息 
typedef struct VNode {   //头结点
	VerTexType data;   //顶点信息
	ArcNode* firstarc;//指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum];//AdjList 表示邻接表类型

typedef struct {
	AdjList vertices;     //邻接表头结点数组
	int vexnum, arcnum;   //图的顶点数和弧数
}ALGraph;

//创建有向图：
int LocateVex(ALGraph* G, VerTexType v)  //G带操作的图；v要在图中定位的顶点
{
	int i;
	for ( i = 0; i < ( G->vexnum ); i++ )
	{
		if ( v == G->vertices[i].data )
			return i;               //顶点存在则返回在头结点数组中的下标；否则返回
	}
	return -1;
}


void CreateAOV(ALGraph* G)
{
	int i, j, k;
	VerTexType v1, v2;
	ArcNode* p1;
	printf("输入总节点数和弧数：\n"); //G带操作的图；v要在图中定位的顶点
	cin>>G->vexnum>>G->arcnum;
	fflush(stdin);    //是清空输入缓冲区的
	printf("输入各个节点的值：\n");
	for ( i = 0; i < G->vexnum; i++ )   //邻接表初始化

	{
		cin>>G->vertices[i].data;
		getchar();
		G->vertices[i].firstarc = NULL;
	}

	cout << "请输入边：" << endl;
	for ( k = 0; k < G->arcnum; k++ )
	{
		//fflush(stdin);   //是清空输入缓冲区的
		cin >> v1;
		getchar();
		cin >> v2;
		getchar();
		i = LocateVex(G, v1);   //返回这两个顶点在顶点数组中的位置
		j = LocateVex(G, v2);
		p1 = (ArcNode*) malloc(sizeof(ArcNode));   //给邻接表指针分配空间
		p1->adjvex = j;                          //赋值给p->adjvex指向的顶点域
		p1->nextarc = G->vertices[i].firstarc; //nextarc指针域指向i结点的firstarc指针域  
		G->vertices[i].firstarc = p1;    //将点i的第一条指针指向
		indegree[j]++;
	}
}

bool TopoSort(ALGraph* G)
{
	stack<int>s;
	queue<VerTexType>ret;
	for ( int i = 0; i < G->vexnum; i++ )
	{
		if ( !indegree[i] )
		{
			s.push(i);
		}
	}

	while ( !s.empty() )
	{
		int val = s.top();
		s.pop();
		ArcNode* e = G->vertices[val].firstarc;
		while ( e )
		{
			indegree[e->adjvex]--;
			if ( !indegree[e->adjvex] )
				s.push(e->adjvex);
			e = e->nextarc;
		}
		ret.push(G->vertices[val].data);
	}

	bool flag = 0;
	if ( ret.size() != G->vexnum )
		flag = false;
	else
		flag = true;

	while ( !ret.empty() )
	{
		cout << ret.front() << " ";
		ret.pop();
	}

	return flag;
}

int main()
{
	ALGraph G;
	CreateAOV(&G);
	cout << TopoSort(&G) << endl;
	return 0;
}

/*
6 8

A B C D E F

A B
A C
A D
C B
C E
D E
F D
F E
*/