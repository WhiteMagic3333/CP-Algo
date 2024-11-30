#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;

void sieve(ll n)
{
	prime.resize(n + 1, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (prime[i] && i * i <= n) {
			for (ll j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
}

template<typename T>
std::istream& operator>>(std::istream&in, std::vector<T>& v) {
	for (T& x : v)
		in >> x;
	return in;
}

template<typename T>
std::ostream& operator<<(std::ostream&out, std::vector<T>& v) {
	for (const T& x : v)
		std::cout << x << ' ';
	std::cout << '\n';
	return out;
}

void dfs(vector<vector<char>> &arr, int n, int r, int c, int k)
{
	if (min(r, c) < 0 || max(r, c) >= n || arr[r][c] == 'X')
		return;
	arr[r][c] = 'X';
	dfs(arr, n, r + k, c, k);
	dfs(arr, n, r - k, c, k);
	dfs(arr, n, r, c + k, k);
	dfs(arr, n, r, c - k, k);

}

void solve()
{
	int n, k, r, c;
	cin >> n >> k >> r >> c;
	r--, c--;
	vector<vector<char>> arr(n, vector<char> (n, '.'));
	dfs(arr, n, r, c, k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int c1 = 0, c2 = 0;
			for (int k = 0; k < n; k++)
			{
				if(arr[i][k] == 'X')
					c1++;
				if(arr[k][j] == 'X')
					c2++;
			}
			if(c1 + c2 == 0)
				dfs(arr, n, i, j, k);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}