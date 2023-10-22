#include<iostream>
#include<algorithm>

//√∞≈›≈≈–Ú
void SwapSort(int* arr, int size)
{
	using namespace std;
	for ( int i = 0; i < size-1; i++ )
	{
		int flag = 1;
		for ( int j = 0; j < size - 1 - i; j++ )
		{
			if ( arr[j] > arr[j + 1] )
			{
				flag = 0;
				swap(arr[j], arr[j + 1]);
			}
		}
		if ( flag )
			break;
	}
}

//øÏÀŸ≈≈–Ú£®Ωªªª≈≈–Ú£©
void QuickSort(int *arr,int start,int end)
{
  if(start < end)
  {
	  int val = arr[start];
	  int i = start, j = end;
	  while ( i < j )
	  {
		  while ( j > i && arr[j] >= val )
			  j--;
		  if ( i >= j )
			  break;
		  arr[i] = arr[j];
		  while ( i < j && arr[i] <= val )
			  i++;
		  if ( i >= j )
			  break;
		  arr[j] = arr[i];
	  }
	  arr[i] = val;

	  QuickSort(arr, start, i - 1);
	  QuickSort(arr, i + 1, end);
  }
  return;
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
	int arr[] = { 1,1,1,2,43,3,1,1,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//SwapSort(arr,size);
	QuickSort(arr, 0, size - 1);
	Print(arr, size);
	return 0;
}