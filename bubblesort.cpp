
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

int main()
{
	int arr[] = { 9,8,7,11,12};
	int N = 5;
	bubbleSort(arr, N);
	cout << "Sorted array: \n";
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	return 0;
}
