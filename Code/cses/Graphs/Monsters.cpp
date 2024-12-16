#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
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
		std::cout << x ;
	std::cout << '\n';
	return out;
}

bool valid(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j, int n, int m)
{
	if(min(i, j) < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == '#')
		return false;
	return true;
}

bool border(int n, int m, int i, int j)
{
	if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
		return true;
	return false;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> grid(n, vector<char> (m));
	vector<vector<array<int, 2>>> prev(n, vector<array<int, 2>> (m));
	vector<vector<bool>> vis(n, vector<bool> (m, false));
	
	for (int i = 0; i < n; i++) 
		cin >> grid[i];

	queue<array<int, 3>> q;
	
	int x, y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 'M') {
				q.push({i, j, 0});
				vis[i][j] = true;
			}
			else if (grid[i][j] == 'A')
			{
				x = i;
				y = j;
				vis[i][j] = true;
			}
		}
	}
	
	q.push({x, y, 1});
	
	string dir = "LRUD";
	vector<array<int, 2>> dxy = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}};
	
	while (q.size())
	{
		array<int, 3> cur = q.front();
		q.pop();
		bool is_hero = cur[2];
		if(is_hero && border(n, m, cur[0], cur[1]))
		{
			vector<char> path;
			int i = cur[0];
			int j = cur[1];
			while(i != x || j != y)
			{
				int px = prev[i][j][0];
				int py = prev[i][j][1];
				int dx = i - px;
				int dy = j - py;
				for (int p = 0; p < 4; p++)
				{
					if(dx == dxy[p][0] && dy == dxy[p][1])
						path.push_back(dir[p]);
				}
				i = px;
				j = py;
			}
			reverse(path.begin(), path.end());
			cout << "YES\n";
			cout << path.size() << "\n";
			cout << path;
			return;
		}

		for (int p = 0; p < 4; p++)
		{
			int i = cur[0] + dxy[p][0];
			int j = cur[1] + dxy[p][1];
			
			if(valid(grid, vis, i, j, n, m))
			{
				if(is_hero)
					prev[i][j] = {cur[0], cur[1]};
				vis[i][j] = true;
				q.push({i, j, cur[2]});
			}
		}

	}
	cout << "NO";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}