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
int indegree[MVNum] = { 0 };//������ȸ���
using namespace std;

//�ڽӱ�������ͼ��ʵ��
//�߽�� 
typedef struct ArcNode {    //������
	int adjvex;           //�ڽӱ�����������ʵ��
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
	printf("�����ܽڵ����ͻ�����\n"); //G��������ͼ��vҪ��ͼ�ж�λ�Ķ���
	cin>>G->vexnum>>G->arcnum;
	fflush(stdin);    //��������뻺������
	printf("��������ڵ��ֵ��\n");
	for ( i = 0; i < G->vexnum; i++ )   //�ڽӱ��ʼ��

	{
		cin>>G->vertices[i].data;
		getchar();
		G->vertices[i].firstarc = NULL;
	}

	cout << "������ߣ�" << endl;
	for ( k = 0; k < G->arcnum; k++ )
	{
		//fflush(stdin);   //��������뻺������
		cin >> v1;
		getchar();
		cin >> v2;
		getchar();
		i = LocateVex(G, v1);   //���������������ڶ��������е�λ��
		j = LocateVex(G, v2);
		p1 = (ArcNode*) malloc(sizeof(ArcNode));   //���ڽӱ�ָ�����ռ�
		p1->adjvex = j;                          //��ֵ��p->adjvexָ��Ķ�����
		p1->nextarc = G->vertices[i].firstarc; //nextarcָ����ָ��i����firstarcָ����  
		G->vertices[i].firstarc = p1;    //����i�ĵ�һ��ָ��ָ��
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