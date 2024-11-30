//TO be updated with nice code
#include <bits/stdc++.h>
using namespace std;

void preCompute(int arr[], int n, int pre[])
{
	pre[0] = arr[0];
	for (int i = 1; i < n; i++)
		pre[i] = arr[i] + pre[i - 1];
}

// Returns sum of elements in arr[i..j]
// It is assumed that i <= j
int rangeSum(int i, int j, int pre[])
{
	if (i == 0)
		return pre[j];

	return pre[j] - pre[i - 1];
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int pre[n];

	// Function call
	preCompute(arr, n, pre);
	cout << rangeSum(1, 3, pre) << endl;
	cout << rangeSum(2, 4, pre) << endl;

	return 0;
}