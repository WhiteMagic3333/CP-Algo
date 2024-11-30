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
int n, m;

bool down(vector<vector<char>> &, vector<vector<bool>> &, bool, int, int);
bool left(vector<vector<char>> &, vector<vector<bool>> &, bool, int, int);
bool right(vector<vector<char>> &, vector<vector<bool>> &, bool, int, int);

bool diagonal(vector<vector<char>> &grid, int i, int j)
{
	bool left_down = (i < n - 1 && j > 0 && grid[i + 1][j - 1] == '*' ? true : false);
	bool right_down = (i < n - 1 && j < m - 1 && grid[i + 1][j + 1] == '*' ? true : false);
	bool left = (j > 0 && grid[i][j - 1] == '*' ? true : false);
	bool right = (j < m - 1 && grid[i][j + 1] == '*' ? true : false);
	bool down = (i < n - 1 && grid[i + 1][j] == '*' ? true : false);
	if (left_down && !(left || down))
		return true;
	if (right_down && !(right || down))
		return true;
	return false;
}

bool down(vector<vector<char>> &grid, vector<vector<bool>> &vis, bool status, int i, int j)
{
	vis[i][j] = true;
	bool below = (i < n - 1 && grid[i + 1][j] == '*' ? true : false);
	bool behind = (j > 0 && grid[i][j - 1] == '*' ? true : false);
	bool ahead = (j < m - 1 && grid[i][j + 1] == '*' ? true : false);
	if (diagonal(grid, i, j) || below)
		return false;
	if (status) {
		if (behind || ahead)
			return false;
		return true;
	}
	if (behind && ahead)
		return false;
	if (!(behind || ahead))
		return false;
	if (below)
		return false;
	if (ahead)
		return right(grid, vis, true, i, j + 1);
	else if (behind)
		return left(grid, vis, true, i, j - 1);
	else
		return false;
}

bool right(vector<vector<char>> &grid, vector<vector<bool>> &vis, bool status, int i, int j)
{
	vis[i][j] = true;
	bool below = (i < n - 1 && grid[i + 1][j] == '*' ? true : false);
	bool ahead = (j < m - 1 && grid[i][j + 1] == '*' ? true : false);
	if (diagonal(grid, i, j) || ahead)
		return false;
	if (status) {
		if (below)
			return false;
		return true;
	}
	if (below)
		return down(grid, vis, true, i + 1, j);
	return false;
}

bool left(vector<vector<char>> &grid, vector<vector<bool>> &vis, bool status, int i, int j)
{
	vis[i][j] = true;
	bool below = (i < n - 1 && grid[i + 1][j] == '*' ? true : false);
	bool behind = (j > 0 && grid[i][j - 1] == '*' ? true : false);
	if (diagonal(grid, i, j) || behind)
		return false;
	if (below)
		return false;
	return true;
}


void solve()
{
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char> (m, '.'));
	vector<vector<bool>> vis(n, vector<bool> (m, false));
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == '*' && !vis[i][j])
			{
				if (diagonal(grid, i, j))
					return void(cout << "NO");
				vis[i][j] = true;
				bool below = (i < n - 1 && grid[i + 1][j] == '*' ? true : false);
				bool ahead = (j < m - 1 && grid[i][j + 1] == '*' ? true : false);
				bool status = below && ahead;
				if (!(below || ahead))
					return void(cout << "NO");
				bool cur = true;
				if (below)
					cur = cur && down(grid, vis, status, i + 1, j);
				if (ahead)
					cur = cur && right(grid, vis, status, i, j + 1);
				if(!cur)
					return void(cout << "NO");
			}
		}
	}
	cout << "YES";
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