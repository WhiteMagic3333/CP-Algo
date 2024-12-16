#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve()
{
	int n;
	cin >> n;
	vector<char> str;
	vector<int> index;
	int i = 1, j = 1;
	while (j <= n)
	{
		cout << "? 2 " << i << " " << j << '\n';
		fflush(stdout);
		int response;
		cin >> response;
		if (response > index.size())
		{
			char ch;
			printf("? 1 %d\n", j);
			fflush(stdout);
			cin >> ch;
			index.push_back(j);
			str.push_back(ch);
		}
		else
		{
			int low = 0;
			int high = index.size() - 1;
			int ans;
			while (low <= high)
			{
				int mid = (low + high) / 2;
				cout << "? 2 " << index[mid] << " " << j << '\n';
				fflush(stdout);
				cin >> response;
				if (response < (index.size() - mid + 1))
				{
					ans = mid;
					low = mid + 1;
				}
				else
					high = mid - 1;
			}
			int temp = ans;
			ans = index[ans];
			str.push_back(str[ans - 1]);
			index.erase(index.begin() + temp);
			index.push_back(j);
		}
		j++;
	}
	printf("! ");
	for (int i = 0; i < n; i++)
		printf("%c", str[i]);
}

int main()
{
	solve();
	return 0;
}