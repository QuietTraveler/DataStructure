#include<iostream>
#include<algorithm>
using namespace std;
//选择排序
int findMin(int* arr, int start, int end)
{
	int index = start, min = arr[start];
	for ( int i = start + 1; i < end; i++ )
	{
		if ( arr[i] < min )
		{
			index = i;
			min = arr[i];
		}
	}
	return index;
}

void SelectSort(int* arr, int size)
{
	for ( int i = 0; i < size - 1; i++ )
	{
		int min = findMin(arr, i, size);
		if ( min != i )
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void AdjustDown(int* arr, int end, int flag)
{
	int n = 2;
	if ( flag == 1 )
		n = 3;
	flag = 1;
	while ( flag && n*2 < end)
	{
		flag = 0;
		int* temp = &( arr[n * 2] );
		if ( n * 2 + 1 < end && arr[n * 2] > arr[n * 2 + 1] )
		{
			temp = &( arr[n * 2 + 1] );
			flag = 1;
		}
		if ( arr[n] > *temp )
		{
			swap(arr[n], *temp);
			if ( !flag )
				flag = -1;
		}
		else
			flag = 0;

		if ( flag == -1 )
			n = n * 2;
		else if(flag == 1 )
			n = n * 2 + 1;
	}
}

void InitHeap(int* arr, int end)
{
	int n = ( end - 1 ) / 2;   //计算最后一个内部结点的下标
	int flag = 0;

	while ( n )
	{
		flag = 0;
		int* temp = &( arr[n * 2] );
		if ( n * 2 + 1 < end && arr[n * 2] > arr[n * 2 + 1] )
		{
			temp = &( arr[n * 2 + 1] );
			flag = 1;
		}
		if ( arr[n] > *temp )
		{
			swap(arr[n], *temp);
			if ( !flag )
				flag = -1;
		}
		n--;
	}

	if(flag)
	AdjustDown(arr, end, flag);
}

void HeapPop(int* arr, int end)
{
	swap(arr[1], arr[end - 1]);
	InitHeap(arr, end - 1);
}

int HeapInsert(int* arr, int val, int end)
{
	arr[end] = val;
	InitHeap(arr, end + 1);
	return end + 1;
}

void HeapSort(int* arr, int size)
{
	int end = size;
	InitHeap(arr, end);
	//end=HeapInsert(arr, 90, end);
	for ( int i = 0; i < end - 1; i++ )
	{
		HeapPop(arr,end - i);
	}
}

void HeapAdjust1(int* arr, int start, int size)
{
	int largest = start, rson = 0, lson = 0;
	while ( largest * 2 + 1 < size )
	{
		lson = largest * 2 + 1;
		rson = largest * 2 + 2;
		if ( lson < size && arr[lson] < arr[largest] )
			largest = lson;
		if ( rson < size && arr[rson] < arr[largest] )
			largest = rson;

		if ( largest != start )
		{
			swap(arr[largest], arr[start]);
			start = largest;
		}
		else
			break;
	}
}

void HeapSort1(int* arr, int size)
{
	for ( int i = ( size - 1 ) / 2; i >= 0; i-- )
	{
		HeapAdjust1(arr, i, size);
	}

	for ( int i = 0; i < size - 1; i++ )
	{
		swap(arr[0], arr[size - 1 - i]);
		if ( i == size - 2 )
			break;
		HeapAdjust1(arr, 0, size - 1 - i );
	}
}

void Print(int* arr, int size)
{
	for ( int i = 0; i < size; i++ )
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[20] = { 0,6,45,2,1,7,8,56,45,11 };
	//int size = sizeof(arr) / sizeof(arr[0]);
	//SelectSort(arr, size);
	int size = 10;
	//HeapSort(arr, size);
	HeapSort1(arr, size);
	Print(arr, size);
	return 0;
}