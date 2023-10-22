//#define _CRT_SECURE_NO_WARNINGS  1
//#define _CRT_SECURE_NO_WARNINGS  1
//
//#include <iostream>
//#include<cstdlib>
//#include<cstring>
//using namespace std;
//#define MAX 6
//typedef struct Queue {
//	int* data;
//	int  front;
//	int  rear;
//	bool tag;
//}Queue;
//
//Queue* Init_Queue()
//{
//	Queue* Q = new Queue;
//	Q->data = new int[MAX];
//	Q->front = Q->rear = 0;
//	Q->tag = 0;
//	return Q;
//}
//
//bool Empty_Queue(Queue* Q)
//{
//	return Q->front == Q->rear && Q->tag==0;
//}
//
//bool Full_Queue(Queue* Q)
//{
//	return Q->front == Q->rear && Q->tag==1;
//}
//
//bool Queue_Push(Queue* Q, int data)
//{
//	if (Full_Queue(Q))
//		return false;
//	Q->data[Q->rear] = data;
//	Q->rear = (Q->rear + 1) % MAX;
//	Q->tag = 1;
//	return true;
//}
//
//bool Queue_Pop(Queue* Q)
//{
//	if (Empty_Queue(Q))
//		return false;
//	Q->front = (Q->front + 1) % MAX;
//	Q->tag = 0;
//	return true;
//}
//
//int Queue_Lenth(Queue* Q)
//{
//	int k = (Q->rear - Q->front + MAX) % MAX;
//	if (!k)
//	{
//		if (Q->tag)
//			return MAX;
//		else
//			return 0;
//	}
//	return k;
//}
//
//void Print(Queue* Q)
//{
//	for (int i = 0; i < Queue_Lenth(Q); i++)
//	{
//		cout << Q->data[i] << " ";
//	}
//	cout << endl;
//	cout << Queue_Lenth(Q) << endl;
//}
//
//int main() {
//	Queue* Q = Init_Queue();
//	Queue_Push(Q, 4);
//	Queue_Push(Q, 5);
//	Queue_Push(Q, 2);
//	Queue_Push(Q, 1);
//	Queue_Push(Q, 1);
//	Queue_Push(Q, 1);
//	Queue_Pop(Q);
//	Queue_Pop(Q);
//	Queue_Pop(Q);
//	Queue_Pop(Q);
//	Print(Q);
//	return 0;
//}
//
