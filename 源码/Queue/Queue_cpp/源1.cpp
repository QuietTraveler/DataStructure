//#define _CRT_SECURE_NO_WARNINGS  1
//#define _CRT_SECURE_NO_WARNINGS  1
//
//#include <iostream>
//#include<cstdlib>
//#include<cstring>
//using namespace std;
//#define MAXSIZE 6
//typedef struct Queue {
//	int* data;
//	int  front;
//	int  rear;
//	int  size;
//}Queue;
//
//Queue* Init_Queue()
//{
//	Queue* Q = new Queue;
//	Q->data = new int[MAXSIZE];
//	Q->front = Q->rear = 0;
//	Q->size = 0;
//	return Q;
//}
//
//bool Empty_Queue(Queue* Q)
//{
//	return Q->size==0;
//}
//
//bool Full_Queue(Queue* Q)
//{
//	return Q->size==MAXSIZE;
//}
//
//bool Queue_Push(Queue* Q, int data)
//{
//	if (Full_Queue(Q))
//		return false;
//	Q->data[Q->rear] = data;
//	Q->rear = (Q->rear + 1) % MAXSIZE;
//	Q->size++;
//	return true;
//}
//
//bool Queue_Pop(Queue* Q)
//{
//	if (Empty_Queue(Q))
//		return false;
//	Q->front = (Q->front + 1) % MAXSIZE;
//	Q->size--;
//	return true;
//}
//
//void Print(Queue* Q)
//{
//	for (int i = 0; i < Q->size; i++)
//	{
//		cout << Q->data[i] << " ";
//	}
//	cout << endl;
//	cout << Q->size << endl;
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
