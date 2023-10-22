//#define _CRT_SECURE_NO_WARNINGS  1
//
//#include <iostream>
//#include<cstdlib>
//#include<cstring>
//// Ñ­»·¶ÓÁÐ
//using namespace std;
//#define MAX 7
//typedef struct Queue {
//	int* data;
//	int  front;
//	int  rear;
//}Queue;
//
//Queue* Init_Queue()
//{
//	Queue* Q = new Queue;
//	Q->data = new int[MAX];
//	Q->front = Q->rear = 0;
//	return Q;
//}
//
//bool Empty_Queue(Queue* Q)
//{
//	return Q->front == Q->rear;
//}
//
//bool Full_Queue(Queue* Q)
//{
//	return (Q->rear + 1) % MAX == Q->front;
//}
//
//bool Queue_Push(Queue* Q,int data)
//{
//	if (Full_Queue(Q))
//		return false;
//	Q->data[Q->rear] = data;
//	Q->rear = (Q->rear + 1) % MAX;
//	return true;
//}
//
//bool Queue_Pop(Queue* Q)
//{
//	if (Empty_Queue(Q))
//		return false;
//	Q->front = (Q->front + 1) % MAX;
//	    return true;
//}
//
//int Queue_Lenth(Queue* Q)
//{
//	return (Q->rear - Q->front + MAX) % MAX;
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
//bool Queue_Destroy(Queue* Q)
//{
//	delete(Q->data);
//	delete(Q);
//	return true;
//}
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
//	Queue_Destroy(Q);
//	return 0;
//}
//
