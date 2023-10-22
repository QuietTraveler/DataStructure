#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int FindMax(int* arr, int size)
{
	int max = arr[0];
	for ( int i = 1; i < size; i++ )
	{
		if ( max < arr[i] )
		{
			max = arr[i];
		}
	}
	return max;
}

//计数排序
void CountSort(int* arr, int size)
{
	int n = FindMax(arr,size)+1;
	int* counts = new int[n];
	int* counts1 = new int[size];
	memset(counts, 0, sizeof(int) * n );
	memset(counts1, 0, sizeof(int) * size );

	for ( int i = 0; i < size; i++ )
	{
		counts[arr[i]]++;
	}

	for ( int i = 0; i < n; i++ )
	{
		if ( !i )
			continue;
		counts[i] = counts[i] + counts[i - 1];
	}

	for ( int i = size - 1; i >= 0; i-- )
	{
		int j = counts[arr[i]];
		counts[arr[i]]--;
		counts1[j - 1] = arr[i];
	}

	memcpy(arr, counts1,sizeof(int)*size);
}

void InitBucket(int** bucket, int row, int col)
{
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			bucket[i][j] = 0;
		}
	}
}

void Print(int* arr, int size)
{
	for ( int i = 0; i < size; i++ ) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//基数排序
void RadixSort(int* arr, int size)
{
	int max = FindMax(arr, size);

	int num = 0;
	while ( max )
	{
		max /= 10;
		num++;
	}

	int** bucket = new int*[10];
	for(int i=0;i<10;i++)
	{
		bucket[i] = new int[size + 1];
	}

	int y = 1,ret=0;

	for ( int i = 1; i <= num; i++ )
	{
		InitBucket(bucket, 10, size + 1);
		
		for ( int j = 0; j < size; j++ )
		{
			ret = arr[j] / y % 10;
			bucket[ret][++bucket[ret][0]] = arr[j];
		}

		y *= 10;

		int e = 0;
		for ( int row = 0; row < 10; row++ )
		{
			for ( int col = 1; col <= bucket[row][0]; col++ )
			{
				arr[e++] = bucket[row][col];
			}
		}

		Print(arr, size);
	}
}


int main()
{
	int arr[] = { 31,49,2,10,3,700,75,53,8,399 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//CountSort(arr, size);
	RadixSort(arr, size);
	//Print(arr, size);
	return 0;
}