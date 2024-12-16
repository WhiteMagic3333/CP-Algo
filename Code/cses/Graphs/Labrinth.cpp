#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
#include<stack>
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

struct con {
	int x;
	int y;
};

bool valid(vector<vector<char>> &grid, vector<vector<bool>> &vis, int &i, int &j)
{
	if (min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#' || vis[i][j])
		return false;
	return true;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char> (m));
	vector<vector<bool>> vis(n, vector<bool> (m, false));
	vector<vector<vector<int>>> prev(n, vector<vector<int>> (m, vector<int> (2, -1)));
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	queue<con> q;
	con cur;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 'A')
			{
				cur.x = i;
				cur.y = j;
				q.push(cur);
				vis[i][j] = true;
			}
		}
	}
	string direction = "LRUD";
	vector<array<int, 2>> dir = {{ 0, -1}, {0, 1}, { -1, 0}, {1, 0}};
	while (q.size())
	{
		cur = q.front();
		con next;
		if (grid[cur.x][cur.y] == 'B')
		{
			cout << "YES\n";
			int x = cur.x;
			int y = cur.y;
			int px, py, dx, dy;
			stack<char> ans;
			while (prev[x][y][0] != -1 && prev[x][y][1] != -1)
			{
				px = prev[x][y][0];
				py = prev[x][y][1];
				dx = x - px;
				dy = y - py;
				for (int i = 0; i < 4; i++)
				{
					if (dx == dir[i][0] && dy == dir[i][1]) {
						ans.push(direction[i]);
					}
				}
				x = px;
				y = py;
			}
			cout << ans.size() << "\n";
			while (ans.size())
			{
				cout << ans.top();
				ans.pop();
			}
			return;
		}
		for (int k = 0; k < 4; k++)
		{
			next.x = cur.x + dir[k][0];
			next.y = cur.y + dir[k][1];
			if (valid(grid, vis, next.x, next.y)) {
				q.push(next);
				vis[next.x][next.y] = true;
				prev[next.x][next.y][0] = cur.x;
				prev[next.x][next.y][1] = cur.y;
			}
		}
		q.pop();
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