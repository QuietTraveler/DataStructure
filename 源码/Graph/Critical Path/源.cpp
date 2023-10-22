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
int indegree[MVNum] = { 0 };//������ȸ���
using namespace std;

//�ؼ�·��

//�ڽӱ�������ͼ��ʵ��
//�߽�� 
typedef struct ArcNode {    //������
	int adjvex;           //�ڽӱ�����������ʵ��
	int weight;           //Ȩֵ
	struct ArcNode* nextarc;    //ָ����һ���ߵ�ָ��
	//OtherInfo info;       //�ͱ���ص���Ϣ
}ArcNode;

//������Ϣ 
typedef struct VNode {   //ͷ���
	VerTexType data;   //������Ϣ
	ArcNode* firstarc;//ָ���һ�������ö���ıߵ�ָ��
}VNode, AdjList[MVNum];//AdjList ��ʾ�ڽӱ�����

typedef struct {
	AdjList vertices;     //�ڽӱ�ͷ�������
	int vexnum, arcnum;   //ͼ�Ķ������ͻ���
}ALGraph;

typedef struct {
	int early;
	int later;
}Time;

//��������ͼ��
int LocateVex(ALGraph* G, VerTexType v)  //G��������ͼ��vҪ��ͼ�ж�λ�Ķ���
{
	int i;
	for ( i = 0; i < ( G->vexnum ); i++ )
	{
		if ( v == G->vertices[i].data )
			return i;               //��������򷵻���ͷ��������е��±ꣻ���򷵻�
	}
	return -1;
}


void CreateAOV(ALGraph* G)
{
	int i, j, k;
	VerTexType v1, v2;
	ArcNode* p1;
	//printf("�����ܽڵ����ͻ�����\n"); //G��������ͼ��vҪ��ͼ�ж�λ�Ķ���
	cin >> G->vexnum >> G->arcnum;
	fflush(stdin);    //��������뻺������
	//printf("��������ڵ��ֵ��\n");
	for ( i = 0; i < G->vexnum; i++ )   //�ڽӱ��ʼ��

	{
		cin >> G->vertices[i].data;
		G->vertices[i].firstarc = NULL;
	}

	//cout << "������ߣ�" << endl;
	for ( k = 0; k < G->arcnum; k++ )
	{
		//fflush(stdin);   //��������뻺������
		int weight=0;
		cin >> v1;
		//getchar();
		cin >> v2;
		//getchar();
		cin >> weight;
		//getchar();
		i = LocateVex(G, v1);   //���������������ڶ��������е�λ��
		j = LocateVex(G, v2);
		p1 = (ArcNode*) malloc(sizeof(ArcNode));   //���ڽӱ�ָ�����ռ�
		p1->adjvex = j;                          //��ֵ��p->adjvexָ��Ķ�����
		p1->weight = weight;                  //��ֵ��p->weightȨֵ
		p1->nextarc = G->vertices[i].firstarc; //nextarcָ����ָ��i����firstarcָ����  
		G->vertices[i].firstarc = p1;    //����i�ĵ�һ��ָ��ָ��
		indegree[j]++;
	}
}

//��������
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
		//������緢��ʱ����ڸ��¼������緢��ʱ��
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