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

int problems(vector<int> &grid)
{
	int cnt = 0;
	for (int i = 1; i < grid.size(); i++)
	{
		if (grid[i - 1] > grid[i])
			cnt++;
	}
	return cnt;
}

void _swap(vector<vector<int>> &grid, int x, int y)
{
	int n = grid.size();
	for (int i = 0; i < n; i++)
		swap(grid[i][x], grid[i][y]);

}

bool check(vector<vector<int>> &grid)
{
	int n = grid.size();
	for (int i = 0; i < n; i++)
	{
		int cnt = problems(grid[i]);
		if (cnt)
			return false;
	}
	return true;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		// cout << grid[i];
	}
	int mx = 0, index;
	for (int i = 0; i < n; i++)
	{
		int cnt = problems(grid[i]);
		if (cnt > mx)
		{
			mx = cnt;
			index = i;
		}
	}
	if (mx == 0)
		return void(cout << "1 1");
	if (mx > 2)
		return void(cout << "-1");
	// cout << mx << " ";
	if (mx == 2)
	{
		int x = -1, y = -1;
		for (int i = 1; i < m; i++)
		{
			if (grid[index][i - 1] > grid[index][i])
			{
				if (x == -1)
					x = i - 1;
				else
					y = i;
			}
		}
		_swap(grid, x, y);
		if (check(grid))
			cout << x + 1 << " " << y + 1;
		else
			cout << "-1";
	}
	else
	{
		// vector<bool> equal(m, false);
		// for (int j = 0; j < m; j++)
		// {
		// 	bool f = true;
		// 	for (int i = 1; i < n; i++)
		// 	{
		// 		if (grid[i][j] != grid[i - 1][j])
		// 			f = false;
		// 	}
		// 	equal[j] = f;
		// }
		// int x = -1, y = -1;
		// for (int j = 1; j < m; j++)
		// {
		// 	if (grid[index][j - 1] > grid[index][j])
		// 	{
		// 		x = j;
		// 		bool f = false;
				
		// 		for (k = j - 1; k >= 0; k--)
		// 		{
		// 			if(equal[k] && is_right(k, j, grid[index]))
		// 			{
		// 				f = true;
		// 			}
		// 		}
		// 	}
		// }
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
		cout << "\n";
	}
	return 0;
}