#include <iostream>
#include <math.h>
#include <vector>
#include<algorithm>
using namespace std;

// Function to print the divisors
void printDivisors(int n)
{
	// Note that this loop runs till square root
	vector<int> ans;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			ans.push_back(n / i);
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << " ";
}

/* Driver program to test above function */
int main()
{
	cout << "The divisors of 100 are: \n";
	printDivisors(180);
	return 0;
}