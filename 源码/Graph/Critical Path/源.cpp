#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
#include<queue>
#include<stack>
#define OK 1
#define ERROR 0
#define MVNum 100
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
typedef int Status;
typedef char VerTexType;
int indegree[MVNum] = { 0 };//结点的入度个数
using namespace std;

//关键路径

//邻接表创建有向图的实现
//边结点 
typedef struct ArcNode {    //链表结点
	int adjvex;           //邻接表创建无向网的实现
	int weight;           //权值
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

typedef struct {
	int early;
	int later;
}Time;

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
	//printf("输入总节点数和弧数：\n"); //G带操作的图；v要在图中定位的顶点
	cin >> G->vexnum >> G->arcnum;
	fflush(stdin);    //是清空输入缓冲区的
	//printf("输入各个节点的值：\n");
	for ( i = 0; i < G->vexnum; i++ )   //邻接表初始化

	{
		cin >> G->vertices[i].data;
		G->vertices[i].firstarc = NULL;
	}

	//cout << "请输入边：" << endl;
	for ( k = 0; k < G->arcnum; k++ )
	{
		//fflush(stdin);   //是清空输入缓冲区的
		int weight=0;
		cin >> v1;
		//getchar();
		cin >> v2;
		//getchar();
		cin >> weight;
		//getchar();
		i = LocateVex(G, v1);   //返回这两个顶点在顶点数组中的位置
		j = LocateVex(G, v2);
		p1 = (ArcNode*) malloc(sizeof(ArcNode));   //给邻接表指针分配空间
		p1->adjvex = j;                          //赋值给p->adjvex指向的顶点域
		p1->weight = weight;                  //赋值给p->weight权值
		p1->nextarc = G->vertices[i].firstarc; //nextarc指针域指向i结点的firstarc指针域  
		G->vertices[i].firstarc = p1;    //将点i的第一条指针指向
		indegree[j]++;
	}
}

//拓扑排序
vector<int> TopoSort(ALGraph* G)
{
	stack<int>s;
	vector<int>ret;
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
		ret.push_back(val);
	}

	return ret;
}

void Find_CriticalPath(ALGraph* G)
{
	Time* event = new Time[G->vexnum];
	for ( int i = 0; i < G->vexnum; i++ )
	{
		event[i].early = 0;
		event[i].later = INT_MAX;
	}

	int index = 0;
	vector<int>s = TopoSort(G);
	event[s[0]].early = 0;

	for ( int i = 0; i < G->vexnum-1; i++ )
	{
		index = s[i];
		ArcNode* e = G->vertices[index].firstarc;
		while ( e )
		{
			event[e->adjvex].early = max(event[e->adjvex].early,event[index].early + e->weight);
			e = e->nextarc;
		}
	}

	event[s[G->vexnum-1]].later = event[s[G->vexnum - 1]].early;

	for ( int i = G->vexnum - 2; i >= 0; i-- )
	{
		index = s[i];
		ArcNode* e = G->vertices[index].firstarc;
		while ( e )
		{
			event[index].later = min(event[index].later, event[e->adjvex].later - e->weight);
			e = e->nextarc;
		}
	}

	for ( int i = 0; i < G->vexnum; i++ )
	{
		index = s[i];
		ArcNode* e = G->vertices[index].firstarc;
		while(e)
		{
		//活动的最早发生时间等于该事件的最早发生时间
		if ( event[e->adjvex].later - e->weight == event[index].early )
		{
			cout << "start=" << index << " " << "end=" << e->adjvex << endl;
		}

		e = e->nextarc;

		}
	}
}

int main()
{
	ALGraph G;
	CreateAOV(&G);
	Find_CriticalPath(&G);
	return 0;
}

//9 11
//A B C D E F G H I
//A B 6
//A C 4
//A D 5
//B E 1
//C E 1
//D F 2
//E G 9
//E H 7
//F H 4
//G I 2
//H I 4