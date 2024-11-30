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

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j)
{
	if (min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#' || vis[i][j])
		return;
	vis[i][j] = true;
	dfs(grid, vis, i - 1, j);
	dfs(grid, vis, i, j - 1);
	dfs(grid, vis, i, j + 1);
	dfs(grid, vis, i + 1, j);

}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char> (m));
	vector<vector<bool>> vis(n, vector<bool> (m, false));
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == '.' && vis[i][j] == false) {
				dfs(grid, vis, i, j);
				ans++;
			}
		}
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}