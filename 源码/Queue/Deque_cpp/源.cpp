//#define _CRT_SECURE_NO_WARNINGS  1
//
//#include <iostream>
//#include<cstdlib>
//#include<cstring>
//#include<assert.h>
//#define MAXSIZE 8
////Ë«¶Ë¶ÓÁÐ 
//typedef struct deque {
//	int* data;
//	int lport;
//	int rport;
//}deque;
//
//using namespace std;
//
//deque* Init_Deque()
//{
//	deque* node = new deque;
//	node->data = new int[MAXSIZE];
//	node->lport = node->rport = 0;
//	return node;
//}
//
//bool Empty_Deque(deque* Q)
//{
//	assert(Q);
//	return Q->lport == Q->rport;
//}
//
//bool Full_Deque(deque* Q)
//{
//	assert(Q);
//	if ((Q->lport - 1 + MAXSIZE) % MAXSIZE == Q->rport)
//		return true;
//	if ((Q->rport + 1) % MAXSIZE == Q->lport)
//		return true;
//	return false;
//}
//
//bool L_Pop_Deque(deque* Q)
//{
//	assert(Q);
//	if (Empty_Deque(Q))
//		return false;
//	Q->lport = (Q->lport + 1) % MAXSIZE;
//	return true;
//}
//
//bool R_Pop_Deque(deque* Q)
//{
//	assert(Q);
//	if (Empty_Deque(Q))
//		return false;
//	Q->rport = (Q->rport - 1 + MAXSIZE) % MAXSIZE;
//	return true;
//}
//
//bool L_Push_Deque(deque* Q,int data)
//{
//	assert(Q);
//	if (Full_Deque(Q))
//		return false;
//	Q->lport = (Q->lport - 1 + MAXSIZE) % MAXSIZE;
//	Q->data[Q->lport] = data;
//	return true;
//}
//
//bool R_Push_Deque(deque* Q,int data)
//{
//	assert(Q);
//	if (Full_Deque(Q))
//		return false;
//	Q->data[Q->rport] = data;
//	Q->rport = (Q->rport + 1) % MAXSIZE;
//	return true;
//}
//
//int Length_Deque(deque* Q)
//{
//	assert(Q);
//	return (Q->rport - Q->lport + MAXSIZE) % MAXSIZE;
//}
//
//bool Destroy_Deque(deque* Q)
//{
//	assert(Q);
//	if (Empty_Deque(Q))
//	return false;
//	delete(Q->data);
//	delete(Q);
//	return true;
//}
//
//void Print(deque* Q)
//{
//	if(Q->lport>Q->rport)
//	{
//
//		for (int i = Q->lport; i <=MAXSIZE - 1; i++)
//		{
//			cout << Q->data[i] << " ";
//		}
//		for (int i = 0; i < Q->rport; i++)
//		{
//			cout << Q->data[i] << " ";
//		}
//		cout << endl;
//		cout << Length_Deque(Q) << endl;
//	}
//	else
//	{
//		int start = (Q->rport > Q->lport) ? Q->lport : Q->rport;
//		int end = (Q->rport < Q->lport) ? Q->lport : Q->rport;
//		for (int i = start; i < end; i++)
//		{
//			cout << Q->data[i] << " ";
//		}
//		cout << endl;
//		cout << Length_Deque(Q) << endl;
//	}
//}
//int main() {
//
//	deque* Q = Init_Deque();
//	R_Push_Deque(Q, 5);
//	R_Push_Deque(Q, 3);
//	R_Push_Deque(Q, 2);
//	R_Push_Deque(Q, 1);
//	R_Push_Deque(Q, 7);
//	L_Push_Deque(Q, 6);
//	L_Push_Deque(Q, 21);
//	Print(Q);
//	L_Pop_Deque(Q);
//	L_Pop_Deque(Q);
//	//L_Pop_Deque(Q);
//	L_Pop_Deque(Q);
//	//L_Pop_Deque(Q);
//	R_Pop_Deque(Q);
//	R_Pop_Deque(Q);
//	//R_Pop_Deque(Q);
//	//L_Pop_Deque(Q);
//	Print(Q);
//	return 0;
//}
//
//
