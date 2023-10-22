#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
//πÈ≤¢≈≈–Ú
void Merge(int* arr, int left, int mid, int right)
{
	int* val = new int[( right + left )*2];
	int i = left, j = mid + 1,t=0;
	while ( i <= mid && j <= right )
	{
		if ( arr[i] < arr[j] )
			val[t++] = arr[i++];
		else
			val[t++] = arr[j++];
	}

	while ( i <= mid )
		val[t++] = arr[i++];
	while ( j <= right )
		val[t++] = arr[j++];

	for ( int r = 0; r < t; r++ )
	{
		arr[left + r] = val[r];
	}
	delete[]val;
}

void MergeSort(int* arr,int left,int right)
{
	if ( left < right )
	{
		int mid = ( left + right ) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		Merge(arr,left,mid,right);
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
	int arr[] = { 2,34,1,8,7,67,45,0,6,111 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr,0,size-1);
	Print(arr, size);
	return 0;
}