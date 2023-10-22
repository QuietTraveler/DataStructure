#include<iostream>

//直接插入排序
void InsertSort(int* arr, int size)
{
	int val = 0, j = 0;
	for ( int i = 1; i < size; i++ )
	{
		val = arr[i];
		int j = i - 1;
		if ( val >= arr[j] )
			continue;
		for ( ; j >= 0; j-- )
		{
			if ( val >= arr[j] )
				break;
			else
				arr[j + 1] = arr[j];
		}
		arr[j + 1] = val;
	}
}

//希尔排序（直接插入排序的优化）
void ShellSort(int* arr, int size)
{
	for ( int d = 5; d >= 1; d /= 2 )
	{
		for ( int i = d; i < size; i++ )
		{
			int val = arr[i];
			int j = i - d;
			if ( val >= arr[i - d] )
			{
				continue;
			}
			for ( ; j >= 0; j -= d )
			{
				if ( val >= arr[j] )
					break;
				else
					arr[j + d] = arr[j];
			}
			arr[j + d] = val;
		}
	}
}

void Print(int* arr, int size)
{
	using namespace std;
	for ( int i = 0; i < size; i++ )
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 2,3,12,6,4,8,9,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, size);
	ShellSort(arr, size);
	Print(arr, size);

	return 0;
}