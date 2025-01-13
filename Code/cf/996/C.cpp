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

ll sum;


void update(vector<vector<bool>> &vis, string &path) {
	int x = 0, y = 0;
	for (char ch : path) {
		vis[x][y] = false;
		if (ch == 'D') {
			x++;
		} else {
			y++;
		}
	}
	vis[x][y] = false;
}

bool update_row(vector<vector<int>> &grid, vector<vector<bool>> &vis, int r) {
	for (int i = 0; i < grid[r].size(); i++) {
		
	}
}

bool update_col(vector<vector<int>> &grid, vector<vector<bool>> &vis, int c) {

}
 
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int> (m, 0));
	vector<vector<bool>> vis(n, vector<bool> (m, true));
	string path;
	cin >> path;	
	for (auto &row : grid) {
		cin >> row;
		cout << row;
	}
	int x = 0, y = 0, k = 0;
	update(vis, path);
	vis[0][0] = true;
	sum = 0;
	if (path[0] == 'D') {
		for (int j = 0; j < m; j++) {
			sum += grid[0][j];
		}
	} else {
		for (int j = 0; j < m; j++) {
			sum += grid[j][0];
		}
	}
	while(k < path.length()) {
		if (path[k] == 'D') {
			x++;
		} else {
			y++;
		}
		k++;
		update_row(grid, vis, x) || update_col(grid, vis, y);
		vis[x][y] = true;
	}
	for (auto &row : grid) {
		cout << row;
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